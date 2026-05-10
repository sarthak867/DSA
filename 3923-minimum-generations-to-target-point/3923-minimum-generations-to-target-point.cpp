class Solution {
public:
    vector<int> cal(const vector<int> &v1, const vector<int> &v2) {
        return {
            (v1[0] + v2[0]) / 2,
            (v1[1] + v2[1]) / 2,
            (v1[2] + v2[2]) / 2
        };
    }
    
    int eval(set<vector<int>> &s, vector<int> target) {
        int ans = 0;
        
        while (!s.contains(target)) {
            auto temp = s;
            
            for (auto it1 = s.begin(); it1 != s.end(); it1++) {
                for (auto it2 = next(it1); it2 != s.end(); it2++) {
                    temp.insert(cal(*it1, *it2));
                }
            }

            if (temp == s) return -1;
            
            s = temp;
            ans++;
        }

        return ans;
    }
    
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        set<vector<int>> pts;

        for (auto &it : points) {
            pts.insert(it);
        }
        
        return eval(pts, target);
    }
};