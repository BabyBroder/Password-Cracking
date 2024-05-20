#include "setup.hpp"

/**
 * @brief Generates and writes all combinations of names, dates, and combined name-date
 *        formats to a file.
 *
 * This function takes two arguments:
 *  - `full_name_vt`: A vector of strings representing a full name
 *                    (potentially containing first, middle, and last names).
 *  - `tabel_date`: A vector of vectors of strings representing possible
 *                  combinations of date components (e.g., day, month, year).
 *
 * The function writes all possible combinations of names, dates, and combined
 * name-date formats to a file named "nameday.txt" located in the
 * "../../dictionary/information_user/" directory.
 *
 * The function performs the following steps:
 *
 * 1. **Write Separate Names and Dates:**
 *    - Calls `ouput_date` to write all permutations of possible dates to the file.
 *    - Calls helper functions (assumed) to process names and write them to the file.
 *        - Likely involves generating subsets and permutations of names similar to
 *          `ouput_name`.
 *
 * 2. **Combine Names and Dates:**
 *    - Iterates through subsets of names (`name_subset`) and available dates (`tabel_date`).
 *    - For each name-date combination:
 *      - Merges the name and date components into a single vector using
 *        `custom_merge_vector` (assumed function).
 *      - Generates all uppercase letter combinations for the merged vector using
 *        `uppercase_word_vt` (assumed function).
 *      - For each uppercase combination:
 *        - Generates all permutations of the uppercase name-date combination
 *          using `findPermutations`.
 *        - Writes each permutation (representing a possible combined name-date
 *          format) to the file using `display_file_vt_vt` (assumed function).
 *
 * **Note:** This function assumes the existence of several helper functions like
 * `custom_merge_vector`, `uppercase_word_vt`, `display_file`, `display_file_vt`,
 * and `display_file_vt_vt`.
 */
