#include<iostream>
#include<cstring>
using namespace std;

int value(char one[10], char two[10])
{
    int i= strcmp(one,two);
    return i;
}

void check(int n)
{
    if(n<0)
        cout<<"second string is larger than the first: "<<endl;
    else if(n>0)
        cout<<"first string is larger than second: "<<endl;
    else
        cout<<"both are equal"<<endl;
}

int main()
{
  char a[]="harshit1111";
  size_t len=strlen(a);
  cout<<len<<endl;
  char b[]="harshit1110";

  int x= value(a,b);
  cout<<"value returned: "<<x<<endl;
  check(x);

  const char ca[] = {'h', 'e', 'l', 'l', 'o'};
  const char *cp = ca;
/* IMPORTANT : this char array does not have a null character ,so it prints garbage value until it finds a null char */
  while (*cp)      // terminate on null character only
    {
       cout << *cp <<",";
       cp++;
    }

    const char ba[] = {'h', 'e', 'l', 'l', 'o','\0'};   // however if we print this than only limited values are printed till null pointer

return 0;
}
