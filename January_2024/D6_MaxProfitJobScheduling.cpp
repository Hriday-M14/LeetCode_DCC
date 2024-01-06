// Maximum Profit in Job Scheduling

class Solution {
public:
    int MaximumProfit(vector<pair<int, pair<int, int>>>& Jobs, int CurrJob, int TotalJobs, vector<int>& dp, vector<int>& startTime)
    {
        if(CurrJob >= TotalJobs)
            return 0;
        if(dp[CurrJob]!=-1){
            return dp[CurrJob];
        }

        int NextJobToConsider = lower_bound(startTime.begin(), startTime.end(), Jobs[CurrJob].second.first) - startTime.begin();
        int Include = Jobs[CurrJob].second.second + MaximumProfit(Jobs, NextJobToConsider, TotalJobs, dp, startTime);
        int Exclude = MaximumProfit(Jobs, CurrJob+1, TotalJobs, dp, startTime);
        dp[CurrJob] = max(Include, Exclude);
        return dp[CurrJob];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int, pair<int, int>>> jobs(startTime.size());
        for(int i = 0; i < startTime.size(); i++)
        {
            jobs[i].first = startTime[i];
            jobs[i].second.first = endTime[i];
            jobs[i].second.second = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());
        vector<int> dp(jobs.size()+1, -1);
        return MaximumProfit(jobs, 0, jobs.size(), dp, startTime);
    }
};