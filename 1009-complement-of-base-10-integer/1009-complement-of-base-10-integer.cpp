class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        for(int i = 1 ; i<= 30 ; i++){
            int num = (1<<i)-1;
            if(n<=num) return num-n;
        }
        return 0;
    }
};