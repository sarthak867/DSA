class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());
        for(int i =0 ; i<ast.size() ; i++){
            if(mass<ast[i]){
                return 0;
            }else if(mass>100000) return 1;
            else mass+= ast[i];
        }
        return 1;
    }
};