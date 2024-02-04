// Longest Common Subsequence

// Recursive Approach
class Solution {
public:
    int LongestCommSubsequence(string s1, int i1, int n1, string s2, int i2, int n2)
    {
        if(i1>=n1 || i2>=n2)
            return 0;
        
        if(s1[i1]==s2[i2])
            return 1 + LongestCommSubsequence(s1, i1+1, n1, s2, i2+1, n2);
        else
            return max(LongestCommSubsequence(s1, i1+1, n1, s2, i2, n2), 
                        LongestCommSubsequence(s1, i1, n1, s2, i2+1, n2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return LongestCommSubsequence(text1, 0, text1.size(), text2, 0, text2.size());
    }
};

// Memoization Approach
class Solution {
public:
    int LongestCommSubsequence(string s1, int i1, int n1, string s2, int i2, int n2, vector<vector<int>>& dp)
    {
        if(i1>=n1 || i2>=n2)
            return 0;
        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
        if(s1[i1]==s2[i2])
            dp[i1][i2] = 1 + LongestCommSubsequence(s1, i1+1, n1, s2, i2+1, n2, dp);
        else
            dp[i1][i2] = max(LongestCommSubsequence(s1, i1+1, n1, s2, i2, n2, dp), 
                        LongestCommSubsequence(s1, i1, n1, s2, i2+1, n2, dp));
        return dp[i1][i2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        return LongestCommSubsequence(text1, 0, text1.size(), text2, 0, text2.size(), dp);
    }
};


// DP - Bottom Up
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
     
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }  
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};