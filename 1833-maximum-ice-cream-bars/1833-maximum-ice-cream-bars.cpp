class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int c=0,i=0;
        for(int ice : costs ){
            c+=ice;
            if(c<=coins) i++;
            else return i;
        }
        return i;
    }
};