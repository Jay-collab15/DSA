class Solution {
public:
    //Jay
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int a;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.emplace_back(0);
                i--;
                n--; 
            }
        }
    }
};