void ouput_name_date(std::vector<std::string> full_name_vt, std::vector<std::vector<std::string>> tabel_date)
{
    // WRITE TO FILE INCLUDE NAME OR DATE OR NAME AND DATE

    // Find the subet of vetor contain each word of name
    // Such as {"Nguyen", "Van", "anh"} will take the result
    //  {"Nguyen"}, {"Van"}, {"anh"}, {"Nguyen", "Van"},........
    std::vector<std::vector<std::string>> name_subset = subsets_vt(full_name_vt);

    //  open file to write
    FILE *fd = freopen("../../dictionary/information_user/nameday.txt", "w+", stdout);

    // Only have date born
    for (int id_day = 0, size_table_date = tabel_date.size(); id_day < size_table_date; id_day++)
    {
        // Loop each available date
        std::vector<std::string> one_subset_date = tabel_date[id_day];

        // Find permutation of this vector
        std::vector<std::vector<std::string>> permu_date = findPermutations(one_subset_date);

        // Loop each element in permutation of vector
        for (int id_per = 0, size_per = permu_date.size(); id_per < size_per; id_per++)
        {
            display_file(permu_date[id_per]);
        }
    }

    // Only have name
    // Loop each subset
    for (int id_sub = 1, size_sub = name_subset.size(); id_sub < size_sub; id_sub++)
    {
        // Find the permutations of subet
        std::vector<std::vector<std::string>> per_sub = findPermutations(name_subset[id_sub]);

        // Loop each permutations of subet
        for (int id_per_sub = 0, size_per_sub = per_sub.size(); id_per_sub < per_sub.size(); id_per_sub++)
        {
            // Merge vector string to string
            // Such as {"Nguyen", "Van", "A"} -> "NguyenVanA"
            std::string str_out = custom_merge_vector_tostring(per_sub[id_per_sub]);

            // Find the permutation of upper-case letter in str_out
            std::vector<std::string> str_out_uppeer = uppercase_word(str_out);

            // write to file
            display_file_vt(str_out_uppeer);
        }
    }

    // Combine name and date
    for (int id_sub = 1, size_sub = name_subset.size(); id_sub < size_sub; id_sub++)
    {
        // Loop each subsets of name

        for (int id_day = 0, size_table_date = tabel_date.size(); id_day < size_table_date; id_day++)
        {
            // Loop each available date

            // Meger name and date
            std::vector<std::string> Merge_name_day = custom_merge_vector(name_subset[id_sub], tabel_date[id_day]);

            // Find the uppercarse of word in vector include name and date
            std::vector<std::vector<std::string>> vt_upper_name_day = uppercase_word_vt(Merge_name_day);

            // Loop each result of uppercarse of word in vector include name and date
            for (int id_upper_nd = 0, size_upper_nd = vt_upper_name_day.size(); id_upper_nd < size_upper_nd; id_upper_nd++)
            {
                // Find the permutation of this uppercarse of word in vector include name and date
                std::vector<std::vector<std::string>> permutation_per_upper = findPermutations(vt_upper_name_day[id_upper_nd]);

                // write to file
                display_file_vt_vt(permutation_per_upper);
            }
        }
    }
    fclose(fd);

/*
    *COMBINE ONE SYMBOL + NAME OR DATE OR NAME AND DATE, AFTERWARDS WRITE TO FILE

    std::vector<std::string> symblos = {"~", "`", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")",
                                        "-", "_", "+", "=", "{", "}", "[", "]", ":", ";", "'", "\"",
                                        "\\", "|", "<", ",", ">", ".", "?", "/"};
    int len_symbols = symblos.size();


    *Find the subet of vetor contain each word of name
    *Such as {"Nguyen", "Van", "anh"} will take the result
    *{"Nguyen"}, {"Van"}, {"anh"}, {"Nguyen", "Van"},........
    std::vector<std::vector<std::string>> name_subset = subsets_vt(full_name_vt);

    *open file to write
    FILE *fd1 = freopen("../../dictionary/nameday_onesymbols.txt", "w+", stdout);


    *Only have date born + one symbol
        
    for (int id_symbol = 0; id_symbol < len_symbols; id_symbol++)
    {
    
        for (int id_day = 0, size_table_date = tabel_date.size(); id_day < size_table_date; id_day++)
        {
            *Loop each available date
            std::vector<std::string> one_subset_date = tabel_date[id_day];

            *Push one symmbol
            one_subset_date.push_back(symblos[id_symbol]);

            *Find permutation of this vector
            std::vector<std::vector<std::string>> permu_date = findPermutations(one_subset_date);

            *Loop each element in permutation of vector
            for (int id_per = 0, size_per = permu_date.size(); id_per < size_per; id_per++)
            {
                display_file(permu_date[id_per]);
            }

        }

        * Only have name + one symbol
        * Loop each subset
        for (int id_sub = 1, size_sub = name_subset.size(); id_sub < size_sub; id_sub++)
        {
            *Find the permutations of subet
            std::vector<std::vector<std::string>> per_sub = findPermutations(name_subset[id_sub]);

            * Loop each permutations of subet
            for (int id_per_sub = 0, size_per_sub = per_sub.size(); id_per_sub < per_sub.size(); id_per_sub++)
            {

                std::vector<std::string> sym_per_sub = per_sub[id_per_sub];

                *Push one symbol
                sym_per_sub.push_back(symblos[id_symbol]);

                *Merge vector string to string
                *Such as {"Nguyen", "Van", "A", "!"} -> "NguyenVanA!"
                std::string str_out = custom_merge_vector_tostring(sym_per_sub);

                * Find the permutation of upper-case letter in str_out
                std::vector<std::string> str_out_uppeer = uppercase_word(str_out);

                *write to file
                display_file_vt(str_out_uppeer);
            }
        }

        * Combine name and date + one symbol
        for (int id_sub = 1, size_sub = name_subset.size(); id_sub < size_sub; id_sub++)
        {
            *Loop each subsets of name


            for (int id_day = 0, size_table_date = tabel_date.size(); id_day < size_table_date; id_day++)
            {
                *Loop each available date

                *Meger name and date
                std::vector<std::string> Merge_name_day = custom_merge_vector(name_subset[id_sub], tabel_date[id_day]);

                *Push one symbol
                Merge_name_day.push_back(symblos[id_symbol]);

                *Find the uppercarse of word in vector include name and date
                std::vector<std::vector<std::string>> vt_upper_name_day = uppercase_word_vt(Merge_name_day);

                *Loop each result of uppercarse of word in vector include name and date
                for (int id_upper_nd = 0, size_upper_nd = vt_upper_name_day.size(); id_upper_nd < size_upper_nd; id_upper_nd++)
                {
                    *Find the permutation of this uppercarse of word in vector include name and date
                    std::vector<std::vector<std::string>> permutation_per_upper = findPermutations(vt_upper_name_day[id_upper_nd]);

                    *write to file
                    display_file_vt_vt(permutation_per_upper);
                }
            }
        }
    }

    fclose(fd1);

/*
    -----------------------------------------------------------------
    |This is an example code to add one symbols to make a dictionary|
    |If you have enough time and want to make dictionary better, you|
    |can configure it.                                              |
    |You can add one, two,... words, letters or wordlist to what you| 
    |want.                                                          |
    -----------------------------------------------------------------
*/

}
/**
 * @brief Generates and writes all possible name combinations to a file.
 *
 * This function takes a vector of strings `full_name_vt` (potentially containing
 * first name, middle name, and last name) and writes all possible combinations
 * of names to a file named "name.txt" located in the
 * "../../dictionary/information_user/" directory.
 *
 * The function performs the following steps:
 *
 * 1. **Generate Subsets of Names:**
 *    - Calls `subsets_vt` to generate all subsets of words from `full_name_vt`.
 *    - This captures all possible combinations of names, including single names,
 *      double names (first and middle or middle and last), and the full name.
 *
 * 2. **Permute Each Subset:**
 *    - Iterates through the generated subsets (excluding the first element,
 *      which is the original `full_name_vt`):
 *      - For each subset, calls `findPermutations` to generate all possible
 *        arrangements (orders) of the words within the subset.
 *
 * 3. **Generate Uppercase Combinations:**
 *    - Iterates through the permutations of each subset:
 *      - Merges the words in the permutation into a single string using
 *        `custom_merge_vector_tostring` (assumed function).
 *      - Calls `uppercase_word` (assumed function) to generate all possible
 *        combinations of uppercase letters within the merged string.
 *
 * 4. **Write to File:**
 *    - Uses `display_file_vt` (assumed function) to write each generated
 *      uppercase combination (representing a possible name) to the output file.
 *
 * **Note:** This function assumes the existence of helper functions like
 * `custom_merge_vector_tostring`, `uppercase_word`, and `display_file_vt`.
 *
 * @param full_name_vt A vector of strings representing a full name
 *                     (potentially containing first, middle, and last names).
 */
