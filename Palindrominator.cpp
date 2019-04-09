/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Spring 2019
 *
 * @file    Palindrominator.cpp
 * @authors Jim Daehn <jdaehn@missouristate.edu>
 *          Shannon Campbell <sfc489@live.missouristate.edu>
 */

#include <stack>   // Provides access to std::stack<T> where T is the template parameter, e.g., char
#include <sstream> // Provides access to std::stringstream which may be useful in the reverse helper operation
#include "Palindrominator.h"

Palindrominator::Palindrominator(bool append) : append_{append} {
    /* no-op */
}

bool Palindrominator::isPalindrome(const std::string &text) const {
    std::queue<char> aQueue;
    std::stack<char> aStack;

    int length = text.length();
    for (int i = 0; i < length; i++) {
        char nextChar = text[i];
        aQueue.push(nextChar);
        aStack.push(nextChar);
    }

    bool charactersAreEqual = true;
    while (aQueue.size() != 0 && charactersAreEqual) {
        char queueFront = aQueue.front();
        char stackTop = aStack.top();

        if (queueFront == stackTop) {
            aQueue.pop();
            aStack.pop();
        }
        else {
            charactersAreEqual = false;
        }
    }
    return charactersAreEqual;
}

std::string Palindrominator::makePalindrome(const std::string &text) const {

    std::string reverse;
    std::stack<char> reverseStack;

    for (int i = 0; i < text.length(); i++) {
        reverseStack.push(text[i]);
    }

    for (int i = 0; i < text.length(); i++) {
        reverse += reverseStack.top();
        reverseStack.pop();
    }

    std::string palindrome;

    if (append_ == true) {
        palindrome = text + reverse;
    }
    else {
        palindrome = reverse + text;
    }
    return palindrome;
}
