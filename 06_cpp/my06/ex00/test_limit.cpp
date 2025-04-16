#include <iostream> 
#include <limits> 

int main ()
{
  std::cout << "Minimum value for char: " << (int) std::numeric_limits<char>::min() << '\n';
  std::cout << "Maximum value for char: " << (int) std::numeric_limits<char>::max() << '\n';
  std::cout << "Minimum value for unsigned char: " << (int) std::numeric_limits<unsigned char>::min() << '\n';
  std::cout << "Maximum value for unsigned char: " << (int) std::numeric_limits<unsigned char>::max() << '\n';
  std::cout << "Minimum value for int: " << std::numeric_limits<int>::min() << '\n';
  std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << '\n';
  std::cout << "Minimum value for float: " << std::numeric_limits<float>::min() << '\n';
  std::cout << "Maximum value for float: " << std::numeric_limits<float>::max() << '\n';
  std::cout << "Minimum value for double: " << std::numeric_limits<double>::min() << '\n';
  std::cout << "Maximum value for double: " << std::numeric_limits<double>::max() << '\n';
  std::cout << "Minimum value for long double: " << std::numeric_limits<long double>::min() << '\n';
  std::cout << "Maximum value for long double: " << std::numeric_limits<long double>::max() << std::endl;
  return (0);
}
