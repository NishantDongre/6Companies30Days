class Solution
{
public:
    int countCollisions(string directions)
    {
        int n = directions.size();
        int i = 0, j = n - 1;
        for (i = 0; i < n; i++)
            if (directions[i] != 'L')
                break;
        for (j = n - 1; j >= 0; j--)
            if (directions[j] != 'R')
                break;

        int Rcnt = 0, Lcnt = 0;

        int res = 0;
        for (int k = i; k <= j; k++)
        {
            if (directions[k] == 'R' and k + 1 < n and directions[k + 1] == 'L')
            {
                res += 2;
                k++;
                continue;
            }
            if (directions[k] == 'R' or directions[k] == 'L')
                res++;
        }
        return res;
    }
};