class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto &flight : flights){
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int,int>> q; // {node, cost}

        q.push({src, 0});
        dist[src] = 0;

        int stops = 0;

        while(!q.empty() && stops <= k){

            int size = q.size();

            while(size--){

                auto [node, cost] = q.front();
                q.pop();

                for(auto [next, price] : graph[node]){

                    if(cost + price < dist[next]){

                        dist[next] = cost + price;
                        q.push({next, dist[next]});
                    }
                }
            }

            stops++;
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};