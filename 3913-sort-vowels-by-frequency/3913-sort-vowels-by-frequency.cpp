class Solution {
public:
    string sortVowels(string s) {
        vector<pair<char, int>> mp = {
            {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}
        };
        
        unordered_map<char, int> firstPos;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            for (auto& p : mp) {
                if (p.first == c) {
                    p.second++;
                    if (!firstPos.count(c)) {
                        firstPos[c] = i;
                    }
                    break;
                }
            }
        }

        sort(mp.begin(), mp.end(), [&](auto& a, auto& b) {
            if (a.second != b.second)
                return a.second > b.second;
            return firstPos[a.first] < firstPos[b.first];
        });

        // build sorted vowel list
        vector<char> sortedVowels;
        for (auto& p : mp) {
            for (int i = 0; i < p.second; i++) {
                sortedVowels.push_back(p.first);
            }
        }

        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            for (auto& p : mp) {
                if (s[i] == p.first) {
                    s[i] = sortedVowels[idx++];
                    break;
                }
            }
        }

        return s;
    }
};