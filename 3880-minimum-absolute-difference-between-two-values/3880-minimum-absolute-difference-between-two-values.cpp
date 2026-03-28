class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int l1 =-1,l2=-1;
        int j=0;
        int ans =INT_MAX;
        for(int i :  nums){
            if(i==1){
                l1= j;
            }else if(i==2){
                l2=j;
            }
            if(l1!=-1 && l2!=-1){
                ans = min(ans,abs(l1-l2));
            }
            j++;
        }
        return (ans==INT_MAX)?-1:ans;
    }
};