#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

	String(const char *str = ""){
        int din_size = 100;
        this->str = new char[din_size]; 
        for(int i = 0; str[i] != '\0'; ++i){
            this->str[i] = str[i];
            this->size = i;
            if(i == din_size){
                char* temp2 = new char[2*din_size];
                for(int j = 0; j != i; ++j)
                    temp2[j] = temp[i];
                temp = temp2;
            }
        }
        this->str[size] = '\0';
        this->size -= 1;
        this->str = temp;

    }
    
	size_t size;
	char *str;
};

int main(){
    String s("Hello world\0");

    return 0;
}

