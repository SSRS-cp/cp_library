struct lowest_common_ancestor{
    vector<int> p, sz, in, next;
    void dfs1(vector<vector<int>> &c, int v = 0){
        sz[v] = 1;
        for (int &w : c[v]){
            dfs1(c, w);
            sz[v] += sz[w];
            if (sz[w] > sz[c[v][0]]){
                swap(w, c[v][0]);
            }
        }
    }
    void dfs2(vector<vector<int>> &c, int &t, int v = 0){
        in[v] = t;
        t++;
        for (int w : c[v]){
            if (w == c[v][0]){
                next[w] = next[v];
            } else {
                next[w] = w;
            }
            dfs2(c, t, w);
        }
    }
    lowest_common_ancestor(vector<int> &p, vector<vector<int>> &c): p(p){
        int N = p.size();
        sz = vector<int>(N);
        dfs1(c);
        in = vector<int>(N);
        next = vector<int>(N, 0);
        int t = 0;
        dfs2(c, t);
    }
    int lca(int u, int v){
        while (1){
            if (in[u] > in[v]){
                swap(u, v);
            }
            if (next[u] == next[v]){
                return u;
            }
            v = p[next[v]];
        }
    }
};
