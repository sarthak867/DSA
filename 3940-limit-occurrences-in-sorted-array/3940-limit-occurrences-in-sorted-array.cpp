class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector <int> ans;
        int c =0, l=-1;
        for(int i : nums){
            if(i==l){
                c++;
            }else{
                c=0;
                l=i;
            }
            if(c<k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};