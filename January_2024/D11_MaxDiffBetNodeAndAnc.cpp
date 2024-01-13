// Max Difference Between Node and Ancestor

// Required Maximum Value can be get only when our Current Node's Value is subtracted from either the Maximum Possible Ancestor
// of our Current Node or Minimum Possible Ancestor of our Current Node.

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int Ans = 0, MaxAncOfCurr = INT_MIN, MinAncOfCurr = INT_MAX;
        GetMaxDiff(root, Ans, MaxAncOfCurr, MinAncOfCurr);
        return Ans;
    }
    void GetMaxDiff(TreeNode* root, int& Ans, int MaxAncOfCurr, int MinAncOfCurr)
    {
        if(root==NULL)
            return;
        
        if(MaxAncOfCurr != INT_MIN)
            Ans = max(Ans, abs(root->val - MaxAncOfCurr));
        if(MinAncOfCurr != INT_MAX)
            Ans = max(Ans, abs(root->val - MinAncOfCurr));
        
        MaxAncOfCurr = max(root->val, MaxAncOfCurr);
        MinAncOfCurr = min(root->val, MinAncOfCurr);
        GetMaxDiff(root->left, Ans, MaxAncOfCurr, MinAncOfCurr);
        GetMaxDiff(root->right, Ans, MaxAncOfCurr, MinAncOfCurr);
    }
};