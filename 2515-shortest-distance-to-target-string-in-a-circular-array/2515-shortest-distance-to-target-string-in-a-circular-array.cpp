class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        if(words[start]==target) return 0;
        
        int move =0;
        int left = start ,right = start ;
        while(move<=words.size()/2){
            move++;
            left --;
            right++;
            if(left<0) left = words.size()-1;
            else if(right>=words.size()) right =0;
            if(words[left]== target || words[right]==target) return move;
        }
        return -1;
    }
};