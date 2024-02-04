// Sum of Subarray Minimums

// Brute Force Approach
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) { 
        int sz = arr.size();
        int SubArraysMinSum = 0;
        for(int i = 0; i < sz; i++)
        {
            int CurrSubArraysMin = INT_MAX;
            for(int j = i; j < sz; j++)
            {
                CurrSubArraysMin = min(CurrSubArraysMin, arr[j]);
                SubArraysMinSum += CurrSubArraysMin;
            }
        }
        return SubArraysMinSum;
    }
};

// Better Approach Using Monotonic Stacks
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) { 
        int sz = arr.size();
        vector<int> left(sz, 0), right(sz, 0);

        stack<pair<int, int>> leftStack, rightStack;
        for(int i = 0; i < sz; i++)
        {
            int GreaterCount = 1;
            while(!leftStack.empty() && leftStack.top().first > arr[i])
            {
                GreaterCount += leftStack.top().second;
                leftStack.pop();
            }
            leftStack.push({arr[i], GreaterCount});
            left[i] = GreaterCount;
        }

        for(int i = sz-1; i >= 0; i--)
        {
            int GreaterCount = 1;
            while(!rightStack.empty() && rightStack.top().first >= arr[i])
            {
                GreaterCount += rightStack.top().second;
                rightStack.pop();
            }
            rightStack.push({arr[i], GreaterCount});
            right[i] = GreaterCount;
        }
        int ans = 0;
        for(int i = 0; i < sz; i++)
        {
            ans = (ans + ((arr[i] * ((long long)(left[i] * right[i])%1000000007))%1000000007))%1000000007;
        }
        return ans;
    }
};