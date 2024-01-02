// Assign Cookies
// It is given in the Question that We have to maximize the number of our content children. Clearly this can be achieved only if we select the size of the Cookie 
// which is just greater than or equal to the greed factor of our children. This Observation leads us to the conclusion that Sorting the arrays first will help us
// in implementing the Solution.

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int Ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int CurrCookie = 0, CurrChild = 0;
        while(CurrCookie < s.size() && CurrChild < g.size())
        {
            if(s[CurrCookie]>=g[CurrChild])
            {
                Ans++;
                CurrCookie++;
                CurrChild++;
            }
            else
            {
                CurrCookie++;
            }
        }
        return Ans;
    }
};