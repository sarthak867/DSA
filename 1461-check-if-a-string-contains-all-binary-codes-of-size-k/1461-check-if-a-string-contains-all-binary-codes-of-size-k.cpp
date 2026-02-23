class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map <string , int> sub;
        int tot = pow(2,k);
        int c= 0;
        if(k>s.length()) return false;
        for(int i = 0 ; i <= s.size()-k;i++){
            string st = s.substr(i,k);
            if(!sub.count(st)){
                sub[st]++;
                c++;
                if(c==tot) return true;
            }
        }
        return false;
    }
};