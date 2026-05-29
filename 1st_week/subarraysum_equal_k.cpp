class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.count(sum-k)){
                cnt+=mp[sum-k];
            }

            if(mp[sum]!=0){
                mp[sum]+=1;
            }
            
            else{
                mp[sum]=1;
            }
            

        }
        return cnt;
    }
};