class Solution {
public:
    int passwordStrength(string p) {
        unordered_map <char,int> mp;
        for(char c : p){
            mp[c]++;
        }
        int ans=0;
        for(auto [a,b] : mp){
            if(a>='a' && a<='z') ans++;
            else if(a>='A' && a<='Z') ans+=2;
            else if(a>='0' && a<='9') ans += 3;
            else ans += 5;
        }
        return ans;
    }
};