

/*
References:
    T&          <-- lvalue reference                                                        - fun(a)    // int a
    T const &   <-- lvalue const reference  - Read-only                                     - fun(c)    // int const c{}
    T&&         <-- rvalue reference        - int && x{5}; but x can be changed later.      - fun(23)
    T const &&  <-- rvalue const reference  - Read-only

*/


#include <iostream>
using std::cout, std::endl;


int main()
{   

    int a = 1;
    int b = 1;
    {
        int b = 2;
        {
            int a = 3;
            cout << a << b << endl;
        }
        {
            int b = 4;
            cout << a << b << endl;
        }

    }
    cout << a << b << endl;

    int x{5};
    int const y{7};
    int const * v {&x};  // this is okay - non-const --> const (but not the other way around)
    int* const w {&x};

    //Example: int const * const x  <--  x is a constant pointer to a constant integer.

    x = 7;
    //y = 7; - not allowed.

    v = &y;
    //w = &y; - not allowed as w is a constant pointer to &x.

    //*v = 8; - not allowed as *v is constant.
    *w = 10;

    return 0;
}

// ------------------------------------------------------------------------------------- //

int r;  // static storage (global variable)

void funct()
{
    static Constructor other{1};    // static storage - can be accessed as soon as the function has been called once.
}

// ------------------------------------------------------------------------------------- //
// Special Member Functions:

class class2
{
    public:
        class2();                           // default constructor.
        class2(class2 const&);              // copy constructor.    - Usually exsists in the compiler but do you want to specify what to do?
        class2(class2&&);                   // move constructor.    - same

        ~class2();                          // destructor.

        class2& operator=(class2 const&);   // copy assignment.
        class2& operator=(class2&&);        // move assignment.

};


// ------------------------------------------------------------------------------------- //

class My_Class;     // forward declaration - mostly done in header files .h
void temp();        // same here.


class My_Class      // defaults to private.
{
    public:     // visible outside of this class.
        void foo();     // forward declaration of a class.
        void set(int num)
        {
            this->num = num;    // this helps the compiler to know which num is which in this case.
        }

    private:    // not visible outside of this class.
        void foo();     // works for private too.

        int num;
};

void My_Class::foo() {std::cout << "foo" << std::endl; }


struct My_Struct    // defaults to public.
{

};


// ------------------------------------------------------------------------------------- //

// Constructor c{5};
// val1 = 5, val2 = 5, val3 = 2.

class Constructor
{
    public:
        Constructor(int a) : val1{a}, val3{2}, data{new int{a}}
        {
            
        }
        ~Constructor()
        {
            delete data;
        }
    private:
        int* data;
        int val1;
        int val2{2+3};
        int val3{4};    // failsafe init.
};



// ------------------------------------------------------------------------------------- //


/*
    Constant member function:
*/

class Cls
{
    public:
        void fun() const;
        // void fun() &;        - Only introduce if needed too      - Cls c1{c}; -> c1.fun();
        // void fun() &&;       - Only introduce if needed too      - Cls{}.fun();
        // void fun() const&;   - Only introduce if needed too      - Cls const c2{}; -> c2.fun()
    private:
        int data;
};

void Cls::fun() const
{
    // not allowed
    // data = 5;
}

/*
    Mental Model:   - This is an explanation of what happens in the compiler when met with the constant member function above.
*/

struct Str
{
    int data;
};

void fun(/*Str const* this*/)
{
    // not allowed
    // this->data = 5;
}
// void fun(Str& this);         - Only introduce if needed too
// void fun(Str&& this);        - Only introduce if needed too
// void fun(Str const& this);   - Only introduce if needed too


// ------------------------------------------------------------------------------------- //