class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        int c = -1;
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto t = q.front();
                q.pop();

                for(auto &i: d)
                {
                    int newx = t.first + i.first;
                    int newy = t.second + i.second;
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 1)
                    {
                        grid[newx][newy] = 2;
                        q.push({newx, newy});
                        fresh--;
                    }
                }
            }

            c++;
        }

        if(fresh > 0)
        {
            return -1;
        }
        if(c == -1)
        {
            return 0;
        }

        return c;
    }
};