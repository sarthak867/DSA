class Solution {
public:
    bool rotateString(string s, string g) {
        if(s==g) return 1;
        for(int i =1; i<s.size(); i++){
            if(s[i]==g[0]){
                string nw = s.substr(i) + s.substr(0, i );
                if(nw==g) return 1;
            }
        }
        return 0;
    }
};