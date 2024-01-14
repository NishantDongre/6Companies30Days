class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int nodeCnt = 0, nullCnt = 0;
        vector<string> v = splitStr(preorder, ',');
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == "#")
                ++nullCnt;
            else
                ++nodeCnt;
            if (nullCnt >= nodeCnt + 1 && i != v.size() - 1)
                return false;
        }
        return nullCnt == nodeCnt + 1;
    }

    vector<string> splitStr(string str, char delimiter)
    {
        vector<string> r;
        string tmpstr;
        while (!str.empty())
        {
            int ind = str.find_first_of(delimiter);
            if (ind == -1)
            {
                r.push_back(str);
                str.clear();
            }
            else
            {
                r.push_back(str.substr(0, ind));
                str = str.substr(ind + 1, str.size() - ind - 1);
            }
        }
        return r;
    }
};