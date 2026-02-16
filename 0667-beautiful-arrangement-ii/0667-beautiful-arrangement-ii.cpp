class Solution {
public:
    vector<int> constructArray(int n, int k) {
        
        unordered_map<int, int> invector; 
        vector<int> nums;
        
        nums.push_back(1);
        invector[1] = 1;
        
        int dup = k;        // sirf k gaps banane hain
        int gap = k;        // gap n-1 nahi, k se start hoga
        int ins = 1;
        
        while (dup > 0) {
            if (gap % 2 == k % 2)
                ins = ins + gap;
            else
                ins = ins - gap;
                
            nums.push_back(ins);
            invector[ins] = 1;
            
            gap--;
            dup--;
        }
        
        // baaki numbers increasing order me daal do
        for (int i = 2; i <= n; i++) {
            if (!invector.count(i))
                nums.push_back(i);
        }
        
        return nums;
    }
};
