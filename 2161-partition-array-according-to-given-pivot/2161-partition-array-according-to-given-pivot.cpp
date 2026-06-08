class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>l,r;
        int p =0;
        for(int i : nums){
            if(i<pivot) l.push_back(i);
            else if(i==pivot) p++;
            else r.push_back(i);
        }
        int i =0;
        for(int j : l){
            nums[i++]= j;
        }
        while(p){
            nums[i++]=pivot;
            p--;
        }
        for(int j : r){
            nums[i++]=j;
        }
        return nums;
    }
};