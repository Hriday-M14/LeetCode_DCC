// Amount of Time for Binary Tree 

class Solution {
public:
    void MakeGraph(vector<vector<int>>& Adj, TreeNode* root)
    {
        if(root == NULL)
            return;
        if(root->left)
        {
            Adj[root->val].push_back(root->left->val);
            Adj[root->left->val].push_back(root->val);
        }
        if(root->right)
        {
            Adj[root->val].push_back(root->right->val);
            Adj[root->right->val].push_back(root->val);
        }
        MakeGraph(Adj, root->left);
        MakeGraph(Adj, root->right);
    }
    void BFS(vector<vector<int>>& Adj, vector<bool>& Vis, int start, int& Ans)
    {
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int QSize = q.size();
            while(QSize--)
            {
                int Curr = q.front();
                q.pop();
                for(int i = 0; i < Adj[Curr].size(); i++)
                {
                    if(!Vis[Adj[Curr][i]])
                        q.push(Adj[Curr][i]);
                }
                Vis[Curr] = true;
            }
            Ans++;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> Adj(100001);
        vector<bool> Visited(100001, false);

        MakeGraph(Adj, root);
        int Ans = 0;
        BFS(Adj, Visited, start, Ans);
        return Ans - 1;
    }
};