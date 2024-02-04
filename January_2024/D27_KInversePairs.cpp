// K Inverse Pairs Array

// Recursive Approach
class Solution {
public:
    
    int kInversePairs(int n, int k) {
        if(n==0)
        {
            if(k==0)
                return 1;
            return 0;
        }
        if(k==0)
            return 1;
        if(k < 0)
            return 0;
        int Ans = 0;
        for(int i = 1; i <= n; i++)
        {
            Ans = Ans + kInversePairs(n - 1, k - i + 1);
        }
        return Ans; 
    }
};

// Memoization
class Solution {
public:
    int GetArraysWithKInversePairs(int n, int k, vector<vector<int>>& dp)
    {
        if(n==0)
        {
            if(k==0)
                return 1;
            return 0;
        }
        if(k==0)
            return 1;
        if(k < 0)
            return 0;
        if(dp[n][k] != -1)
            return dp[n][k];
        int Ans = 0;
        for(int i = 1; i <= n; i++)
        {
            Ans = (Ans + GetArraysWithKInversePairs(n - 1, k - i + 1, dp))%1000000007;
        }
        return dp[n][k] = Ans;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return GetArraysWithKInversePairs(n, k, dp);         
    }
};

// DP
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
            dp[i][0] = 1;
        for(int N = 1; N <= n; N++)
        {
            for(int K = 1; K <= k; K++)
            {
                for(int i = 1; i <= N; i++)
                {
                    if(K - i + 1 >= 0)
                        dp[N][K] = (dp[N][K] + dp[N-1][K - i + 1])%1000000007;
                }
            }
        }
        return dp[n][k];         
    }
};