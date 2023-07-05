#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
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
            // 同一层,跳过相同的元素,避免结果相同
            if (i > begin && candidates[i] == candidates[i - 1]) {
                continue;
            }

            path.push_back(candidates[i]);
            // 这里避免相同组合,从i+1开始
            backtrack(candidates, target-candidates[i], i + 1, path, ans);
            path.pop_back();
        }
    }
};