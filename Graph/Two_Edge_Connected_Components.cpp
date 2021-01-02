struct two_edge_connected_components{
    vector<bool> used;
    vector<int> ord, low, tcc;
    int t, cnt;
    void dfs1(vector<vector<int>> &E, int v, int p){
        used[v] = true;
        ord[v] = t;
        low[v] = t;
        t++;
        bool p_used = false;
        for (int w : E[v]){
            if (p == w && !p_used){
                p_used = true;
                continue;
            }
            if (!used[w]){
                dfs1(E, w, v);
                low[v] = min(low[v], low[w]);
            } else {
                low[v] = min(low[v], ord[w]);
            }
        }
    }
    void dfs2(vector<vector<int>> &E, int v, int p){
        if (p >= 0 && ord[p] >= low[v]){
            tcc[v] = tcc[p];
        } else {
            tcc[v] = cnt;
            cnt++;
        }
        for (int w : E[v]){
            if (tcc[w] == -1){
                dfs2(E, w, v);
            }
        }
    }
    two_edge_connected_components(vector<vector<int>> &E){
        int N = E.size();
        used = vector<bool>(N, false);
        ord = vector<int>(N, 0);
        low = vector<int>(N, 0);
        t = 0;
        for (int i = 0; i < N; i++){
            if (!used[i]){
                dfs1(E, i, -1);
            }
        }
        tcc = vector<int>(N, -1);
        cnt = 0;
        for (int i = 0; i < N; i++){
            if (tcc[i] == -1){
                dfs2(E, i, -1);
            }
        }
    }
    int operator [](int k){
        return tcc[k];
    }
    int size(){
        return cnt;
    }
};
