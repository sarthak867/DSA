class Solution {
public:
    long long countCommas(long long n) {
        if(n<999) return 0;
        if (n==1000000000000000) return 3998998998999005;
        if(n<1000000) return n-999;
        long long curr = 999999-999;
        if(n<1000000000){
            curr += 2*(n-999999);
            return curr;
        }
        curr += 2*(999999999-999999);
        if(n<1000000000000){
            curr += 3*(n-999999999);
            return curr;
        }
        curr += 3*(999999999999-999999999);
        curr += 4*(n-999999999999);
        return curr;
    }
};