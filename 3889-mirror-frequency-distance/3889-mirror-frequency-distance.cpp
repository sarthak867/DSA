class Solution {
public:
    long long mirrorFrequency(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        long long tot = 0;
        unordered_set<char> visited;

        for (auto const& [a, countA] : freq) {
            if (visited.count(a)) continue;

            char rev;
            if (a >= 'a' && a <= 'z') {
                rev = 'z' - (a - 'a');
            } else {
                rev = '9' - (a - '0');
            }

            int countRev = freq.count(rev) ? freq[rev] : 0;
            
            // Calculate absolute difference
            tot += abs(countA - countRev);

            visited.insert(a);
            visited.insert(rev);
        }

        return tot;
    }
};