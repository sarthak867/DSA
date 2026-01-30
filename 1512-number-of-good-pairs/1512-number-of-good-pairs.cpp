class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int x : nums) {
            ans += mp[x];   // jitni baar pehle aa chuka, utne pairs banenge
            mp[x]++;
        }
        return ans;
    }
};
