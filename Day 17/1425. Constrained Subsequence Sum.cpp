class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        map<int, int> hmap;
        hmap[nums[n - 1]]++;
        dp[n - 1] = nums[n - 1];
        int res = nums[n - 1];
        int cnt = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = nums[i];
            dp[i] = max(dp[i], nums[i] + hmap.rbegin()->first);
            res = max(res, dp[i]);
            if (cnt < k)
            {
                hmap[dp[i]]++, cnt++;
            }
            else
            {
                int ele = dp[i + k];
                hmap[ele]--;
                if (hmap[ele] == 0)
                    hmap.erase(ele);
                hmap[dp[i]]++;
            }
        }
        return res;
    }
};