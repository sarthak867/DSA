class Solution {
public:
    int minPartitions(string n) {
        char m = '0';
        for(char c : n){
            m = max(c,m);
        }
        return m-'0';
    }
};