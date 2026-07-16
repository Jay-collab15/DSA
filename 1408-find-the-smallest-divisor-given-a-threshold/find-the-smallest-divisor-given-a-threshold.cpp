class Solution {
public:
    // Jay
    bool possible(vector<int>& nums, int threshold, int num) {
        long long cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += (long long)ceil((double)nums[i] / num);
        }
        return cnt <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        int low = 1, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(nums, threshold, mid)) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};