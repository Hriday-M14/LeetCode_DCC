// Determine if Two Strings are Close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        vector<int> Chars1Freq(26, 0), Chars2Freq(26, 0);
        vector<bool> Char1Present(26, false), Char2Present(26, false);

        for(int i = 0; i < word1.size(); i++)
        {
            Chars1Freq[word1[i]-'a']++;
            Char1Present[word1[i]-'a'] = true;
        }
        for(int i = 0; i < word2.size(); i++)
        {
            Chars2Freq[word2[i]-'a']++;
            Char2Present[word2[i]-'a'] = true;
        }
        sort(Chars1Freq.begin(), Chars1Freq.end());
        sort(Chars2Freq.begin(), Chars2Freq.end());
        return Chars1Freq == Chars2Freq && Char1Present == Char2Present;
    }
};