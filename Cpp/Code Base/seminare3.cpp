#include <iostream>

using std::string, std::cout, std::endl;


/*
Consturctors or not?

If you need to run code directly after 
initialization then you NEED a constuctor, 

otherwise it will just use aggregate-init 
and then copy.

Therefore it does not matter, and it's up to you.
*/

// ------------------------------ Inheritance Example 1 --------------------------
class Employee
{
public:
    string name{"christoffer"};
    int id{44};

    Employee(int x) : x{x} { }  // Data member initialisation list

private:
    int x;

protected:
    int y;
};
class Teacher : public Employee     // Teacher is now a Derived class of Employee.
{
public:
    string course{"TDDD38"};

    // ! Teacher may never use x from Employee.
    // ! However, y can be access from derived classes according to C++ (this is not the same in every language).

    Teacher(int y) : Employee{y} { }
    int get()
    {
        return y;
    }
};
Teacher c{5};

// ------------------------------ Inheritance Example 2 --------------------------
class Base
{
public:
    Base(int x);
private:
    int x;
};

Base::Base(int x) : x{x} 
{
}


class Derived final : public Base   // "final" means (class A : public Derived) will not work!
{
public:
    Derived(int x, double y);
private:
    double y;
};

Derived::Derived(int x, double y) : Base{x}, y{y}
{
}

// ------------------------------ Inheritance Example 3 --------------------------

// ------------------------------ Polymorphism Example 1 --------------------------

// Check slide page 10 on seminare 3 for code example.

// ------------------------------ Polymorphism Example 2 --------------------------

struct Base2
{
    // "virtual" means that this function is intended to be overridden at some point.
    // "virtual" also means that every "override" function forward will also be "virtual".
    // ! ! ! ! ! "virtual" is more expensive! ! ! ! ! !
    virtual void print()
    {
        cout << "1" << endl;
    }

    // ! If you ever have a "virtual" function, you need to have a "virtual" destructor.
    virtual ~Base2() { /* Maybe print something */ };
};
struct Derived2 : public Base2
{
    // "override" means that this function is intended to override a function.
    void print() override
    {
        cout << "2" << endl;
    }
};

int main()
{
    Base2* bp {new Base2{}};
    bp->print();
    delete bp;

    bp = new Derived2{};
    bp->print();
}

// ------------------------------ Polymorphism Example 3 --------------------------
struct Base3
{
    virtual ~Base3();
    virtual void fun();
    int val1{1};
    int val2{2};
};
struct Derived3 : public Base3
{
    void fun() override;
    double d{3.4};
};
struct Derived33 : public Derived3
{
    void fun() final;   // Final works for functions too.
};

void Base3::fun()
{
    cout << val1 << ' ' << val2;
}
void Derived3::fun()
{
    Base3::fun();
    cout << ' ' << d;
}
void Derived33::fun()
{
    cout << "Derived33 ";
    Derived3::fun();
}

// ------------------------------ Polymorphism Example 4 --------------------------

// Virtual tables and how the base pointer is saved (seminare 3, slide 14).

// ------------------------------ Polymorphism Example 5 --------------------------

// Dynamic cast:

struct Base4 {virtual ~Base4() = default; };
struct Derived4 : public Base4 { };
struct Derived44 : public Derived4 { };
int main() 
{
    Base4* bp{new Derived4()};
    cout << (dynamic_cast<Base4*>(bp) == nullptr) << endl;
    cout << (dynamic_cast<Derived44*>(bp) == nullptr) << endl;
}

// The rest can be seen on the slides in seminare 3.