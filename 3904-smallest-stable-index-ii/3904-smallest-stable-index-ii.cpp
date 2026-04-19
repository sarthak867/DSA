class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> maximum(sz),minimum(sz);
        maximum[0]=nums[0];
        minimum[sz-1]= nums[sz-1];
        for(int i =1; i<sz;i++){
            maximum[i] = max(nums[i],maximum[i-1]);
            minimum[sz-i-1]=min(nums[sz-i-1],minimum[sz-i]);
        }
        for(int i = 0 ; i<sz; i++){
            if(maximum[i]-minimum[i]<=k) return i;
        }
        return -1;
    }
};