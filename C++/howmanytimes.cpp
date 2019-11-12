#include<iostream>

int main()
{
    int curval=0,val=0,count=1;

    if(std::cin>>curval)
    {
        while(std::cin>>val)
        {
            if(val==curval)
                ++count;
                else{
                    std::cout<<curval<<"occurs"<<count<<"times"<<std::endl;
                    curval=val;
                    count=1;
                }
        }
        std::cout<<curval<<"occurs"<<count<<"times"<<std::endl;
        //for printing about the last value entered
    }

}
