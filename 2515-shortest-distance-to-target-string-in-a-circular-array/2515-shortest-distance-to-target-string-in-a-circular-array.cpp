class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = words.size();
        if (words[start] == target) return 0;
        
        int left = start, right = start;
        int limit = n / 2; 

        for (int move = 1; move <= limit; ++move) {
            left = (left - 1 + n) % n;   
            right = (right + 1) % n;

            if (words[left] == target || words[right] == target) {
                return move;
            }
        }
        
        return -1;
    }
};