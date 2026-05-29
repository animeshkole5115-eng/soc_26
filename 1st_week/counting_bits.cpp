class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> out;
        for(int i=0;i<=n;i++){
            int cnt=0;
            int j=i;
            while(j!=0){
                cnt+=j%2;
                j=j/2;
            }
            out.push_back(cnt);
        }
        return out;
    }
};