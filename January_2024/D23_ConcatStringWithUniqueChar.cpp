// Maximum Length of a Concatenated String with Unique Characters

class Solution {
public:
    int max(int a, int b)
    {
        return (a>b)?a:b;
    }
    bool CanBeConcatenated(string s, unordered_map<char, int>& freq)
    {
        unordered_set<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            if((st.find(s[i]) != st.end()) || (freq.find(s[i]) != freq.end()))
                return false;
            st.insert(s[i]);
        }
    
        for(int i = 0; i < s.size(); i++)
            freq[s[i]]++;
        return true;
    }
    void GetMaxLen(vector<string>& arr, int CurrIdx, int& MaxLen, unordered_map<char, int>& freq)
    {
        MaxLen = max(MaxLen, freq.size());
        if(CurrIdx >= arr.size())
            return;
        if(CanBeConcatenated(arr[CurrIdx], freq))
        {
            GetMaxLen(arr, CurrIdx+1, MaxLen, freq);
            for(int j = 0; j < arr[CurrIdx].size(); j++)
            {
                freq.erase(arr[CurrIdx][j]);
            }
        }
        GetMaxLen(arr, CurrIdx+1, MaxLen, freq);
    }
    int maxLength(vector<string>& arr) {
        int MaxLen = 0;
        unordered_map<char, int> freq;
        GetMaxLen(arr, 0, MaxLen, freq);
        return MaxLen;
    }
};