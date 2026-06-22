class Solution {
public:
    bool consecutiveSetBits(int n) {
        int lst =0;
        bool one =0;
        while(n){
            int rem = n%2;
            n/=2;
            if(lst==1 && rem ==1) {
                if(one) return 0;
                one =1;
            }
            lst = rem;
        }
        return one;
    }
};