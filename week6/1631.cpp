class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        effort[0][0] = 0;
        pq.push({0,{0,0}});

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!pq.empty()){

            auto curr = pq.top();
            pq.pop();

            int currEffort = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if(x == m-1 && y == n-1)
                return currEffort;

            if(currEffort > effort[x][y])
                continue;

            for(auto d : dir){

                int nx = x + d.first;
                int ny = y + d.second;

                if(nx>=0 && ny>=0 && nx<m && ny<n){

                    int edge =
                        abs(heights[nx][ny]-heights[x][y]);

                    int newEffort =
                        max(currEffort, edge);

                    if(newEffort < effort[nx][ny]){

                        effort[nx][ny] = newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }

        return 0;
    }
};