constexpr int N=1e5+1;
// union find class with rank
int Root[N], Rank[N];
class UnionFind {
public:
    UnionFind(int n){
        iota(Root, Root+n, 0);
        memset(Rank, 0, n*sizeof(int));
    }

    int Find(int x) {// compressed path
        return (x == Root[x])? x :Root[x]=Find(Root[x]);
    }

    bool Union(int x, int y) {
        x=Find(x), y=Find(y);
        if (x==y) return 0;
        if (Rank[x] > Rank[y]) swap(x, y);
        Root[x] = y;
        if (Rank[x] == Rank[y])
            Rank[y]++;
        return 1;
    }
    bool connected(int x, int y) { return Find(x) == Find(y); }
};
class Solution {
public:
    static int minScore(int n, vector<vector<int>>& roads)
    {      
        UnionFind G(n+1); // 1-indexed
        for (auto& path : roads) {
            const int a=path[0] , b=path[1], d=path[2];
            G.Union(a, b);
        }
        int dist=INT_MAX;
        for(auto& path : roads){
            const int a=path[0] , b=path[1], d=path[2];
            if (G.connected(1, a)) dist=min(dist, d);
        }
        return dist;
    }
};