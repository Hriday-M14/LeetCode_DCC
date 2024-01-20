// Minimum Number of Steps to Make Two Strings Anagram

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int, int> Freq1, Freq2;
        for(int i = 0; i < s.size(); i++)
            Freq1[s[i]]++;
        for(int i = 0; i < t.size(); i++)
            Freq2[t[i]]++;
        int Ans = 0;
        unordered_map<int, int>::iterator it = Freq2.begin();
        for(; it != Freq2.end(); it++)
        {
            unordered_map<int, int>::iterator itForS = Freq1.find(it->first);
            if(itForT != Freq2.end())
            {
                if(it->second>itForT->second)
                    Ans += it->second - itForT->second;
            }
            else
                Ans += it->second;
        }
        return Ans;
    }
};