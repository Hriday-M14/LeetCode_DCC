// Leaf - Similar Trees

class Solution {
public:
    vector<int> GetLeafSequence(TreeNode* root)
    {
        if(root==NULL)
        {
            vector<int> ans;
            return ans;
        }
        if(root->left==NULL && root->right==NULL)
        {
            vector<int> ans;
            ans.push_back(root->val);
            return ans;
        }
        vector<int> LeftTree = GetLeafSequence(root->left);
        vector<int> RightTree = GetLeafSequence(root->right);
        vector<int> ans;
        for(int ele : LeftTree)
            ans.push_back(ele);
        for(int ele : RightTree)
            ans.push_back(ele);
        return ans;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return GetLeafSequence(root1) == GetLeafSequence(root2);
    }
};