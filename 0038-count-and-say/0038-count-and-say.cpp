class Solution {
public:

    string rle(string s){
        int c = 1;
        char l = s[0];
        string ans = "";

        for(int i = 1; i < s.size(); i++){
            if(s[i] == l) {
                c++;
            }
            else{
                ans += to_string(c);
                ans += l;
                l = s[i];
                c = 1;
            }
        }

        ans += to_string(c);
        ans += l;

        return ans;
    }

    string countAndSay(int n) {
        vector<string> dp(n+1);
        dp[1] = "1";

        for(int i = 2; i <= n; i++){
            dp[i] = rle(dp[i-1]);
        }

        return dp[n];
    }
};
