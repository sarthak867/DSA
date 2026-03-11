class Solution {
public:
    int findComplement(int n) {
        if(n==0) return 1;
        for(int i = 0 ; i<= 31; i++){
            long long num = (1LL<<i)-1;
            if(n<=num) return num-n;
        }
        return 1;
    }
};