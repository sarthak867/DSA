class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string nz="";
        int sum =0;
        for(char c: s){
            if(c=='0') continue;
            nz+=c;
            sum+= c-'0';
        }
        if(n==0|| nz=="") return 0;
        n=stoi(nz);
        return 1LL*sum*n;

    }
};