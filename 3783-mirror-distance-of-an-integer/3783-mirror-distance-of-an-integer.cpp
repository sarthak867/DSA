class Solution {
public:
    int mirrorDistance(int n) {
        if(n<10) return 0;
        string s = to_string(n);
        reverse(s.begin(),s.end());
        n = abs(n - stoi(s));
        return n;
    }
};