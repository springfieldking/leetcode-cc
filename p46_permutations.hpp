#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<int> selected;
        selected.resize(nums.size());
        backtrack(nums, ans, path, selected);
        return ans;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, vector<int>& selected){
        if(path.size() == nums.size()) {
            vector<int> p = path;
            ans.push_back(p);
            return;
        }

        for(int i = 0; i < nums.size(); i ++) {
            // 剪枝,跳过访问过的节点
            if (selected[i] == 1) continue;

            selected[i] = 1;
            path.push_back(nums[i]);
            backtrack(nums, ans, path, selected);
            selected[i] = 0;
            path.pop_back();
        }
    }
};