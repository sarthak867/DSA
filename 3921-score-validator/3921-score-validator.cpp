class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int sc=0, c=0;
        for(string s : events){
            if(s=="W") c++;
            else if(s=="WD" || s=="NB") sc++;
            
            else {
                int t= stoi(s);
                sc+= t;
            }
            if(c==10) break;
        }
        return {sc,c};
    }
};