class Solution {
public:
    int numOfStrings(vector<string>& patt, string word) {
        unordered_map<string,int> mp;
        int sz =word.length();
        for(int i =0 ; i<sz ; i++){
            string s="";
            for(int j=i;j<sz;j++){
                s+=word[j];
                mp[s]++;
            }
        }
        int ans=0;
        for(string s: patt ){
            if(mp.count(s)) ans++;
        }
        return ans;
    }
};