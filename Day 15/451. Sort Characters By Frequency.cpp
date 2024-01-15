class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.length();
        vector<int> arr1(26, 0), arr2(26, 0), arr3(10, 0);

        for (int i = 0; i < n; i++)
        {
            if ('A' <= s[i] and s[i] <= 'Z')
                arr1[s[i] - 'A']++;
            if ('a' <= s[i] and s[i] <= 'z')
                arr2[s[i] - 'a']++;
            if ('0' <= s[i] and s[i] <= '9')
                arr3[s[i] - '0']++;
        }

        priority_queue<pair<int, char>> maxHeap;

        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] > 0)
                maxHeap.push({arr1[i], 'A' + i});
            if (arr2[i] > 0)
                maxHeap.push({arr2[i], 'a' + i});
        }
        for (int i = 0; i < 10; i++)
        {
            if (arr3[i] > 0)
                maxHeap.push({arr3[i], '0' + i});
        }

        string res = "";
        while (!maxHeap.empty())
        {
            int cnt = maxHeap.top().first;
            char ch = maxHeap.top().second;
            maxHeap.pop();
            string str(cnt, ch);
            res += str;
        }
        return res;
    }
};