class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        vector<int> dup = nums;
        int j =1;
        for(int  i = 1; i<dup.size();i++){
            if(dup[i]!=nums[j-1]){
                nums[j]=dup[i];
                j++;
            }
        }
        return j;
    }
};