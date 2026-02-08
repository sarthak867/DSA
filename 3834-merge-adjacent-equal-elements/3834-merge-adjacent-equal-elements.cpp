class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        stack<long long> st;
        for (int i : nums) {
            long long cur  = i;
            while(!st.empty() && st.top()==cur){
                cur += st.top();
                st.pop();
            }
            st.push(cur);
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};