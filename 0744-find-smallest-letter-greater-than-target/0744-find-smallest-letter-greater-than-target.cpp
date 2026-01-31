class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans ;
        bool exist = 0;
        for(char i : letters){
            if(i>target){
                ans = i;
                exist =1;
                break;
            }
        }
        if(exist) return ans;
        else return letters[0];
    }
};