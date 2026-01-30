class Solution {
public:
    void f(int idx, int target,vector<int> &v, vector<vector<int>> &result, vector<int> &candidate){
        if(target == 0){
            result.push_back(v);
            return;
        }
        if(idx == candidate.size() || target < 0){
            return;
        }

        v.push_back(candidate[idx]);
        f(idx, target-candidate[idx], v, result, candidate);
        v.pop_back();

        f(idx+1, target, v, result, candidate);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> v;
        f(0, target, v, result, candidates);
        return result;
    }
};