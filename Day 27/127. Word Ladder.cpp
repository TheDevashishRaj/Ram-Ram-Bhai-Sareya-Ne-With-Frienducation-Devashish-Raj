class Solution {
public:
    int diff(string &a, string &b)
    {
        int c = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i])
            {
                c++;
            }
        }

        return c;
    }

    void bfs(int start, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &bfsdist)
    {
        queue<int> q;
        q.push(start);
        vis[start] = true;

        int level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                int t = q.front();
                q.pop();

                bfsdist[t]++;
                for(auto &x: adj[t])
                {
                    if(!vis[x])
                    {
                        q.push(x);
                        vis[x] = true;
                        bfsdist[x] = level;
                    }
                }
            }
            level++;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        reverse(wordList.begin(), wordList.end());
        wordList.push_back(beginWord);
        reverse(wordList.begin(), wordList.end());

        int n = wordList.size();
        vector<vector<int>> adj(n);
        int s = 0, e = -1;
        for(int i = 1; i < n; i++)
        {
            if(wordList[i] == endWord)
            {
                e = i;
            }
        }

        if(e == -1)
        {
            return 0;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(diff(wordList[i], wordList[j]) == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            cout << i << ": ";
            for(auto &j: adj[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }

        vector<bool> vis(n, false);
        vector<int> bfsdist(n, -1);
        bfs(0, adj, vis, bfsdist);

        for(int i = 0; i < n; i++)
        {
            cout << bfsdist[i] << endl;
        }

        return (bfsdist[e] + 1);
    }
};