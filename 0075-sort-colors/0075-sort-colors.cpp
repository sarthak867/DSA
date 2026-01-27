class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0; i<nums.size();i++){
            int s = nums[i], temp=-1;
            for(int j =i+1 ; j < nums.size(); j++){
                if(nums[j]< s){
                    s= nums[j];
                    temp=j;
                }
            }
            if(temp!=-1){
                swap(nums[i], nums[temp]);
            }
        }
    }
};