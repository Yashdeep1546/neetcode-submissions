class Solution {
   public:
    bool rec(int i, int j, int k, vector<vector<int>>& vis, string& word,
             vector<vector<char>>& board) {
                
        if (k == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j] == 1 ||
            word[k] != board[i][j]) {
            return false;
        }

        vis[i][j] = 1;
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int x = 0; x < 4; x++) {
            if (rec(i + dr[x], j + dc[x], k + 1, vis, word, board)) return true;
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
                if (rec(i, j, 0, vis, word, board)) return true;
            }
        }
        return false;
    }
};
