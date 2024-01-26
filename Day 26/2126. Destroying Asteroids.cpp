class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        long long int MASS = mass;
        for (int i = 0; i < arr.size(); i++)
        {
            if (MASS >= arr[i])
                MASS += arr[i];
            else
                return false;
        }
        return true;
    }
};