class Solution {
public:

    int binref(int n){
        string b ="";

        while(n>0){
            b += (n%2 + '0');  // store reversed already
            n/=2;
        }

        int result = 0;

        for(int i = 0; i < b.size(); i++){
            if(b[i] == '1')
                result += (1 << (b.size() - 1 - i));
        }

        return result;
    }

    vector<int> sortByReflection(vector<int>& nums) {

        vector<pair<int,int>> arr;

        for(int i : nums){
            arr.push_back({binref(i), i});
        }

        sort(arr.begin(), arr.end());

        nums.clear();

        for(auto [a,b] : arr){
            nums.push_back(b);
        }

        return nums;
    }
};