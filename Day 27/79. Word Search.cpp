class Solution {
public:
    bool wordsearch(int i, int j, int &l, vector<vector<bool>> &vis, vector<vector<char>>& board, string word, int n, int m)
    {
        // Base-Case
        if(l == word.size())
        {
            return true;
        }

        // Pruning
        if(i >= n || j >= m || i < 0 || j < 0 || board[i][j] != word[l] || vis[i][j])
        {
            return false;
        }

        // Try out the four directions from (i, j)
        vis[i][j] = true;
        l++;

        if(wordsearch(i + 1, j, l, vis, board, word, n, m) == true)
        {
            return true;
        }
        

        if(wordsearch(i, j - 1, l, vis, board, word, n, m) == true)
        {
            return true;
        }
        
        if(wordsearch(i, j + 1, l, vis, board, word, n, m) == true)
        {
            return true;
        }
        
        if(wordsearch(i - 1, j, l, vis, board, word, n, m) == true)
        {
            return true;
        }

        l--;
        vis[i][j] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int l = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(wordsearch(i, j, l, vis, board, word, n, m) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};