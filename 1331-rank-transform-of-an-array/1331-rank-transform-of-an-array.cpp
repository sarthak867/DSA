class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> d= arr;
        sort(d.begin(),d.end());
        unordered_map<int,int>mp;
        int r=1;
        for(int i=0;i<d.size();i++){
            if(mp.count(d[i])) continue;
            mp[d[i]]=r;
            r++;
        }
        for(int i =0 ; i<arr.size(); i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};