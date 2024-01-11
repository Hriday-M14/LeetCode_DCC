// Range Sum of BST

class Solution {
public:
    void GetRangeSumBST(TreeNode* root, int low, int high, int& Sum)
    {
        if(root==NULL)
            return;
        if(root->val>=low && root->val<=high){
            Sum += root->val;
            GetRangeSumBST(root->left, low, high, Sum);
            GetRangeSumBST(root->right, low, high, Sum);
            return;
        }

        if(root->val>high)
            GetRangeSumBST(root->left, low, high, Sum);
        if(root->val<low)
            GetRangeSumBST(root->right, low, high, Sum);
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int Sum = 0;
        GetRangeSumBST(root, low , high, Sum);
        return Sum;
    }
};