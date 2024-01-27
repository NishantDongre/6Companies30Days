class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        int n = aliceValues.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            q.push({(aliceValues[i] + bobValues[i]), i});
        }
        int aliceSum = 0;
        int bobSum = 0;
        bool isAliceChance = true;
        while (q.size())
        {
            auto p = q.top();
            q.pop();
            if (isAliceChance)
            {
                aliceSum += aliceValues[p.second];
            }
            else
            {
                bobSum += bobValues[p.second];
            }
            isAliceChance = !isAliceChance;
        }
        return aliceSum == bobSum ? 0 : aliceSum < bobSum ? -1
                                                          : 1;
    }
};