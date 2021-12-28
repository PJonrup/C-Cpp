#include <iostream>

using std::string, std::cout, std::endl;

/*
Quesiton 1:

a. lvalue
b. prvalue
c. lvalue
d. prvalue
e. xvalue
f. lvalue
g. prvalue
h. lvalue


Question 2:

a. char * ptr;
b. int array[10];
c. std::string * str[3];    // enligt svar -> (*array)[3];
d. char ** ptr;
e. int const n;
f. int const * ptr;
g. int * const ptr;


Question 3:
*/
int main() {
    string words[3]{"hello", "world", "!"};
    char* ptr{new char{'A'}};
    int array[10]{1};
    // string (*words_ptr)[3]{&words}   does not seem to work as answer ses it should.
    char ** ptr_ptr{&ptr};
    int const n{1};
    int const * cptr1{&n};
    int * const cptr2{&array[0]};
} 
/*

Question 4:

(a) int a(int i);
(b) int a(int);
(c) int a(int (i));
(d) int a(int (*i)());
(e) int a(int* const);
(f) int a const();
(g) int a(int const* (*)());
(h) int a(int (*)(int));
(i) int a(int (*i)(int)[10]);
(j) int a(int (*i[10])());
(k) int a(int (&(*i)())[10]);

Answers:
(a) Valid. A function with a named int parameter that returns an int.
(b) Valid. A function with an int parameter (name omitted) that returns
an int.
(c) Valid. A function with a named int parameter that returns an int,
with reduntant parenthesis around the parameter name (identifier).
(d) Valid. A function returning int that has an argument which is a pointer
to a function returning int with no parameters.
(e) Valid. A function returning int that takes a constant pointer to an int
as a parameter.
(f) Illegal.
(g) Valid. A function returning int that takes a (unnamed) parameter that
is a pointer to a function with no arguments that return a pointer to a
constant int.
(h) Valid. A function returning int, that takes a pointer to a function with
one int parameter and that returns an int.
(i) Illegal.
(j) Valid. A function returning int, that takes an array of 10 pointers to
functions taking no parameters and returning int.
(k) Valid. A function returning int, that takes a pointer to a function with
no arguments that return a reference to an array of 10 int.


Question 5:

using x = int(&)(int, int);

Answer:
x is a reference to a function taking two ints and returning an int.

It can be used as this:
int add( int a, int b)
{
    return a + b;
}

using x = int (&)( int , int );

int main ()
{
    x my_fun {add };
    return my_fun (1, 2);  // will call add (1, 2)
}


Question 6:

lenght and size of "Hello World!" (a c-string) is 12 and 13 respectively as c-sting needs "\0" at the end.


Question 7:

1   int i1{};
2   int i2(2);
3   int i3 = 1;
4   int i4 = {};
5   int i5();
6   std::string str1{};
7   std::string str2("hello");
8   std::string str4(3, ’a’);
9   std::string str5 = str2;
10  float f1{5.37e100};
11  float f2 = 5.37e100;
12  float f3{1738335806};

Answers:
1   Valid. The value is 0.
2   Valid. The value is 2.
3   Valid. The value is 1.
4   Valid. The value is 0.
5   Invalid, because most vexing parse forces the compiler to interpret this
    as a declaration of a function returning int with no parameters.
6   Valid. The value is "".
7   Valid. The value is "hello".
8   Valid. The value is "aaa".
9   Valid. The value is "hello".
10  Invalid because brace-initialization checks for narrowing conversions and
    since 5.37e100 is a double which has higher accuracy than float forcing
    a narrowing conversion.
11  Valid (copy initialization does not check for narrowing conversions). The
    value is undefined since float cannot accurately represent 5.37e100,
    but it is probably inf.
12  Invalid, float cannot accurately represent 1738335806 which would
    lead to narrowing conversion.


Question 8:

a lot of conversions... make sure you know what you want and send that... done.


Question 9:

0 - 1u:
unsigned and int, unsigned has higher accuracy therefore the int becomes unsigned but then the expression Underflows.



*/