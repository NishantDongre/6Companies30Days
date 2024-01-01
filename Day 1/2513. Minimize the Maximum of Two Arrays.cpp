#define ll long long
class Solution
{
public:
    bool satisfy(ll d1, ll d2, ll c1, ll c2, ll mid)
    {
        ll divisibleByD1 = mid / d1;
        ll divisibleByD2 = mid / d2;
        ll notDivisibleByD1 = mid - divisibleByD1;
        ll notDivisibleByD2 = mid - divisibleByD2;

        ll notDivisibleByBoth = mid - (mid / lcm(d1, d2));

        if (notDivisibleByD1 >= c1 and notDivisibleByD2 >= c2 and notDivisibleByBoth >= c1 + c2)
            return true;

        return false;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {
        int l = 1, h = INT_MAX;
        int res = INT_MAX;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (satisfy(divisor1, divisor2, uniqueCnt1, uniqueCnt2, mid))
            {
                res = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
};