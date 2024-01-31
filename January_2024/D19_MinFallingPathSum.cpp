// Minimum Falling Path Sum

// Recursive Approach
class Solution {
public:
    int GetMinPathSum(vector<vector<int>>& matrix, int r, int c, int n)
    {
        if(r>=n || c<0 || c>=n)
            return INT_MAX;

        int LeftDiagnol = GetMinPathSum(matrix, r+1, c-1, n);
        int RightDiagnol = GetMinPathSum(matrix, r+1, c+1, n);
        int Down = GetMinPathSum(matrix, r+1, c, n);
        int MinPossibility = min(Down, min(LeftDiagnol, RightDiagnol));

        if(MinPossibility != INT_MAX)
            return matrix[r][c] + MinPossibility;
        return matrix[r][c];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, GetMinPathSum(matrix, 0, i, n));
        }
        return ans;
    }
};


// Memoization
class Solution {
public:
    int GetMinPathSum(vector<vector<int>>& matrix, int r, int c, int n, vector<vector<int>>& dp)
    {
        if(r>=n || c<0 || c>=n)
            return INT_MAX;

        if(dp[r][c] != -1)
            return dp[r][c];
        int LeftDiagnol = GetMinPathSum(matrix, r+1, c-1, n, dp);
        int RightDiagnol = GetMinPathSum(matrix, r+1, c+1, n, dp);
        int Down = GetMinPathSum(matrix, r+1, c, n, dp);
        int MinPossibility = min(Down, min(LeftDiagnol, RightDiagnol));

        if(MinPossibility != INT_MAX)
            return dp[r][c] = matrix[r][c] + MinPossibility;
        return dp[r][c] = matrix[r][c];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, GetMinPathSum(matrix, 0, i, n, dp));
        }
        return ans;
    }
};

// DP
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int LeftDiagnol = INT_MAX, RightDiagnol = INT_MAX;
                if(j-1>=0)
                    LeftDiagnol = dp[i-1][j-1];
                if(j+1<n)
                    RightDiagnol = dp[i-1][j+1];
                int Up = dp[i-1][j];
                int MinPossibility = min(Up, min(LeftDiagnol, RightDiagnol));
                dp[i][j] = matrix[i][j] + MinPossibility;
            }
        }
        for(int i = 0; i < n; i++)
            ans = min(ans, dp[n-1][i]);
        return ans;
    }
};