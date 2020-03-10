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

void traUpDown(TreeNode *root)
{
    if(!root) return;

    deque<TreeNode*> q;
    int q_size = 0;

    q.push_front(root);
    while((q_size=q.size())) {
        while(q_size--) {
            TreeNode *node = q.back(); q.pop_back();
            cout << node->val << ' ';
            if(node->left) q.push_front(node->left);
            if(node->right) q.push_front(node->right);
        }
        cout << endl;
    }
}

void traDownUp(TreeNode * root)
{
    if(!root) return;

    deque<TreeNode*> s;
    deque<TreeNode*> q;
    int q_size = 0;

    q.push_front(root);
    while((q_size=q.size())) {
        while(q_size--) {
            TreeNode* node = q.back(); q.pop_back();
            if(node->right) q.push_front(node->right);
            if(node->left) q.push_front(node->left);
            s.push_front(node);
        }
        s.push_front(nullptr);
    }

    while(s.size()) {
        TreeNode* node = s.front(); s.pop_front();
        if(!node) cout << endl;
        else cout << node->val << ' ';
    }
}

//------------------------------------------------------------------------------------------------- Easy

/*
 * Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
 */

struct lc0119 {
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        res[0] = 1;
        for(int i=1; i<=rowIndex; i++)
            for(int j=i; j>=1; j--)
                res[j] += res[j-1];
        return res;
    }
};

void main_lc0119() {
    lc0119 solu;
    auto ans = solu.getRow(3);
    for(auto a:ans)
        cout << a << " ";
    cout << endl;
}

/*
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 */
struct lc0118 { //E
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);

        if(!numRows) return res;

        for(auto i=0; i<numRows; i++) {
            for(auto j=0; j<=i; j++) {
                if(j==0 || j==i)
                    res[i].push_back(1);
                else
                    res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            }
        }
        return res;
    }
};

void main_lc0118() {
    lc0118 solu;
    auto ans = solu.generate(5);
    for(auto i : ans) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
}


/*
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up
 * all the values along the path equals the given sum.
 */
struct lc0112 {
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right && root->val==sum) return true;
        return hasPathSum(root->left, sum-root->val) ||
               hasPathSum(root->right, sum-root->val);
    }
};

void main_lc0112() {
    lc0112 solu;
    TreeNode *tree = new TreeNode(5);
    tree->left = new TreeNode(4);
    tree->right = new TreeNode(8);
    tree->left->left = new TreeNode(11);
    tree->right->left = new TreeNode(13);
    tree->right->right = new TreeNode(4);
    tree->left->left->left = new TreeNode(7);
    tree->left->left->right = new TreeNode(2);
    tree->right->right->right = new TreeNode(1);
    traUpDown(tree);
    cout << endl << solu.hasPathSum(tree, 22) << endl;
}


/*
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */
struct lc0111 {
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right)  return 1;

        int hLeft = root->left ? minDepth(root->left) : INT_MAX;
        int hRight = root->right ? minDepth(root->right) : INT_MAX;
        return min(hLeft, hRight)+1;
    }
};

void main_lc0111() {
    lc0111 solu;
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
//    tree->left = new TreeNode(9);
//    tree->right = new TreeNode(20);
//    tree->right->left = new TreeNode(15);2
//    tree->right->right = new TreeNode(7);
    traUpDown(tree);
    cout << solu.minDepth(tree) << endl;
}

/*
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 */

struct lc0110 { //E
    int _getTreeDepth(TreeNode *node, bool &bIsBalanced) {
        if(!node) return 0;

        int hLeft = _getTreeDepth(node->left, bIsBalanced);
        int hRight = _getTreeDepth(node->right, bIsBalanced);
        if(abs(hLeft-hRight)>1) bIsBalanced = false;
        return max(hLeft, hRight)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        bool bIsBalanced = true;
        _getTreeDepth(root, bIsBalanced);
        return bIsBalanced;
    }
};

void main_lc0110(void) {
    lc0110 solu;
    TreeNode *tree = new TreeNode(3);
    tree->left = new TreeNode(9);
    tree->right = new TreeNode(20);
    tree->right->left = new TreeNode(15);
    tree->right->right = new TreeNode(7);
    traUpDown(tree);
    cout << solu.isBalanced(tree) << endl;
}


/*
 * Convert Sorted Array to Binary Search Tree
 */
struct lc0108 {
    TreeNode* _sortedArrayToBST(vector<int>& nums, int l, int r) {
        if(l>r) return nullptr;

        int m = l + (r-l)/2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = _sortedArrayToBST(nums, l, m-1);
        node->right = _sortedArrayToBST(nums, m+1, r);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size()-1);
    }
};

void main_lc0108(void)
{
    lc0108 solu;
    vector<int> nums {-10,-3,0,5,9};
    traUpDown(solu.sortedArrayToBST(nums));
}

/*
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right,
 * level by level from leaf to root).
 */
struct lc0107 {
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        deque<TreeNode*> s;
        deque<TreeNode*> q;
        int q_size = 0;

        q.push_front(root);
        while((q_size=q.size())) {
            while(q_size--) {
                TreeNode* node = q.back(); q.pop_back();
                if(node->right) q.push_front(node->right);
                if(node->left) q.push_front(node->left);
                s.push_front(node);
            }
            s.push_front(nullptr);
        }

        s.pop_front();
        vector<int> level;
        while(s.size()) {
            TreeNode* node = s.front(); s.pop_front();
            if(!node) {
                res.push_back(level);
                level.clear();
            }
            else
                level.push_back(node->val);
        }
        res.push_back(level);

        return res;
    }
};

void main_lc0107(void)
{
    lc0107 solu;
    TreeNode *tree = new TreeNode(3);
    tree->left = new TreeNode(9);
    tree->right = new TreeNode(20);
    tree->right->left = new TreeNode(15);
    tree->right->right = new TreeNode(7);
    //traDownUp(tree);
    auto ans = solu.levelOrderBottom(tree);
}

/*
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */
struct lc0104 { // E
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};

void main_lc0104(void) {
    lc0104 solu;
    TreeNode* tree = new TreeNode(3);
    tree->left = new TreeNode(9);
    tree->right = new TreeNode(20);
    tree->right->left = new TreeNode(15);
    tree->right->right = new TreeNode(7);
    traUpDown(tree);
    auto ans = solu.maxDepth(tree);
    cout << ans << endl;
}

/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 */

struct lc0101 {
    bool _isSymmetric(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(!left || !right) return false;
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
    traUpDown(tree);
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