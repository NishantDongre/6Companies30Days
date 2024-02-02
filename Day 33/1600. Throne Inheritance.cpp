class ThroneInheritance
{
private:
    unordered_map<string, vector<string>> children;
    vector<string> inheritance;
    unordered_set<string> dead;
    string curr_king;

public:
    ThroneInheritance(string kingName)
    {
        curr_king = kingName;
    }

    void birth(string parentName, string childName)
    {
        children[parentName].push_back(childName);
    }

    void death(string name)
    {
        dead.insert(name);
    }

    void rec(string parent)
    {
        if (!dead.count(parent))
            inheritance.push_back(parent);
        for (auto child : children[parent])
            rec(child);
    }

    vector<string> getInheritanceOrder()
    {
        inheritance = {};
        rec(curr_king);
        return inheritance;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */