#!/usr/bin/env python3
import subprocess
import gi

gi.require_version("Gtk", "3.0")
from gi.repository import GObject
from gi.repository import Gtk
from gi.repository import GLib
import attack

rar_file = None
target_file = None


class CommandTextView(Gtk.TextView):
    """
    Improved text view widget that reads and displays the output of multiple
    commands asynchronously.

    This custom text view prevents user editing and provides methods to run
    commands and handle their standard output and error streams asynchronously.
    """

    def __init__(self):
        """
        Initializes the CommandTextView object.

        Sets the text view buffer and disables editing functionality.
        """
        super(CommandTextView, self).__init__()
        self.buffer = self.get_buffer()
        self.set_editable(False)                    #no edit

    
    def clear(self):
        """
        Clears the text view buffer.
        """
        self.buffer.set_text("")

    def run(self, command):
        """
        Runs a command asynchronously and displays the output in the text view.

        Args:
            command (str): The command to execute.
        """
        proc = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
        stdout, stderr = proc.communicate()
        self.handle_output(stdout)
        self.handle_error(stderr)

    def handle_output(self, data):
        """
        Processes the captured standard output data from the command.

        Args:
            data (bytes): The captured standard output data from the command.
        """
        if data:
            output = data.decode("utf-8")
            # Append output with a newline separator
            self.buffer.insert_at_cursor(output + "\n")

    def handle_error(self, data):
        """
        Handles errors captured from the standard error stream of the command.

        Args:
            data (bytes): The captured standard error data from the command.
        """
        if data:
            error_output = data.decode("utf-8")
            print(f"Error: {error_output}")


class CommandWindow(Gtk.Window):
    """
    Window with a text view widget that displays the output of multiple commands.

    This window class creates a scrollable window containing a CommandTextView
    object for displaying command output. It also provides methods to run
    commands and connect to the window's "destroy" signal.
    """

    def __init__(self, command_text_view):
        """
        Initializes the CommandWindow object.

        Sets the window title, default size, and creates a scrollable window
        containing the provided command text view.

        Args:
            command_text_view (CommandTextView): The text view object to display command output.
        """
        
        super(CommandWindow, self).__init__(title="The Note")
        self.set_default_size(1200, 400)

        # Create a scrollable window
        scrollview = Gtk.ScrolledWindow()
        scrollview.add(command_text_view)

        # Add the scrollable window to the main window
        self.add(scrollview)

        self.command_text_view = command_text_view  # Store the text view reference

    def run_commands(self, command):
        """
        Runs a list of commands sequentially and displays their outputs.

        This method assumes a single command string is provided and directly
        calls the `run` method of the stored command text view to execute it.

        Args:
            command (str): The command to execute.
        """
        
        self.command_text_view.run(command)

    def connect_destroy(self, callback):
        """
        Connects the "destroy" signal to the provided callback function.

        This allows other code to perform actions when the window is closed.

        Args:
            callback: The function to be called when the window is destroyed.
        """
        self.connect("destroy", callback)


    

