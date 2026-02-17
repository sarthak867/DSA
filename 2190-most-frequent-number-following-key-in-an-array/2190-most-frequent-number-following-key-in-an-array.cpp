class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> freq;
        int lst = -1,ans =0;
        int maxf = INT_MIN;
        for (int i : nums) {
            if(lst == key){
                freq[i]++;
                if (freq[i] > maxf){
                    maxf = freq[i];
                    ans =i;
                }
            }
            lst = i;

        }
        return ans;
    }
};