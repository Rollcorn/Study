#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
/*
    void strcat(char *to, const char *from)
    {
    char* strend = to;
    while(*strend != '\0'){++strend;}
    for(int i = 0; from[i] != '\0'; i++)
    {
        *strend = from[i];
        strend++;
    }
    *strend = '\0';
    }
*/
struct String {
    //Контсруктор создающий строку в которой n раз повторяется символ c.
	String(size_t n, char c)
    {
        this->size = n;
        this->str = new char[n+1];
        for(int i = 0; i != n; ++i)
        this->str[i] = c;
    }

    //Конструктор по умолчанию
	String(const char *str = "")
    {
        this->size = strlen(str);
        this->str = new char[this->size + 2];
        strcpy(this->str, str);
    }

    //Деструктор
	~String(){
        delete [] this->str;
    }
    
    //Метод дописывающий в конец строки другую строку
    void append(String &other)
    {    
        char* str_tmp = new char[size + other.size + 2];
        strcpy(str_tmp, str);
        str_tmp[size + 1] = '\0';
        
        strcat(str_tmp, other.str);
        size = size + other.size;
        str_tmp[size + 1] = '\0';
        delete [] str;
        
        str = str_tmp;
    }
    //Метод возвращающий  элемент с индексом idx из строки
    char & at(size_t idx)       { 
        std::cout << "Не константный метод" << std::endl;    
        return str[idx]; 
    }
    char   at(size_t idx) const { 
        std::cout << "Константный метод" << std::endl;
        return str[idx]; 
    }
    
	size_t size;
	char *str;
};

int main(){
    
    String greet("Hello");
    char ch1 = greet.at(0);
   
    String const const_greet("Hello, Const!");
    char const &ch2 = const_greet.at(0);

    std::cout << ch1 << " " << ch2 << std::endl;
 
    return 0;
}

