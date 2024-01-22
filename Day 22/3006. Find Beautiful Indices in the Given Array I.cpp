class Solution
{
public:
    vector<int> util(string &str, string &a)
    {
        int n = str.length();
        vector<int> res;
        int ind = 0;

        while (ind <= n - a.length())
        {

            bool flag = true;
            for (int j = 0; j < a.length(); j++)
            {
                if (str[ind + j] != a[j])
                {
                    flag = false;
                }
            }

            if (flag)
                res.push_back(ind);

            ind++;
        }
        return res;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        if (s.length() < a.length() or s.length() < b.length())
            return {};
        vector<int> numsA = util(s, a);
        vector<int> numsB = util(s, b);

        vector<int> res;
        for (int it = 0; it < numsA.size(); it++)
        {
            auto lower = lower_bound(numsB.begin(), numsB.end(), numsA[it] - k);
            auto lowerInd = lower - numsB.begin();

            cout << lowerInd << endl;
            if (lowerInd < numsB.size() and abs(*lower - numsA[it]) <= k)
                res.push_back(numsA[it]);
        }
        return res;
    }
};