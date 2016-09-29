# Algorithms: Project #1
## Nathan Stackpole

This project contains 3 files: BinaryInteger.cpp, BinaryInteger.hpp, and main.cpp

BinaryInteger.hpp is the header for BinaryInteger.cpp and contains the declarations
for the following member functions and variables:

* std::vector<int> _bits_ - a private vector of ints that holds 2048 binary digits
* binary_integer() - default constructor, fills _bits_ with 2048 0's
* binary_integer(binary_integer const&) - copy constructor. constructs a new binary_digit and copies the bits from the given binary_integer into the new one's _bits_.
* binary_integer(unsigned) - constructor that takes an unsigned int and fills _bits_ with its binary representation
* void twice() and void half() - run *this<<1 and *this>>1 respectively.
* std::vector<int> convert_to_bits(unsigned) - returns a vector containing the binary representation in the format necessary for _bits_.
* void printBits() - prints all significant bits from _bits_ (no leading zeroes)
* void printBitsWithZeroes() - prints all bits from _bits_ (including leading zeroes)
* void printDecimal() - prints the decimal representation of the binary number contained in _bits_
* std::vector<int> addBits(int, int, int) - Used for adding two binary_integer objects, adds individual bits with a carry.
* Overlaods of the =, +=, -=, *=, /=. *, -, +, /, <<, >>, <, >, >=, <=, ==, !=, ostream <<, istream >> operators.

BinaryInteger.cpp implements the functions defined in its header.

main.cpp contains tests for the binary_integer class.