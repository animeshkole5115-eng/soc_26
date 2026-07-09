class DSU {
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){

        int px = find(x);
        int py = find(y);

        if(px == py)
            return;

        if(rank[px] < rank[py])
            parent[px] = py;

        else if(rank[px] > rank[py])
            parent[py] = px;

        else{
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DSU dsu(n);

        unordered_map<string, int> emailToAccount;

        // Union accounts sharing an email
        for(int i = 0; i < n; i++){

            for(int j = 1; j < accounts[i].size(); j++){

                string email = accounts[i][j];

                if(emailToAccount.count(email))
                    dsu.unite(i, emailToAccount[email]);

                else
                    emailToAccount[email] = i;
            }
        }

        unordered_map<int, vector<string>> groups;

        // Group emails by parent
        for(auto &entry : emailToAccount){

            string email = entry.first;
            int account = entry.second;

            int parent = dsu.find(account);

            groups[parent].push_back(email);
        }

        vector<vector<string>> ans;

        for(auto &group : groups){

            int parent = group.first;

            sort(group.second.begin(), group.second.end());

            vector<string> temp;

            temp.push_back(accounts[parent][0]);

            for(string &email : group.second)
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};