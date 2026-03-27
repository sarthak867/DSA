class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        k = k%n;
        if(k==0) return 1;
        for(auto& rows : mat){
            vector<int> nums = rows;
            rotate(rows.begin(),rows.begin()+k,rows.end());
            if(rows!=nums) return false;
        }
        return true;
    }
};