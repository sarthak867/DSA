class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> req;
        for(int i =0 ; i<nums.size();i++){
            int r = target - nums[i];
            if(req.contains(r)){
                return {req[r],i};
            }
            req[nums[i]] = i;
        }
        return{-1};
    }
};