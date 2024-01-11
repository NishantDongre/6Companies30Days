class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n, 1), prevInd(n, -1), res;
        int maxInd = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((nums[i] % nums[j] == 0) && (dp[i] < dp[j] + 1))
                {
                    dp[i] = dp[j] + 1;
                    prevInd[i] = j;
                }
            }
            maxInd = dp[i] > dp[maxInd] ? i : maxInd;
        }

        int i = maxInd;
        while (i >= 0)
        {
            res.push_back(nums[i]);
            i = prevInd[i];
        }

        return res;
    }
};