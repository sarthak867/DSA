class Solution {
public:
    string bin(int num, int n) {
        string res = "";

        for (int i = n - 1; i >= 0; i--) {
            res += ((num >> i) & 1) ? '1' : '0';
        }

        return res;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());
        int n =nums.size();
        for (int i = 0; i <n ; i++) {
            int d = stoi(nums[i], nullptr, 2);
            if (d != i) {
                return bin(i,n);
            }
        }
        return bin(n,n);
    }
};