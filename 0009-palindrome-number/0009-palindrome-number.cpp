class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string str = to_string(x);
        string s = str;
        reverse(str.begin(), str.end());
        if(s == str) return true;
        return false;
    }
};