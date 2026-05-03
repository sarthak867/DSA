class Solution {
    
    struct FT {
        vector<int> t;

        FT(int n){
            t.resize(n+3);
            for(int i=0;i<t.size();i++) t[i]=0;
        }

        void upd(int i,int v){
            i++;
            while(i<t.size()){
                if(t[i]<v) t[i]=v;
                i += (i & -i);
            }
        }

        int get(int i){
            i++;
            int r=0;
            while(i>0){
                if(t[i]>r) r=t[i];
                i -= (i & -i);
            }
            return r;
        }
    };

public:
    int maxFixedPoints(vector<int>& nums) {
        
        int n = nums.size();

        vector<pair<int,int>> ok;

        for(int i=0;i<n;i++){
            if(nums[i]<=i){
                ok.push_back({nums[i], i-nums[i]});
            }
        }

        sort(ok.begin(), ok.end());

        FT f(n);

        int ans=0;

        int i=0;

        while(i<ok.size()){

            int val = ok[i].first;

            vector<pair<int,int>> tmp;

            while(i<ok.size() && ok[i].first==val){

                int g = ok[i].second;

                int best = f.get(g);

                int cur = best + 1;

                tmp.push_back({g,cur});

                if(cur>ans) ans=cur;

                i++;
            }

            for(int j=0;j<tmp.size();j++){
                f.upd(tmp[j].first , tmp[j].second);
            }
        }

        return ans;
    }
};