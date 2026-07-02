class Solution {
public:
    //Jay
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
                for(int l=i+1;l<n;l++){
                    if (l !=i+1 && nums[l] == nums[l - 1])
                continue;
            int j = l + 1;
            int k = n - 1;
            while (j < k) {
                long long  sum = nums[i] + nums[l] ;
                sum+= nums[k];
                sum+=nums[j];
                if (sum > target)
                    k--;
                else if (sum < target)
                    j++;
                else {
                    vector<int> t = {nums[i], nums[j], nums[k],nums[l]};
                    ans.push_back(t);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
                }
        }
        return ans;
    }
};