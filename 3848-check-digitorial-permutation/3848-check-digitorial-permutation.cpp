class Solution {
public:
        int fact(int n){
            if(n==0) return 1;
            if(n<=2) return n;
            if(n==3) return 6;
            if(n==4) return 24;
            if(n==5) return 120;
            if(n==6) return 720;
            if(n==7) return 5040;
            if(n==8) return 40320;
            if(n==9) return 362880;
            return -1;
        }
    
    bool isDigitorialPermutation(int n) {
        long long sum = 0;
        int dup = n;
        while(dup>0){
            int rem = dup%10;
            sum += fact(rem);
            dup /= 10;
        }
        string s  = to_string(n);
        string p = to_string(sum);
        if(s.size()!=p.size()) return 0;
        sort(s.begin(),s.end());
        sort(p.begin(),p.end());
        return (s==p);
    }
};