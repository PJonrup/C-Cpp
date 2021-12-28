/*
Data types: 
    Fundamental      --> (int, float, double, std::nullptr_t, ...), 
    Array            --> (int x[5], c-string = "hello"), 
    Class            --> (struct, class, union, std::string), 
    Enum.

Value category:
    5, "hello", 3.5f <-- rvalues, literals (can not appear on the left hand side)
    fun(int && x)    <-- xvalues, rvalues references (the function takes an rvalue but the values can be changed inside the function - also called expiring values)
    int x            <-- lvalues (can be reffered to later)

Initialization:
    int x = 5;       <-- Copy init   (Copy value --> fail)  (ACTUALLY: --> Convert value and then copy --> try to call a non-explicit constructor --> fail)
    int x(5);        <-- Direct init (Use constructor --> Aggregate init* --> Copy init)        -- Only use if you know that you want a constructor to be cont.
    int x{};         <-- Value init  (default-init)
    int x{5};        <-- List init   (Aggregate init* --> Use constructor --> Copy init)        -- Use this as often as possible - Example. Error will occur if you do int x{2.5} as it's a float!

    * Aggregate init - (can be done if the values (class,struct) have public members)

Conversions:
    array-to-pointer:
        Example:  
            int x[5];      -->  [-> 1, 2, 3, 4, 5],  
            x + 1 = *x[1]  -->  [1, -> 2, 3, 4, 5]

    function to pointer:
        - you are either a genius or stupid.
        - function --> function pointer --> bool (true or false, mostly true).
        - the flag -Werror will warn about this conversion"

    Promotion conversions:
        
        long long > long > int* > short > char > bool       *default

        Example:
            'a' + 5 = int('a') + 5 = 97 + 5 = 102
            5l + 3 = 5l + 3l = 8l
        
        long double > double* > float       *default

        Example: 
            int x = 3.5f = 3.5 (double) = 3 (int)

        Further:
            Int can me made double and vice versa.

    Inverse conversions:
        static_cast

*/

#include <iostream>
using std::cout;

int main()
{

    Person p;
    p.get_age();    // or p.age, if age is public;

    return 0;
}

struct Person   // struct is at default public - (usually used for very simple classes).
{
    std::string name;   // class type;
    int age;            // fundamental type;
    int get_age() { return age; }   // function
};

union JSON   // Uses the same memory space - (If we set val = 2 and then str = "hello", we can only get str and val has been forgotten.)    - mostly used to save memory space.
{
    double val;
    char const* str;
    double get_value() { return val; }
};

enum Status   // unscoped - can be reached bby writing GRANTED (if (s == GRANTED))
{
    ERROR,  // = 0
    PENDING,    // = 1
    GRANTED = 10,   
    DENIED  // = 11
};

// has nothing to do with class or struct per-say.
// : char - translates the variables to s = 0 = '\0'
// : char - is mostly unnessesary as computers nowdays are made to use int over char.
// : int - default
enum class LoginStatus : char   // scoped - can be reached by writing LoginStatus::GRANTED
{
    Error = -1,
    Pending,
    GRANTED,
    DENIED
};


/*
Example 1: Assignment in function.

int x {2};

if(x = 0)   // Will work, although x = 0 = false - (all other values would return true)
{
    cout << "x is zero\n" << std::endl;
}
else
{
    cout << "Value of x: " << x << std::endl;
}

*/