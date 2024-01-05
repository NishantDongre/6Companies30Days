/*You are required to complete this function */

string encode(string str)
{
    // Your code here
    int n = str.length();
    string res = "";
    char ch = str[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (ch == str[i])
            cnt++;
        else
        {
            res += ch + to_string(cnt);
            cnt = 1;
            ch = str[i];
        }
    }
    res += ch + to_string(cnt);
    return res;
}