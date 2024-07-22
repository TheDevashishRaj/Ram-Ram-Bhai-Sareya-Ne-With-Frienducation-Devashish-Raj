class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int n = rooms.size();
        vector<bool> vis(n, false);
        q.push(0);
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            if(vis[t])
            {
                continue;
            }

            vis[t] = true;
            for(auto &i: rooms[t])
            {
                if(!vis[i])
                {
                    q.push(i);
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                return false;
            }
        }

        return true;
    }
};