class Solution
{
public:
    bool isPal(string &str)
    {
        int n = str.length();
        int l = 0, h = n - 1;

        while (l < h)
        {
            if (str[l] != str[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
    int util(int ind, string str1, string str2, string &s)
    {
        if (ind == s.length())
        {
            if (isPal(str1) and isPal(str2))
            {
                return str1.length() * str2.length();
            }
            return INT_MIN;
        }

        int pick1 = util(ind + 1, str1 + s[ind], str2, s);
        int pick2 = util(ind + 1, str1, str2 + s[ind], s);
        int notPick = util(ind + 1, str1, str2, s);

        return max({pick1, pick2, notPick});
    }
    int maxProduct(string s)
    {
        int n = s.length();
        int ind = 0;
        string str1 = "", str2 = "";
        return util(ind, str1, str2, s);
    }
};