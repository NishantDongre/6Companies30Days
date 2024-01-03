class DataStream
{
public:
    int value, k;
    int prevValueInd;
    int ind;
    DataStream(int value, int k)
    {
        this->value = value;
        this->k = k;
        this->prevValueInd = -1;
        this->ind = 0;
    }

    bool consec(int num)
    {
        if (num == value)
        {
            if (prevValueInd != -1)
            {
                if (ind - prevValueInd + 1 >= k)
                {
                    ind++;
                    return true;
                }
                else
                {
                    ind++;
                    return false;
                }
            }
            else
            {
                prevValueInd = 0;
                ind = 1;
                if (k == 1)
                    return true;
                return false;
            }
        }
        else
        {
            ind = 0;
            prevValueInd = -1;
            return false;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */