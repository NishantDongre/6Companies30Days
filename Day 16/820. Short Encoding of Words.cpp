class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        unordered_set<string> hset1(words.begin(), words.end());
        unordered_set<string> hset2(words.begin(), words.end());

        for (auto it : hset1)
        {
            string word = it;

            for (int i = 1; i < word.length(); i++)
            {
                string subStr = word.substr(i);
                if (hset2.find(subStr) != hset2.end())
                    hset2.erase(subStr);
            }
        }

        int res = 0;
        for (auto it : hset2)
        {
            res += it.length();
            res += 1;
        }

        return res;
    }
};