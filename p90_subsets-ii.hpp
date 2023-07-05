#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, path, 0);
        return ans;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, int begin) {
        ans.push_back(path);
        for(int i = begin; i < nums.size(); i++) {
            // 剪枝,同一层级相同的元素不重复遍历
            if(i > begin && nums[i] == nums[i -1]) continue;

            path.push_back(nums[i]);
            backtrack(nums, ans, path, i + 1);
            path.pop_back();
        }
    }
};