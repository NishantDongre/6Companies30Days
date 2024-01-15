class Solution
{
private:
    int miniNumber(int i, string &s, unordered_set<string> &st, int dp[])
    {
        int n = s.size();
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        string str = "";
        int mini = n;
        for (int j = i; j < n; j++)
        {
            str += s[j];
            int curr = st.find(str) == st.end() ? str.size() : 0;
            curr += miniNumber(j + 1, s, st, dp);
            mini = min(mini, curr);
        }
        return dp[i] = mini;
    }

public:
    int minExtraChar(string s, vector<string> &dictionary)
    {

        int n = s.size();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        int dp[n];
        memset(dp, -1, sizeof(dp));
        return miniNumber(0, s, st, dp);
    }
};