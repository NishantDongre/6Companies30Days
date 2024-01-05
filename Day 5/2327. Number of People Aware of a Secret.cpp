class Solution
{
public:
    int naiveSol(int n, int delay, int forget)
    {
        queue<pair<int, int>> q;
        q.push({delay, forget});

        int day = 2;
        while (!q.empty())
        {
            int size = q.size();
            if (day == n + 1)
                return size;

            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                int delayTime = node.first;
                int forgetIn = node.second;

                // decrement the delay and forget days/time
                delayTime--;
                forgetIn--;

                if (delayTime <= 0 and forgetIn != 0)
                {
                    q.push({delay, forget});
                }
                if (forgetIn != 0)
                    q.push({delayTime, forgetIn});
            }

            day++;
        }
        return 0;
    }
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        vector<long> dp(n + 1, 0);
        long MOD = 1e9 + 7;
        long noOfPeopleSharingSecret = 0;
        long res = 0;

        // one person knows the secret on day 1
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            long noOfNewPeopleSharingSecret = dp[max(i - delay, 0)];
            long noOfPeopleForgetingSecret = dp[max(i - forget, 0)];
            noOfPeopleSharingSecret += (noOfNewPeopleSharingSecret - noOfPeopleForgetingSecret + MOD) % MOD;
            dp[i] = noOfPeopleSharingSecret;
        }

        for (int i = n - forget + 1; i <= n; i++)
        {
            res = (res + dp[i]) % MOD;
        }
        return (int)res;
    }
};