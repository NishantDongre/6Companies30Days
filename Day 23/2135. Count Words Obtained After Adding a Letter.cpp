class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        unordered_set<string> hset;

        for (int i = 0; i < startWords.size(); i++)
        {
            string str = startWords[i];
            sort(str.begin(), str.end());
            hset.insert(str);
            // cout<<str<<" ";
        }
        cout << endl;
        int res = 0;
        for (int i = 0; i < targetWords.size(); i++)
        {
            string str = targetWords[i];
            sort(str.begin(), str.end());
            // cout<<str<<" ****** "<<endl;
            for (int j = 0; j < str.length(); j++)
            {
                string left = str.substr(0, j);
                string right = str.substr(j + 1);
                // cout<<left<<" "<<right<<endl;
                string newStr = left + right;

                if (hset.find(newStr) != hset.end())
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};