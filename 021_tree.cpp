#include <iostream>
#include <vector>
#include <deque>
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

void traUpDwon(TreeNode *root)
{
    if(!root) return;

    deque<TreeNode*> q;
    int q_size = 0;

    q.push_front(root);
    while(q_size=q.size()) {
        while(q_size--) {
            TreeNode *node = q.back(); q.pop_back();
            cout << node->val << ' ';
            if(node->left) q.push_front(node->left);
            if(node->right) q.push_front(node->right);
        }
        cout << endl;
    }
}

//------------------------------------------------------------------------------------------------- Easy

struct lc0101 {
    bool _isSymmetric(TreeNode* left, TreeNode* right) {
        if((!left && right) || (left && !right))
            return false;
        if(!left && !right)
            return true;
        return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left) && left->val == right->val;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return _isSymmetric(root->left, root->right);
    }
};

void main_lc0101(void)
{
    lc0101 solu;
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(2);
    tree->left->left = new TreeNode(3);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(4);
    //tree->right->right = new TreeNode(3);
    traUpDwon(tree);
    auto ans = solu.isSymmetric(tree);
    cout << ans << endl;
}

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