class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i: nums){
            s.insert(i);
        }
        int count=0;
        for(int num: s){
            if(!s.count(num - 1)){
                int curr=num;
                int cnt=1;
                while(s.count(curr + 1)){
                    cnt++;
                    curr++;
                }
                count=max(count,cnt);

            }
            

        }
        return count;
    }
};