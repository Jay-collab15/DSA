class Solution {
public:
    // Jay
    bool possible(vector<int>& weights, int days, int weight) {
        int cnt = 0, day = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (cnt + weights[i] > weight) {
                day = day + 1;
                cnt = weights[i];
            } else {
                cnt += weights[i];
            }
        }
        return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN, high = 0;
        for (int i = 0; i < weights.size(); i++) {
            low = max(low, weights[i]);
            high = high + weights[i];
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(weights, days, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};