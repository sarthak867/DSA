class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i =0 ; i <n; i++){
            int ti = (i + nums[i])%n;
            if(ti < 0){
                ans.push_back(nums[n + ti]);
            }else ans.push_back(nums[ti]);
        }
        return ans;
    }
};