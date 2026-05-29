class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> first(1, 1);
        ans.push_back(first);

        for (int i = 1; i < numRows; i++) {
            vector<int> curr(i+1, 1);
            for (int j = 0; j < i - 1; j++) {
                curr[j+1] = ans[i-1][j] + ans[i-1][j+1];
            }
            ans.push_back(curr);

        }

        return ans;
        
    }
};