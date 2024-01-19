class Solution
{
public:
    int cntValidSeats(string &str)
    {
        int res = 0;
        char col2 = str[2];
        char col3 = str[3];
        char col4 = str[4];
        char col5 = str[5];
        char col6 = str[6];
        char col7 = str[7];
        char col8 = str[8];
        char col9 = str[9];

        if (col2 == '0' and col3 == '0' and col4 == '0' and col5 == '0')
        {
            res++;
            if (col6 == '0' and col7 == '0' and col8 == '0' and col9 == '0')
                res++;
        }
        else if (col4 == '0' and col5 == '0' and col6 == '0' and col7 == '0')
        {
            res++;
        }
        else if (col6 == '0' and col7 == '0' and col8 == '0' and col9 == '0')
        {
            res++;
        }
        return res;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        sort(reservedSeats.begin(), reservedSeats.end());
        int prevRow = 0;
        int processingRow = reservedSeats[0][0];
        string processingStr = "00000000000";
        int res = 0;
        for (int i = 0; i < reservedSeats.size(); i++)
        {
            int currRow = reservedSeats[i][0];
            int currCol = reservedSeats[i][1];

            if (processingRow == currRow)
            {
                processingStr[currCol] = '1';
            }
            else
            {
                res += ((processingRow - prevRow) - 1) * 2;
                res += cntValidSeats(processingStr);
                prevRow = processingRow;
                processingRow = currRow;
                processingStr = "00000000000";
                processingStr[currCol] = '1';
            }
        }

        res += (((n)-prevRow) - 1) * 2;
        res += cntValidSeats(processingStr);
        return res;
    }
};