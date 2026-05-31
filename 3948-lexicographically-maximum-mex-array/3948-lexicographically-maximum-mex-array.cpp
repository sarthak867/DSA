class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(n + 1, 0);
        for (int x : nums) {
            if (x <= n) freq[x]++;
        }

        set<int> missing;
        for (int i = 0; i <= n; i++) {
            if (freq[i] == 0) missing.insert(i);
        }

        vector<int> ans;
        vector<int> seen(n + 1, 0);

        int i = 0;
        int tag = 1;

        while (i < n) {
            int mex = *missing.begin();

            if (mex == 0) {
                while (i < n) {
                    ans.push_back(0);
                    i++;
                }
                break;
            }

            ans.push_back(mex);

            int need = mex;
            int curTag = tag++;

            while (need > 0) {
                int x = nums[i];

                if (x <= n) {
                    freq[x]--;
                    if (freq[x] == 0) missing.insert(x);
                }

                if (x < mex && seen[x] != curTag) {
                    seen[x] = curTag;
                    need--;
                }

                i++;
            }
        }

        return ans;
    }
};