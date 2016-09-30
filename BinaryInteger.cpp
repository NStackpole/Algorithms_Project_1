#include "BinaryInteger.hpp"

//Default Constructor. Filles bits with 0's'
binary_integer::binary_integer()
{
    bits = std::vector<int>(2048, 0);
}

//Copy constructor
binary_integer::binary_integer(binary_integer const& x)
{
    bits = x.bits;
}

//contructor that takes an unsigned int and fills bits with its binary representation
binary_integer::binary_integer(unsigned x)
{
    bits = convert_to_binary(x);
}

//converts an unsigned int to binary, putting it in the right format to be inserted into bits.
std::vector<int> binary_integer::convert_to_binary(unsigned value)
{
    std::vector<int> ans(2048, 0);
    int count = 0;

    while(value != 1)
    {
        ans[count] = (value%2);
        value /= 2;
        count++;
    }

    ans[count] = (1%2);
    return ans;
}

//Prints only the significant ints from bits (only the first 1 and all bits after it.)
//Runs in O(n) time since it is printing n (size of list) digits.
void binary_integer::print_bits()
{
    bool first_one_found = false;

    for(int i = bits.size() -1; i>=0; i--)
    {
        if(bits[i] == 1 && !first_one_found) first_one_found = true;

        if(first_one_found)
            std::cout<<bits[i];
    }

    if(!first_one_found)
        std::cout<<"0";

    std::cout<<"\n";
}

//Prints *all* of the ints in bits.
//Runs in O(n) time since it is printing n (size of list) digits.
void binary_integer::print_bits_with_zeroes()
{

    for(int i = bits.size() -1; i>=0; i--)
    {
        std::cout<<bits[i];
    }

    std::cout<<"\n";
}

//Prints the base 10 representation of this binary number represented by bits
void binary_integer::print_decimal()
{
    int answer =0;
    for(int i = 0; i<bits.size(); ++i)
    {
        if(bits[i] == 1)
            answer+= bits[i] * pow(2,i);
    }

    std::cout<<answer<<"\n";
}

//Doubles this binary_integer using the left shift operator
void binary_integer::twice()
{
    *this<<1;
}

//Halves this binary_integer using the right shift operator.
void binary_integer::half()
{
    *this>>1;
}

//Overloading the equals assignment operator
//Assigns this.bits to R.bits, effectively making this binary_integer a copy of R.
binary_integer& binary_integer::operator = (binary_integer const& R)
{
    bits = R.bits;
    return *this;
}

//Overload of the += operator
//Adds this binary_integer to another binary_integer
binary_integer& binary_integer::operator += (binary_integer const& R)
{

    int carry = 0;
    std::vector<int> sum(2,0);

    for(int i = 0; i<bits.size(); ++i)
    {
        sum = add_bits(bits[i], R.bits[i], carry);
        bits[i] = sum[0];
        carry = sum[1];
    }
    
    return *this;
}

//Helper function for the overload of the addition operators
//returns an array of two ints in this format {sum, carry}
std::vector<int> binary_integer::add_bits(int bit_a, int bit_b, int carry)
{

    std::vector<int> ans(2,0);

    if((bit_a + bit_b + carry) == 3)
        ans = {1,1};
    else if((bit_a + bit_b + carry) == 2)
        ans = {0,1};
    else if((bit_a + bit_b + carry) == 1)
        ans = {1,0};
    else if((bit_a + bit_b + carry) == 0)
        ans = {0,0};

    return ans;
}

//Overloading of the left shift operator
//Shifts all bits to the left rhs times. Effectively multipilies bits by 2^rhs
binary_integer& binary_integer::operator << (unsigned rhs)
{
    for(int j = 0; j<rhs;++j)
    {
        std::vector<int> temp (2048, 0);
        for(int i = 1; i<bits.size(); ++i)
        {
            temp[i] = bits[i-1];
        }
    bits = temp;
    }
}

//Overloading of the right shift operator
//Shifts all bits to the right rhs times. Effectively divides bits by 2^rhs
binary_integer& binary_integer::operator >> (unsigned rhs)
{
    for(int j = 0; j<rhs;++j)
    {
        std::vector<int> temp (2048, 0);
        for(int i = 2046; i>=0; --i)
        {
            temp[i] = bits[i+1];
        }

    bits = temp;
    }
}

//Overloading of the subtraction operator
binary_integer& binary_integer::operator -= (binary_integer const& R)
{

    return *this;
}

//overloading of the multiplication operator
binary_integer& binary_integer::operator *=(binary_integer const& R)
{
    for(int i = 0; i<bits.size(); ++i)
    {
        if(R.bits[i]%2 == 0)
        {
            
        }

    
    }

    return *this;
}

//overloading of the division operator
binary_integer& binary_integer::operator /=(binary_integer const& R)
{

    return *this;
}

//overloading of the modulus operator
binary_integer& binary_integer::operator %= (binary_integer const& R)
{
    return *this;
}


binary_integer operator %(binary_integer a, binary_integer b)
{
    return a %= b;
}

binary_integer operator /(binary_integer a, binary_integer b)
{
    return a /= b;
}

binary_integer operator +(binary_integer a, binary_integer b)
{
    return a += b;
}

binary_integer operator - (binary_integer a, binary_integer b)
{
    return a -= b;
}

binary_integer operator *(binary_integer a, binary_integer b)
{
    return a *= b;
}


//overloading of the istream operator
std::istream& operator >> (std::istream& inputstream,  binary_integer& input)
{
    

}

//Boolean Operators' overloads
bool operator == (binary_integer const& a, binary_integer const& b)
{
    return (a.bits == b.bits);
}

bool operator != (binary_integer const& a, binary_integer const& b)
{
    return !(a.bits == b.bits);
}

bool operator < (binary_integer const& a, binary_integer const& b)
{
    return !(a>=b);
}

//This  function should run in O(n) time where n is the 2048
bool operator >(binary_integer const& a, binary_integer const& b)
{
    for(int i = 2047; i>=0; --i)
    {
        if(a.bits[i] > b.bits[i])
        return true;
    }

    return false;
}

bool operator <= (binary_integer const& a, binary_integer const& b)
{
    if(a==b)
        return true;
    return !(a>=b);
}

bool operator >= (binary_integer const& a, binary_integer const& b)
{

    if(a == b)
        return true;
        
    for(int i = 2047; i>=0; --i)
    {
        if(a.bits[i] > b.bits[i])
        return true;
    }

    return false;
}

