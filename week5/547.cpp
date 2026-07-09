class Solution {
public:

    void dfs(int city, vector<vector<int>>& isConnected,
             vector<bool>& vis){

        vis[city] = true;

        int n = isConnected.size();

        for(int next = 0; next < n; next++){

            if(isConnected[city][next] == 1 && !vis[next]){
                dfs(next, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<bool> vis(n, false);

        int provinces = 0;

        for(int i = 0; i < n; i++){

            if(!vis[i]){
                provinces++;
                dfs(i, isConnected, vis);
            }
        }

        return provinces;
    }
};