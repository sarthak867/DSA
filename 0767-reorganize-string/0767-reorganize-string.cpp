class Solution {
public:
    string reorganizeString(string s) {
        if (s.size() == 1)
            return s;

        vector<pair<int, char>> freq;
        map<char, int> mp;

        int mx = 0;
        for (char c : s) {
            mp[c]++;
            mx = max(mx, mp[c]);
        }

        int sz = s.size();

        // Impossible condition
        if (mx > (sz + 1) / 2)
            return "";

        // Fill vector
        for (auto it : mp) {
            freq.push_back({it.second, it.first});
        }

        string ans = "";

        while (!freq.empty()) {

            sort(freq.rbegin(), freq.rend());

            if (freq[0].first == 0) {
                freq.erase(freq.begin());
                continue;
            }

            if (!ans.empty() && ans.back() == freq[0].second) {

                if (freq.size() == 1)
                    return "";   

                ans += freq[1].second;
                freq[1].first--;

            } else {
                ans += freq[0].second;
                freq[0].first--;
            }
        }

        return ans;
    }
};