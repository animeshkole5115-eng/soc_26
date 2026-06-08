class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=piles[0];
        for(int i=1;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int out=maxi;
        int st=1;
        int end=maxi;
        int mid=(st+end)/2;
        while(st<=end){
            long long hr=0;
            mid=(st+end)/2;
            for(int bananas:piles){
                hr+=(bananas+mid-1)/mid;
            }
            if(hr<=h){
                end=mid-1;
                out=mid;
            }
            if(hr>h){
                st=mid+1;
            }
        }
        return out;
    }
    
};