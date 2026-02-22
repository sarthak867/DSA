class Solution {
public:
    string maximumXor(string s, string t) {
        int num1 =0, num0 =0;
        for(char c : t){
            if(c=='1') num1++;
            else num0++;
        }
        string ans ="";
        for(char c : s){
            if(c=='1'){
                if(num0>0){
                    ans += '1';
                    num0--;
                }
                else{
                    ans+= '0';
                    num1--;
                }
            }else{
                if(num1>0){
                    ans += '1';
                    num1--;
                }else{
                    ans+='0';
                    num0--;
                }
            }
        }
        return ans;
    }
};