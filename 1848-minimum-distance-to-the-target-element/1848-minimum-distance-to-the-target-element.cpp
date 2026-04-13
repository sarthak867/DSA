class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        if(nums[start]==target) return 0;
        int sz = nums.size();
        int i =1;
        while(start-i>=0 || start+i <sz){
            if(start-i>=0 && start+i <sz){
                if(nums[start-i]==target || nums[start+i]==target) return i;
            }else if(start-i>=0 && nums[start-i]==target){
                return i;
            }else if(start+i <sz && nums[start+i]==target){
                return i;
            }
            i++;
        }
        return -1;
    }
};