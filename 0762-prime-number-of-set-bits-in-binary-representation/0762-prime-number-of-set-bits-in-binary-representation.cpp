class Solution {
public:
    vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    bool prime(int n){
        int set = __builtin_popcount(n);
        for(int i : p){
            if(i==set) return true;
        }
        return false;
    }

    int countPrimeSetBits(int l, int r) {
        int ans =0;
        while(l<=r){
            if(prime(l) ) ans++;
            l++;
        }
        return ans;
    }
};