#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {

        if (s.length() != t.length()){
            return false;
        }
        std::unordered_map<char,int> counts;

        for (int i = 0; i < s.length(); i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }

        for (auto const& [key,val] : counts){
            if (val != 0){
                return false;
            }
        }

        return true;
    }
};