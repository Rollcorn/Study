#include <iostream>
#include <string>

int main()
{
    std::string hello = "hello, world!";
    std::string result;
    
    std::cout << hello << std::endl;
    int times_to_concatenate;
    std::cin >> times_to_concatenate;

    for(int i=0;i<times_to_concatenate;i++)
        result += hello;

    std::cout << result << std::endl;
    return 0;
}
