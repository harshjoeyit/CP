
// structure

struct emp
{
    int pay=190;
    char grade='a';
};

// class

class student
{
public:
    int x;
    int y;
};

void printname()
{
    cout<<"harshit gangwar"<<endl;
}

int calc(int a,int b)
{
    return a+b;
}

// bubble sort
// dont forget to give prototype of the function in the program to be used
void bubblesort(int (&a)[100],int sz)
{
    for(int i=0; i<sz-1; i++)
    {
        int t;
        // swap ==0;
        for(int j=0; j<sz-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                // swap =1;
            }
        }
        for(int i=0; i<sz; i++) // breaking loop if already sorted no more passes required
        {
            if(a[i]>a[i+1])
                break;
        }
          // if(swap==0) // this means array is sorted and no value has swapped in the last pass
            // break;
    }
}
