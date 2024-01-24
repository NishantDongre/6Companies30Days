class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int size = nums[0].size();
        vector<int> res;
        for (int i = 0; i < queries.size(); i++)
        {

            vector<pair<string, int>> v;
            for (int j = 0; j < n; j++)
            {
                string strNum = nums[j].substr(size - queries[i][1]);
                v.push_back({strNum, j});
            }
            sort(v.begin(), v.end());
            int pRes = v[queries[i][0] - 1].second;
            res.push_back(pRes);
        }
        return res;
    }
};