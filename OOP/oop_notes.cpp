/*
Public mode: If we derive a sub class from a public base class. 
Then the public member of the base class will become public in the derived class and
protected members of the base class will become protected in derived class.

Protected mode: If we derive a sub class from a Protected base class. 
Then both public member and protected members of the base class will become protected in derived class.

Private mode: If we derive a sub class from a Private base class. 
Then both public member and protected members of the base class will become Private in derived class.




Types of inheritence 

Single Inheritance.
Multiple Inheritance.
Hierarchical Inheritance.
Multilevel Inheritance.
Hybrid Inheritance (also known as Virtual Inheritance)


<< is insertion operator 
>> is extraction operator 



classe            vs                      struct
defalut private                           default public
while inheriting 
defalut specifier private                 here it is public 





>> Use of Protected constructor    
      - we don't want people creating Animal objects directly,
       -but we still want derived classes to be able to use it.

      - but the probkem is 
            -The constructor is still accessible from within derived classes, making it possible to instantiate an Animal object.
      

>> Need of runtime polymorphism using virtual functions (consider Animal class example)

      - Writing seperate function for printing sound and name, Not too difficult, but consider what would happen 
      if we had 30 different animal types instead of 2. You’d have to write 30 almost identical functions! 
      Plus, if you ever added a new type of animal, you’d have to write a new function for that one too. 
      This is a huge waste of time considering the only real difference is the type of the parameter.


      - Second, let’s say you had 3 cats and 3 dogs that you wanted to keep in an array for easy access. 
      Because arrays can only hold objects of one type, without a pointer or reference to a base class, 
      you’d have to create a different array for each derived type, like this:
      Now, consider what would happen if you had 30 different types of animals. You’d need 30 arrays, one for each type of animal!



>>  Use of the virtual keyword

      - If a function is marked as virtual, all matching overrides are also considered virtual, even if 
      they are not explicitly marked as such. However, having the keyword virtual on the derived functions 
      does not hurt, and it serves as a useful reminder that the function is a virtual function rather than 
      a normal one. Consequently, it’s generally a good idea to use the virtual keyword for virtualized 
      functions in derived classes even though it’s not strictly necessary.




>> You should not call virtual functions from constructors or destructors. Why?

      Remember that when a Derived class is created, the Base portion is constructed first. 
      If you were to call a virtual function from the Base constructor, and Derived portion 
      of the class hadn’t even been created yet, it would be unable to call the Derived 
      version of the function because there’s no Derived object for the Derived function 
      to work on. In C++, it will call the Base version instead.


      - A similar issue exists for destructors. If you call a virtual function in a Base class 
      destructor, it will always resolve to the Base class version of the function, because the 
      Derived portion of the class will already have been destroyed.


>> The downside of virtual functions

      Since most of the time you’ll want your functions to be virtual, why not just make 
      all functions virtual? The answer is because it’s inefficient -- resolving a virtual 
      function call takes longer than resolving a regular one. Furthermore, the compiler 
      also has to allocate an extra pointer for each class object that has one or more 
      virtual functions. 



>> Override specifier 
      - example 
            - virtual const char* getName1(short int x) override { return "B"; } 

      - There is no performance penalty for using the override specifier, and it helps avoid 
      inadvertent errors. Consequently, we highly recommend using it for every virtual function 
      override you write to ensure you’ve actually overridden the function you think you have.

      - Rule: Apply the override specifier to every intended override function you write.


>>  final sepecifier
      - example 
            - virtual const char* getName() override final { return "B"; }

      - no child class can override this function


>> Covariant return type 

      - If the return type of a virtual function is a pointer or a reference to a class, 
      override functions can return a pointer or a reference to a derived class. These are 
      called covariant return types. Here is an example:


>> virtual table 

      - The virtual table is actually quite simple, though it’s a little complex to describe 
      in words. First, every class that uses virtual functions (or is derived from a class 
      that uses virtual functions) is given its own virtual table. This table is simply a 
      static array that the compiler sets up at compile time. A virtual table contains one 
      entry for each virtual function that can be called by objects of the class. Each entry 
      in this table is simply a function pointer that points to the most-derived function 
      accessible by that class.

      
>> vtpr
      
      - When a class object is created, *__vptr is set to point to the virtual table for that 
      class. For example, when an object of type Base is created, *__vptr is set to point to 
      the virtual table for Base. When objects of type D1 or D2 are constructed, *__vptr is set 
      to point to the virtual table for D1 or D2 respectively.

      
// more - learncpp.com/cpp-tutorial/125-the-virtual-table/


>> Interface Class 
      - An interface class is a class that has no member variables, and where all of 
      the functions are pure virtual! In other words, the class is purely a definition, 
      and has no actual implementation. Interfaces are useful when you want to define 
      the functionality that derived classes must implement, but leave the details of 
      how the derived class implements that functionality entirely up to the derived class.


>> virtual inheritence 
      - solves diamond problem 


>> Object Slicing 
      -  When we assign a Derived object to a Base object, only the Base portion of the 
      Derived object is copied. The Derived portion is not. In the example above, base 
      receives a copy of the Base portion of derived, but not the Derived portion. That 
      Derived portion has effectively been “sliced off”. Consequently, the assigning of 
      a Derived class object to a Base class object is called object slicing (or slicing 
      for short).


>> Why class object must be passed by reference 
      - slicing here can all be easily avoided by making the function parameter a reference 
      instead of a pass by value (yet another reason why passing classes by reference instead 
      of value is a good idea).

*/