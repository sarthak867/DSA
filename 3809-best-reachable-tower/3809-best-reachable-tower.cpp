class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& tower, vector<int>& center,
                          int radius) {
        int maxq = -1;
        int cx = center[0];
        int cy = center[1];
        int tx = -1, ty = -1;
        for (int i = 0; i < tower.size(); i++) {
            int x = tower[i][0];
            int y = tower[i][1];
            int q = tower[i][2];
            if(abs(x-cx)+ abs(y-cy)<=radius){
                if(q>maxq || (q==maxq && (x<tx || (x==tx && y<ty)))){
                    tx =x;
                    ty =y;
                    maxq =q;
                }
            }
        }
        // for (int i = 0; i < tower.size(); i++) {
        //     int xi = tower[i][0];
        //     int yi = tower[i][1];
        //     int q = tower[i][2];
        //     int manhattan = abs(xi - ci) + abs(yi - cy);
        //     if (manhattan <= radius) {
        //         if (maxq < q) {
        //             maxq = q;
        //             ti = xi;
        //             ty = yi;
        //         } else if (maxq == q) {
        //             if (xi < ti || (xi == ti && yi < ty)) {
        //                 ti = xi;
        //                 ty = yi;
        //             }
        //         }
        //     }
        // }
        return {tx, ty};
    }
};