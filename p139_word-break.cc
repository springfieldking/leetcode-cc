#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
private:
    string subString(string s, int i, int j) {
        return "";
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp
        set<string> wordSet;
        for(auto & w : wordDict) {
            wordSet.insert(w);
        }

        vector<bool> dp;
        dp.resize(s.size() + 1);
        dp[0] = true;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size()+1; j ++) {
                if(dp[i] && wordSet.find(subString(s, i, j)) != wordSet.end()) {
                    dp[j] = true;
                }
            }
        }
        return dp[ s.size()];
    }

private:
    bool backtrack(string s, const set<string> & wordSet) {
        if(s.size() == 0) {
            return true;
        }

        bool ret = false;
        for(int i = 0; i < s.size(); i++) {
            auto subs1 = subString(s, 0, i);
            if(wordSet.find(subs1) != wordSet.end()) {
                ret = backtrack(subString(s, i, s.size()), wordSet) || ret;
            }
        }
        return ret;
    }
public:

    bool wordBreak_backtrack(string s, vector<string>& wordDict) {
        set<string> wordSet;
        for(auto & w : wordDict) {
            wordSet.insert(w);
        }
        return backtrack(s, wordSet);
    }
};

void main() {
    Solution s;
}