class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i : nums){
            vector<int> temp;
            while(i){
                temp.push_back(i%10);
                i/=10;
            }
            ans.insert(ans.end(), temp.rbegin(), temp.rend());
        }
        return ans;
    }
};