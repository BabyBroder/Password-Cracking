#include <bits/stdc++.h>
#include "usage.hpp"
#include "work.hpp"

std::string full_name;
std::string date_born;

std::vector<std::string> full_name_vt;
std::vector<std::string> date_born_vt;
/**
 * @brief Entry point for the dictionary attack program.
 *
 * This function is the main entry point for the program. It performs the
 * following tasks:
 *
 * 1. **Input Name and Birthday:**
 *    - Calls the `choice` function (assumed to be defined elsewhere) to
 *      prompt the user for the full name and date of birth of the RAR file owner.
 *      - Stores the user input in `full_name` and `date_born` variables.
 *
 * 2. **Process Input:**
 *    - Checks if both name and date of birth are provided:
 *      - If yes, calls functions to generate dictionary entries for various
 *        combinations of names, dates, and combined name-date formats.
 *    - If only name is provided, calls functions to generate dictionary entries
 *      using all possible permutations of the name.
 *    - If only date of birth is provided, calls functions to generate
 *      dictionary entries using all possible permutations of the date components.
 *    - If no name or date of birth is provided, informs the user and exits.
 *
 * **Note:** This function relies on several helper functions defined,
 * including:
 *  - `choice` (for user input)
 *  - `split_string_by_space_vt_name` (for splitting name into a vector)
 *  - `split_string_by_space_vt_day` (for splitting date of birth into a vector)
 *  - `date_permutation` (for generating permutations of date components)
 *  - `ouput_name_date` (for generating dictionary entries with name, date, and combined formats)
 *  - `ouput_name` (for generating dictionary entries with name permutations)
 *  - `ouput_date` (for generating dictionary entries with date permutations)
 */
int main()
{
    /*input name and birthday*/
    choice(full_name, date_born);

    
    if (!date_born.empty() && !full_name.empty())
    {
        /*If have both name and birthday*/
        std::cout << "[*]Dictionary attack\n";
        std::cout << "You give me the name and birthday of the owner of rar file, I will attempt to create a good Dictionary for you\nHappy cracking!!!\nWait a minute.....\n";

        // give both name and birthday

        // get each word in name to vector
        full_name_vt = split_string_by_space_vt_name(full_name);

        // get number in birthday to vector
        date_born_vt = split_string_by_space_vt_day(date_born);

        // find the available permutation of number in birthday to vector
        std::vector<std::vector<std::string>> table_born = date_permutation(date_born_vt);


        // write to file
        if(!full_name_vt.size() && !table_born.size()){
            return 0;
        }
        ouput_name_date(full_name_vt, table_born);
        return 0;
    }
    if (!full_name.empty() && date_born.empty())
    {
        /*If only have name*/
        std::cout << "[*]Dictionary attack\n";
        std::cout << "You only give me the name of the owner of rar file, dictionary with the available name will be created\nHappy cracking!!!\nWait a minute.....\n";

        // get each word in name to vector
        full_name_vt = split_string_by_space_vt_name(full_name);

        if (full_name_vt.size() == 0)
        {
            // Invalid name
            return 0;
        }

        ouput_name(full_name_vt);
        return 0;
    }
    if (full_name.empty() && !date_born.empty())
    {
        /*If only have birthday*/
        std::cout << "[*]Dictionary attack\n";
        std::cout << "You only give me the birthday of the owner of rar file, dictionary with the available birthday will be created\nHappy cracking!!!\nWait a minute.....\n";

        // get number in birthday to vector
        date_born_vt = split_string_by_space_vt_day(date_born);

        // find the available permutation of number in birthday to vector
        std::vector<std::vector<std::string>> table_born = date_permutation(date_born_vt);

        if (table_born.size() == 0)
        {
            // Invalid birthday
            return 0;
        }
        ouput_date(table_born);
        return 0;
    }
    std::cout << "Hmmmm........ You don't give any informations for me, so I can't create Dictionary for you\n";
    sleep(5);
    return 0;
}
