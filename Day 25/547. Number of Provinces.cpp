class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        queue<int> q;
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int c = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                q.push(i);
                while(!q.empty())
                {
                    int t = q.front();
                    q.pop();
                    if(vis[t])
                    {
                        continue;
                    }

                    vis[t] = true;
                    for(int j = 0; j < n; j++)
                    {
                        if(isConnected[t][j] && !vis[j])
                        {
                            q.push(j);
                        }
                    }
                }

                c++;
            }
        }

        return c;        
    }
};