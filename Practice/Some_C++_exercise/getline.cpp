#include <iostream>

char *resize(char *str, unsigned size, unsigned new_size)
{
    char* str2 = new char[new_size];
    for(int i = 0; i != ((size < new_size)? size : new_size); i++)
    {
        str2[i] = str[i];
    }
    delete [] str;
    return str2;
}


char* getline(){
    unsigned ARR_SIZE = 10;
    char* line = new char[ARR_SIZE];
    char ch = '\0';
    int i = 0;
    while(std::cin.get(ch) && ch != '\n'){
        if ((i + 1) == ARR_SIZE)
            line = resize(line, ARR_SIZE, ARR_SIZE *= 1.5);
        line[i] = ch;
        line[++i] = '\0';
    }

    return resize(line, ARR_SIZE, i);    
}



int main(){
    char* line = getline();
    for(int i = 0; line[i] != '\0'; i++)
        std::cout << line[i];
        std::cout << std::endl;
    delete[] line;    
    return 0;
} 
