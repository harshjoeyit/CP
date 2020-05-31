_ #include<bits/stdc++.h>
using namespace std;


void add_pre_suff( string prefix , string &name , string suffix )
{
    name.insert( 0 , prefix);
    name = name.append(suffix);
}


int main()
{
    string name, prefix, suffix;
    cin>>prefix>>name>>suffix;
    add_pre_suff( prefix , name , suffix );

    // or simply  name = prefix + " " + name + " " + suffix;

    cout<<name;
}