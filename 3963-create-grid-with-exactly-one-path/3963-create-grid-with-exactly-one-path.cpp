class Solution {
public:
    vector<string> createGrid(int n, int m) {
        
        vector <string> ans;
        for(int i = 0; i<n; i++){
            if(i==0){
               string s(m,'.'); 
               ans.push_back(s);
            }else{
                string s(m-1,'#');
                s+='.';
                ans.push_back(s);
            }
        }
        return ans;
    }
};