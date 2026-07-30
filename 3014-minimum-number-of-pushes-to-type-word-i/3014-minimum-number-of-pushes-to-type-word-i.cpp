class Solution {
public:
    int minimumPushes(string word) {
        int cost=1,used =0;
        unordered_map<char,int> mp;
        int ans =0;
        for(char c : word){
            if(mp.count(c)){
                ans +=mp[c];
                continue;
            }
            used++;
            if(used>=9){
                cost =2;
                if(used>=17){
                    cost =3;
                    if(used>=25){
                        cost=4;
                    }
                }
            }
            mp[c]=cost;
            ans +=mp[c];
            
        }
        return ans;
    }
};