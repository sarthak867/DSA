class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalsum =0 ;
       unordered_map <long , long> possiblesum ;
       
        long long sum =0;
        for(auto &row : grid){
            for(int i=0 ; i < row.size() ; i++ ){
                sum+=row[i];
                totalsum+= row[i];
            }
            possiblesum[sum]++;
            
        }
        if(totalsum%2==1) return false;
        totalsum/=2;
        if(possiblesum.count(totalsum)) return true;
        sum = 0;
        for(int i = 0; i<grid[0].size(); i++){
            for(int j = 0; j<grid.size(); j++){
                sum+= grid[j][i];
            }
            possiblesum[sum]++;
        }
        if(possiblesum.count(totalsum)) return true;
        return false;
    }
};