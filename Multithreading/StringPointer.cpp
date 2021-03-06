#include <iostream>
#include <string>

/*Cоздать умный указатель на объект класса std::string. 
Он должен иметь защиту от разыменования NULL - при попытке 
это сделать он должен конструировать внутри себя пустую 
строку.*/

class StringPointer{
public:
    std::string* operator->(){
        if(!str){
            str = new std::string("");
        }
        return str;
    }

    operator std::string*(){
        if(!str){
            str = new std::string("");
        }
        return str;
    }

    StringPointer(std::string* pointer): str(pointer){
    }

    ~StringPointer(){}

private:
    std::string* str;
};

int main(){
    std::string s1 = "Hello, world!";

    StringPointer sp1(&s1);
    StringPointer sp2(nullptr);

    std::cout << sp1->length() << std::endl;
    std::cout << *sp1 << std::endl;
    std::cout << sp2->length() << std::endl;
    std::cout << *sp2 << std::endl;




    return 0;
}
