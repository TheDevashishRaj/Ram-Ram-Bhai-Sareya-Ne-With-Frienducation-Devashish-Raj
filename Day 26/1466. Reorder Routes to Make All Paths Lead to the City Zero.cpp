class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> G;
        unordered_set<int> vis;
        int cnt = 0;
        
        for (auto& c : connections) {
            int u = c[0], v = c[1];
            G[u].push_back({v, 1});
            G[v].push_back({u, 0});
        }
        
        dfsrec(0, G, vis, cnt);
        return cnt;
    }
    
    void dfsrec(int u, unordered_map<int, vector<pair<int, int>>>& G, unordered_set<int>& vis, int& cnt) {
        vis.insert(u);
        for (auto& e : G[u]) {
            int v = e.first, w = e.second;
            if (vis.find(v) == vis.end()) {
                if (w == 1)
                {
                    cnt++;
                }
                dfsrec(v, G, vis, cnt);
            }
        }
    }
};