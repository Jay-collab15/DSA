class Solution {
public:
    // Jay
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int min = INT_MAX, ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int rem = abs(target - sum);
                if (min > rem) {
                    min = rem;
                    ans = sum;
                }
                if (sum == target) 
                    return sum;
                if (sum < target) 
                    j++;
                else 
                    k--;
            }
        }
        return ans;
    }
};