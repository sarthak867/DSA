// const auto __ = []()
// {
//     struct Leetcode
//     {
//         static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
//     };
//     std::atexit(&Leetcode::_);
//     return 0;
// }();

class Solution {
public:
    int bestClosingTime(string customers) {
        int c1 =0 , c2=0; 
        for(char c : customers){
            (c=='Y')?c1++:c2++;
        }
        int pan = c1;
        int time = 0;
        for(int i =0 ; i<customers.size(); i++){
            if(customers[i]=='Y') c1--;
            else c1++;
            if(c1<pan){
                pan = c1;
                time = i+1;
            }
        }
        return time;
    }
};