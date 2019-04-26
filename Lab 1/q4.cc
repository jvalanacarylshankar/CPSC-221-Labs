#include <cstdlib>
#include <iostream>
// prototype
void moveDisks(int m, const char* a, const char* b, const char* c);

int main(int argc, char *argv[]) {
 if (argc != 2) {
 std::cout << "Usage: " << argv[0] << " number_of_disks" << std::endl;
 return -1;
 }
 moveDisks( atoi(argv[1]), "peg A", "peg B", "peg C" );
 return 0;
}

void moveDisks(int m, const char* a, const char* b, const char* c)
{
  if(m == 1){
    std::cout << "Move disc " << m << " from " << a << " to " << c << std::endl;
  }else{  
    moveDisks(m-1, a,c,b);
    std::cout << "Move disc " << m << " from " << a << " to " << c << std::endl;
    moveDisks(m-1,b,a,c);
  }
}