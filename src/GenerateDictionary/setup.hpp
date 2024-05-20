#include <bits/stdc++.h>

/**
 * @brief Checks if a string consists only of alphabetic characters (a-z, A-Z).
 *
 * This function iterates through each character in the given string `s`.
 * It uses `std::isalpha(*it)` to check if the current character (`*it`) is
 * an alphabetic character. If any character is not alphabetic, the function
 * returns `false`.
 *
 * The function also checks if the string is empty (`s.empty()`). An empty
 * string is not considered alphabetic.
 *
 * If all characters in the string are alphabetic and the string is not empty,
 * the function returns `true`.
 *
 * Check if string is alpha such as "Hello3" is not aplha, "Nguyen" is alpha
 * @param s The string to be checked.
 * @return `true` if the string consists only of alphabetic characters, `false` otherwise.
 */
bool is_alpha(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isalpha(*it))
        ++it;
    return !s.empty() && it == s.end();
}
/**
 * @brief Checks if a string consists only of numeric characters (0-9).
 *
 * This function iterates through each character in the given string `s`.
 * It uses `std::isdigit(*it)` to check if the current character (`*it`) is
 * a numeric character. If any character is not numeric, the function
 * returns `false`.
 *
 * The function also checks if the string is empty (`s.empty()`). An empty
 * string is not considered numeric.
 *
 * If all characters in the string are numeric and the string is not empty,
 * the function returns `true`.
 *
 * Check if string is number
 * 
 * @param s The string to be checked.
 * @return `true` if the string consists only of numeric characters, `false` otherwise.
 */
bool is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
// MERGE

/**
 * @brief Merges a vector of strings into a single string.
 *
 * This function iterates over the provided `info` vector and concatenates
 * each string element to a resulting string (`res`).
 *
 * The function assumes that the `info` vector contains strings.
 *
 * @param info A vector of strings to be merged.
 * @return A single string formed by concatenating all strings in the input vector.
 */
std::string custom_merge_vector_tostring(std::vector<std::string> info)
{
    // This function merge vector string to string
    // Such as {"Hello", "World"} => "HelloWorld"
    std::string res = "";
    for (int i = 0; i < info.size(); i++)
    {
        res += info[i];
    }
    return res;
}
/**
 * @brief Merges two vectors of strings into a single vector.
 *
 * This function creates a new vector `res` to store the merged elements.
 * It uses `std::make_move_iterator` to efficiently insert elements from
 * both `vector1` and `vector2` into the `res` vector. This approach avoids
 * unnecessary copying of data.
 *
 * The function assumes that both `vector1` and `vector2` contain strings.
 *
 * @param vector1 The first vector to be merged.
 * @param vector2 The second vector to be merged.
 * @return A new vector containing all elements from both input vectors.
 */
std::vector<std::string> custom_merge_vector(std::vector<std::string> vector1, std::vector<std::string> vector2)
{
    // This function merge vector and vector
    std::vector<std::string> res;

    // Insert vector 1
    res.insert(
        res.end(),
        std::make_move_iterator(vector1.begin()),
        std::make_move_iterator(vector1.end()));
    // Insert vector 2
    res.insert(
        res.end(),
        std::make_move_iterator(vector2.begin()),
        std::make_move_iterator(vector2.end()));
    return res;
}

//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
/**
 * @brief Splits a string into words separated by spaces, validating for alphabetic characters.
 *
 * This function takes a string `str` and splits it into individual words
 * separated by spaces. It uses an `std::istringstream` object `iss` to
 * treat the string as a stream of characters.
 *
 * The function iterates through the stream using `getline(iss, word, ' ')`.
 * In each iteration, it extracts a word up to the next space character
 * and stores it in the `word` variable.
 *
 * However, this function also performs validation on each extracted word.
 * It calls `is_alpha(word)` (assumed to be defined elsewhere) to check if
 * the word consists only of alphabetic characters (a-z, A-Z). If any word
 * contains non-alphabetic characters, an error message is printed indicating
 * invalid input for a name and an empty vector is returned.
 *
 * If all words are valid (alphabetic), the function adds each word to the
 * `words` vector. Finally, it returns the `words` vector containing the
 * split words.
 *
 * @param str The string to be split.
 * @return A vector of strings containing the individual words from the input string,
 *         or an empty vector if the input contains non-alphabetic characters.
 */
