#include "BinaryInteger.hpp"

int main()
{
    binary_integer Test1;
    Test1.print_bits();
    Test1.print_decimal();

    binary_integer Test2 = binary_integer(100000);
    Test2.print_bits();
    Test2.print_decimal();

    std::cout<<"\n";

    binary_integer Test3 = binary_integer(7500);
    Test3.print_bits();
    Test3.print_decimal();

    std::cout<<"Addition testing\n";

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

    std::cout<<"Bit shift testing\n";

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

    std::cout<<"Test 2:"<<Test2;
    Test2.print_decimal();

     

    std::cout<<"\n";

    std::cout<<"Subtraction testing\n";
    std::cout<<"Test 2:"<<Test2;
    Test2.print_decimal();
    std::cout<<"Test 3:"<<Test3;
    Test3.print_decimal();


    Test2 -= Test3;

    std::cout<<"Test 2:"<<Test2;
    Test2.print_decimal();

    std::cout<<"Modulus Test\n";
    binary_integer ModulusTest1 = binary_integer(0);
    std::cout<<"ModulusTest1:"<<ModulusTest1;

    binary_integer ModulusTest2 = binary_integer(2);
    std::cout<<"ModulusTest2:"<<ModulusTest2;
    
    ModulusTest1 %= ModulusTest2;
    std::cout<<"ModulusTest1 % ModulusTest2 = "<<ModulusTest1;

    std::cout<<"Division testing\n";

    binary_integer DivisionTest1 = binary_integer(2);
    std::cout<<"DivisionTest1:"<<DivisionTest1;
    DivisionTest1.print_decimal();

    binary_integer DivisionTest2 = binary_integer(2);
    std::cout<<"DivisionTest2:"<<DivisionTest2;
    DivisionTest2.print_decimal();

    DivisionTest1 /= DivisionTest2;
    std::cout<<"DivisionTest1 / DivisionTest2 = "<<DivisionTest1;
    DivisionTest1.print_decimal();
    
  


    std::cout<<"Multiplication by factor of two test\n";

    binary_integer MultiplyTest1= binary_integer(120);
    std::cout<<"MultiplyTest1:"<<MultiplyTest1;
    MultiplyTest1.print_decimal();
    
    binary_integer MultiplyTest2 = binary_integer(80); 
    std::cout<<"MultiplyTest2:"<<MultiplyTest2;
    MultiplyTest2.print_decimal();

    MultiplyTest1 *= MultiplyTest2;
    std::cout<<"MultiplyTest1 * MultiplyTest2 = "<<MultiplyTest1;
    MultiplyTest1.print_decimal();
    
    std::cout<<"Input Testing:\n";
    
    std::cout<<"Input a binary number with less than 2048 bits:";
    std::cin>>Test2;
   
    std::cout<<Test2;
    Test2.print_decimal();


    //std::cout<<"\n";

//    Test2 << 2;
   
    

  //  Test2.printBits();
    //Test2.printDecimal();

    

    return 0;
}