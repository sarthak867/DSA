class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int s = INT_MAX;
        long long ts =0;
        int neg =0;
        for(auto& row : matrix){
            for(int i =0 ; i< row.size(); i++){
                if(row[i]<0) {
                    neg++;
                    row[i] = abs(row[i]);
                }
                if(row[i]<s){
                    s= row[i];
                }
                ts += row[i];
            }
        }
        if(neg%2==1){
            return ts-2*s;
        }
        return ts;
    }
};