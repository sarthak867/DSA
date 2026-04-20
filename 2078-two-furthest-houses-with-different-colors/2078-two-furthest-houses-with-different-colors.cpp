class Solution {
public:
    int maxDistance(vector<int>& c) {
        int lst = c.size() - 1;
        if (c[0] != c[lst])
            return lst ;
        int s = 1, last = lst - 1;
        while (s<lst+1) {
            if (c[s] != c[lst] || c[0] != c[last]) {
                return last ;
            } else {
                s++;
                last--;
            }
        }
        return 0;
    }
};