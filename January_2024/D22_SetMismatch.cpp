// Set Mismatch 

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> freq;
        int TotalSumOfNums = 0, duplicate = 0, missing = 0, sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            TotalSumOfNums += nums[i];
            if(freq.find(nums[i]) == freq.end())
                freq[nums[i]]++;
            else
                duplicate = nums[i];
        }
        ans.push_back(duplicate);
        missing = (sz*(sz+1))/2-TotalSumOfNums+duplicate;
        ans.push_back(missing);
        return ans;
    }
};