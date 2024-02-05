class Solution
{
public:
    vector<int> patternMatching(string str)
    {
        int n = str.length();
        vector<int> arr(n);
        int low = 0;
        int high = 0;
        for (int i = 1; i < n; i++)
        {
            if (i > high)
            {
                low = i;
                high = i;
                while (high < n && str[high] == str[high - low])
                {
                    high++;
                }
                arr[i] = high - low;
                high--;
            }
            else
            {
                int k = i - low;
                if (arr[k] < high - i + 1)
                {
                    arr[i] = arr[k];
                }
                else
                {
                    low = i;
                    while (high < n && str[high] == str[high - low])
                    {
                        high++;
                    }
                    arr[i] = high - low;
                    high--;
                }
            }
        }
        return arr;
    }
    long long sumScores(string s)
    {
        vector<int> ans = patternMatching(s);
        long sum = s.length();
        for (int i : ans)
        {
            sum += i;
        }
        return sum;
    }
};