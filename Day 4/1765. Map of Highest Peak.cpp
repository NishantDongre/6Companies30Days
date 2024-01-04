class Solution
{
public:
    bool isValidCell(int row, int col, int m, int n)
    {
        if (row >= 0 and row < m and col >= 0 and col < n)
            return true;
        return false;
    }
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }

        int step = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                int row = node.first;
                int col = node.second;

                int dr[4] = {0, -1, 0, 1};
                int dc[4] = {-1, 0, 1, 0};

                for (int k = 0; k < 4; k++)
                {
                    int newRow = row + dr[k];
                    int newCol = col + dc[k];

                    if (isValidCell(newRow, newCol, m, n) and res[newRow][newCol] == -1)
                    {
                        res[newRow][newCol] = step;
                        q.push({newRow, newCol});
                    }
                }
            }
            step++;
        }
        return res;
    }
};