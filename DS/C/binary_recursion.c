#include <stdio.h> 
  
// Decimal to binary conversion 
// using recursion 
int find(int decimal_number) 
{ 
    if (decimal_number == 0)  
        return 0;  
    else
        return (decimal_number % 8 + 10 *  
                find(decimal_number / 8)); 
} 
  
// Driver code  
int main() 
{ 
    int decimal_number = 1234; 
    printf("%d", find(decimal_number)); 
    return 0; 
}