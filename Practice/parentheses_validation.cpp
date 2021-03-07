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
#include <string>

void parentheses_valid(std::string seq){
 
    std::stack<char> stack;
  
    for(auto i = seq.begin(); i != seq.end(); i++){
        
        if((*i == ')' or *i =='}' or *i == ']') and stack.empty()) stack.push(*i);
        
        switch(*i){
        case(')'):
            if(stack.top() == '(') {stack.pop();}
            else {stack.push(*i);}
            break;
        case('}'):
            if(stack.top() == '{') stack.pop();
            else {stack.push(*i);}
            break;
        case(']'):
            if(stack.top() == '[') stack.pop();
            else {stack.push(*i);}
            break;
        default:
            if(*i == '(' || *i == '{' || *i == '[') {
            stack.push(*i);
            }
        }
    }
   
    std::cout << "Resul is: " << std::endl;
    
    for (auto i = seq.begin(); i != seq.end(); i++) std::cout << *i << " ";
    std::cout << std::endl;
    
    if (stack.empty()) std::cout << "It is RIGHT sequence!" << std::endl;
    else std::cout << "It is BAD sequence!" << std::endl;
}


int main(){
    
    std::string seq;
    
    std::cout << "Enter your sequence: " << std::endl;
    std::getline(std::cin, seq);
    parentheses_valid(seq); 
    

    //Some tests:
    std::cout << "Test 1-f" << '\n';
    std::string test1 = "{)";
    parentheses_valid(test1);
    
    std::cout << "Test 2-f" << '\n';
    std::string test2 = ")";
    parentheses_valid(test2);
    
    std::cout << "Test 3-f" << '\n';
    std::string test3 = "(]]]]";
    parentheses_valid(test3);
    
    std::cout << "Test 4-t" << '\n';
    std::string test4 = "(){}[]";
    parentheses_valid(test4);
    
    std::cout << "Test 5-f" << '\n';
    std::string test5 = "}}}}";
    parentheses_valid(test5);
    
    std::cout << "Test 6-f" << '\n';
    std::string test6 = "[[[[";
    parentheses_valid(test6);

 
    return 0;
}
