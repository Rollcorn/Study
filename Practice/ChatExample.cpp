#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include <unordered_map>

using namespace std;

void to_lower(string& str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

string user(){
    string question;
    cout << "[USER]: ";
    getline(cin, question);
    to_lower(question);
    return question;
}

void bot(string text){
    cout << "[BOT]: " << text << endl;
}

int main()
{
    unordered_map<string, string> database = {
        {"hello", "Oh, hello to you human"},
        {"how are you", "I'm good"},
        {"what is your name", "SUPERBOT"},
    };
    
    string question;
    bot( "Hello, welcome to SUPERBOT, please ask any question: ");
    while(question.compare("exit") != 0){
        question = user();
        for (auto entry : database){
            auto expression = regex(".*" + entry.first + ".*");
            if (regex_match(question, expression)){
                bot(entry.second);
            }
        }
    }

   return 0;
} 
