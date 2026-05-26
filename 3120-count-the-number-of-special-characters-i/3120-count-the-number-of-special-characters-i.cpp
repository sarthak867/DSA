class Solution {
public:
    int numberOfSpecialChars(string word) {
        int diff = 'a'-'A';
        vector <int> mp(52,0);
        for(char c : word){
            if(c>='a'&& c<='z'){
                int ind = c-'a';
                mp[ind]=1;
            }else{
                int ind = c-'A'+26;
                mp[ind] =1;
            }
        }
        int c=0;
        for(int i =0 ; i<26; i++){
            if(mp[i] && mp[i+26]) c++;
        }
        return c;
    }
};