class Solution {
public:

    string addBinary(string a, string b) {
        int s1 = a.size()-1;
        int s2 = b.size()-1;
        string ans ="";
        int c=0;
        while(s1>=0 && s2>=0){
            if(a[s1]=='1'&& b[s2]=='1'){
                if(c){
                    ans+='1';
                }else{
                    ans+='0';
                }
                c=1;
            }else if(a[s1]=='0' && b[s2]=='0'){
                if(c){
                    ans += '1';
                    c=0;
                }else ans +='0';
            }
            else{
                if(c){
                    ans +='0';
                }else ans +='1';
            }
            s1--;
            s2--;
        }
        while(s1>=0){
            if(c){
                if(a[s1]=='1'){
                    ans += '0';
                }else{
                    ans+= '1';
                    c=0;
                }
            }else ans+= a[s1];
            s1--;

        }
        while(s2>=0){
            if(c){
                if(b[s2]=='1'){
                    ans += '0';
                }else{
                    ans+= '1';
                    c=0;
                }
            }else ans+= b[s2];
            s2--;
        }
        if(c){
            ans += '1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};