class Solution
{
public:
    vector<long long> solve(int a, vector<pair<int, int>> adj[])
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, a});
        vector<long long> dist(26, -1);
        while (!pq.empty())
        {
            pair<long long, int> p = pq.top();
            pq.pop();
            for (auto it : adj[p.second])
            {
                if (dist[it.first] == -1 || p.first + it.second < dist[it.first])
                {
                    dist[it.first] = p.first + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        return dist;
    }
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<pair<int, int>> adj[30];

        int n = original.size();
        for (int i = 0; i < n; i++)
        {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        map<int, vector<long long>> hmap;
        for (int i = 0; i < 26; i++)
        {
            vector<long long> k = solve(i, adj);
            hmap[i] = (k);
        }
        n = source.size();
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            if (source[i] != target[i])
            {
                long long k = hmap[source[i] - 'a'][target[i] - 'a'];
                if (k == -1)
                    return -1;
                res = res + k;
            }
        }
        return res;
    }
};