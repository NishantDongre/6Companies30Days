class Solution
{
public:
    void util(vector<vector<int>> &res, vector<int> &ds, int start, int k, int target)
    {
        if (target == 0 and k == 0)
        {
            res.push_back(ds);
            return;
        }
        for (int i = start; i <= 10 - k and i <= target; i++)
        {
            ds.push_back(i);
            util(res, ds, i + 1, k - 1, target - i);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> ds;
        util(res, ds, 1, k, n);
        return res;
    }
};
