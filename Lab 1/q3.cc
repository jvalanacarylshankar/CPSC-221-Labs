#include <iostream> // needed for cin and cout
int array[10];
void fill_array(); // declare function prototype
int main(void) {
 fill_array();
for(int i = 0; i < 10; i++)
std::cout << array[i]<< std::endl;
 return 0;
}

void fill_array() {
 for(int i = 0; i < 10; i++)
array[i] = i+1;
} 