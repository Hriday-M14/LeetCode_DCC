// Determine If String Halves are Alike

class Solution {
public:
    bool isVowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
                || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    bool halvesAreAlike(string s) {
        int mid = s.size()/2;
        int i=0, j=mid, count1=0, count2=0;
        while(i<mid)
        {
            if(isVowel(s[i]))
                count1++;
            i++;
        }
        while(j<s.size())
        {
            if(isVowel(s[j]))
                count2++;
            j++;
        }
        return count1==count2;
    }
};