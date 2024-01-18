class Solution
{
public:
    int LCS(int m, int n, string &X, string &Y)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
    bool isValidSubsequence(string str1, string str2)
    {
        int n1 = str1.length(), n2 = str2.length();

        int ind1 = 0, ind2 = 0;
        while (ind1 < n1 and ind2 < n2)
        {
            if (str1[ind1] == str2[ind2])
            {
                ind1++;
                ind2++;
            }
            else
            {
                ind1++;
            }
        }
        if (ind2 == n2)
            return true;
        return false;
    }
    string findLongestWord(string s, vector<string> &dictionary)
    {
        // Method 1 -> Giving TLE
        // int n = dictionary.size();

        // string res = "";
        // for(int i=0;i<n;i++){
        //     int lengthOfLCS = LCS(s.length(), dictionary[i].size(), s, dictionary[i]);

        //     if(lengthOfLCS == dictionary[i].length()){
        //         if(lengthOfLCS == res.length() and dictionary[i] < res)
        //             res = dictionary[i];
        //         if(lengthOfLCS > res.length())
        //             res = dictionary[i];
        //     }
        // }
        // return res;

        // Method 2

        int n = dictionary.size();
        sort(dictionary.begin(), dictionary.end());

        string res = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (isValidSubsequence(s, dictionary[i]))
            {
                if (dictionary[i].length() == res.length() and dictionary[i] < res)
                    res = dictionary[i];
                else if (dictionary[i].length() > res.length())
                {
                    res = dictionary[i];
                }
            }
        }
        return res;
    }
};