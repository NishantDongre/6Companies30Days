class Solution
{
public:
    int longestString(int x, int y, int z)
    {
        int mini = min(x, y);
        if (x == y)
            return x * 4 + z * 2;
        return (mini * 2 + (mini + 1) * 2 + z * 2);
    }
};