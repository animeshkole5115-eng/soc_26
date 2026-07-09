class Solution {
public:

    int m, n;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& image,
             int oldColor, int newColor){

        image[i][j] = newColor;

        for(auto d : dir){

            int ni = i + d.first;
            int nj = j + d.second;

            if(ni >= 0 && nj >= 0 &&
               ni < m && nj < n &&
               image[ni][nj] == oldColor){

                dfs(ni, nj, image, oldColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc,
                                  int color) {

        m = image.size();
        n = image[0].size();

        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        dfs(sr, sc, image, oldColor, color);

        return image;
    }
};