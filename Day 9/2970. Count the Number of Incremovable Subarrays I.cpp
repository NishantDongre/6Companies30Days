class Solution
{
public:
    bool checkIncremovable(vector<int> &nums, unordered_set<int> &hset)
    {
        int n = nums.size();

        int currEle = -1;
        for (int i = 0; i < n; i++)
        {
            if (hset.find(i) == hset.end())
            {
                if (currEle >= nums[i])
                    return false;
                currEle = nums[i];
            }
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> hset;
            for (int j = i; j < n; j++)
            {
                hset.insert(j);
                if (checkIncremovable(nums, hset))
                {
                    res++;
                }
            }
        }
        return res;
    }
};