class Solution
{
public:
    map<int, vector<int>> hmap;
    int totalPoints;
    Solution(vector<vector<int>> &rects)
    {
        this->totalPoints = 0;
        for (auto it : rects)
        {
            int noOfPoints = (it[3] - it[1] + 1) * (it[2] - it[0] + 1);
            totalPoints += noOfPoints;
            hmap[totalPoints] = it;
        }
    }

    vector<int> pick()
    {
        vector<int> res;
        int randomPoint = rand() % totalPoints;

        auto temp = hmap.upper_bound(randomPoint);

        vector rect = temp->second;

        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */