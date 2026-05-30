class Solution {
public:
    int lengthOfLastWord(string s) {
        int l=s.size()-1;
        while(s[l]==' ') l--;
        int a =0;
        while(l>=0 && s[l--]!=' ')a++;
        return a;
    }
};