std::vector<std::string> split_string_by_space_vt_name(const std::string &str)
{
    // Get the word in the string that include a space
    // Such as "This is my project"
    // vector : {"This", "is", "my", "project"}
    //empty for invalid input
    std::vector<std::string> empty;
    std::vector<std::string> words;
    std::istringstream iss(str);
    std::string word;

    // Read words from the stringstream one at a time
    while (getline(iss, word, ' '))
    {
        //Invalid name
        if(!is_alpha(word)){
            std::cout << "\nInvalid input for name.\nThe dictionary will not contain name\n\n";
            return empty;
        }
        words.push_back(word);
    }

    return words;
}

/**
 * @brief Splits a string into words separated by spaces (without validation).
 *
 * This function is similar to `split_string_by_space_vt_name` but does not perform
 * any validation on the extracted words. It simply splits the input string `str`
 * into individual words separated by spaces using an `std::istringstream` and
 * stores them in the `words` vector.
 *
 * This function is likely intended for cases where validation is not necessary
 * or handled elsewhere.
 *
 * @param str The string to be split.
 * @return A vector of strings containing the individual words from the input string.
 */
std::vector<std::string> split_string_by_space_vt_day(const std::string &str)
{
    // Get the word in the string that include a space
    // Such as "This is my project"
    // vector : {"This", "is", "my", "project"}
    //empty for invalid input
    std::vector<std::string> empty;
    std::vector<std::string> words;
    std::istringstream iss(str);
    std::string word;

    // Read words from the stringstream one at a time
    while (getline(iss, word, ' '))
    {
        words.push_back(word);
    }

    return words;
}

//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
// Rely on: https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/ to make the algorithm for my purposing
// With vector vt = {"Nguyen", "Van", "Anh"}
// I will create the vector<vector<string>>
// At index
// 1: {"nguyen", "Nguyen", ......,"NGuyEn" ........., "NGUYEN"}
// 2: {"van", "Van",............"vAN",.............., "VAN"}
// 3: {"anh", "Anh",.............."AnH",............, "ANH"}

/**
 * @brief Uppercases a single character in a string at a specified index.
 *
 * This function takes a string `str` and an index `id`. It checks if the index
 * is within the valid range of the string (`id >= 0 && id < str.size()`) and
 * if the character at that index is alphabetic (`isalpha(str[id])`).
 *
 * If both conditions are met, the function uppercases the character at the
 * specified index using `std::toupper(str[id])` and modifies the original
 * string `str`.
 *
 * The function then returns the modified string.
 *
 * @param str The string to modify.
 * @param id The index of the character to uppercase.
 * @return The modified string with the character at `id` uppercased (if valid).
 */
std::string toupper_one(std::string str, int id)
{
    // Function to upper-case one letter of string at index id.
    if (id >= 0 && id < str.size() && isalpha(str[id]))
    {
        str[id] = std::toupper(str[id]);
    }
    return str;
}
/**
 * @brief Helper function for generating all subsets of a set (recursive implementation).
 *
 * This function is a helper function used by `subsets` to recursively generate
 * all possible subsets of a set with `num` elements using a backtracking approach.
 *
 * The function takes the following arguments:
 *  - `num`: The total number of elements in the set.
 *  - `res`: A reference to a vector of vectors of integers. This vector will
 *          store all generated subsets as the recursion progresses.
 *  - `subset`: A reference to a vector of integers that represents the current
 *              subset being built during the recursion. Initially, this will be
 *              empty.
 *  - `index`: The current index used in the recursive process. This starts at 0
 *          and is incremented during recursion to explore different possibilities.
 *
 * The function works by recursively exploring two options at each step:
 *  1. **Include the current element:**
 *     - The function adds the element at the current index (`index`) to the
 *       `subset` vector.
 *     - It then calls itself recursively with `index + 1` to explore further
 *       possibilities where the current element is included in the subset.
 *     - After the recursive call returns, it removes the element from the
 *       `subset` vector (backtracking).
 *  2. **Exclude the current element:**
 *     - The function simply continues the recursion with `index + 1` without
 *       modifying the current `subset`. This explores possibilities where the
 *       current element is not included.
 *
 * By recursively exploring both options (include or exclude) at each step
 * and backtracking to remove included elements, the function ensures that all
 * possible combinations of elements are considered, generating all subsets.
 *
 * @details This function assumes that `num` is a valid non-negative integer.
 */
