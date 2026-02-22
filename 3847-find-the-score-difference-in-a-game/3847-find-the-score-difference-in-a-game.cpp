class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int c = 1;
        bool act2 =0;
        bool act1 = 1;
        int sum1 =0, sum2=0;
        for(int i : nums){
            if(c==6){
                c=0;
                act2 = !act2;
                act1 = !act1;
            }
            if(i%2==1){
                act2 = !act2;
                act1 = !act1;
            }
            if(act1){
                sum1 += i;
            }else{
                sum2 += i;
            }
            c++;
        }
        return sum1- sum2;
    }
};