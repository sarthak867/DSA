class Solution {
public:
    void solve(int n, string curr, vector<string>& v){
        if(curr.size() == n){
            v.push_back(curr);
            return;
        }

        for(char c : {'a','b','c'}){
            if(curr.empty() || curr.back() != c){
                solve(n, curr + c, v);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> v;
        solve(n, "", v);

        if(k > v.size()) return "";
        return v[k-1];
    }
};