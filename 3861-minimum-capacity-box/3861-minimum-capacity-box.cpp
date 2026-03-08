class Solution {
public:
    int minimumIndex(vector<int>& c, int sz) {
        int ind =0;
        int m = INT_MAX;
        int ans =-1;
        for(int i : c){
            if(i>=sz && i<m){
                m= i;
                ans = ind;
            }
            ind++;
        }
        return ans;
    }
};