// Find Players With Zero or One Losses

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        map<int, int> WinFreq, LoseFreq;
        for(int i = 0; i < matches.size(); i++)
        {
            WinFreq[matches[i][0]]++;
            LoseFreq[matches[i][1]]++;
        }
        vector<int> NotLostAnyMatch, LostOneMatch;
        map<int, int>::iterator it;
        for(it = WinFreq.begin(); it != WinFreq.end(); it++)
        {
            if(LoseFreq.find(it->first)==LoseFreq.end())
                NotLostAnyMatch.push_back(it->first);
        }
        for(it = LoseFreq.begin(); it != LoseFreq.end(); it++)
        {
            if(it->second==1)
                LostOneMatch.push_back(it->first);
        }
        ans.push_back(NotLostAnyMatch);
        ans.push_back(LostOneMatch);
        return ans;
    }
};