class Solution {
public:
    bool check(vector<int>& nums) {
        int sz = nums.size();
        int c =0;
        if(nums[0]<nums[sz-1]) c++;
        for(int i =1 ; i<sz ; i++){
            if(nums[i-1]>nums[i]) c++;
            if(c>1) return 0;
        }
        return 1;
    }
};