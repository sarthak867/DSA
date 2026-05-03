class Solution {
public:
    
    // decide nearest side
    int pickSide(int i, vector<int>& a) {
        int L = a[i] - a[i - 1];
        int R = a[i + 1] - a[i];
        if (L <= R) return i - 1;
        return i + 1;
    }

    // build nearest array
    void buildNearest(vector<int>& a, vector<int>& nearIdx) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                nearIdx[i] = 1;
            } else if (i == n - 1) {
                nearIdx[i] = n - 2;
            } else {
                nearIdx[i] = pickSide(i, a);
            }
        }
    }

    // build prefix for right movement
    void buildRight(vector<int>& a, vector<int>& nearIdx, vector<long long>& pref) {
        int n = a.size();
        for (int i = 1; i < n; i++) {
            long long add = a[i] - a[i - 1];
            if (nearIdx[i - 1] == i) add = 1;
            pref[i] = pref[i - 1] + add;
        }
    }

    // build prefix for left movement
    void buildLeft(vector<int>& a, vector<int>& nearIdx, vector<long long>& pref) {
        int n = a.size();
        for (int i = n - 2; i >= 0; i--) {
            long long add = a[i + 1] - a[i];
            if (nearIdx[i + 1] == i) add = 1;
            pref[i] = pref[i + 1] + add;
        }
    }

    int getAns(int l, int r, vector<long long>& pr, vector<long long>& pl) {
        if (l < r) return (int)(pr[r] - pr[l]);
        return (int)(pl[r] - pl[l]);
    }

    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> nearIdx(n);
        buildNearest(nums, nearIdx);

        vector<long long> prefR(n, 0), prefL(n, 0);

        buildRight(nums, nearIdx, prefR);
        buildLeft(nums, nearIdx, prefL);

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            ans.push_back(getAns(l, r, prefR, prefL));
        }

        return ans;
    }
};