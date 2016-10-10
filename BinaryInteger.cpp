#include "BinaryInteger.hpp"

//Nathan Stackpole. Algorithms Project 1


//Default Constructor. Filles bits with 0's'
//Performs n digit operations
binary_integer::binary_integer()
{
    bits = std::vector<int>(2048, 0);
}

//Copy constructor
//Performs n digit operations.
binary_integer::binary_integer(binary_integer const& x)
{
    bits = x.bits;
}

//contructor that takes an unsigned int and fills bits with its binary representation
//Performs n + (n + log2(n) + 1) = 2n + log2(n) + 1 digit operations
binary_integer::binary_integer(unsigned x)
{
    bits = convert_to_binary(x);
}

//converts an unsigned int to binary, putting it in the right format to be inserted into bits.
//Performs n + log2(n) + 1 digit operations.
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

//Prints *all* of the ints in bits. Mostly for debuggin purposes
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

//Converts the binary number represented by bits to base 10.
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
//Performs n-1 bit operations
void binary_integer::twice()
{
    *this<<1;
}

//Halves this binary_integer using the right shift operator.
//Performs n-1 bit operations
void binary_integer::half()
{
    *this>>1;
}

//Overloading the equals assignment operator
//Assigns this.bits to R.bits, effectively making this binary_integer a copy of R.
//Performs n digit operations
binary_integer& binary_integer::operator = (binary_integer const& rhs)
{
    bits = rhs.bits;
    return *this;
}

//Overload of the += operator
//Adds this binary_integer to another binary_integer
//Performs a worst case of (6+1) * 2048 = (7 * 2048) or (7 * n) digit operations.
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
//Performs a worst cast of 6 digit operations.
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
//Performs rhs * 2047 or rhs * (n-1) digit operations.
//This function with run in O(rhs * 2047) or, simplified, O(n) where n=rhs.
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
//Performs rhs * 2047 or rhs * (n-1) digit operations.
//This function with run in O(rhs * 2047) or, simplified, O(n) where n=rhs.
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
//Performs a worst case 2048 * (3 + 1) or n*4 digit operations 
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
//Performs 3 digit operations
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
//performs the floor(log2(rhs)) recursions.
//Performs worst case about n*2 + n + n + 7n + 4n - 1 = 15n -1 digit operations.
binary_integer& binary_integer::operator *=(binary_integer const& rhs)
{
    if(*this == binary_integer(0) || rhs == binary_integer(1))
        return *this;

    //n digit operations for the assignment.
    binary_integer z = *this * (rhs/binary_integer(2));

    //This block performs 2n digit operations. n for the comparison and n for the assignment.
    if(rhs == binary_integer(0))
    {
        *this = binary_integer(0);
        return *this;
    }

    //This block performs 8n-1 digit operations. 6n for the modulus operation, n for the comparison, n-1 for the twice(), and n for the assignment.
    else if (rhs%binary_integer(2) ==binary_integer(0))
    {
        z.twice();
        *this = z;

        return *this;
    }

    //This block performs 4n-1 operations. n-1 for the twice(), n for the addition, n for the first assignment, and n for the last assignment.
    else
    {
        z.twice();
        binary_integer ans = *this + (z);
        *this = ans;
        return *this;
    }
}

//overloading of the division operator
//Performs (*this-rhs)/rhs recursions.
//Performs a worst case of n + n + n + n + n + n + n = 7n digit operations
binary_integer& binary_integer::operator /=(binary_integer const& rhs)
{
    assert(rhs != binary_integer(0));

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
//Performs *this/rhs recursions if *this > rhs. 
//Performs worst case n + n + 4n = 6n digit operations. n for the comparison, n for the assignment, and 4n for the subtraction. 
binary_integer& binary_integer::operator %= (binary_integer const& rhs)
{
    if(*this < rhs)
        return *this;
    *this = (*this-rhs);
    
    *this%=rhs;

    return *this;
}

//For analysis of runtime, see comments above the respective compound assignment overloads
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
//Performs n + ((bit_string.size() -1) * 1) + n = 2n + bit_string.size()-1 digit operations
std::istream& operator >> (std::istream& inputstream,  binary_integer& input)
{
    std::string bit_string;
    inputstream >> bit_string;

    if(bit_string.size() > 2048)
    {
        std::cout<<"You entered a string of more than 2048 digits, function returned without assigning any values.\n";
        return inputstream;
    }

    std::vector<int> temp_input(2048,0); 
    int input_index = bit_string.size()-1;
    for(int i = 0; i<bit_string.size(); ++i)
    {
        
        if(bit_string.at(i) == '0')
            temp_input[input_index] = 0;
        else if (bit_string.at(i) == '1')
            temp_input[input_index] = 1;
        else
        {
            std::cout<<"You entered a digit besides a 1 or a 0, function returned without assigning any values. \n";
            return inputstream;
        }

        input_index -=1;
        
    }
    input.bits = temp_input;
    return inputstream;
}

//Boolean Operators' overloads
//Pefroms n digit operations, one comparison for each bit in the vectors
bool operator == (binary_integer const& lhs, binary_integer const& rhs)
{
    return (lhs.bits == rhs.bits);
}

//Performs at worst case n digit operations if the vectors are of the same size and only the last elements are different in the vectors.
bool operator != (binary_integer const& lhs, binary_integer const& rhs)
{
    return !(lhs.bits == rhs.bits);
}

//Performs a worst case of 2n digit operations.
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

//This function should run in O(n) time where n is the 2048
//Performs a worst case of 2n digit operations.
bool operator >(binary_integer const& lhs, binary_integer const& rhs)
{
    for(int i = 2047; i>=0; --i)
    {
        if(rhs.bits[i] > lhs.bits[i])
            return false;
        if(lhs.bits[i] > rhs.bits[i])
            return true;
    }

    return false;
}

//Performs a worst case of about n + 2n digit operations. n for the first comparison of the two vectors, and then 2n for the worst case of the loop.
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

//Performs a worst case of about n + 2n digit operations. n for the first comparison of the two vectors, and then 2n for the worst case of the loop.
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

