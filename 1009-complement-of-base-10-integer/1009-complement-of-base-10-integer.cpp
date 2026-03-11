class Solution {
public:
    int bitwiseComplement(int n) {
        vector<long long> nums;
        for (int i = 0; i <= 30; i++) {
            nums.push_back((1LL << i)-1);
        }
        if(n==0) return 1;
        for(int i : nums){
            if(n<=i) return i-n;
        }
        return -1;
    }
};