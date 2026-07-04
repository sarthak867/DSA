constexpr int N=1e5+1;
struct Edge{int v, w, nxt=-1;};
Edge E[N*2];// undirected
int eIdx=0;
int adj[N];
inline void addEdge(int u, int v, int w){
    E[eIdx]={v, w, adj[u]};
    adj[u]=eIdx++;
}
bitset<N> vis;
int q[N], front, back;
class Solution {
public:
    static void adjacent_ini(int n, vector<vector<int>>& roads){
        eIdx=0;
        memset(adj+1, -1, sizeof(int)*n);
        for (auto& path : roads) {
            const int u=path[0] , v=path[1], w=path[2];
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
    }

    static int minScore(int n, vector<vector<int>>& roads)
    {      
        adjacent_ini(n, roads);
        vis.reset();
        int dist=INT_MAX;
        front=back=0;
        q[back++]=1;// start from 1
        vis[1]=1;
        while (front<back){
            int u=q[front++];
            for(int idx=adj[u]; idx!=-1; idx=E[idx].nxt){
                const int v=E[idx].v, w=E[idx].w;
                dist=min(dist, w);
                if (vis[v]) continue;
                vis[v]=1;
                q[back++]=v;
            }
        }
        return dist;
    }
};