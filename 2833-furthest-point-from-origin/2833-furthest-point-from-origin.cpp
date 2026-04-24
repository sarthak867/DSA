class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int o=0,b=0;
        for (char c : moves) {
            if (c == 'L') o--;
            else if (c == 'R') o++;
            else b++;
        }

        return abs(o) + b;
    }
};