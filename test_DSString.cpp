#include <iostream>
#include <vector>
#include <algorithm>
#include "DSString.h"

int main()
{
    
    DSString myString = "Hello, World!";
    std::cout << myString << "\n";

    // Assign a new value to myString 
    myString = "Good bye!";
    std::cout << myString << "\n";

    // Print a substring of myString
    std::cout << "substr: " << myString.substring(5, 3) << "\n";

    // assignment and equality check
    DSString a = "test";
    DSString b;
    b = a;

    // Print whether the two strings are equal
    std::cout << std::boolalpha;
    std::cout << (a == b) << "\n";

    // Modify b and check equality again
    b[0] = 'T';
    std::cout << "a is now: " << a << "\n";
    std::cout << (a == b) << "\n";

    // Create and print a vector of DSString objects
    std::vector<DSString> strings = {
        DSString("bb"),
        DSString("aaa"),
        DSString("ddd"),
        DSString("ee"),
        DSString("ccc")};

    for (const auto &s : strings)
        std::cout << s << "\n";

    // Search for specific strings in the vector
    std::cout << "found ddd: " << (std::find(strings.begin(), strings.end(), DSString("ddd")) != strings.end()) << "\n";
    std::cout << "found z: " << (std::find(strings.begin(), strings.end(), DSString("z")) != strings.end()) << "\n";

    // Sort the vector and print the sorted result
    std::sort(strings.begin(), strings.end());

    for (const auto &s : strings)
        std::cout << s << "\n";

    // Use binary search to check for specific strings in the sorted vector
    std::cout << "found ddd: " << std::binary_search(strings.begin(), strings.end(), DSString("ddd")) << "\n";
    std::cout << "found z: " << std::binary_search(strings.begin(), strings.end(), DSString("z")) << "\n";

    return 0;
}
