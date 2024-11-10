#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstddef> 
// Class representing a dynamic string
class DSString
{
private:
    char *data; 
    size_t len; 

public:
    DSString(); 
    DSString(const char *); // Constructor from a C-string
    DSString(const DSString &); // Copy constructor
    DSString &operator=(const DSString &); // Copy assignment operator
    ~DSString(); // Destructor

    size_t length() const; // Returns the length of the string
    char &operator[](size_t); // Mutable access to character at index
    const char &operator[](size_t) const; // Consant access to character at index

    DSString operator+(const DSString &) const; 
    bool operator==(const DSString &) const; // Equality comparison
    bool operator<(const DSString &) const; 

    DSString substring(size_t start, size_t numChars) const; // Returns a substring
    DSString toLower() const; // Converts characters to lowercase

    const char *c_str() const; // Returns C-string representation

    friend std::ostream &operator<<(std::ostream &, const DSString &); // Output stream operator
};

// Specialization of std::hash for DSString
#include <functional>

namespace std {
    template<>
    struct hash<DSString> {
        std::size_t operator()(const DSString& s) const noexcept {
            std::size_t h = 0;
            const char* data = s.c_str();
            for (size_t i = 0; i < s.length(); ++i) {
                h = h * 31 + data[i];
            }
            return h;
        }
    };
}

#endif
