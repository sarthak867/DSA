class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target% gcd(x,y)!=0 || x+y<target) return 0;
        return 1;
    }
};