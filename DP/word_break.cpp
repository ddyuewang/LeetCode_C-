#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // f[i] = or (f[j], j+1-i is also a word in the wordDict)
        int n = s.length();
        bool f[n+1];
        f[0] = true;
        //get the max length
        int max_len = 0;
        for (int i=0; i< wordDict.size(); i++)
        {
            if(max_len < wordDict[i].length())
            { max_len = wordDict[i].length();}
        }

        // main update
        for (int i =1; i<= n; i++)
        {
            f[i] = false;
            // main logic
            for (int j=1; j<=max_len && j<=i; j++)
            {
                if(!f[i-j]) {continue;}
                string tmp = s.substr(i-j,j);
                if ( std::find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end())
                {   f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }

};