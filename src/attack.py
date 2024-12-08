import subprocess
import sys
import os
from time import sleep

writeable_word = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~"


def fileAtLocation(filename):
    """
fileAtLocation()- function:

    Description:
        This funtion check if file exists
        
    Args:
        The path to file + file name
        Ex: /home/broder/file.txt

    Variables:
        None

    Returns:
        True: if file exists
        False: if file does not exist
    """
    return os.path.exists(filename)

def usage():
    """
usage()- function:

    Description:
        This funtion print the usage
    
    Args:
        None
        
    Variables:
        None
        
    Returns:
        exit(-1)
    """
    print("Usage:\n\tpython3 attack.py <rar_file> <target_file>\n\tpython3 attack.py <rar_file>")
    exit(-1)

def handle_input():
    """
Handle_input() - function:
    
    Description:
        This funtion hanle input to do command
        
    Args:
        Two agruments from the input of the user(require at least 1)

    Variables:
        global rar_file
        global target_file
        
    Returns:
        rar_file, target_file if user give target file
        only rar_file if user don't give target file
    """
    
    global rar_file
    global target_file
    
    if(len(sys.argv) == 2):
        rar_file = sys.argv[1]
        
        return rar_file, None
        
    elif(len(sys.argv) == 3):
        rar_file = sys.argv[1]
        target_file = sys.argv[2]
        
        return rar_file, target_file
    
    else:
        usage()
        
                

class attack():
    """
attack() - class:

    Description:
    
        This class give the method to extract file rar.
        
    Attributes:
    
        rar file, passwd (guess password) and target file(if exist).

    Methods:
    
        def __init__(self, rar_file, passwd ,target_file=None):
        
            Description:
                Handle agrument for class.
                
            Args:
                rar file, passwd (guess password) and target file(if exist).
            
            Variables:
                self.rar_file
                self.passwd
                self.target_file
                
            Returns:
                None
        
        def run(self):
        
            Description:
                Depend on the exists of target_file to determine which 
                function(method to extract file rar) to call.
                
            Args:
                self.target_file
                self.attack_onlyfilerar()
                self.attack_filerar_fileinside()
                
            Variables:
                None
                
            Returns:
                self.attack_onlyfilerar(): if target_file exist.
                self.attack_filerar_fileinside(): if target_file doesn't not exist.
               
        def attack_onlyfilerar(self):     

            Description:
                This function run when user only give rar_file. 
                run command: unrar t -p"password" rar_file.
                
            Args:
                self.rar_file
                self.passwd
                
            Variables:
                passwd_writable
                command
                output
                
            Returns:
                exit(0): if password found.
                1: if function run normally
                exit(-1): if function happens errors.
                
            Libraries:
                subprocess.
                
        def attack_filerar_fileinside(self):     

            Description:
                This function run when user only give rar_file. 
                run command: rar -p"password" x rar_file target_file.
                
            Args:
                self.rar_file
                self.passwd
                self.target_file
                
            Variables:
                passwd_writable
                command
                output
                
            Returns:
                exit(0): if password found.
                1: if function run normally
                exit(-1): if function happens errors.
                
            Libraries:
                subprocess.
       
    """
    
    def __init__(self, rar_file, passwd ,target_file=None):
        self.rar_file =rar_file
        self.passwd = str(passwd)
        self.target_file = target_file
    
    def run(self):
        
        if self.target_file is None:
            self.attack_onlyfilerar()
        elif self.target_file:
            self.attack_filerar_fileinside()
        else:
            print("Invalid number of arguments provided.")
    
    
    def attack_onlyfilerar(self):
       
        try:
            passwd_writable = ""
          
            #Handler some special symbols when execute command in Linux     
            for i in range(len(self.passwd)):
                
                if self.passwd[i] in ('\"', '$', '`'):
                    passwd_writable = passwd_writable + '\\' +  self.passwd[i]
                    
                else: 
                    passwd_writable = passwd_writable + self.passwd[i]

            # For debug
            # print(f'[~]Guessing:........ {self.passwd}')
            
            # Execute the RAR extraction command
            command = f'unrar t -p"{passwd_writable.strip()}" {self.rar_file}'
            
            
            #Using subprocess.run to run the command and check the output.
            #If "All OK" exists, password is correct, you will have password
            
            output = subprocess.run(command, capture_output=True, text=True, shell=True)
            
            if "All OK" in output.stdout:
                print(f"[*]Cracking successful!\nPassword: {self.passwd}")
                exit(0)
            return 1
        
        except subprocess.CalledProcessError as e:
            print(f"Error executing the command: {e}")
            exit(-1)
    
    def attack_filerar_fileinside(self):

        try:
            passwd_writable = ""
            
            #Handler some special symbols when execute command in Linux
            
            for i in range(len(self.passwd)):
                
                if self.passwd[i] in ('\"', '$', '`'):
                    passwd_writable = passwd_writable + '\\' +  self.passwd[i]
                    
                else: 
                    passwd_writable = passwd_writable + self.passwd[i]

            # For debug
            # print(f'[~]Guessing:........ {self.passwd}')
            
            # Execute the RAR extraction command
            command = f'rar -p"{passwd_writable.strip()}" x {self.rar_file} "{self.target_file}"'
            
            #Using subprocess.run to run the command and check the output.
            #If "All OK" exists, password is correct, you will have password
            
            output = subprocess.run(command, capture_output=True, text=True, shell=True)
            
            if "All OK" in output.stdout:
                print(f"[*]Cracking successful!\nPassword: {self.passwd}")
                sleep(10)
                exit(0)
            return 1
        
        except subprocess.CalledProcessError as e:
            print(f"Error executing the command: {e}")
            exit(-1) 


