#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> names;
    std::vector<int> scores;    
    std::string name;
    int score;
    while(std::cin >> name >> score){
            if(name == "NoName" and score == 0){
            break;    
        }else{
            names.push_back(name);
            scores.push_back(score);
        }
    }


    return 0;
}

