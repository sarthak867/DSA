class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans ="";
        for(string s : words){
            int sum =0;
            for(char c : s){
                int ind = c - 'a' ;
                sum = (sum + weights[ind])%26;
            }
            sum = 26 - sum;
            char ch = 'a' + sum -1;
            ans += ch;
        }
        return ans;
    }
};