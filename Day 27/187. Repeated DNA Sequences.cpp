class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int n = s.length();
        unordered_set<string> hset1, hset2;

        vector<string> res;
        for (int i = 0; i <= n - 10; i++)
        {
            string str = s.substr(i, 10);
            if (hset1.find(str) != hset1.end())
            {
                hset2.insert(str);
            }
            hset1.insert(str);
        }

        for (auto it : hset2)
            res.push_back(it);

        return res;
    }
};
