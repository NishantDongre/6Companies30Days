class Solution
{
public:
    int util(int ind, vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        int n = needs.size();
        if (ind == special.size())
        {
            int individualBuyCostSum = 0;
            for (int i = 0; i < n; i++)
            {
                individualBuyCostSum += needs[i] * price[i];
            }
            return individualBuyCostSum;
        }

        // check if we can avail this offer or not
        for (int i = 0; i < n; i++)
        {
            if (needs[i] - special[ind][i] < 0)
                return util(ind + 1, price, special, needs);
        }

        // Yes we can avail this offer
        for (int i = 0; i < n; i++)
        {
            needs[i] = needs[i] - special[ind][i];
        }

        // pick this offer
        int pick = special[ind][n] + util(ind, price, special, needs);

        // revert back the needs[] array for not picking up this offer
        for (int i = 0; i < special[ind].size() - 1; i++)
        {
            needs[i] = needs[i] + special[ind][i];
        }
        // don't pick this offer and move forwad
        int notPick = util(ind + 1, price, special, needs);

        return min(pick, notPick);
    }
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        int ind = 0;
        return util(ind, price, special, needs);
    }
};