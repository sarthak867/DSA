class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int f =0;
        int e=0;
        for(char c : moves){
            if(c=='L') f--;
            else if(c=='R') f++;
            else e++;
        }
        return abs(f) +e;
    }
};