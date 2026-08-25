class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> mult(nums.size(),0);
        for(int i : nums){
            if(i%k==0 && i/k<=nums.size()) mult[i/k-1]=1;
        }
        for(int i =0 ; i<mult.size();i++){
            if(mult[i]==0) return (i+1)*k;
        }
        return (nums.size()+1)*k;
    }
};