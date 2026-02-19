class Solution {
public:
    int countBinarySubstrings(string s) {

        int n = s.length();
        if(n < 2) return 0;

        int ans = 0;

        for(int i = 0; i < n - 1; i++) {

            if(s[i] != s[i+1]) {

                char leftChar = s[i];
                char rightChar = s[i+1];

                int l = i;
                int r = i + 1;

                while(l >= 0 && r < n &&
                      s[l] == leftChar &&
                      s[r] == rightChar) {

                    ans++;
                    l--;
                    r++;
                }
            }
        }

        return ans;
    }
};
