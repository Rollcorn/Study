/*Скобки могут быть всех трех видов - ()[]{}.

На вход программа или функция должна принимать строку, а на 
выходе ответить правильно ли расставлены скобочки в ней.

Те есть открывающиеся скобочки корректно закрываются скобочкой
 того же вида.

Например:
"([])" - true
"{[(]}"- false */

#include <iostream>
#include <stack>
#include <vector>

int main(){
    
    std::stack<char> stack;
    std::vector<char> seq;
    char el;
    
    std::cout << "Enter your sequence (press R to finish enter): " << std::endl;
    while (std::cin >>  el && el != 'R')
        seq.push_back(el); 
    std::cout << "Resul is: " << std::endl;
    for(int i = 0; i != seq.size(); i++){
            switch(seq[i]){
            case(')'):
                if(stack.top() == '(' && !stack.empty()) stack.pop();
                
                break;
            case('}'):
                if(stack.top() == '{') stack.pop();
                break;
            case(']'):
                if(stack.top() == '[') stack.pop();
                break;
            default:
                if(seq[i] == '(' || seq[i] == '{' || seq[i] == '[') {
                    stack.push(seq[i]);
                } else {
                    std::cout << "Bad enter!" << std::endl;
               }
            }
            
    }
    for(int i = 0; i != seq.size(); i++) std::cout << seq[i] << " ";
    std::cout << std::endl;
    if(stack.empty()) std::cout << "Is right sequence!" << std::endl;
    else std::cout << "Is BAD sequence!" << std::endl;
    

    return 0;

}
