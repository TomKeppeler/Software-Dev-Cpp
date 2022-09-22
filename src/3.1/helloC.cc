#include "iostream"
#include <ostream>
int main()
{
  int* ptr;
  int var = 7;
  int foo = 21;
  ptr = &var;
  ptr = &foo;
  int& ref = var;
  ref = 19;
  std::cout << "ref: " << ref << std::endl << "var: " << var <<std::endl
  << "ptr: " << ptr << std::endl;
  return 0;
}