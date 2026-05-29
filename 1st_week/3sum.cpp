class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> out;
             for(int i=0;i<n-2;i++){

                if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
           
                int j=i+1;
                int k=n-1;
                int total;
                while(k>j){
                    total=nums[i]+nums[j]+nums[k];
                    if(total>0)
                    k--;
                    else if(total<0)
                    j++;
                    else{
                        out.push_back({nums[i],nums[j],nums[k]});
                        j++;
                          while (nums[j] == nums[j-1] && j < k) {
                         j++;}
                    }
                    }
                }

            
        return out;
    }
};