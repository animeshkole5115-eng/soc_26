class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>out;
        vector<int> current=intervals[0];
        for(int i=1;i<n;i++){
            if(current[1]>=intervals[i][0]){
                current[1]=max(current[1],intervals[i][1]);
            }
            else{
                out.push_back(current);
                current=intervals[i];
            }
        }
        out.push_back(current);
        return out;
    }
};