class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int m = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>m) m=nums[i];
            nums[i]= gcd(nums[i],m);
        }
        sort(nums.begin(),nums.end());
        long long s=0;
        for(int i=0;i<n/2; i++){
            s+= gcd(nums[i],nums[n-i-1]);
        }
        return s;
    }
};