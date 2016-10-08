#include <climits>
#include <iostream>
#include <cassert>
#include <vector>
#include <fstream>
#include <cmath>

#ifndef BINARYINTEGER
#define BINARYINTEGER

class binary_integer{
    public:

    //Array member, holds the bits.
    std::vector<int> bits; 

    std::vector<int> convert_to_binary(unsigned);

    //Default constructor, fills the array with zeroes.
    binary_integer();

    //Copy constructor.
    binary_integer(binary_integer const&);

    //Contructor that takes an unsigned int and initializes the number to the binary representation of that number.
    binary_integer(unsigned);

    //Overloading arithmetic operators

    binary_integer& operator = (binary_integer const&);

    binary_integer& operator += (binary_integer const&);

    binary_integer& operator -= (binary_integer const&);

    binary_integer& operator *= (binary_integer const&);

    binary_integer& operator /= (binary_integer const&);

    binary_integer& operator %= (binary_integer const&);

    std::vector<int> subtract_bits(int, int, int);

    void print_bits();

    void print_bits_with_zeroes();

    void print_decimal();

    std::vector<int> add_bits(int, int, int);

    unsigned convert_to_decimal() const;

    void twice();
    void half();

    binary_integer& operator << (unsigned);
    binary_integer& operator >> (unsigned);
};

    //More arithmetic operator overloads
    binary_integer operator + (binary_integer, binary_integer);

    binary_integer operator % (binary_integer, binary_integer);

    binary_integer operator - (binary_integer, binary_integer);

    binary_integer operator * (binary_integer, binary_integer);

    binary_integer operator / (binary_integer, binary_integer);

    //Output and input operator overloads
    inline std::ostream& operator << (std::ostream& outstream, binary_integer& output)
    {
        output.print_bits();
    }

    std::istream& operator >> (std::istream& ,  binary_integer&);


    //boolean operator overloads           
    bool operator >= (binary_integer const& , binary_integer const&);
    bool operator < (binary_integer const& , binary_integer const&);
    bool operator > (binary_integer const& , binary_integer const&);
    bool operator <= (binary_integer const& , binary_integer const&);
    bool operator == (binary_integer const& , binary_integer const&);
    bool operator != (binary_integer const& , binary_integer const&); 

#endif