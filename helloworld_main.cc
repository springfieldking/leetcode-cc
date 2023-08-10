
#include <vector>
#include <iostream>

class TreeNode{
public:
    TreeNode() {
        val = 0;
        l = nullptr;
        r = nullptr;
    }
    int val;
    TreeNode *l;
    TreeNode *r;
};

void search(TreeNode *t, int k, std::vector<int> & ret) {
    if(t == nullptr) {
        std::cout << "search: null return " << std::endl;
        return;
    }
    search(t->l, k, ret);

    if(ret.size() >= k) {
        std::cout << "search: full return " << std::endl;
        return;
    }
    std::cout << "search: " << t->val << std::endl;
    ret.push_back(t->val);

    search(t->r,  k, ret);
}

void main() {
    
    TreeNode node1;
    node1.val = 1;

    TreeNode node3;
    node3.val = 3;

    TreeNode root;
    root.val = 2;

    root.l = &node1;
    root.r = &node3;

    std::cout << "===== begin =====" << std::endl;
    std::vector<int> ret;
    search(&root, 2, ret);
    std::cout << ret.back() << std::endl;
    std::cout << "===== end: " << ret.size() << " =====" << std::endl;
}