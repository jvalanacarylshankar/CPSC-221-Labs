#include <iostream> 
int array[10];
void fill_array();
void fill_array(int , int); 
int main(void) {
int first;
int increment;
 fill_array();
std::cout << "First Type"<< std::endl;
for(int i = 0; i < 10; i++)
std::cout << array[i]<< std::endl<< std::endl;

std::cout << "Second Type"<< std::endl;
std::cout << "Enter first : ";
std::cin >> first; 
std::cout << "Enter increment : ";
std::cin >> increment; 

fill_array(first, increment);
for(int i = 0; i < 10; i++)
std::cout << array[i]<< std::endl<< std::endl;
 return 0;
}

void fill_array() {
 for(int i = 0; i < 10; i++)
array[i] = i+1;
} 

void fill_array(int first, int increment) {
array[0] = first;
first += increment;
 for(int i = 1; i < 10; i++)
{
array[i] = first;
first += increment;
}
} 