class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), l = 1;
        vector<pair<int, int>> a(n * n + 1);
        vector<int> cols(n);
        iota(cols.begin(), cols.end(), 0);
        for (int r = n - 1; r >= 0; r--)
        {
            for (int c : cols) {
                a[l++] = {r, c};
            }
            reverse(cols.begin(), cols.end());
        }
        vector<int> d(n*n+1, -1);
        d[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++)
            {
                auto [r, c] = a[next];
                int f = board[r][c] != -1 ? board[r][c] : next;
                if (d[f] == -1)
                {
                    d[f] = d[curr] + 1;
                    q.push(f);
                }
            }
        }

        return d[n * n];
    }
};