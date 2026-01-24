class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int max_len = 0, left = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // If we've seen the char and it's inside the current window
            if (last_seen.count(c) && last_seen[c] >= left) {
                left = last_seen[c] + 1;
            }

            last_seen[c] = right;
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};