class bruteforce():

    """
bruteforce() - class:

    Description:
    
        This class gives functions to start attacking.
        There are some methods to attack: brute-force, dictionary.
        
    Attributes:
    
        rar file, target file(if exist).

    Methods:

        def __init__(self ,rar_file, target_file=None):
        
            Description:
                Handle agrument for class.
                
            Args:
                rar file and target file(if exist).
            
            Variables:
                self.rar_file
                self.target_file
                
            Returns:
                None

        def attack_bruteforce_len(self ,size, writeable_word, current_string=""):
      
            Description:
                Generates all possible character combinations of length n from 
                the given chars. Brute-force with passowrd which the size is n.
                
            Args:
                size: the length of password need to create.
                writeable_word: string inlcudes characters which you want to create password.
                current_string: string to make password.
                self.rar_file
                self.target_file
            
            Variables:
                char
                new_string
                            
            Function or Class outside:
                atack = attack()

                            
            Returns:
                None    
                
        def attack_bruteforce_small_length(self):

            Description:
                Function bruteforce password with length in range 1-2.
                
            Args:
                self
            
            Variables:
                len
                writeable_word
                
            Function or Class outside:
                
                bruteforce()
                
            Returns:
                None          

        def attack_bruteforce_large_length(self):

            Description:
                Function bruteforce password with length larger 2.
                
            Args:
                self
            
            Variables:
                len
                writeable_word
                           
            Function or Class outside:
                bruteforce()
                
            Returns:
                None     
                
        def attack_dictionary(self):

            Description:
                Using dictionary attack:
                    First, the dictionary with the popular password.
                    Then, the information of user.
                
            Args:
                self
            
            Variables:
                len
                
            Returns:
                None    
            
            Function or Class outside:
                fileAtLocation()
                attack()                                
    """
    
    
    def __init__(self ,rar_file, target_file=None):
        self.rar_file = rar_file
        self.target_file = target_file
        
    def attack_bruteforce_len(self ,size, writeable_word, current_string=""):
        # Base case: If n is 0, print the current string (combination)
        if size == 0:
            atck = attack(self.rar_file, current_string ,self.target_file)
            atck.run()
            return

        # Loop through each character in chars
        for char in writeable_word:
            # Append the character to the current string
            new_string = current_string + char
            # Recursively call with n-1 and the new string
            bruteforce.attack_bruteforce_len(self, size - 1, writeable_word, new_string)  
            
    def attack_bruteforce_small_length(self):
        print("\nBrutforce with length of password in range 1-2\n")
        sleep(2)
        
        len = 1
        while True: 
            bruteforce.attack_bruteforce_len(self, len, writeable_word)
            len = len + 1
            if(len > 2):
                break

    def attack_bruteforce_large_length(self):
    
        print("\nBrutforce with length of password in range larger 2\n")
        sleep(2)
        
        len = 3
        while True: 
            bruteforce.attack_bruteforce_len(self, len, writeable_word)
            len = len + 1

  
    def attack_dictionary(self):
   
        print("\nDictionary attack\n")
        sleep(5)
        
        if (fileAtLocation('../dictionary/wordlists/common_word.txt')):
            
            print("Dictionary attack with wordlist(commond password)\n")
            sleep(2)
            
            with open("../dictionary/wordlists/common_word.txt", 'r+') as fp:
                for line in fp:
                    atck = attack(self.rar_file, line ,self.target_file)
                    atck.run()
      
        
            
        
        if (fileAtLocation('../dictionary/information_user/name.txt')):

            #Check if file exists
         
            print("\nDictionary attack with name of the owner file rar\n")
            sleep(2)
            
            with open("../dictionary/information_user/name.txt") as fp:
                for line in fp:
                    atck = attack(self.rar_file, line ,self.target_file)
                    atck.run()   


        
        if (fileAtLocation('../dictionary/information_user/day.txt')):
            #Check if file exists  
                    
            print("\nDictionary attack with day of the owner file rar\n")
            sleep(2)
            
            with open("../dictionary/information_user/day.txt") as fp:
                for line in fp:
                    atck = attack(self.rar_file, line ,self.target_file)
                    atck.run()   


        if (fileAtLocation('../dictionary/information_user/nameday.txt')):
            #Check if file exists
            
            print("\nDictionary attack with name and birthday of the owner file rar\n")
            sleep(2)    
        
            with open("../dictionary/information_user/nameday.txt") as fp:
                for line in fp:
                    atck = attack(self.rar_file, line ,self.target_file)
                    atck.run()   

        

  
  
