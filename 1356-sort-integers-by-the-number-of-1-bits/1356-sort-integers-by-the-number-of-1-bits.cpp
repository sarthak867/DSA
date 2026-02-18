class Solution {
public:
    vector<int> sortByBits(vector<int>& nums) {
        map<int, vector<int>> set;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int s = 0;
            while (n > 0) {
                if (n % 2 == 1)
                    s++;
                n /= 2;
            }
            set[s].push_back(nums[i]);
        }
        nums.clear();
        for (auto& vec : set) {
            vector<int> s = vec.second;
            sort(s.begin(), s.end());
            nums.insert(nums.end(),s.begin(),s.end());
        }
        return nums;
    }
};