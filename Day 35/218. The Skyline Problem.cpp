class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> nums;
        for (auto it : buildings)
        {
            nums.push_back({it[0], -it[2]});
            nums.push_back({it[1], it[2]});
        }

        sort(nums.begin(), nums.end());
        int prev = 0, curr = 0;

        multiset<int> hmap;
        vector<vector<int>> res;

        hmap.insert(0);
        for (auto it : nums)
        {
            if (it.second < 0)
            {
                hmap.insert(-it.second);
            }
            else
            {
                hmap.erase(hmap.find(it.second));
            }

            curr = *hmap.rbegin();

            if (curr != prev)
            {
                res.push_back({it.first, curr});
                prev = curr;
            }
        }
        return res;
    }
};