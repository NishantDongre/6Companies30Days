class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.length();
        int start = 0, end = 0;
        int totalCost = 0;

        int res = 0;
        while (end < n)
        {
            int currCost = abs(s[end] - t[end]);
            if (currCost > maxCost)
            {
                end += 1;
                start = end;
                totalCost = 0;
                continue;
            }
            if (totalCost + currCost <= maxCost)
            {
                totalCost += currCost;
                res = max(res, end - start + 1);
                end++;
            }
            else
            {
                totalCost -= abs(s[start] - t[start]);
                start++;
            }
        }
        return res;
    }
};