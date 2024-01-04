// Minimum Number of Operations to Make Array Empty

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        unordered_map<int, int>::iterator it = freq.begin();
        for(; it != freq.end(); it++)
        {
            if(it->second==1)
            {
                ans = -1;
                break;
            }
            else if(it->second%3==1)
            {
                ans += (it->second/3) - 1;
                ans += 2;
            }
            else
            {
                ans += (it->second/3);
                ans += (it->second%3)/2;
            }
        }
        return ans;
    }
};