void calcSubset(int num, std::vector<std::vector<int>> &res, std::vector<int> &subset, int index)
{
    res.push_back(subset);
    // Add the current subset to the result list

    // Generate subsets by recursively including and
    // excluding elements
    for (int i = index; i < num; i++)
    {
        // Include the current element in the subset

        subset.push_back(i);

        // Recursively generate subsets with the current
        // element included

        calcSubset(num, res, subset, i + 1);

        // Exclude the current element from the subset
        // (backtracking)

        subset.pop_back();
    }
}
/**
 * @brief Generates all subsets of a set with a given number of elements (recursive implementation).
 *
 * This function implements a recursive backtracking algorithm to generate
 * all possible subsets of a set with `num` elements. It relies on the
 * `calcSubset` helper function (assumed to be defined elsewhere) to perform
 * the actual recursive generation.
 *
 * The function creates an empty vector `subset` to store the current subset
 * being built and a vector of vectors `res` to store all generated subsets.
 * It then calls `calcSubset` with the initial parameters: `num`, a reference
 * to `res`, a reference to the empty `subset`, and an initial index of 0.
 *
 * The `calcSubset` function performs the recursive exploration of subsets,
 * and the final result is the `res` vector containing all generated subsets.
 *
 * @param num The number of elements in the set.
 * @return A vector of vectors of integers, where each inner vector represents
 *         a unique subset of the original set.
 */
std::vector<std::vector<int>> subsets(int num)
{
    // Function to create the table index of the permunation combination 
    // subsets(4) will return
    // 0
    // 0 1
    // 0 1 2
    // 0 2
    // 1
    // 1 2
    // 2
    std::vector<int> subset;
    // vetor to return
    std::vector<std::vector<int>> res;
    int index = 0;
    calcSubset(num, res, subset, index);
    return res;
}

/**
 * @brief Generates all uppercase letter combinations for a given word.
 *
 * This function takes a string `str` as input and generates all possible
 * combinations where one or more letters are uppercased. It uses a
 * backtracking approach to explore all combinations.
 *
 * The function performs the following steps:
 *  1. Converts the input string `str` to lowercase using `transform` to ensure
 *     consistent handling of case.
 *  2. Calls the `subsets` function (assumed to be defined elsewhere) to
 *     generate all possible combinations of indices where letters can be
 *     uppercased. `subsets(len)` provides these combinations, where `len` is
 *     the length of the input string.
 *  3. Iterates through the generated combinations from `subsets`:
 *     - For each combination, a copy of the original string (`str_copy`) is created
     - The `toupper_one` function (assumed to be defined elsewhere) is used on
       `str_copy` to uppercase letters at the indices specified in the current
       combination.
 *  4. The modified string (`str_copy`) with the uppercase combination applied
 *     is added to the result vector `res`.
 *
 * Finally, the function returns the `res` vector containing all generated
 * uppercase combinations for the input word.
 *
 * @param str The word for which to generate uppercase letter combinations.
 * @return A vector of strings containing all possible uppercase combinations
 *         of the input word.
 */
std::vector<std::string> uppercase_word(std::string str)
{
    // Generate the Combination upper-case of word
    //  vector: hi: hi, Hi, hI, HI

    // vetor to return
    std::vector<std::string> res;
    int len = str.size();

    // Make string str lower-case
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    // Generate the Combination upper-case of word
    std::vector<std::vector<int>> num = subsets(len);

    for (int i = 0; i < num.size(); i++)
    {
        // Create upper-case combination string without modify original string
        std::string str_copy = str;

        for (int j = 0; j < num[i].size(); j++)
            str_copy = toupper_one(str_copy, num[i][j]);

        // Push to vector res
        res.push_back(str_copy);
    }
    return res;
}

