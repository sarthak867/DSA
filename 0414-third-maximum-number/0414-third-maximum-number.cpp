class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int count = 1;  
        int last = nums[n-1];  
        
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] != last) {  
                count++;
                last = nums[i];
            }
            if(count == 3) {
                return nums[i];
            }
        }
        
        return nums[n-1];   
    }
};