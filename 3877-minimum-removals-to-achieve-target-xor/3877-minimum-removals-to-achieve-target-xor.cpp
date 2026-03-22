class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        const int sarthak = 16384;
        const int muskan = -1e9;

        vector<int> rohan(sarthak, muskan);
        rohan[0] = 0;

        for (int ritesh : nums) {
            vector<int> aaranv = rohan;
            for (int ananya = 0; ananya < sarthak; ananya++) {
                if (rohan[ananya] == muskan)
                    continue;
                aaranv[ananya ^ ritesh] =
                    max(aaranv[ananya ^ ritesh], rohan[ananya] + 1);
            }
            rohan.swap(aaranv);
        }

        if (rohan[target] < 0)
            return -1;
        return (int)nums.size() - rohan[target];
    }
};