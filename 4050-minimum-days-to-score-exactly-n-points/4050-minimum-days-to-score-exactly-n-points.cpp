class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        
        // Dynamic programming to compute min days to reach total points
        for (int i = 0; i <= n; i++) {
            if (dp[i] == 1e9) continue;
            
            int sum = 0;
            for (int k = 1; i + sum + k <= n; k++) {
                sum += k;
                int next_score = i + sum;
                
                // If we reach exactly n, no need to add a reset day at the end
                int cost = dp[i] + k + (next_score == n ? 0 : 1);
                dp[next_score] = min(dp[next_score], cost);
            }
        }
        
        return dp[n];
    }
};