def ATCK(rar_file, target_file):
    """
ATCK() - function:

    Description:
        This funtion are the same as main, to call outside.
        
    Args:
        rar_file
        target_file

    Variables:
        None

    Returns:
        None
    """
    try:
        if not fileAtLocation(rar_file):     
            print("No file rar can be found")
            sys.exit(0)       
        print(f'[*]You pick rar file: {rar_file}')
        print(f'[*]You pick target file: {target_file}')
        brute = bruteforce(rar_file, target_file)
        brute.attack_bruteforce_small_length()
        brute.attack_dictionary()
        brute.attack_bruteforce_large_length()  
    except KeyboardInterrupt:
        print("[+]Exit crack password!!!")
                    
         
def main():
    """
main() - function:

    Description:
        This function to run code.
        First, handler input to get rar_file and target_file.
        Aterwards, cracking password.
        
    Args:
        rar_file
        target_file

    Variables:
        None

    Returns:
        None
    """
    try:
        rar_file, target_file = handle_input()
        if not fileAtLocation(rar_file):     
            print("No file rar can be found")
            sys.exit(0)
        print(f'[*]You pick rar file: {rar_file}')
        print(f'[*]You pick target file: {target_file}')
        brute = bruteforce(rar_file, target_file)
        brute.attack_bruteforce_small_length()
        brute.attack_dictionary()
        brute.attack_bruteforce_large_length()
    except KeyboardInterrupt:
        print("[+]Exit crack password!!!")
           
    

if __name__ == "__main__":
    main()


