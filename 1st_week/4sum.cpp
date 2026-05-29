class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      int n=nums.size();
      sort(nums.begin(),nums.end());
      vector<vector<int>> out;
      for(int i=0;i<n-3;i++){
        if(i>0 && nums[i-1]==nums[i])
            continue;
        for(int j=i+1;j<n;j++){
            int l=j+1;
            int r=n-1;
            long long sum;
            if(j > i + 1 && nums[j] == nums[j-1])
             continue;
            while(l<r){
                sum=(long long )nums[i]+(long long)nums[j]+(long long)nums[l]+(long long)nums[r];
                if(sum>target)
                r--;
                else if(sum<target)
                l++;
                else{
                    out.push_back({nums[i],nums[j],nums[l],nums[r]});
                    while(l<r && nums[l+1]==nums[l]){
                        l++;
                    }
                    l++;
                    
                }
            }
        }
      }
      return out;  
    }
};