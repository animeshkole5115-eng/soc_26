/*class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        for(i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            break;
        }
        if(i!=0)
           { 
            for(int j = nums.size()-1; j >= i; j--)
{
    if(nums[j] > nums[i-1])
    {
        swap(nums[j], nums[i-1]);
        break;
    }
}
     
       }
       int st=i;
       int end=nums.size()-1;
       while(st<end)
       {
            swap(nums[st],nums[end]);
            st++;
            end--;
       }
       
       }
};
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i+1]>nums[i])
            {
                swap(nums[nums.size()-1],nums[i]);
                i++;
                while(i<j)
                {
                    swap(nums[i],nums[j]);
                    i++;
                    j--;
                    
                }
                return;
            }
        

        }
        int i=0;
        while(i<j)
        {
           swap(nums[i],nums[j]);
                    i++;
                    j--;
                     
        }

    }
};