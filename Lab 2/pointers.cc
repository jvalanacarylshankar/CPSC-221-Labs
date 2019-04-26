#include <iostream>

int main () {
int x = 5, y = 15;
int * p1, *p2;

p1 = &x;
std::cout << "1st type" << std::endl;
std::cout << "x : " << x << std::endl;
std::cout << "y : " << y << std::endl;
std::cout << "Addr of x : " << &x << std::endl;
std::cout << "Addr of y : " << &y << std::endl;
std::cout << "p1 : " << p1 << std::endl;
std::cout << "Val of p1 : " << *p1 << std::endl;
std::cout << "Val of p2 : " << *p2 << std::endl;
std::cout << "p2 : " << p2 << std::endl<< std::endl;

p2 = &y;
std::cout << "2nd type" << std::endl;
std::cout << "x : " << x << std::endl;
std::cout << "y : " << y << std::endl;
std::cout << "Addr of x : " << &x << std::endl;
std::cout << "Addr of y : " << &y << std::endl;
std::cout << "p1 : " << p1 << std::endl;
std::cout << "Val of p1 : " << *p1 << std::endl;
std::cout << "Val of p2 : " << *p2 << std::endl;
std::cout << "p2 : " << p2 << std::endl<< std::endl;

*p1 = 6;
std::cout << "3rd type" << std::endl;
std::cout << "x : " << x << std::endl;
std::cout << "y : " << y << std::endl;
std::cout << "Addr of x : " << &x << std::endl;
std::cout << "Addr of y : " << &y << std::endl;
std::cout << "p1 : " << p1 << std::endl;
std::cout << "Val of p1 : " << *p1 << std::endl;
std::cout << "Val of p2 : " << *p2 << std::endl;
std::cout << "p2 : " << p2 << std::endl<< std::endl;

*p1 = *p2;
std::cout << "4th type" << std::endl;
std::cout << "x : " << x << std::endl;
std::cout << "y : " << y << std::endl;
std::cout << "Addr of x : " << &x << std::endl;
std::cout << "Addr of y : " << &y << std::endl;
std::cout << "p1 : " << p1 << std::endl;
std::cout << "Val of p1 : " << *p1 << std::endl;
std::cout << "Val of p2 : " << *p2 << std::endl;
std::cout << "p2 : " << p2 << std::endl<< std::endl;

p2 = p1;
std::cout << "5th type" << std::endl;
std::cout << "x : " << x << std::endl;
std::cout << "y : " << y << std::endl;
std::cout << "Addr of x : " << &x << std::endl;
std::cout << "Addr of y : " << &y << std::endl;
std::cout << "p1 : " << p1 << std::endl;
std::cout << "Val of p1 : " << *p1 << std::endl;
std::cout << "Val of p2 : " << *p2 << std::endl;
std::cout << "p2 : " << p2 << std::endl<< std::endl;

*p1 = *p2+10;
std::cout << "6th type" << std::endl;
std::cout << "x : " << x << std::endl;
std::cout << "y : " << y << std::endl;
std::cout << "Addr of x : " << &x << std::endl;
std::cout << "Addr of y : " << &y << std::endl;
std::cout << "p1 : " << p1 << std::endl;
std::cout << "Val of p1 : " << *p1 << std::endl;
std::cout << "Val of p2 : " << *p2 << std::endl;
std::cout << "p2 : " << p2 << std::endl<< std::endl;

return 0;
}