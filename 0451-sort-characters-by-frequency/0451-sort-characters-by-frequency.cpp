class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        map<int, vector<char>> freq2;

        for(char c : s){
            freq[c]++;
        }

        for(auto &mp : freq){
            freq2[mp.second].push_back(mp.first);
        }

        string result = "";

        for(auto it = freq2.rbegin(); it != freq2.rend(); it++){
            int count = it->first;

            for(char c : it->second){
                result += string(count, c);
            }
        }

        return result;
    }
};