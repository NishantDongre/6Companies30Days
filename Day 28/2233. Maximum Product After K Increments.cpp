class Solution
{
public:
    int maximumProduct(vector<int> &nums, int k)
    {
        //         sort(nums.begin(),nums.end());

        //         int cnt0 = 0;

        //         int ind = 0, n = nums.size();
        //         while(ind < n and nums[ind] == 0 and  k > 0){
        //             nums[ind]++;
        //             ind++;
        //             k--;
        //         }

        long long mul = 1;
        int MOD = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        while (k > 0)
        {
            int ele = pq.top();
            pq.pop();
            pq.push(ele + 1);
            k--;
        }

        while (!pq.empty())
        {
            int ele = pq.top();
            mul = ((mul % MOD) * (ele % MOD)) % MOD;
            pq.pop();
        }

        return (int)mul % MOD;
    }
};