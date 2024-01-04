class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int n = nums.size();
        set<vector<int>> hset;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmpArr;
            int cnt = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] % p == 0)
                    cnt++;
                if (cnt > k)
                    break;
                tmpArr.push_back(nums[j]);
                hset.insert(tmpArr);
            }
        }
        return hset.size();
    }
};