class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size() -1;
        for( auto arr : matrix){
            if(arr[0]<=target && arr[n]>= target){
                int l = 0, r= n;
                while(l<=r){
                    int m = (l +r)/2;
                    if(arr[m]==target) return true;
                    if(arr[m]>target){
                        r=m-1;
                    }else l = m+1;
                }
                return false;
            }
        }
        return false;
    }
};