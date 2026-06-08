class Solution {
public:
    void fina(vector<int>& candidates, int target,int i ,vector<int> &ans,vector<vector<int>> &out){

        if(target<0){
            return;
        }
        if(target==0){
            out.push_back(ans);
            return;
        }
        for(int j=i;j<candidates.size();j++){
            
            ans.push_back(candidates[j]);
            fina(candidates,target-candidates[j],j,ans,out);
            ans.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> out;
        fina(candidates,target,0,ans,out);
        return out;
    }
};