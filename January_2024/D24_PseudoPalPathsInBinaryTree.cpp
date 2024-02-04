// Pseudo - Palindromic Paths in a Binary Tree

class Solution {
public:
    bool IsPseudoPalPath(vector<int> freq)
    {
        int OddFreqCount = 0;
        for(int i = 0; i < freq.size(); i++)
        {
            if(freq[i]%2==1)
                OddFreqCount++;
        }
        return ((OddFreqCount == 1) || (OddFreqCount == 0)) ? true : false;
    }
    void GetCountPalPaths(TreeNode* root, int& Ans, vector<int> freq)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            freq[root->val]++;
            if(IsPseudoPalPath(freq))
                Ans++;
            return;
        }
        freq[root->val]++;
        GetCountPalPaths(root->left, Ans, freq);
        GetCountPalPaths(root->right, Ans, freq);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10, 0);
        int Ans = 0;
        GetCountPalPaths(root, Ans, v);
        return Ans;
    }
};