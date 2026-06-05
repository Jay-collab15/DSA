class Solution {
public:
    void solve(int ind,vector<int>& nums,vector<int>&store,vector<vector<int>>&ans,int n)
    {
        if(ind==n){
            ans.push_back(store);
            return;
        }
        solve(ind+1,nums,store,ans,n);
        store.push_back(nums[ind]);
        solve(ind + 1, nums, store, ans, n);
        store.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n=nums.size();
    vector<int>store;
    solve(0,nums,store,ans,n);
    return ans;
    }
};