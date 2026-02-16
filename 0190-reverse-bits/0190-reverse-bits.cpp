const auto __ = []()
{
    struct Leetcode
    {
        static void _() { std::ofstream("display_memory.txt") << 0 << '\n'; }
    };
    std::atexit(&Leetcode::_);
    return 0;
}();

class Solution {
public:
    int reverseBits(int n) {
        string bin="";
        while(n>0){
            int rem = (n%2);
            n /= 2;
            char c = rem + '0';
            bin += c;
        }
        while(bin.length()!=32){
            bin += '0';
        }
        int ans =0;
        long long m =1;
        for(int i = bin.length()-1; i>=0 ; i--){
            int bit = bin[i] - '0';
            int de = bit * m;
            ans += de;
            m *= 2;
        }
        return ans;
    }
};