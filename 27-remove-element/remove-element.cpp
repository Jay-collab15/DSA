class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
     int k=0,n=nums.size();
     for(int i=0;i<n;i++)   
     {
        if(nums[i]!=val)
            k++;
        else
        {
            for(int j=i;j<n-1;j++)
                nums[j]=nums[j+1];
            n--;
            i--;
        }
     }
     return k;
    }
};