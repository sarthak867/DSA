class Solution {
public:
    bool isPossibleToRearrange(string st, string t, int k) {
        int n  = t.length()/k;
        int co = 0;
        string s = "";
        unordered_map<string ,int> freq;
        for(char c : t){
            s+=c;
            co++;
            if(co==n){
                freq[s]++;
                s="";
                co=0;
            }
        }
        co=0;
        s="";
        for(char c : st){
            s+=c;
            co++;
            if(co==n){
                if(freq.count(s) && freq[s]>0){
                    freq[s]--;
                }else return false;
                s="";
                co=0;
            }
        }
        return true;
    }
};