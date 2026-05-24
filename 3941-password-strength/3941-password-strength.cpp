class Solution {
public:
    int passwordStrength(string password) {
        unordered_set <char> s;
        for(char c : password){
            s.insert(c);
        }
        int ans =0;
        for(char a : s){
            if(a>='a' && a<='z') ans++;
            else if(a>='A' && a<='Z') ans+=2;
            else if(a>='0' && a<='9') ans += 3;
            else ans += 5;
        }
        return ans;
    }
};