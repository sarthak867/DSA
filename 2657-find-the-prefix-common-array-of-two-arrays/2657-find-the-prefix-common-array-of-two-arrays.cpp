class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int> nums(a.size()+ 1,0), ans;
        vector <int> nums2 = nums;
        int c =0;
        for(int i= 0 ; i<a.size(); i++){
            if(a[i]==b[i]) {
                c++;
                ans.push_back(c);
                continue;
            }
            nums[a[i]] =1;
            nums2[b[i]] = 1;
            if(nums[a[i]]== nums2[a[i]]){
                c++;
            }
            if(nums[b[i]]== nums2[b[i]]){
                c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};