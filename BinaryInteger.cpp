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
    if(value == 0)
        return ans;

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
    std::cout<<convert_to_decimal()<<"\n";
}

unsigned binary_integer::convert_to_decimal() const
{
    unsigned answer =0;
    for(int i = 0; i<bits.size(); ++i)
    {
        if(bits[i] == 1)
            answer+= bits[i] * pow(2,i);
    }

    return answer;
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
binary_integer& binary_integer::operator = (binary_integer const& rhs)
{
    bits = rhs.bits;
    return *this;
}

//Overload of the += operator
//Adds this binary_integer to another binary_integer
binary_integer& binary_integer::operator += (binary_integer const& rhs)
{

    int carry = 0;
    std::vector<int> sum(2,0);

    for(int i = 0; i<bits.size(); ++i)
    {
        sum = add_bits(bits[i], rhs.bits[i], carry);
        bits[i] = sum[0];
        carry = sum[1];
    }
    
    return *this;
}

//Helper function for the overload of the addition operators
//returns an array of two ints in this format {sum, carry}
//Asymptotic run time is O(1), constant time, since there are no loops, only addition, comparisons, and the allocation of an array with 2 ints. 
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
//This function with run in O(rhs * 2046) or, simplified, O(n) where n=rhs.
//The outer loop runs rhs times, and the inner loop always runs 2046 times (from 1 to 2047)
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
//This function with run in O(rhs * 2046) or, simplified, O(n) where n=rhs.
//The outer loop runs rhs times, and the inner loop always runs 2046 times (from 2046 to 0)
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
//Due to the for loop, 
binary_integer& binary_integer::operator -= (binary_integer const& rhs)
{
    assert(rhs<=*this);
    int borrow = 0;
    std::vector<int> bit_diff(2,0);

    for(int i = 0; i<bits.size(); ++i)
    {
        bit_diff = subtract_bits(bits[i], rhs.bits[i], borrow);
        bits[i] = bit_diff[0];
        borrow = bit_diff[1];
    }

    return *this;
}

//Helper function for binary_integer subtraction. Subtracts two bits while taking into consideration an borrow. Returns the difference and the borrow.
//Runs in O(1) constant time since there are all operations within the function are constant.
std::vector<int> binary_integer::subtract_bits(int top_bit, int bottom_bit, int borrow)
{
    std::vector<int> ans(2,0);
    bottom_bit += borrow;
    
    if(top_bit < bottom_bit)
    {
        ans[1] = 1;
        top_bit += 2;
    }

    ans[0] = top_bit - bottom_bit;
    
    return ans;
}


//overloading of the multiplication operator
binary_integer& binary_integer::operator *=(binary_integer const& rhs)
{
    if(*this == binary_integer(0) || rhs == binary_integer(1))
        return *this;

    binary_integer rhs_copy = binary_integer();
    rhs_copy.bits = rhs.bits;
    binary_integer z = *this * (rhs/binary_integer(2));
    if(rhs == binary_integer(0))
    {
        *this = binary_integer(0);
        return *this;
    }

    else if (rhs%binary_integer(2) ==binary_integer(0))
    {
        z.twice();
        *this = z;

        return *this;
    }

    else
    {
        z.twice();
        binary_integer ans = *this + (z);
        *this = ans;
        return *this;
    }
}

//overloading of the division operator
binary_integer& binary_integer::operator /=(binary_integer const& rhs)
{
    assert(rhs != binary_integer(0));

    binary_integer binary_one = binary_integer(1);

    if(*this == rhs)
    {
        *this = binary_integer(1);
        return *this;
    }

    if(*this == binary_integer(0))
        return *this;

    if(rhs > *this)
        *this = binary_integer(0);
        
    else
    {
        binary_integer rhs_copy = rhs;
        binary_integer temp = *this;
        *this = ((temp-rhs_copy)/rhs_copy) + binary_integer(1);
    }
    return *this;
}

//overloading of the modulus operator
binary_integer& binary_integer::operator %= (binary_integer const& rhs)
{
    if(*this < rhs)
        return *this;
    *this = (*this-rhs);
    
    *this%=rhs;

    return *this;
}


binary_integer operator %(binary_integer lhs, binary_integer rhs)
{
    return lhs %= rhs;
}

binary_integer operator /(binary_integer lhs, binary_integer rhs)
{
    return lhs /= rhs;
}

binary_integer operator +(binary_integer lhs, binary_integer rhs)
{
    return lhs += rhs;
}

binary_integer operator - (binary_integer lhs, binary_integer rhs)
{
    return lhs -= rhs;
}

binary_integer operator *(binary_integer lhs, binary_integer rhs)
{
    return lhs *= rhs;
}


//overloading of the istream operator
std::istream& operator >> (std::istream& inputstream,  binary_integer& input)
{
    

}

//Boolean Operators' overloads
bool operator == (binary_integer const& lhs, binary_integer const& rhs)
{
    return (lhs.bits == rhs.bits);
}

bool operator != (binary_integer const& lhs, binary_integer const& rhs)
{
    return !(lhs.bits == rhs.bits);
}

bool operator < (binary_integer const& lhs, binary_integer const& rhs)
{
    for(int i = 2047; i>=0; --i)
    {
        if( rhs.bits[i] > lhs.bits[i])
            return true;
        if(lhs.bits[i] > rhs.bits[i])
            return false;
    }

    return false;
    
}

//This  function should run in O(n) time where n is the 2048
bool operator >(binary_integer const& lhs, binary_integer const& rhs)
{
    for(int i = 2047; i>=0; --i)
    {
        if( rhs.bits[i] > lhs.bits[i])
            return false;
        if(lhs.bits[i] > rhs.bits[i])
            return true;
    }

    return false;
}

bool operator <= (binary_integer const& lhs, binary_integer const& rhs)
{
    if(lhs == rhs)
        return true;
        
    for(int i = 2047; i>=0; --i)
    {
        if(rhs.bits[i] > lhs.bits[i])
            return true;
        if(lhs.bits[i] > rhs.bits[i])
            return false;
    }

    return false;
}

bool operator >= (binary_integer const& lhs, binary_integer const& rhs)
{
    if(lhs == rhs)
        return true;
        
    for(int i = 2047; i>=0; --i)
    {
        if( rhs.bits[i] > lhs.bits[i])
            return false;
        if(lhs.bits[i] > rhs.bits[i])
            return true;
    }

    return true;
    
}

