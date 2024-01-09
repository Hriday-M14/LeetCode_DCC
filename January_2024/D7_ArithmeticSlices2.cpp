// Arithmetic Slices 2 - Subsequences

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int Ans = 0, sz = nums.size();
        unordered_map<long, int> mp[sz];
        for(int i = 0; i < sz; i++)
        {
            for(int j = 0; j < i; j++)
            {
                long diff = (long)(nums[i]) - (nums[j]);
                int count_j = 0;
                if(mp[j].find(diff) != mp[j].end())
                {
                    count_j = mp[j][diff];
                }
                else
                    count_j = 0;
                Ans += count_j;
                mp[i][diff] += count_j + 1;
            }
        }
        return Ans;
    }
};