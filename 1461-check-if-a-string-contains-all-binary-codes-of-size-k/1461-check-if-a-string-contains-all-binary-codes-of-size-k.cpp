class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.length()) return false;

        unordered_set<string> st;
        int total = 1 << k;

        for (int i = 0; i <= s.size() - k; i++) {
            st.insert(s.substr(i, k));
        }

        return st.size() == total;
    }
};