class Solution {
public:
    void inc(string &s){
        for(int i =s.size()-1;i>=0; i--){
            if(s[i]=='1'){
                s[i]='0';
            }else{
                s[i]='1';
                return ;
            }
        }
        s= "1"+ s;
        return;
    }
    int numSteps(string s) {
        int n =0;
        while(s.length()>1){
            if(s.back()=='1'){
                inc(s);
                n++;
            }
            s.pop_back();
            n++;
        }
        return n;
    }
};