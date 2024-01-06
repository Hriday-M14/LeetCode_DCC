// Longest Increasing Subsequence
// T.C.: O(N*N)
// S.C.: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        int *output = new int[sz];
        for(int i=0; i<sz; i++)
        {
            output[i] = 1;
            int possAns = INT_MIN;
            for(int j=i-1; j>=0; j--)
            {
                if(nums[i]>nums[j])
                {
                    possAns = max(possAns, output[j]);
                    output[i] = possAns+1;
                }   
                
            }
        }
        int best = INT_MIN;
        for(int i=0; i<sz; i++)
        {
            best = max(best, output[i]);
        }
        return best;
    }
};

// Here the temp vector will not exactly be our longest strictly increasing subsequence. We are only using the Greedy Approach
// to get the estimate of what exactly be the size or length of our Longest Strictly increasing Subsequence.
// There might be cases also where temp vector elements matches with the longest strictly increasing subsequence.
// T.C.: O(N*LogN)
// S.C.: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++)
        {
            if(temp.back() < nums[i])
                temp.push_back(nums[i]);
            else
            {
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
        return temp.size();
    }
};