class FileChooserWindow(Gtk.Window):
    """
    Window with a button to trigger a file chooser dialog for selecting a RAR file.

    This window allows the user to choose a RAR file using a file chooser dialog
    and displays basic information about the selected file.
    """
    
    def __init__(self, win_output):
        """
        Initializes the FileChooserWindow object.

        Sets the window title, default size, and creates a button labeled
        "Choose File" that triggers the file chooser dialog when clicked.

        Args:
            win_output (CommandWindow): The CommandWindow object to display information about the selected file.
        """
        Gtk.Window.__init__(self, title="Password Cracking")
        self.set_default_size(1000, 800)  # Set window size
        self.window = win_output

        # Fixed positioning (using fixed container)
        fixed = Gtk.Fixed()
        self.add(fixed)

        button1 = Gtk.Button(label="Choose File")
        button1.connect("clicked", self.on_file_clicked)
        button1.set_size_request(200, 200)
        fixed.put(button1, 400, 300)  # Place button at (400, 300) coordinates
    

    def on_file_clicked(self, widget):
        """
        Presents a file chooser dialog when the "Choose File" button is clicked.

        This method creates a file chooser dialog with filters for RAR files
        and any files. It retrieves the selected filename and displays basic
        information about the chosen file in the provided CommandWindow object.

        Args:
            widget (Gtk.Button): The button that was clicked (assumed to be the "Choose File" button).
        """
        global rar_file
        global target_file
        
        """
        Create Dialog to choose file
        """
        dialog = Gtk.FileChooserDialog(
            title="Please choose a file", parent=self, action=Gtk.FileChooserAction.OPEN
        )
        
        #add buttons
        dialog.add_buttons(
            Gtk.STOCK_CANCEL,
            Gtk.ResponseType.CANCEL,
            Gtk.STOCK_OPEN,
            Gtk.ResponseType.OK,
        )

        #add filter
        self.add_filters(dialog)

        #run dialog
        response = dialog.run()
        if response == Gtk.ResponseType.OK:
            """
            Open window and write information of file rar after choosing to it.
            """
            out = setup(self.window)
            rar_file = dialog.get_filename()
            arr_path = rar_file.rsplit("/", 1)
            out.output(f'echo "In the directory : {arr_path[0]}"')
            out.output(f'echo "You choose file : {arr_path[1]}"')
            
        elif response == Gtk.ResponseType.CANCEL:
            print("Cancel clicked")

        dialog.destroy()
        self.destroy()

    def add_filters(self, dialog):
        """
        Adds filters to the file chooser dialog for RAR files and any files.

        This method creates two file filters: one for RAR files with the MIME
        type "application/x-rar" and another for any file type using a wildcard pattern "*".
        It then adds both filters to the file chooser dialog.

        Args:
            dialog (Gtk.FileChooserDialog): The file chooser dialog to add filters to.
        """
        filter_rar = Gtk.FileFilter()
        filter_rar.set_name("RAR files")
        filter_rar.add_mime_type("application/x-rar") 
        dialog.add_filter(filter_rar)


        filter_any = Gtk.FileFilter()
        filter_any.set_name("Any files")
        filter_any.add_pattern("*")
        dialog.add_filter(filter_any)


class setup():
    """
    Helper class for managing file selection and output redirection in the password cracking application.

    This class provides methods to open a file chooser window for selecting the RAR file
    and to redirect the standard output of commands to the designated CommandWindow object.
    """
    def __init__(self, window):
        """
        Initializes the setup object.

        Stores a reference to the provided CommandWindow object.

        Args:
            window (CommandWindow): The CommandWindow object to redirect command output to.
        """
        self.window = window
    
    def choosefile(self):
        """
        Opens a FileChooserWindow to allow the user to select a RAR archive.

        This method creates a FileChooserWindow instance and displays it to the user.
        The user can then navigate and select the desired RAR file.
        """
        win_open = FileChooserWindow(self.window)
        win_open.show_all()    
    

    def output(self, command):
        """
        Redirects the standard output of a command to the CommandWindow object.

        This method calls the `run_commands` method of the stored CommandWindow object,
        passing the provided command string. This allows the command's output to be displayed
        in the CommandTextView widget within the CommandWindow.

        Args:
            command (str): The command to execute and redirect its output.
        """
        
        self.window.run_commands(command)

def get_target_file():
    """
    Prompts the user for the target file within the RAR archive and returns it.

    This function asks the user if they want to specify a target file within
    the RAR archive. It validates the user's input (Y or n) and returns the
    target filename if provided, otherwise returns None.

    Returns:
        str: The target filename within the RAR archive (if provided), otherwise None.
    """

    while True:
        choice = input("Do you want to give the target file inside file rar [Y/n]: ").upper()
        if choice in ("Y", "N"):
            if choice == "Y":
                target_file = input("Give me the target file: ")
                return target_file
            else:
                return None  # User chose not to provide a target file
        else:
            print("Invalid choice! Please enter Y or n.")



def main():
    """
    The main function that creates the application window and initiates execution.

    This function creates a CommandWindow object with a CommandTextView, opens
    a setup object to manage file selection and output redirection, presents
    the file chooser window, displays the contents of the README.md file
    (assuming it's in the same directory), connects the window's "destroy"
    signal to quit the application, shows the window, and starts the GTK main loop.
    Finally, it calls the get_target_file function to prompt the user for the
    target file and passes both the RAR file path and target file path (if provided)
    to the attack.ATCK function (assuming it's defined in the attack.py module).
    """

    #Create window to show information
    window = CommandWindow(CommandTextView())
    run = setup(window)
    
    #Choose file rar
    run.choosefile()
    
    run.output("cat README.md")  
    
    window.connect_destroy(Gtk.main_quit)
    window.show_all()  
    Gtk.main()
    
    #Get target file
    target_file = get_target_file()
    attack.ATCK(rar_file, target_file)

if __name__ == "__main__":
    main()
