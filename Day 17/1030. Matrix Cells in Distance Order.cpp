class Solution
{
public:
    bool static cmp(const vector<int> &a, const vector<int> &b, int rCenter, int cCenter)
    {
        return abs(a[0] - rCenter) + abs(a[1] - cCenter) < abs(b[0] - rCenter) + abs(b[1] - cCenter);
    }
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        vector<vector<int>> res;

        int cnt = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res.push_back({i, j});
                cnt++;
            }
        }

        sort(res.begin(), res.end(), [&rCenter, &cCenter](const auto &a, const auto &b)
             { return cmp(a, b, rCenter, cCenter); });
        return res;
    }
};