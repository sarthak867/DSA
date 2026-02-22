class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        bool zero =0,p=1;
        vector<int> neg;
        long long ans = 1;
        for (int i : nums) {
            if (i == 0){
                zero = 1;
                continue;
            }
            if (i > 0) {
                ans *= i;
                p=0;
                continue;
            }
            else neg.push_back(i);
        }
        if(ans ==1 && zero &&p&& neg.size()<=1) return 0;
        sort(neg.begin(),neg.end());
        while(neg.size()>1){
            ans*= abs(neg[0])*abs(neg[1]);
            neg.erase(neg.begin());
            neg.erase(neg.begin());
        }
        return ans;
    }
};