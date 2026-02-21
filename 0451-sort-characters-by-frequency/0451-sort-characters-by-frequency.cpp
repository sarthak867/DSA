class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        map<int, vector<char>> freq2;

        for(char c : s) {
            freq[c]++;
        }

        for(auto &mp : freq) {
            freq2[mp.second].push_back(mp.first);
        }

        string result = "";

        for(auto &mp : freq2) {
            for(char c : mp.second) {
                result += string(mp.first, c);
            }
        }

        reverse(result.begin(), result.end());  
        return result;
    }
};