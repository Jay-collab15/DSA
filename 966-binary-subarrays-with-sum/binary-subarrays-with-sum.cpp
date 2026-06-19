class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    int prev=0,cnt=0;
    map<int,int>mp;
    mp[0]=1;
    for(int i=0;i<nums.size();i++)
    {
        prev+=nums[i];
        int remove=prev-goal;
        cnt+=mp[remove];
        mp[prev]++;
    }
    return cnt;
    }
};