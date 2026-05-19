class Solution {
public:
    int countKthRoots(int l, int r, int k) {
         int s = ceil(pow(l, 1.0 / k) - 1e-12);
        int e = floor(pow(r, 1.0 / k) + 1e-12);
        return e-s+1;
    }
};