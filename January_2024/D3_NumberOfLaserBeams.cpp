// Number of Laser Beams in a Bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int TotalLaserBeams = 0;
        int TotalDevInPrevRow = 0, rows = bank.size();
        for(int i = 0; i < bank[0].size(); i++)
        {
            if(bank[0][i]=='1')
                TotalDevInPrevRow++;
        }
        for(int i = 1; i < rows; i++)
        {
            int TotalDevInCurrRow = 0;
            for(int j = 0; j < bank[i].size(); j++)
            {
                if(bank[i][j]=='1')
                    TotalDevInCurrRow++;
            }
            TotalLaserBeams += (TotalDevInCurrRow*TotalDevInPrevRow);
            if(TotalDevInCurrRow>0)
                TotalDevInPrevRow = TotalDevInCurrRow;
        }
        return TotalLaserBeams;
    }
};