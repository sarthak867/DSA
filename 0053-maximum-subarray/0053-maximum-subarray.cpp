class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int mx = 0;
        int smx = 0;
        bool allneg=1;
        for(int i : nums){
            if(i>-1) allneg =0;
            int curr = smx +i;
            if(curr<1) smx = 0;
            else smx += i; 
            mx = max(mx,smx);
        }
        if(allneg){
            int ans = *max_element(nums.begin(), nums.end());
            return ans;
        }
        return mx;
    }
};