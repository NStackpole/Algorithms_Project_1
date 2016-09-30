#include "BinaryInteger.hpp"

int main()
{
    binary_integer Test1;
    Test1.print_bits();
    Test1.print_decimal();

    binary_integer Test2 = binary_integer(2600);
    Test2.print_bits();
    Test2.print_decimal();

    std::cout<<"\n";

    binary_integer Test3 = binary_integer(600);
    Test3.print_bits();
    Test3.print_decimal();

    std::cout<<"\n";

    //Test2 += Test3;

    Test2.print_bits();
    Test2.print_decimal();

    std::cout<<"\n";

    std::cout<<"Test2 is ";
    Test2.print_decimal();
    std::cout<<"Test3 is ";
    Test3.print_decimal();

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

    std::cout<<"\n";

    std::cout<<Test2;
    Test2.print_decimal();

    Test2<<1;
    std::cout<<"\n";

    std::cout<<Test2;
    Test2.print_decimal();

    Test2>>1;
    std::cout<<"\n";

    std::cout<<Test2;
    Test2.print_decimal();

    Test2.twice();
    std::cout<<"\n";

    std::cout<<Test2;
    Test2.print_decimal();

    Test2.half();
    std::cout<<"\n";

    std::cout<<Test2;
    Test2.print_decimal();

    //std::cin>>Test2;
   
    


    //std::cout<<"\n";

//    Test2 << 2;
   
    

  //  Test2.printBits();
    //Test2.printDecimal();

    

    return 0;
}