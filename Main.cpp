/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Spring 2019
 *
 * @file      Main.cpp
 * @authors   Jim Daehn <jdaehn@missouristate.edu>
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Palindrominator.h"
#include <memory>

const bool PREPEND_FLAG{false};

int main(int argc, char* argv[]) {
    std::cout << "Until the code is properly implemented, the output of this program will not make sense!\n"
              << std::endl;

    // Create a smart pointer to a default Palindrominator...
    auto palindrominator = std::make_unique<Palindrominator>();
    std::cout << "Is \"bbbb\" a palindrome? " << (palindrominator->isPalindrome("bbbb") ? "Yes" : "No") << std::endl;
    std::cout << "(It should say \"Yes\")\n";

    std::cout << "\nMake a palindrome out of \"abc\": " << palindrominator->makePalindrome("abc") << std::endl;
    std::cout << "(It should have generated \"abccba\")\n" << std::endl;

    std::cout << "Is palindrominator->makePalindrome(\"abc123\") a palindrome? "
              << (palindrominator->isPalindrome(palindrominator->makePalindrome("abc123")) ? "Yes" : "No")
              << std::endl;
    std::cout << "(It should say \"Yes\")\n";

    // Create a Palindrominator that overrides the default appending behavior
    Palindrominator prepender{PREPEND_FLAG};
    std::cout << "\nMake a palindrome out of \"abc\": " << prepender.makePalindrome("abc") << std::endl;
    std::cout << "(It should have generated \"cbaabc\")" << std::endl;
    return EXIT_SUCCESS;
}
