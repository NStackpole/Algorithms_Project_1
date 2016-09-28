#include "BinaryInteger.hpp"

int main()
{
    binary_integer Test1;
    Test1.printBits();
    Test1.printDecimal();

    binary_integer Test2 = binary_integer(2600);
    Test2.printBits();
    Test2.printDecimal();

    std::cout<<"\n";

    binary_integer Test3 = binary_integer(600);
    Test3.printBits();
    Test3.printDecimal();

    std::cout<<"\n";

    //Test2 += Test3;

    Test2.printBits();
    Test2.printDecimal();

    std::cout<<"\n";

    std::cout<<"Test2 is ";
    Test2.printDecimal();
    std::cout<<"Test3 is ";
    Test3.printDecimal();

    if(Test2 == Test3)
        std::cout<<"Test2 is Equal To Test3\n";

    if(Test2 != Test3)
        std::cout<<"Test2 is not Equal To Test3\n";

    if(Test2 <= Test3)
        std::cout<<"Test2 is Less Than Or Equal To Test3\n";
    else
        std::cout<<"Test2 is Not Less Than Or Equal To Test3\n";

    if(Test2 < Test3)
        std::cout<<"Test2 is Less Than Test3\n";
    else
        std::cout<<"Test2 is Not Less Than Test3\n";

    if(Test2 >= Test3)
        std::cout<<"Test2 is Greater Than or equal to Test3\n";
    else
        std::cout<<"Test2 is Not Greater Than or equal to Test3\n";

    if(Test2 > Test3)
        std::cout<<"Test2 is Greater Than Test3\n";
    else
        std::cout<<"Test2 is Not Greater Than Test3\n";

    

    return 0;
}