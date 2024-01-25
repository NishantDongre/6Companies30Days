class Solution
{
public:
    bool binarySearch(vector<int> &nums, int target, int d)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (abs(nums[mid] - target) <= d)
            {
                return false;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return true;
    }

    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int res = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            int ele = arr1[i];
            if (binarySearch(arr2, ele, d))
            {
                res++;
            }
        }
        return res;
    }
};