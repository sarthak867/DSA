class Solution {
public:
    int rev(int num) {
        int r = 0;
        while (num) {
            r = r * 10 + num % 10;
            num /= 10;
        }
        return r;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // store all indices first
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // only right side check
        for (int i = 0; i < n; i++) {
            int r = rev(nums[i]);

            if (!mp.count(r)) continue;

            for (int j : mp[r]) {
                if (j > i) {  //only right side
                    ans = min(ans, j - i);
                    if (ans == 1) return 1;
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};