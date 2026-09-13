class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map <int, vector<int>> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        int ans =0;
        for(auto [a,b]: mp){
            if(b.size()<3) continue;
            int gap = b[1]-b[0];
            bool sp=1;
            for(int i = 2;i<b.size();i++){
                if(b[i]-b[i-1]==gap) continue;
                sp=0;
            }
            if(sp) ans++;
        }
        return ans;
    }
};