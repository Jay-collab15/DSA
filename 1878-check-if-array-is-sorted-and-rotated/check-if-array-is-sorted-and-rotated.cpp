class Solution {
public:
    //Jay
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])
            count++;
        }
        if(count ==1 && nums[0]>=nums[n-1])
        return true;
        if(count ==0)
        return true;
        return false;
    }
};