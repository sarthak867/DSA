class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& f) {
        unordered_map<int,int> fr;
        for(int i : f){
            fr[i]++;
        }
        f.clear();
        for(int i : order){
            if(fr.count(i)) f.push_back(i);
        }
        return f;
    }
};