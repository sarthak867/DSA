class Solution {
public:
    int binaryGap(int n) {
        int m =0;
        int lst =-1;
        int i =0;
        while(n>0){
            int rem = n%2;
            i++;
            n/=2;
            if(rem == 0)continue;
            if(lst !=-1){
                m = max(m, i-lst);
            }
            lst =i;
        }
        return m;
    }
};