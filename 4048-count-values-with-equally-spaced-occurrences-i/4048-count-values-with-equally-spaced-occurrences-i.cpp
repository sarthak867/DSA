class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map <int, vector<int>> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        int ans =0;
        for(auto [a,b]: mp){
            if(b.size()!=3) continue;
            if(b[2]-b[1]==b[1]-b[0]) ans++;
        }
        return ans;
    }
};
