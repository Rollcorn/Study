#include <iostream>
#include <vector>
#include <string>

void vectors_print(std::vector<std::string> names,
                   std::vector<int> scores){
    for(int i = 0; i < names.size(); i++)
    std::cout << "#" << i << " " << names[i] << 
                " - " << scores[i] << std::endl;

}

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
    
    vectors_print(names, scores);

    return 0;
}

