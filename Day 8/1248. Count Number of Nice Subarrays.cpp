class Solution
{
public:
    int subArray(vector<int> &nums, int k)
    {
        int count = 0, res = 0, start = 0, end = 0;
        int n = nums.size();
        while (end < n)
        {
            if (nums[end] % 2 == 1)
            {
                count++;
            }
            while (count > k)
            {
                if (nums[start] % 2 == 1)
                {
                    count--;
                }
                start++;
            }
            res += end - start + 1;
            end++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return subArray(nums, k) - subArray(nums, k - 1);
    }
};