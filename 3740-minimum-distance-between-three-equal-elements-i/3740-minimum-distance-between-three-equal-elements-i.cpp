class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i =0 ; i< nums.size();i++){
            mp[nums[i]].push_back(i);
        } 
        int minimum =INT_MAX;
        for(auto&[a,b]: mp){
            if(b.size()<3) continue;
            for(int i =2;i<b.size(); i++){
                int dist = 2*(b[i]-b[i-2]);
                minimum = min(minimum,dist );
            }
        }
        if(minimum==INT_MAX) return -1;
        return minimum;
    }
};