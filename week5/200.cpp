class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& trac, int m, int n){

        if(i<0 || j<0 || i>=m || j>=n || trac[i][j] || grid[i][j] =='0')
        return;

        trac[i][j] = true;
        // top 
        dfs(i-1, j, grid, trac, m, n);
        // right
        dfs(i, j+1, grid, trac, m, n);
        //bottom
        dfs(i+1, j, grid, trac, m, n);
        //left
        dfs(i, j-1, grid, trac, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> trac(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!trac[i][j] && grid[i][j] == '1'){
                    dfs(i, j, grid, trac, m, n);
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};