#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}

    TreeNode(int _val, TreeNode* _left, TreeNode* _right)
            : val(_val), left(_left), right(_right) {}
};

class Solution {
private:
    bool isSame = true;
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        else if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) {
            return false;
        }
        dfs(p, q);
        return isSame;
    }

    void dfs(TreeNode* currentNode_p, TreeNode* currentNode_q) {
        if (currentNode_p->val != currentNode_q->val) {
            isSame = false;
            return;
        }
        if ((currentNode_p->left != nullptr && currentNode_q->left == nullptr) || (currentNode_p->left == nullptr && currentNode_q->left != nullptr)) {
            isSame = false;
            return;
        }
        if ((currentNode_p->right != nullptr && currentNode_q->right == nullptr) || (currentNode_p->right == nullptr && currentNode_q->right != nullptr)) {
            isSame = false;
            return;
        }

        if (currentNode_p->right != nullptr && currentNode_q->right != nullptr) {
            dfs(currentNode_p->right, currentNode_q->right);
        }
        if (currentNode_p->left != nullptr && currentNode_q->left != nullptr) {
            dfs(currentNode_p->left, currentNode_q->left);
        }
    }
};

int main() {
    TreeNode* root_of_p = new TreeNode(1);
    TreeNode* root_of_q = new TreeNode(1);
    TreeNode* left_p = new TreeNode(2);
    TreeNode* right_q = new TreeNode(2);

    root_of_p->left = left_p;
    root_of_q->right = right_q;

    Solution sol;
    if (sol.isSameTree(root_of_p, root_of_q)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}