void ouput_name(std::vector<std::string> full_name_vt)
{
    // WRITE TO FILE INCLUDE NAME OR DATE OR NAME AND DATE

    // Find the subet of vetor contain each word of name
    // Such as {"Nguyen", "Van", "anh"} will take the result
    //  {"Nguyen"}, {"Van"}, {"anh"}, {"Nguyen", "Van"},........
    std::vector<std::vector<std::string>> name_subset = subsets_vt(full_name_vt);

    //  open file to write
    FILE *fd = freopen("../../dictionary/information_user/name.txt", "w+", stdout);

    // Only have name
    // Loop each subset
    for (int id_sub = 1, size_sub = name_subset.size(); id_sub < size_sub; id_sub++)
    {
        // Find the permutations of subet
        std::vector<std::vector<std::string>> per_sub = findPermutations(name_subset[id_sub]);

        // Loop each permutations of subet
        for (int id_per_sub = 0, size_per_sub = per_sub.size(); id_per_sub < per_sub.size(); id_per_sub++)
        {
            // Merge vector string to string
            // Such as {"Nguyen", "Van", "A"} -> "NguyenVanA"
            std::string str_out = custom_merge_vector_tostring(per_sub[id_per_sub]);

            // Find the permutation of upper-case letter in str_out
            std::vector<std::string> str_out_uppeer = uppercase_word(str_out);

            // write to file
            display_file_vt(str_out_uppeer);
        }
    }
    fclose(fd);
}

/**
 * @brief Generates and writes all permutations of possible dates to a file.
 *
 * This function takes a vector of vectors of strings `tabel_date`. Each inner
 * vector represents a possible combination of date components (e.g., ["04", "09"],
 * ["04", "2024"]). The function writes all permutations of these possible
 * dates to a file named "day.txt" located in the
 * "../../dictionary/information_user/" directory.
 *
 * The function performs the following steps:
 *
 * 1. **Iterate Through Possible Dates:**
 *    - Iterates through each inner vector in `tabel_date`. This represents a
 *      possible combination of date components.
 *
 * 2. **Generate Permutations:**
 *    - For each possible date combination, calls `findPermutations` to generate
 *      all possible arrangements (orders) of the components within the date.
 *
 * 3. **Write Permutations to File:**
 *    - Iterates through the permutations of each date combination:
 *      - Uses `display_file` (assumed function) to write each permutation
 *        (representing a possible date format) to the output file.
 *
 * @param tabel_date A vector of vectors of strings representing possible
 *                   combinations of date components (e.g., day, month, year).
 */
void ouput_date(std::vector<std::vector<std::string>> tabel_date)
{

    //  open file to write
    FILE *fd = freopen("../../dictionary/information_user/day.txt", "w+", stdout);

    // Only have date born
    for (int id_day = 0, size_table_date = tabel_date.size(); id_day < size_table_date; id_day++)
    {
        // Loop each available date
        std::vector<std::string> one_subset_date = tabel_date[id_day];

        // Find permutation of this vector
        std::vector<std::vector<std::string>> permu_date = findPermutations(one_subset_date);

        // Loop each element in permutation of vector
        for (int id_per = 0, size_per = permu_date.size(); id_per < size_per; id_per++)
        {
            display_file(permu_date[id_per]);
        }
    }
    fclose(fd);
}