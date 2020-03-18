#include<iostream>
using namespace std;

struct maxindex
{
    int maxx,index;
};

maxindex retval(int c[100],int dis[100],int s)  // return type is structure
{
    maxindex mi;
    int maximum=-999,I,ct;
    for(int i=0; i<s; i++)
    {
        if(dis[i]>maximum)
        {
            maximum=dis[i];
            I=i;
            ct=c[i];
        }
        else
        if(dis[i]==maximum)
        {
            if(ct>c[i])
                I=i;
        }
    }
    mi.maxx=maximum;
    mi.index=I;

    return mi;  // returning a structure
}

void display(maxindex r,int c[100])
{
    cout<<r.maxx<<" "<<c[r.index]<<endl;
}

int main()
{
    int T,n,c,l,x,city1[100]={},city2[100]={},city3[100]={},dis1[100]={},dis2[100]={},dis3[100]={},s1,s2,s3;
    maxindex r1[100],r2[100],r3[100];
 //   cout<<"enter test cases: ";
    cin>>T;

  while(T!=0)
  {

    s1=0,s2=0,s3=0;
 //   cout<<"enter coupons -> n: ";
    cin>>n;

    while(n--)
    {
  //      cout<<"city,level,discount\n";
        cin>>c>>l>>x;

        if(l==1)
        {
            city1[s1]=c;
            dis1[s1]=x;
            ++s1;
        }
        else
        if(l==2)
        {
            city2[s2]=c;
            dis2[s2]=x;
            ++s2;
        }
        else
        if(l==3)
        {
            city3[s3]=c;
            dis3[s3]=x;
            ++s3;
        }

      } // end of while for each test case


        r1=retval(city1,dis1,s1);
        r2=retval(city2,dis2,s2);
        r3=retval(city3,dis3,s3);

        display(r1,city1);
        display(r2,city2);
        display(r3,city3);

        --T;
   }

  return 0;
}
