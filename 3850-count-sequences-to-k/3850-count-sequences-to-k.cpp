class Solution {
public:
    int rec(int idx, double curr, vector<int>& nums, long long k, map<pair<int, double>, int> &mp)
    {
        if(idx == nums.size())
        {
            double y = static_cast<double>(k);
            if(abs(curr-y) < 1e-9)
            {
                return 1;
            }  
            return 0;
        }
        if(mp.find({idx, curr}) != mp.end())
        {
            return mp[{idx, curr}];
        }    
        double t = nums[idx];
        int mul = rec(idx+1, curr*t, nums, k,mp);
        int div = rec(idx+1, curr/t, nums, k,mp);
        int leave = rec(idx+1, curr, nums, k,mp);
        return mp[{idx, curr}] = mul + div + leave;
    }
    int countSequences(vector<int>& nums, long long k) 
    {
        map<pair<int, double>, int> mp;
        return rec(0, 1.0, nums, k, mp);
        
    }
};