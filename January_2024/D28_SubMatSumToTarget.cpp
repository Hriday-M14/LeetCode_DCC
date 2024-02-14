// Number of Submatrices that Sum to Target

// Brute Force Approach
class Solution {
public:

    int SumOfSubMatrix(vector<vector<int>>& matrix, int RowS, int RowSize, int ColS, int ColSize)
    {
        int Sum = 0;
        for(int i = RowS; i < RowS+RowSize; i++)
        {
            for(int j = ColS; j < ColS+ColSize; j++)
            {
                Sum += matrix[i][j];
            }
        }
        return Sum;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0, r = matrix.size(), c = matrix[0].size();
        for(int RowStart = 0; RowStart < r; RowStart++)
        {
            for(int RowSize = 1; RowStart + RowSize <= r; RowSize++)
            {
                for(int ColStart = 0; ColStart < c; ColStart++)
                {
                    for(int ColSize = 1; ColStart + ColSize <= c; ColSize++)
                    {
                        if(SumOfSubMatrix(matrix, RowStart, RowSize, ColStart, ColSize) == target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};

// Better Approach - Prefix Sum
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0, r = matrix.size(), c = matrix[0].size();
        for(int i = 0; i < r; i++)
        {
            for(int j = 1; j < c; j++)
                matrix[i][j] += matrix[i][j-1];
        }
        for(int ColStart = 0; ColStart < c; ColStart++)
        {
            for(int ColEnd = ColStart; ColEnd < c; ColEnd++)
            {
                for(int RowStart = 0; RowStart < r; RowStart++)
                {
                    int Sum = 0;
                    for(int RowEnd = RowStart; RowEnd < r; RowEnd++)
                    {
                        Sum += matrix[RowEnd][ColEnd] - (ColStart ? matrix[RowEnd][ColStart-1] : 0);
                        if(Sum == target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};

// Optimal Approach
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0, r = matrix.size(), c = matrix[0].size();
        for(int i = 0; i < r; i++)
        {
            for(int j = 1; j < c; j++)
                matrix[i][j] += matrix[i][j-1];
        }
        unordered_map<int, int> freq;
        for(int ColStart = 0; ColStart < c; ColStart++)
        {
            for(int ColEnd = ColStart; ColEnd < c; ColEnd++)
            {
                int CurrSum = 0;
                freq = {{0, 1}};
                for(int Row = 0; Row < r; Row++)
                {
                    CurrSum += matrix[Row][ColEnd] - (ColStart ? matrix[Row][ColStart-1] : 0);
                    ans += freq[CurrSum - target];
                    freq[CurrSum]++;
                }
            }
        }
        return ans;
    }
};