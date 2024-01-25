class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();

        int res = 0;
        unordered_map<int, set<int>> hmap;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            hmap[nums[i]].insert(i);

            if (hmap[nums[i]].size() > k)
            {
                int ele = *hmap[nums[i]].begin();
                while (start <= ele)
                {
                    hmap[nums[start]].erase(start);
                    start++;
                }
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};