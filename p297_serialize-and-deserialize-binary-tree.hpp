#include <string>
#include <sstream>
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "X";
        string v = to_string(root->val);
        string l = serialize(root->left);
        string r = serialize(root->right);
        return v + ',' + l + ',' + r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q = splitData(data);
        return buildTree(q);
    }
private:
    TreeNode* buildTree(queue<string> & tokens) {
        string token = tokens.front();
        tokens.pop();
        if(token == "X")
            return nullptr;
        
        int val = stoi(token);
        TreeNode* root = new TreeNode(val);
        root->left = buildTree(tokens);
        root->right = buildTree(tokens);
        return root;
    }

    queue<string> splitData(string & data) {
        stringstream ss(data);
        string token;
        queue<string> q;
        while(getline(ss, token, ',')) {
            q.push(token);
        }
        return q;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));