class Solution
{
public:
    int util(int n, int k)
    {
        if (n == 1)
            return 0;

        return (util(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k)
    {
        return util(n, k) + 1;
    }
};