/**
 * @brief Generates all uppercase letter combinations for words in a vector,
 * combining them with original dates.
 *
 * This function takes a vector of strings `str_vt` containing a mix of words
 * (potentially names and dates). It processes the vector to separate names
 * (alphabetic words) from potential dates (numeric strings), generates all
 * uppercase letter combinations for each name, and finally combines the
 * processed names with the original dates.
 *
 * The function performs the following steps:
 *
 * 1. **Separation of Names and Dates:**
 *    - Iterates through `str_vt`.
 *    - If a non-alphabetic string is encountered (`!is_alpha(str_vt[i])`), it's
 *      assumed to be the start of dates.
 *    - All subsequent elements are moved to a separate `Num` vector to store
 *      dates. The loop breaks after this point.
 *    - Otherwise, the size of the current word (string) is pushed to a `size`
 *      vector to keep track of word lengths for later processing.
 *
 * 2. **Merging and Lowercasing Names:**
 *    - The remaining alphabetic words in `str_vt` are merged into a single
 *      string `str` using `custom_merge_vector_tostring`. (Assumes this function
 *      exists and concatenates strings in `str_vt`.)
 *    - The merged string `str` is converted to lowercase using `transform` to
 *      ensure consistent handling of case during uppercase letter combination
 *      generation.
 *
 * 3. **Generating Uppercase Combinations:**
 *    - `subsets(len)` (where `len` is the length of `str`) is called to generate
 *      all possible combinations of indices for uppercase letters.
 *    - Iterates through the generated combinations:
 *      - For each combination, a copy of the lowercase string (`str_copy`) is
 *        created.
 *      - The `toupper_one` function is used on `str_copy` to uppercase letters
 *        at the indices specified in the current combination.
 *      - The modified string (`str_copy`) with the uppercase combination applied
 *        is added to a `vt_str` vector.
 *
 * 4. **Splitting Uppercased Names and Combining with Dates:**
 *    - Iterates through the `vt_str` vector containing uppercase combinations.
 *    - For each combination, a new vector `ret` is created to store the final
 *      result (processed name with dates).
 *    - Iterates through the `size` vector, which stores the original word lengths.
 *    - For each word length:
 *      - Uses `substr` to extract the corresponding section from the current
 *        uppercase combination string in `vt_str`.
 *      - Adds the extracted word (substring) to the `ret` vector, effectively
 *        splitting the uppercase combination into separate words.
 *    - Finally, the processed names (`ret`) are merged with the original dates
 *      (`Num`) using `custom_merge_vector` (assumed to exist).
 *
 * 5. **Adding Result to Overall Output:**
 *    - The final result (`ret`) for the current name is added to the overall
 *      result vector `res`.
 *
 * @param str_vt A vector of strings containing words (potentially names and dates).
 * @return A vector of vectors of strings. Each inner vector represents a
 *         combination of a name with uppercased letters and the corresponding dates.
 */
