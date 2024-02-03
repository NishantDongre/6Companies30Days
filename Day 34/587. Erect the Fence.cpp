class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0] or (a[0] == b[0] and a[1] < b[1]);
    }

    int orientation(vector<int> &p, vector<int> &q, vector<int> &r)
    {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<vector<int>> ans;
        sort(points.begin(), points.end(), cmp);

        for (int i = 0; i < n; i++)
        {
            while (ans.size() > 1 and orientation(ans[ans.size() - 2], ans.back(), points[i]) < 0)
            {
                ans.pop_back();
            }
            ans.push_back(points[i]);
        }

        if (ans.size() == n)
            return ans;

        for (int i = n - 2; i >= 0; i--)
        {
            while (ans.size() > 1 and orientation(ans[ans.size() - 2], ans.back(), points[i]) < 0)
            {
                ans.pop_back();
            }
            ans.push_back(points[i]);
        }

        ans.pop_back();
        return ans;
    }
};