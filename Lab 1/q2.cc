#include <iostream>
#include <string>
#include <fstream>

std::ifstream in;
std::ofstream out;

int main(void) {
 in.open("infile.txt");
 out.open("outfile.txt");
 std::string ss;
 // getline() puts next line in ss and discards any newline characters
 while (getline(in, ss))
 out << ss << std::endl; // add each line to the new file, appending endl
 std::cout << "End of program" << std::endl;
 return 0;
}