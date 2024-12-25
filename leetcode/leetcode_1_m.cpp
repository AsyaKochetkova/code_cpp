/*Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words.
The returned string should only have a single space separating the words. Do not include any extra spaces.*/

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

int main(){
    std::string src="";
    std::string answer="";
    std::vector<std::string> res;
    std::getline(std::cin,src);
    std::stringstream ss(src);
    std::string word;

    while(ss >> word){
        res.push_back(word);
    }



    for(int i=res.size()-1; i>0; i--){
        answer += res[i] + " ";
    }
    answer += res[0];

    std::cout << answer;

    return 0;
}

