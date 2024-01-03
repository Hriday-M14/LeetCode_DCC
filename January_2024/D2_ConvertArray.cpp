// Convert an Array Into a 2D Array With Conditions

// It is given that each row in the 2D Array should contain distinct integers and the number of rows in the 2D Array should
// be minimal. The minimum number of rows in 2D Array thus will be equal to the maximum frequency of a element in nums

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> freq;
        int RowsInAns = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        unordered_map<int, int>::iterator it = freq.begin();
        for(; it != freq.end(); it++)
            RowsInAns = max(RowsInAns, it->second);
        
        for(int i = 0; i < RowsInAns; i++)
        {
            vector<int> Row;
            for(it = freq.begin(); it != freq.end(); it++)
            {
                if(it->second > 0)
                {
                    Row.push_back(it->first);
                    it->second--;
                }
            }
            ans.push_back(Row);
        }
        return ans;
    }
};