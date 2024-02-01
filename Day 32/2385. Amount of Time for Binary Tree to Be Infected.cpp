/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> hmap;
        unordered_map<int, int> vis;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                hmap[node->val].push_back(node->left->val);
                hmap[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if (node->right)
            {
                hmap[node->val].push_back(node->right->val);
                hmap[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }
        queue<pair<int, int>> pq;
        pq.push({start, 0});
        int res = 0;
        vis[start] = 1;
        while (!pq.empty())
        {
            auto p = pq.front();
            pq.pop();
            res = max(res, p.second);
            for (auto x : hmap[p.first])
            {
                if (vis[x] == 0)
                {
                    vis[x] = 1;
                    pq.push({x, p.second + 1});
                }
            }
        }
        return res;
    }
};