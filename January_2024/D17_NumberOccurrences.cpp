// Unique Number of Occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int i = 0; i < arr.size(); i++)
            freq[arr[i]]++;

        set<int> s;
        unordered_map<int, int>::iterator it;
        for(it = freq.begin(); it != freq.end(); it++)
        {
            if(s.find(it->second) != s.end())
                return false;
            else
                s.insert(it->second);
        }
        return true;
    }
};