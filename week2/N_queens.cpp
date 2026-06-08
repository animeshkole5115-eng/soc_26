class Solution {
public:

  bool ispossible(vector<string> &ans,int index,int i,int n){

    // column
    for(int j=0;j<index;j++){
        if(ans[j][i]=='Q')
            return false;
    }

    // upper-left diagonal
    for(int j=i-1,k=index-1; j>=0 && k>=0; j--,k--){
        if(ans[k][j]=='Q')
            return false;
    }

    // upper-right diagonal
    for(int j=i+1,k=index-1; j<n && k>=0; j++,k--){
        if(ans[k][j]=='Q')
            return false;
    }

    return true;
}

    void nqueens(int n,vector<string>& ans,int index,vector<vector<string>> &out){

        if(index==n){
            out.push_back(ans);
            return;
        }
        for(int i=0;i<n;i++){
            if(ispossible(ans,index,i,n)){
                ans[index][i]='Q';
                nqueens(n,ans,index+1,out);
                ans[index][i]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> ans(n,string(n,'.'));
        vector<vector<string>>out;

        nqueens(n,ans,0,out);
        return out;
    }
};