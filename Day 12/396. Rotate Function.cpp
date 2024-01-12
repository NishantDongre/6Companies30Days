class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = 0;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            res += i * nums[i];
            totalSum += nums[i];
        }

        int curr = res;
        for (int i = n - 1; i >= 0; i--)
        {
            curr = curr - (nums[i] * (n - 1)) + (totalSum - nums[i]);
            res = max(res, curr);
        }

        return res;
    }
};