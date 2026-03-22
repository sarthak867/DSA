class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int se = INT_MAX, so = INT_MAX;
        for (int i : nums1) {
            if (i % 2 == 0) {
                if(i<se) se=i;
            } else {
                if(i<so) so =i;
            }
        }
        if (se == INT_MAX || so == INT_MAX)
            return true;
        if (se-so>0) return 1;
        return 0;
    }
};