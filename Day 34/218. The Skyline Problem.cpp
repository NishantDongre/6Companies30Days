class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> h;

        for (auto b : buildings)
        {
            h.push_back({b[0], -b[2]});
            h.push_back({b[1], b[2]});
        }

        sort(h.begin(), h.end());
        int prev = 0, cur = 0;

        multiset<int> m;
        vector<vector<int>> res;

        m.insert(0);
        for (auto it : h)
        {

            if (it.second < 0)
            {
                m.insert(-it.second);
            }
            else
            {
                m.erase(m.find(it.second));
            }

            cur = *m.rbegin();

            if (cur != prev)
            {
                res.push_back({it.first, cur});
                prev = cur;
            }
        }
        return res;
    }
};