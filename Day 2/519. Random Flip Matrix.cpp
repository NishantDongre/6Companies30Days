class Solution
{
public:
    int m, n, size;
    unordered_set<int> hset;
    Solution(int m, int n)
    {
        this->m = m;
        this->n = n;
        this->size = m * n;
    }

    vector<int> flip()
    {
        if (hset.size() == size)
            return {};

        int randomNum = rand() % size;

        while (hset.find(randomNum) != hset.end())
        {
            randomNum++;
            randomNum %= size;
        }

        hset.insert(randomNum);

        int row = randomNum / n, col = randomNum % n;
        return {row, col};
    }

    void reset()
    {
        hset.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */