#include <iostream>
int main()
{
    int sum = 0, value = 0;
std::cout<<"enter the number \n ";
   // read until end-of-file, calculating a running total of all values read
 while (std::cin >> value)
{
sum += value;
// equivalent to sum = sum + value
std::cout << " Sum of numbers upto now is: " << sum << std::endl;
std::cout<<" \n enter the next no.  \n";
}
return 0; }
