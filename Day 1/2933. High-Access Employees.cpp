class Solution
{
public:
    string addOneHour(string str)
    {
        int a = str[0] - '0';
        int b = str[1] - '0';

        int tmp = b + 1;
        int carry = tmp / 10;
        int aNew = a + carry;
        int bNew = tmp % 10;

        return "" + to_string(aNew) + to_string(bNew) + str.substr(2);
    }
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        unordered_map<string, vector<string>> hmap;
        for (auto it : access_times)
        {
            string emp = it[0];
            string ac_time = it[1];
            hmap[emp].push_back(ac_time);
        }
        vector<string> res;
        for (auto it : hmap)
        {
            string emp = it.first;
            vector<string> nums = it.second;
            sort(nums.begin(), nums.end());
            for (auto it : nums)
                cout << it << " ";
            for (int i = 0; i < (int)nums.size() - 2; i++)
            {
                string startTime = nums[i];
                string nextTime1 = nums[i + 1];
                string nextTime2 = nums[i + 2];
                string endTime = addOneHour(nums[i]);
                if (nums[i][0] == '2' and nums[i][1] == '3')
                    endTime = "2400";
                if (nextTime1 < endTime and nextTime2 < endTime)
                {
                    res.push_back(emp);
                    break;
                }
            }
        }
        return res;
    }
};