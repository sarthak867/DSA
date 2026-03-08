class Solution {
public:
    int minOperations(string s) {
        string b = s;
        sort(b.begin(),b.end());
        if(b==s) return 0;
        int n =s.size();
        if(n==2) return -1;
        if(s[0]==b[0] || s[n-1]==b[n-1]) return 1;
        string c =s;
        sort(s.begin(),s.end()-1);
        
        sort(c.begin()+1,c.end());
        if(s[0]==b[0] || c[n-1]==b[n-1]) return 2;
        return 3;
    }
};