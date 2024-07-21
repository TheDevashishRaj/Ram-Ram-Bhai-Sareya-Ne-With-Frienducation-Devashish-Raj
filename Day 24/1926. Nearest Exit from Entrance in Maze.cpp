class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int c = 0;
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto t = q.front();
                q.pop();

                if(t.first == 0 || t.second == 0 || t.first == n - 1 || t.second == m - 1)
                {
                    if(t.first != entrance[0] || t.second != entrance[1])
                    {
                        return c;
                    }
                }

                for(auto &i: d)
                {
                    int newx = t.first + i.first;
                    int newy = t.second + i.second;
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && maze[newx][newy] != '+')
                    {
                        maze[newx][newy] = '+';
                        q.push({newx, newy});
                    }
                }
            }

            c++;
        }

        return -1;
    }
};