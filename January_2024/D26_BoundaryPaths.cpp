// Out of Boundary Paths

// Recursive Approach
class Solution {
public:

    int GetPaths(int rows, int cols, int MoveLeft, int CurrRow, int CurrCol, vector<vector<int>>& dp)
    {
        if(MoveLeft==0)
        {
            if(CurrRow<0 || CurrRow>=rows || CurrCol<0 || CurrCol>=cols)
                return 1;
            return 0;
        }
        if(CurrRow<0 || CurrRow>=rows || CurrCol<0 || CurrCol>=cols)
            return 0;
        int Down = GetPaths(rows, cols, MoveLeft-1, CurrRow+1, CurrCol, dp);
        int Up = GetPaths(rows, cols, MoveLeft-1, CurrRow-1, CurrCol, dp);
        int Right = GetPaths(rows, cols, MoveLeft-1, CurrRow, CurrCol+1, dp);
        int Left = GetPaths(rows, cols, MoveLeft-1, CurrRow, CurrCol-1, dp);
        return (Down + Up + Right + Left);
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        for(int i = 1; i <= maxMove; i++)
        {
            ans += GetPaths(m, n, i, startRow, startColumn, dp);
        }
        return ans;
    }
};

// Memoization (3 Dimensional Dynamic Programming)
class Solution {
public:

    int GetPaths(int rows, int cols, int MoveLeft, int CurrRow, int CurrCol, vector<vector<vector<long long int>>>& dp)
    {
        if(MoveLeft==0)
        {
            if(CurrRow<0 || CurrRow>=rows || CurrCol<0 || CurrCol>=cols)
                return 1;
            return 0;
        }
        if(CurrRow<0 || CurrRow>=rows || CurrCol<0 || CurrCol>=cols)
            return 0;
        if(dp[CurrRow][CurrCol][MoveLeft]!=-1)
            return dp[CurrRow][CurrCol][MoveLeft];
        long long int Down = GetPaths(rows, cols, MoveLeft-1, CurrRow+1, CurrCol, dp);
        long long int Up = GetPaths(rows, cols, MoveLeft-1, CurrRow-1, CurrCol, dp);
        long long int Right = GetPaths(rows, cols, MoveLeft-1, CurrRow, CurrCol+1, dp);
        long long int Left = GetPaths(rows, cols, MoveLeft-1, CurrRow, CurrCol-1, dp);
        
        return dp[CurrRow][CurrCol][MoveLeft] = (Down + Up + Right + Left)%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long long int ans = 0;
        for(int i = 1; i <= maxMove; i++)
        {
            vector<vector<vector<long long int>>> dp(m+1, vector<vector<long long int>>(n+1, vector<long long int>(i+1, -1)));
            ans = (ans + GetPaths(m, n, i, startRow, startColumn, dp))%1000000007;
        }
        return ans;
    }
};