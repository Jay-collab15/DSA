class Solution {
public:
    //Jay
    int maxProduct(vector<int>& nums) {
    int pre=1,suff=1;
    int ans=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        if(pre==0)pre=1;
        if(suff==0)suff=1;
        pre=pre*nums[i];
        suff=suff*nums[nums.size()-1-i];
        ans=max(ans,max(pre,suff));
    }
    return ans;
    }
};