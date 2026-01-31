class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int  i=0 , j=nums.size()-1;
        int cnt =0;
        for(int k =1 ; k<j; k++) {
           if(nums[k]>nums[i] && nums[k]<nums[j]) cnt++;
        }
        return cnt;
    }
};