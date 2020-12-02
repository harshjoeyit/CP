#include <stdio.h>
#define SWAP(a, b) \
      int t;       \
      t = a, a = b, b = t;
int main()
{
      int a = 10, b = 12;
      SWAP(a, b);
      printf("a = %d, b = %d\n", a, b);
      return 0;
}