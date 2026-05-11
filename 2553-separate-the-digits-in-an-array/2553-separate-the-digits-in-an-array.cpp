class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i : nums){
            stack<int> temp;
            while(i){
                temp.push(i%10);
                i/=10;
            }
            while(!temp.empty()){
                ans.push_back(temp.top());
                temp.pop();
            }
        }
        return ans;
    }
};