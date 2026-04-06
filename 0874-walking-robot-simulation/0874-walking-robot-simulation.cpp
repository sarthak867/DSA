#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
        // Direction vectors: North, East, South, West
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        // Use a hash set for fast obstacle lookup
        // We can map (x, y) to a single long long for the key: (x + 30000) << 16 | (y + 30000)
        std::unordered_set<long long> obsSet;
        for (const auto& obs : obstacles) {
            obsSet.insert(((long long)obs[0] + 30000) << 16 | ((long long)obs[1] + 30000));
        }

        int x = 0, y = 0, dir = 0; // dir 0: North, 1: East, 2: South, 3: West
        int maxDistSq = 0;

        for (int cmd : commands) {
            if (cmd == -2) { // Turn left
                dir = (dir + 3) % 4;
            } else if (cmd == -1) { // Turn right
                dir = (dir + 1) % 4;
            } else { // Move forward k units
                for (int i = 0; i < cmd; ++i) {
                    int nextX = x + dx[dir];
                    int nextY = y + dy[dir];
                    
                    // Check if the next position is an obstacle
                    if (obsSet.count(((long long)nextX + 30000) << 16 | ((long long)nextY + 30000))) {
                        break; // Stop at the obstacle
                    }
                    
                    x = nextX;
                    y = nextY;
                    maxDistSq = std::max(maxDistSq, x * x + y * y);
                }
            }
        }

        return maxDistSq;
    }
};