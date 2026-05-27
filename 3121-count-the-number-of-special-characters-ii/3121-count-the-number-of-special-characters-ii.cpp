class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> mp(52, 0);

        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                int ind = c - 'a';

                if (mp[ind + 26] != 0) {
                    mp[ind] = -1;
                } else if (mp[ind] != -1) {
                    mp[ind] = 1;
                }
            } else {
                int ind = c - 'A';

                if (mp[ind] == 1) {
                    mp[ind + 26] = 1;
                } else if (mp[ind + 26] == 0) {
                    mp[ind + 26] = -1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (mp[i] == 1 && mp[i + 26] == 1) ans++;
        }

        return ans;
    }
};