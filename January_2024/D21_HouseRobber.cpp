// House Robber 

// Recursive Approach
class Solution {
public:

    int GetMaxMoney(vector<int>& nums, int CurrIdx, int n)
    {
        if(CurrIdx >= n)
            return 0;
        
        return max(nums[CurrIdx]+GetMaxMoney(nums, CurrIdx+2, n), GetMaxMoney(nums, CurrIdx+1, n));
    }
    int rob(vector<int>& nums) {
        int sz = nums.size();
        return GetMaxMoney(nums, 0, sz);
    }
};

// Memoization
int GetMaxMoney(vector<int>& nums, int CurrIdx, int n, vector<int>& dp)
{
    if(CurrIdx >= n)
        return 0;
    if(dp[CurrIdx] != -1)
        return dp[CurrIdx];
    return dp[CurrIdx] = max(nums[CurrIdx]+GetMaxMoney(nums, CurrIdx+2, n, dp), GetMaxMoney(nums, CurrIdx+1, n, dp));
}
int rob(vector<int>& nums) {
    int sz = nums.size();
    vector<int> dp(sz+1, -1);
    return GetMaxMoney(nums, 0, sz, dp);
}

// DP
class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        if(sz > 1)
        {
            dp[2] = max(nums[1], nums[0]);
            for(int i=3; i<=sz; i++)
                dp[i] = max(nums[i-1]+dp[i-2], dp[i-1]);
        }
        
        return dp[sz];
    }
};