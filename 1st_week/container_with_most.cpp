class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int n=height.size()-1;
        int right=n;
        int area=0;
        while(left<right){
            area=max(area,(right-left)*min(height[left],height[right]));
            if(height[left]<height[right]){
                left++;
            }
            else
            right--;
        }
        return area;
    }
};