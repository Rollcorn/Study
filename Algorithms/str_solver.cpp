#include <string>
#include <iostream>

int main()
{
  std::string hello = "Hello, World! ";
  std::string result;

  std::cout << hello << std::endl;
  int times_to_concatenate;
  std::cout << "Enter count of copy\n";
  std::cin >> times_to_concatenate;

  for (int i = 0; i < times_to_concatenate; i++){
      result += hello;
  }

  std::cout << result << std::endl;

  return 0;

}







