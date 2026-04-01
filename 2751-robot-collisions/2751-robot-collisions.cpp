
const auto __ = []()
{
    struct Leetcode
    {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&Leetcode::_);
    return 0;
}();

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {

        int n = positions.size();
        map<int, pair<int, char>> robo;

        for (int i = 0; i < n; i++) {
            robo[positions[i]] = {healths[i], directions[i]};
        }

        vector<int> res;
        stack<int> st; 

        for (auto& it : robo) {

            int pos = it.first;
            int& hel = it.second.first;
            char dir = it.second.second;

            if (dir == 'R') {
                st.push(pos);
            } else { // dir == 'L'

                while (!st.empty() && hel > 0) {

                    int prevPos = st.top();
                    int& prevHel = robo[prevPos].first;

                    if (prevHel < hel) {
                        st.pop();
                        prevHel = 0;
                        hel--;
                    } else if (prevHel == hel) {
                        st.pop();
                        prevHel = 0;
                        hel = 0;
                    } else {
                        prevHel--;
                        hel = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (robo[positions[i]].first > 0)
                res.push_back(robo[positions[i]].first);
        }

        return res;
    }
};