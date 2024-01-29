// Climbing Stairs

// Recursive Approach - Top Down
class Solution {
public:
    int WaysToTop(int n)
    {
        if(n <= 1)
            return 1;
        return WaysToTop(n-1) + WaysToTop(n-2);
    }
    int climbStairs(int n) {
        return WaysToTop(n);
    }
};


// DP - Memoization
class Solution {
public:
    int WaysToTop(int n, vector<int>& dp)
    {
        if(n <= 1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = WaysToTop(n-1, dp) + WaysToTop(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return WaysToTop(n, dp);
    }
};


// DP - Bottom Up 
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 1);
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};