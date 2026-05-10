int dp [1000];
class Solution {
public:
    static int dfs(int i, vector<int>& nums, int target) {
        if (i==0)
            return dp[i]=0;

        if (dp[i]!=-1)
            return dp[i];

        int ans=INT_MIN;
        for (int j=0; j<i; j++) {
            if (abs(nums[j]-nums[i])<=target) {
                ans=max(ans , 1+dfs(j, nums, target));
            }
        }
        return dp[i]=ans;
    }

    static int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        memset(dp, -1, sizeof(int)*n);
        int ans=dfs(n-1, nums,  target);
        return  ans<0?-1:ans;
    }
};