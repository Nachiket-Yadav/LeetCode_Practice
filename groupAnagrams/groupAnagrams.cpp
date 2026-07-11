class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string,std::vector<std::string>> res;

        for (const auto&  s : strs){
            std::vector<int> freqs(26,0);
            for (char c : s){
                freqs[c - 'a']++; // Create the freqeuency map
            }

            std::string key = to_string(freqs[0]);
            for (int i = 1; i < 26; i++){
                key += ',' + to_string(freqs[i]); // Create a unique key for the frequency map
            }

            res[key].push_back(s);
        }

        std::vector<std::vector<std::string>> result;
        for (const auto& pair : res){
            result.push_back(pair.second); // Append the list/vector of anagram strings from each key to the results vector

        }

        return result;
    }
};