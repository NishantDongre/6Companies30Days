class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxContHorizontalBars = 1;
        int currContHorizontalBars = 1;

        for (int i = 0; i < hBars.size() - 1; i++)
        {
            if (hBars[i] + 1 == hBars[i + 1])
                currContHorizontalBars++;
            else
                currContHorizontalBars = 1;
            maxContHorizontalBars = max(maxContHorizontalBars, currContHorizontalBars);
        }

        int maxContVerticalBars = 1;
        int currContVerticalBars = 1;

        for (int i = 0; i < vBars.size() - 1; i++)
        {
            if (vBars[i] + 1 == vBars[i + 1])
                currContVerticalBars++;
            else
                currContVerticalBars = 1;
            maxContVerticalBars = max(maxContVerticalBars, currContVerticalBars);
        }

        int squareSide = min(maxContHorizontalBars, maxContVerticalBars) + 1;
        return squareSide * squareSide;
    }
};