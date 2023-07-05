#include <vector>
#include <queue>
#include "common.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        // bfs
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            // 把这一层所有的数据都读出来
            int size = q.size();
            for(int i = 0; i < size; i ++ ) {
                TreeNode * node = q.front();
                q.pop();

                // 把下一层数据加入队列
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);

                // 当前层的最后一个加入ans
                if(i == size - 1) ans.push_back(node->val);
            }
        }
        return ans;
    }
};