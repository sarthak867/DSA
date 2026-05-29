class Solution {
public:
    int cal(int n) {
        int s = 0;
        while (n) {
            int r = n % 10;
            s += r;
            n /= 10;
        }
        return s;
    }

    int minElement(vector<int>& nums) {
        int ans =INT_MAX;
        for (int i : nums) {
            int c = cal(i);
            if(c==1){
                return c;
            }
            if(c<ans) ans =c;
        }
        return ans;
    }
};