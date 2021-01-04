#include <iostream>

unsigned strlen(const char* str){
    unsigned len = 0;
    while (str[len] != '\0'){len += 1;}
    return len;
}

void strcat(char* to, const char* from){
    char* strend = to;
    while(*strend != '\0'){++strend;}
    for(int i = 0; from[i] != '\0'; i++)
    { 
        *strend = from[i]; 
        strend++;
    }
   *strend = '\0';
}

int strstr(const char *text, const char* pattern){
    if(pattern == ) return 0;
    for(int j = 0; text[j] != '\0'; j++){
        for(int i = 0; pattern[i] == text[i+j] and pattern[i] != '\0'; i++){
            if(pattern[i] == '\0') return j;
        }
    }
    return -1;
}

int main(){
    char str1[] = "abbacbaabbaca\0";
    const char str2[] = "\0";
    std::cout << strstr(str1, str2) << std::endl;
    
    return 0;
}
