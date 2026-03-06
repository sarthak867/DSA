class Solution {
public:
    bool checkOnesSegment(string s) {
        bool fo= 0, zaf =0;
        for(char i : s){
            if(i=='1'){
                if(fo ==0) fo=1;
                else if(zaf ==1 ) return false;
            }else{
                if(fo==1) zaf =1;
            }
        }
        return true;
    }
};