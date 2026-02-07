class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0, b = 0;

        for (auto& c : s) {
            if (c=='b') b++;
            else if (b) {
                res++;
                b--;
            }
        }

        return res;
    }
};
