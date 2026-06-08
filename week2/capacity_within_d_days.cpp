class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int mid = -1;
        for (int i = 0; i < n; i++) {
            sum += weights[i];
        }
        int st = 1;
        int end = sum;
        while (st <= end) {
            mid = st + (end - st) / 2;
            int mid2 = mid;
            int sum = 0;
            int hr = 0;
            for (int i = 0; i < n; i++) {
                mid2 = mid2 - weights[i];
                if (weights[i] > mid) hr = days+1;
                if (mid2 == 0) {
                    hr++;
                    mid2 = mid;
                    continue;
                }
                if (mid2 < 0) {
                    hr++;
                    mid2 = mid - weights[i];
                }
                if (i == n - 1 && mid2 < mid)
                    hr++;
            }
            if (hr <= days) {
                end = mid-1;
            } else
                st = mid + 1;

            
        }
        return st;
    }
};