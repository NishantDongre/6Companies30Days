class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }

        // dist of node 'i' to node 'i' is always ZERO (All Diagonal Cells)
        for (int i = 0; i < n; i++)
            matrix[i][i] = 0;

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        int resNode = -1;
        int resNodeCityCnt = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int cityCnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] <= distanceThreshold)
                    cityCnt++;
            }

            if (cityCnt <= resNodeCityCnt)
            {
                resNodeCityCnt = cityCnt;
                resNode = i;
            }
        }

        return resNode;
    }
};