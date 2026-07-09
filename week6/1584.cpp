class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<bool> vis(n, false);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, 0});

        int cost = 0;
        int edgesUsed = 0;

        while(edgesUsed < n){

            auto [wt, node] = pq.top();
            pq.pop();

            if(vis[node])
                continue;

            vis[node] = true;
            cost += wt;
            edgesUsed++;

            for(int next = 0; next < n; next++){

                if(!vis[next]){

                    int dist =
                        abs(points[node][0] - points[next][0]) +
                        abs(points[node][1] - points[next][1]);

                    pq.push({dist, next});
                }
            }
        }

        return cost;
    }
};