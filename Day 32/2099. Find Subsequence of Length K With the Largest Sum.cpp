class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        if (nums.size() == k)
            return nums;

        priority_queue<pair<int, int>> q;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            q.push({nums[i], i});

        vector<pair<int, int>> arr;
        while (k--)
        {
            arr.push_back({q.top().second, q.top().first});
            q.pop();
        }
        sort(arr.begin(), arr.end());

        vector<int> ans;
        for (auto it : arr)
            ans.push_back(it.second);

        return ans;
    }
};