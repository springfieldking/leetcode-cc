#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(nums, ans, path, 0);
        return ans;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, int begin) {
        ans.push_back(path);
        for(int i = begin; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, ans, path, i + 1);
            path.pop_back();
        }
    }
};