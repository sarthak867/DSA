class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int c =1, l = nums[0];
        for(int i =1 ; i<nums.size(); i++){
            if(nums[i]== l){
                c++;
            }else{
                c=1;
                l=nums[i];
            }
            if(c>k){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums;
    }
};