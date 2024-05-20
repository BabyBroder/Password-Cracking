#include <iostream>
#include <string>
#include <cstdlib>
/**
 * @brief Prompts the user for a string input, storing it in the provided reference.
 *
 * This function displays a message "Your input:" followed by a tab character.
 * It then discards any characters remaining in the standard input buffer
 * using `std::cin.ignore()` to avoid unintended input from previous operations.
 * Finally, it uses `std::getline` to read a line of text from standard input,
 * storing the entire line (including whitespace) in the `STR` reference
 * up to the first occurrence of a newline character (`\n`).
 *
 * @param STR A reference to a `std::string` object where the user's input will be stored.
 */

void input_string(std::string &STR)
{
    std::cout << "Your input:\t";
    std::cin.ignore();
    getline(std::cin, STR, '\n');
}
/**
 * @brief Displays a usage message for the program.
 *
 * This function prints three lines to the standard output stream:
 *   - "1. Input full name"
 *   - "2. Input date of Birth"
 *   - "3. Exit"
 *
 * These lines provide the user with a menu of options for interacting with
 * the program.
 */

void usage()
{
    std::cout << "1. Input full name\n";
    std::cout << "2. Input date of Birth\n";
    std::cout << "3. Exit\n";
}
/**
 * @brief Allows the user to choose an action from a menu.
 *
 * This function presents a menu of three options to the user using `usage()`,
 * then prompts the user to enter their choice. The loop continues until
 * the user enters a valid choice ("1", "2", or "3").
 *
 * - If the user enters "1", `input_string` is called to get the full name
 *   and store it in the `full_name` reference.
 * - If the user enters "2", `input_string` is called to get the date of birth
 *   and store it in the `date_born` reference.
 * - If the user enters "3", the function returns to terminate the program.
 * - If the user enters an invalid choice, an error message is displayed.
 *
 * @param full_name A reference to a `std::string` object where the user's full name will be stored.
 * @param date_born A reference to a `std::string` object where the user's date of birth will be stored.
 */

void choice(std::string &full_name, std::string &date_born)
{

    while (true)
    {
        std::string your_choice;

        usage();
        std::cout << "You choose:\t";
        std::cin >> your_choice;

        if(your_choice == std::string("1")){

            input_string(full_name);

        }else if(your_choice == std::string("2")){

            input_string(date_born);

        }else if(your_choice == std::string("3")){
        
            return;

        }else{
            std::cout << "Invalid choice \n";
        }
    }
    
}