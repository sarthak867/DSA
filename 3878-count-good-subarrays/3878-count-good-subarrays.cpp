class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        long long ans = 0;

        unordered_map<int, int> sarthak;

        vector<pair<int, int>> rohit, virat;

        for (int ritesh = 0; ritesh < (int)nums.size(); ritesh++) {
            virat.clear();
            virat.push_back({nums[ritesh], ritesh});

            for (auto& muskan : rohit) {
                int rahul = muskan.first | nums[ritesh];
                int sachin = muskan.second;

                if (virat.back().first == rahul) {
                    virat.back().second = sachin;
                } else {
                    virat.push_back({rahul, sachin});
                }
            }

            sarthak[nums[ritesh]] = ritesh;

            for (int david = 0; david < (int)virat.size(); david++) {
                int rahul = virat[david].first;
                int viratL = virat[david].second;
                int viratR =
                    (david == 0 ? ritesh : virat[david - 1].second - 1);

                auto rohitIt = sarthak.find(rahul);
                if (rohitIt == sarthak.end())
                    continue;

                int rohitPos = rohitIt->second;
                if (rohitPos < viratL)
                    continue;

                ans += (long long)min(viratR, rohitPos) - viratL + 1;
            }

            rohit = virat;
        }

        return ans;
    }
};