class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1};
                int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

                int cntNeighborsCells = 1;
                int totalNeighborsCells = img[row][col];
                for (int k = 0; k < 8; k++)
                {
                    int nrow = row + dr[k];
                    int ncol = col + dc[k];

                    if (nrow >= 0 and nrow < m and ncol >= 0 and ncol < n)
                    {
                        cntNeighborsCells++;
                        totalNeighborsCells += img[nrow][ncol];
                    }
                }
                res[row][col] = floor(totalNeighborsCells / cntNeighborsCells);
            }
        }
        return res;
    }
};