#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        // code here

        // A = Missing Number
        // B = Twice Occured Number
        int A, B;

        for (int i = 0; i < n; i++)
        {
            if (arr[abs(arr[i]) - 1] > 0)
            {
                arr[abs(arr[i]) - 1] *= -1;
            }
            else
            {
                B = abs(arr[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                A = i + 1;
        }

        return {B, A};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends