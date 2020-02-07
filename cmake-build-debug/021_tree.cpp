#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfsInOrder(TreeNode *root)
{
    if(root->left) dfsInOrder(root->left);
    cout << root->val << ' ';
    if(root->right) dfsInOrder(root->right);
}

//------------------------------------------------------------------------------------------------- Easy

/*
 * Given two binary trees, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 */
struct lc0100 {
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p&&!q) return true;
        if((!p||!q) || (p->val!=q->val))return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

void main_lc0100(void)
{
    lc0100 solu;
    TreeNode *tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    cout << "tree 1: ";
    dfsInOrder(tree1);
    cout << endl;
    TreeNode *tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    cout << "tree 2: ";
    dfsInOrder(tree2);
    cout << endl;

    auto ans = solu.isSameTree(tree1, tree2);
    cout << ans << endl;
}