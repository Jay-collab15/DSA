class Solution {
public:
    // Jay
    bool possible(vector<int>& nums, int k, int mid) {
        int sub = 1, last = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (last + nums[i] <= mid)
                last += nums[i];
            else {
                sub++;
                last = nums[i];
            }
        }
        return sub <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low = INT_MIN, high = 0;
        for (int i = 0; i < nums.size(); i++) {
            low = max(low, (long long)nums[i]);
            high += nums[i];
        }
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (possible(nums, k, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};