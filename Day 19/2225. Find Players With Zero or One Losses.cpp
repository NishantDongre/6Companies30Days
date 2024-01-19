class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        int n = matches.size();
        vector<int> win(1e5 + 1, 0), lose(1e5 + 1);

        for (int i = 0; i < n; i++)
        {
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }

        vector<vector<int>> res(2);
        for (int i = 1; i <= 1e5; i++)
        {
            if (lose[i] == 0 and win[i] > 0)
                res[0].push_back(i);
            if (lose[i] == 1)
                res[1].push_back(i);
        }
        return res;
    }
};