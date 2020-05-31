#include<bits/stdc++.h> 
using namespace std;


class Screen 
{

    friend class Window_mgr;        // giving Window_mgr access to screen's private members
    public: 
        typedef string::size_type pos;
        Screen() = default;     // neede because screen has another constructor 
        Screen( pos ht , pos wd , char c ) : height(ht) , width(wd) , contents( ht*wd , c ) { }

        char get() const                            // imlicitley inline
        {                                           // get char at the cursor 
            return contents[cursor];
        }
        inline char get( pos ht , pos wd ) const;   // explicitley inline
        Screen &move( pos r , pos c );             // can be made inline later
        void some_member() const;
        // functions for setting characters ar cursor , or ata location 
        Screen &set( char );
        Screen &set( pos , pos , char );
        // display functions
        Screen &display( ostream &os )                  // the implicit this pointer is not const pointer  
        {
            do_display(os);
            return *this;
        }
        const Screen &display( ostream &os ) const      // the implicit this pointer is const pointer , so return type const reference 
        {
            do_display(os);
            return *this;       
        }
        pos size() const;

    private:
        pos cursor = 0;                 // in class initializer 
        pos height = 0;
        pos width = 0;
        string contents;
        mutable size_t access_ctr;                  // may be it should be initialized to be zero 
        void do_display( ostream &os ) const        // const makes the implicit this pointer passed constant , so this function cannot modify the onject as this is const pointer to the object 
        {
            os<<contents.size()<<"-"<<contents<<endl;
        }
};



//inline function outside the function's body . make it easier to read the class
inline Screen & Screen :: move( pos r , pos c ) 	// cannot be a const member function , changes the value of the cursor
{
    pos row = r * width;        // compute the row location 
    cursor = row + c;           // move the cursor to the column within that row
    return *this;               // return this object as lvalue 
}

char Screen :: get( pos r , pos c ) const   // declared as inline 
{// returns the char specified by row and column 
    pos row = r * width;        // compute row location 
    return contents[row + c];   // return character at the given column 
}

void Screen :: some_member() const          // const member function
{
    ++access_ctr;   // change is allowed in class member , because it is mutanle data member 
    // keeps the count on the calls of some_member 
}

inline Screen &Screen:: set( char c )
{
    contents[cursor] = c;               // new value st the current cursor location 
    return *this;                       // return object
}

inline Screen &Screen::set( pos r , pos col , char ch )
{
    contents[ r * width + col ] = ch;           // set the value at specific location 
    return *this;
}

Screen::pos Screen::size() const
{
    return height*width;
}





// window manager class , collection of all the screens on a display 
class Window_mgr
{
    public: 
    // location ID for each screen on the window 
    using ScreenIndex = vector<Screen>:: size_type;
    // reset the screen at the given position to all blanks 
    void clear( ScreenIndex );
    ScreenIndex addScreen( const Screen& );     // holds the reference to an object of type screen

    private:
        // by default one standard sized blank screen( char argument -> '') 
        vector<Screen> screens{ Screen(24,80,' ') };        // initializing the data member , 
        // this is also considered in class initialization , could be using = , or brackets ( ) 

};


void Window_mgr::clear( ScreenIndex i )         //:: defines that we are now in the scope of the mentioned class 
{
    //s is a reference to the screen we want to clear 
    Screen &s = screens[i];
    //reset the contents of that to all blanks 
    // contents is a member of class Screen , here callled by reference object s 
    s.contents = string( s.height * s.width ,' ');      // string constructior
}

// return type is typename defined in the Window_mgr class 
Window_mgr::ScreenIndex Window_mgr::addScreen( const Screen &s )
{
    screens.push_back(s);
    return screens.size() - 1;      // index 
}



// literal class - just used as a user defined data type 
class demo {       
public: 
    int ival;
    string s;
    float f;
    char ch;
};






int main()
{
    //const Screen myscreen;
    //auto x = myscreen.set('#');     -> cannot call set on a const screen object

    Screen myscreen1(5,3,'$');
    const Screen blank(7,9,' ');
    myscreen1.display( cout );         // calls the non const version
    blank.display( cout );                      // calls the const version

    Screen myscreen2(5,3,'X');      // screen with 3 width, 5 height
    myscreen2.move(4,0).set('#').display(cout); //value of cursor-3*4 + 0 , set value at this index - #
    myscreen2.display(cout);
    /*  works like a 2D matrix
        matrix of 3*5 - h = 5 , w = 3
        move to block with 4th row , 0th column
        change value at this block
    */
   
    Screen::pos ht = 24, wd = 80;           //typenames are accessed by 
    Screen scr( ht , wd , '*');
    Screen *p = &scr;
    char c = scr.get();
    cout<<"c: "<<c<<endl;
    auto x = p->set('%');           //x is the reference class object 
    c = x.get();                
    cout<<"c: "<<c<<endl;           // any changes made in x are reflected in scr
    c = scr.get();
    cout<<"c: "<<c<<endl;
    Screen::pos sz = scr.size();
    cout<<"size: "<<sz<<endl;


    demo obj;
    obj = { 0 ,"anna" };
    // no implicit type-casting takes place here
    // obj = {0, 'a'} - gives error char - to - string conversion
    cout<<obj.ival<<obj.s<<obj.ch<<obj.f<<endl;
}