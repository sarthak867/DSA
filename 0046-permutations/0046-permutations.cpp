class Solution {
public:

vector<vector<int> > ans;
    void perm(vector<int> nums, int ind){
        if(ind==nums.size()) ans.push_back(nums);
        for(int i = ind ; i<nums.size(); i++){
            swap(nums[ind],nums[i]);
            perm(nums,ind+1);
        }
    }
    vector<vector<int>> permute(vector<int> nums) {
        perm(nums,0);
        return ans;
    }
};