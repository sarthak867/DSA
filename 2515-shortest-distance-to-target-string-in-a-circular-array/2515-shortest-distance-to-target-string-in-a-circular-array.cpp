class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        if(words[start]==target) return 0;
        int vectorsize = words.size();
        int maxmoves = vectorsize/2;
        int move =0;
        int left = start ,right = start ;
        while(move<=maxmoves){
            move++;
            left --;
            right++;
            if(left<0) left = vectorsize-1;
            if(right>=vectorsize) right =0;
            if(words[left]== target || words[right]==target) return move;
        }
        return -1;
    }
};