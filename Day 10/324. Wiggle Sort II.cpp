class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        // Base case -> size == 1
        if (n == 1)
            return;

        vector<int> copyNums = nums;
        sort(copyNums.begin(), copyNums.end());

        int i = 1;
        int j = n - 1;
        while (i < n)
        {
            nums[i] = copyNums[j];
            j--;
            i += 2;
        }

        i = 0;

        while (i < n)
        {
            nums[i] = copyNums[j];
            j--;
            i += 2;
        }
    }
};