std::vector<std::vector<std::string>> uppercase_word_vt(std::vector<std::string> str_vt)
{
    // Such as vector : {"Nguyen", "Van", "Anh", "01", "01", "2005"}
    // First, pop numbers and save to other vector(Num)
    // Second, meger this string "NguyenVanAnh", and to lower all, "nguyenvananh"
    // Next, find the permutation of uppercase of this string
    // Push the vector(num)

    // vetor to return
    std::vector<std::vector<std::string>> res;
    // vector to save number
    std::vector<std::string> Num;

    // Vector size will save the length of each word in name
    std::vector<int> size;

    // First, pop numbers and save to other vector(Num)
    for (int i = 0; i < str_vt.size(); i++)
    {
        if (!is_alpha(str_vt[i]))
        {
            // Because I create vector with name and afterwards is date;
            // when the first num is seen, this is the end of name
            for (int j = str_vt.size() - i - 1; j >= 0; j--)
            {
                Num.push_back(str_vt[j + i]);
                str_vt.pop_back();
            }
            break;
        }
        // push the size of word in name
        size.push_back(str_vt[i].size());
    }

    // Second, meger string
    std::string str = custom_merge_vector_tostring(str_vt);

    // vector save strings after upper-case combination
    std::vector<std::string> vt_str;
    int len = str.size();

    // Second, meger string to lower-case
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    // Next, find the permutation of uppercase of string
    std::vector<std::vector<int>> num = subsets(len);

    for (int i = 0; i < num.size(); i++)
    {
        // Loop each vector in vector<vector<>>

        // Create upper-case combination string without modify original string
        std::string str_copy = str;

        for (int j = 0; j < num[i].size(); j++)
            str_copy = toupper_one(str_copy, num[i][j]);

        vt_str.push_back(str_copy);
    }

    for (int i = 0, len = vt_str.size(); i < len; i++)
    {
        std::vector<std::string> ret;

        // index for vector size
        int id = 0;
        for (int j = 0; j < size.size(); j++)
        {
            // Loop each size of original string
            // The purpose is split string name to vector string
            // Such as: "HELLOwoRlD" => {"HELLO", "woRlD"}

            // use substring to get each word
            std::string each_str = vt_str[i].substr(id, size[j]);

            // increase index
            id += size[j];

            // push to ret
            ret.push_back(each_str);
        }

        // meger name and date
        ret = custom_merge_vector(ret, Num);

        // push to res
        res.push_back(ret);
    }
    return res;
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

/**
 * @brief Generates all possible date permutations from a given birth date.
 *
 * This function takes a vector of strings `date_birth` representing a birth
 * date (e.g., ["04", "09", "2024"]). It performs various checks to ensure the
 * input is valid (all digits) and within reasonable ranges (day: 1-31,
 * month: 1-12, year: positive integer). If the input is invalid, an error
 * message is printed, and an empty vector is returned.
 *
 * Otherwise, the function generates all possible combinations of date
 * components by considering different splitting points.
 *
 * The function creates separate vectors for days, months, and years, 
 * considering single-digit and double-digit formats. It then iterates through
 * these vectors, pushing each combination to the result vector `res`.
 *
 * @param date_birth A vector of strings representing a birth date (e.g., ["04", "09", "2024"]).
 * @return A vector of vectors of strings. Each inner vector represents a
 *         possible permutation of the birth date (e.g., ["04", "09", "2024"],
 *         ["04", "2024"], ["09", "2024"], etc.).
 */
std::vector<std::vector<std::string>> date_permutation(std::vector<std::string> date_birth)
{
    // Create the table of dates born
    // Such as 04/09/2024
    // The possible case exists in the password
    // 04
    // 04 09
    // 04 09 2005
    // 04 09 05
    // 04 9
    // 04 9  2005
    // 04 9  05
    // 4
    // 4  09
    // 4  09 2005
    // 4  09 05
    // 4  9
    // 4  9  2005
    // 4  9  05
    std::vector<std::vector<std::string>> res;

    // Handle input for birthday, check if vector only have number
    for (int id = 0; id < date_birth.size(); id++)
    {
        if (!is_number(date_birth[id]))
        {
            std::cout << "\nInvalid input for birthday!!!\nThe dictionary will not contain birthday\n\n";
            return res;
        }
    }

    std::vector<std::string> days;
    std::vector<std::string> months;
    std::vector<std::string> years;

    if (stoi(date_birth[0]) <= 0 || stoi(date_birth[0]) >= 32)
    {
        // Invalid day
        std::cout << "\nInvalid input(day) for birthday!!!\nThe dictionary will not contain birthday\n\n";
        return res;
    }
    days.push_back(date_birth[0]);

    if (date_birth.size() == 1)
    {
        months.push_back("");
        years.push_back("");
    }
    else if (date_birth.size() == 2)
    {

        if (stoi(date_birth[1]) <= 0 || stoi(date_birth[1]) >= 13)
        {
            // Invalid month
            std::cout << "\nInvalid input(month) for birthday!!!\nThe dictionary will not contain birthday\n\n";
            return res;
        }

        months.push_back(date_birth[1]);
        years.push_back("");
    }
    else if (date_birth.size() == 3)
    {
        if (stoi(date_birth[1]) <= 0 || stoi(date_birth[1]) >= 13)
        {
            // Invalid month
            std::cout << "\nInvalid input(month) for birthday!!!\nThe dictionary will not contain birthday\n\n";
            return res;
        }

        if (stoi(date_birth[2]) <= 0 || stoi(date_birth[2]) >= 9999)
        {
            // Invalid year
            std::cout << "\nInvalid input(year) for birthday!!!\nThe dictionary will not contain birthday\n\n";
            return res;
        }

        months.push_back(date_birth[1]);
        years.push_back(date_birth[2]);
    }
    else
    {
        std::cout << "\nInvalid input for birthday!!!\nThe dictionary will not contain birthday\n\n";
        return res;
    }

    // if day < 10, push it
    if (stoi(date_birth[0]) < 10)
    {
        days.push_back(std::to_string(stoi(date_birth[0])));
    }

    // if month < 10, push it
    if (stoi(date_birth[1]) < 10)
    {
        months.push_back(std::to_string(stoi(date_birth[1])));
    }

    // push last two number digit in year
    years.push_back(date_birth[2].substr(2, 2));

    // Create date_copy without modify original date
    std::vector<std::string> date_copy;

    for (int i = 0; i < days.size(); i++)
    {

        // push each available day
        date_copy.push_back(days[i]);

        // push to res
        res.push_back(date_copy);

        for (int j = 0; j < months.size(); j++)
        {
            // push each available day
            date_copy.push_back(months[j]);

            // push to res
            res.push_back(date_copy);
            for (int k = 0; k < years.size(); k++)
            {
                // push each available year
                date_copy.push_back(years[k]);

                // push to res
                res.push_back(date_copy);

                // pop to renew year
                date_copy.pop_back();
            }

            // pop to renew month
            date_copy.pop_back();
        }

        // pop to renew day
        date_copy.pop_back();
    }
    return res;
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
// DISPLAY TO FILE

// display to file
void display_file(std::vector<std::string> a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i];
    }
    std::cout << '\n';
}
// display to file
void display_file_vt(std::vector<std::string> table)
{
    for (int i = 0; i < table.size(); i++)
    {
        std::cout << table[i];
        std::cout << '\n';
    }
}
// display to file
void display_file_vt_vt(std::vector<std::vector<std::string>> table)
{
    for (int i = 0; i < table.size(); i++)
    {
        display_file(table[i]);
    }
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//

/**
 * @brief Generates all permutations of a given vector of strings.
 *
 * This function takes a vector of strings `a` and returns a vector of vectors
 * of strings, where each inner vector represents a permutation of the original
 * input. Permutation refers to all possible arrangements of the elements in
 * the input vector.
 *
 * The function performs the following steps:
 *  1. Sorts the input vector `a` using `std::sort` to ensure consistent
 *     ordering during permutation generation.
 *  2. Uses `std::next_permutation` in a loop to iterate through all possible
 *     permutations of the sorted vector. For each permutation, a copy of the
 *     current vector `a` is pushed back to the result vector `res`.
 *
 * @param a A vector of strings.
 * @return A vector of vectors of strings. Each inner vector represents a
 *         permutation of the input vector.
 */
std::vector<std::vector<std::string>> findPermutations(std::vector<std::string> a)
{
    // Function to find the permutations of vector string

    std::vector<std::vector<std::string>> res;

    // Sort the given array
    std::sort(a.begin(), a.end());

    // Find all possible permutations
    do
    {
        res.push_back(a);
    } while (std::next_permutation(a.begin(), a.end()));

    return res;
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
// https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/
// Find the subset of vector

/**
 * @brief Helper function to generate all subsets of a vector using backtracking.
 *
 * This function is a helper function for the `subsets_vt` function. It
 * implements a backtracking algorithm to recursively generate all possible
 * subsets of a given vector `A`.
 *
 * The function takes the following arguments:
 *  - `A`: The original vector of strings (passed by reference).
 *  - `res`: The result vector to store generated subsets (passed by reference).
 *  - `subset`: A temporary vector to store the current subset being built during recursion.
 *  - `index`: The current index used during recursion to track the position in `A`.
 *
 * The function works as follows:
 *  1. It adds the current subset (`subset`) to the result vector (`res`). This captures
 *     the current state of the subset being built.
 *  2. It iterates through the elements of `A` starting from the current `index`.
 *     - For each element:
 *       - It includes the element in the current subset by pushing it to `subset`.
 *       - It recursively calls itself (`calcSubset_vt`) to explore possibilities where
 *         the current element is included in the subset. It passes the updated `subset`
 *         and a new `index` (one position further) to explore further down the recursion tree.
 *       - After the recursive call, it backtracks by removing the element from `subset`
 *         using `pop_back`. This explores the possibility of excluding the current element
 *         from the subset.
 */
void calcSubset_vt(std::vector<std::string> &A, std::vector<std::vector<std::string>> &res,
                   std::vector<std::string> &subset, int index)
{
    // Add the current subset to the result list
    res.push_back(subset);

    // Generate subsets by recursively including and
    // excluding elements
    for (int i = index; i < A.size(); i++)
    {
        // Include the current element in the subset
        subset.push_back(A[i]);

        // Recursively generate subsets with the current
        // element included
        calcSubset_vt(A, res, subset, i + 1);

        // Exclude the current element from the subset
        // (backtracking)
        subset.pop_back();
    }
}
/**
 * @brief Generates all subsets of a given vector of strings.
 *
 * This function takes a vector of strings `A` by reference and returns a vector
 * of vectors of strings, where each inner vector represents a subset of the
 * original input. Subset refers to a collection of elements from the original
 * set that may or may not include all elements.
 *
 * The function utilizes a helper function `calcSubset_vt` for recursion.
 * 
 * @param A A vector of strings (passed by reference).
 * @return A vector of vectors of strings. Each inner vector represents a
 *         subset of the input vector.
 */
std::vector<std::vector<std::string>> subsets_vt(std::vector<std::string> &A)
{
    // Find the subet of vetor contain each word of name
    // Such as {"Nguyen", "Van", "anh"} will take the result
    //  {"Nguyen"}, {"Van"}, {"anh"}, {"Nguyen", "Van"},........
    std::vector<std::string> subset;
    std::vector<std::vector<std::string>> res;
    int index = 0;
    calcSubset_vt(A, res, subset, index);
    return res;
}
