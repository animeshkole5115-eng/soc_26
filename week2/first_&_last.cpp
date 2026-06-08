class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st=0;
        int end=nums.size()-1;
        int mid=(st+end)/2;
        vector<int> ans={-1,-1};
        while(st<=end){
            mid=(st+end)/2;
            if(nums[mid]==target){
            ans[0]=mid;
            end=mid-1;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
            
        }
      
         st=0;
         end=nums.size()-1;
         mid=(st+end)/2;
        while(st<=end){
            mid=(st+end)/2;
            if(nums[mid]==target){
            ans[1]=mid;
            st=mid+1;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
            
        }
  
        return ans;
    }
};