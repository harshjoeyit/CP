
#include <stdlib.h>
#include <stdio.h>


enum {
      false,
      true
};
int main() {
      int i = 1;
      do {
            printf("%d\n", i++);
            if (i < 15)
                  continue;
      } while (false);

      getchar();
      return 0;
}
// Output : 1 
// Explanation : The do wile loop checks condition after each 
// iteration.So after continue statement, control transfers to the statement 
// while (false).Since the condition is false ‘i’ is printed only once.

int main()
{
      int i = 1;
      do
      {
            printf("%d\n", i);
            i++;
            if (i < 15)
                  break;
      } while (true);

      getchar();
      return 0;
}

// Gives same output




char *getString()
{
      char *str = "Nice test for strings";
      return str;
}

int main()
{
      printf("%s", getString());
      getchar();
      return 0;
}
// Output: “Nice test for strings”
// The above program works because string constants are stored in 
// Data Section(not in Stack Section).So, when getString returns *
// str is not lost.




#include <stdio.h>
char *getString()
{
      char str[] = "Will I be printed?";
      return str;
}
int main()
{
      printf("%s", getString());
      getchar();
}

// Output: Some garbage value
// The above program doesn’t work because array variables are stored 
// in Stack Section.So, when getString returns values at str are 
// deleted and str becomes dangling pointer.




#include <stdio.h>
int main()
{
      static int i = 5;
      if (--i)
      {
            main();
            printf("%d ", i);
      }
}
// Output: 0 0 0 0





#include <stdio.h>
int main()
{
      int x;
      printf("%d", scanf("%d", &x));
      /* Suppose that input value given  
        for above scanf is 20 */
      return 1;
}
// Output : 1 scanf returns the no.of inputs it has successfully read.





int main()
{
      int i = 0;
      for (i = 0; i < 20; i++)
      {
            switch (i)
            {
            case 0:
                  i += 5;
            case 1:
                  i += 2;
            case 5:
                  i += 5;
            default:
                  i += 4;
                  break;
            }
            printf("%d  ", i);
      }

      getchar();
      return 0;
}
// Output : 16 21 Explanation : Initially i = 0. Since case 0 is true i 
// becomes 5, and since there is no break statement till last statement 
// of switch block, i becomes 16. Before starting the next iteration, i 
// becomes 17 due to i++.Now in next iteration no case is true, so 
// execution goes to default and i becomes 21.




int main() 
{ 
  printf("%p", main); 
  getchar(); 
  return 0; 
} 
// Output: Address of function main.