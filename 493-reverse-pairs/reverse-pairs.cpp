class Solution {
public:
    //Jay
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid)
            temp.push_back(arr[left++]);
        while (right <= high)
            temp.push_back(arr[right++]);
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }
    int countpairs(vector<int>& arr, int low, int mid, int high) {
        int c = 0, right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)arr[i] > 2LL * arr[right])
                right++;
            c += right - (mid + 1);
        }
        return c;
    }
    int mergeSort(vector<int>& arr, int low, int high) {
        int c = 0;
        if (low >= high)
            return c;
        int mid = (low + high) / 2;
        c += mergeSort(arr, low, mid);
        c += mergeSort(arr, mid + 1, high);
        c += countpairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return c;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};