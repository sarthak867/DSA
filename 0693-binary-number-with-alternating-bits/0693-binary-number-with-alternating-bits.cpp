class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lst = n%2;
        n=n/2;
        while(n>0){
            if(n%2==lst) return false;
            lst = n%2;
            n/=2;
        }
        return true;
    }
};