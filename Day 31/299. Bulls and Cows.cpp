class Solution
{
public:
    string getHint(string secret, string guess)
    {
        unordered_map<char, int> mp;
        int n = secret.size();
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                cnt1++;
                continue;
            }
            mp[secret[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (secret[i] != guess[i] && mp[guess[i]] > 0)
            {
                mp[guess[i]]--;
                cnt2++;
            }
        }
        return to_string(cnt1) + 'A' + to_string(cnt2) + 'B';
    }
};