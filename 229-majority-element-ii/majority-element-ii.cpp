class Solution {
public:
    //Jay
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>hash;
        int n=nums.size();
        vector<int>store;
        for(int i=0;i<n;i++)
        {
          hash[nums[i]]++;
        }
        for(auto it:hash)
        {
            if(it.second>(n/3))
                store.push_back(it.first);
        }
        return store;
    }
};