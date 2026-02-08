class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque <int> mx, mn;
        long long ans = 0;
        int l =0 ;
        for(int i = 0 ; i< nums.size(); i++){
            while(!mx.empty()&& nums[mx.back()]<= nums[i]) mx.pop_back();
            mx.push_back(i);

            while(!mn.empty()&& nums[mn.back()]>= nums[i]) mn.pop_back();
            mn.push_back(i);

            while(!mx.empty() && !mn.empty() && (long long)(nums[mx.front()]- nums[mn.front()] ) * (i-l+1) >k){
                if(mx.front()==l) mx.pop_front();
                if(mn.front()==l) mn.pop_front();
                l++;
            }
            ans += (i - l +1); 
        }
        return ans;
    }
};