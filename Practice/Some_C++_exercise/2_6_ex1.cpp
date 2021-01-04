#include <iostream>

char* resize(const char* str, unsigned size, unsigned new_size)
{
    char* str2 = new char[new_size];
    unsigned _size = (size <= new_size)? size : new_size;
    for(unsigned i = 0; i < _size; i++)
    {
        str2[i] = str[i];
    }
    str2[_size] = '\0';
    delete [] str;
    return str2;
}

int main(){
    unsigned size = 15;
    unsigned new_size = 20;
    const char* str1 = new char[size];
    str1  = "Hello world!\0";
    std::cout << str1 << std::endl;    
    std::cout << resize(str1, size, new_size) << std::endl;
     
    return 0;
}
