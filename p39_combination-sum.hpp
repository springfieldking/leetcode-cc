#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(candidates, target, 0, path, ans);
        return ans;
    }
private:
    void backtrack(vector<int>& candidates, int target, int begin, vector<int>& path, vector<vector<int>>& ans) {
        // 不符合结果,剪枝
        if(target < 0)  return;
        
        // 符合结果
        if(target == 0) {
            vector<int> p = path;
            ans.push_back(p);
            return;
        }

        for(int i = begin; i < candidates.size(); i ++) {
            path.push_back(candidates[i]);
            // 这里begin如果每次从0开始则,则会枚举出同一个答案的不同组合,比如[2,2,3] [2,3,2] [3,2,2],基本和深度递归一样了
            // 如果从i开始相当于做了一些剪枝,不会把之前做的选择再选一遍
            backtrack(candidates, target-candidates[i], i, path, ans);
            path.pop_back();
        }
    }
};