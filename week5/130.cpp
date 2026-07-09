class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& board, int m, int n){
        //base case
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] == 'X')
        return; 
        
        //mark visit
        board[i][j] = 'X';
        //top
        dfs(i-1, j, board, m, n);
        dfs(i, j+1, board, m, n);
        dfs(i+1, j, board, m, n);
        dfs(i, j-1, board, m, n);
        
    }

    void solve(vector<vector<char>>& board) {
        int cnt = 0;
        int m = board.size();
        int n = board[0].size();
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(board[i][j] == 'O'){
                    dfs(i, j, board, m, n);
 
                }
            }
        }
    }
};