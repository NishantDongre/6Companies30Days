class Solution
{
public:
    void utilFun(int ind, string &digits, string str, unordered_map<int, string> &hmap, vector<string> &res)
    {
        if (ind == digits.size())
        {
            res.push_back(str);
            return;
        }
        int num = digits[ind] - '0';
        for (int i = 0; i < hmap[num].length(); i++)
        {
            utilFun(ind + 1, digits, str + hmap[num][i], hmap, res);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        unordered_map<int, string> hmap;
        hmap[2] = "abc";
        hmap[3] = "def";
        hmap[4] = "ghi";
        hmap[5] = "jkl";
        hmap[6] = "mno";
        hmap[7] = "pqrs";
        hmap[8] = "tuv";
        hmap[9] = "wxyz";

        vector<string> res;
        utilFun(0, digits, "", hmap, res);
        return res;
    }
};