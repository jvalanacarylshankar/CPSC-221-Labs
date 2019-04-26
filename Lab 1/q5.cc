#include <iostream>
#include <stdlib.h>

int main(void) {
char guess[256];
srand(1);
char ans;
int secret = rand() % 100 + 1;

do
{
std::cout<<"Play or exit ('p' or 'e') : ";
std::cin>>ans;

if(ans=='p')
{
std::cout << "Enter guess : ";
std::cin >> guess;

if(atoi(guess) == secret)
std::cout<<"Correct"<<std::endl;
else
std::cout<<"Incorrect! Correct answer was : "<< secret <<std::endl;

secret = rand() % 100 + 1;
}

else
std::cout<<"Bye!";

}while(atoi(guess) != secret && ans == 'p');


 return 0;
}