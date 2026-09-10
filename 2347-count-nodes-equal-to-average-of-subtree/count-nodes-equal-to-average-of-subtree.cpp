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
    int matchingNodesCount=0;
    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0,0};

        auto left=dfs(root-> left);
        auto right=dfs(root-> right);

        int currentSum = root->val + left.first + right.first;
        int currentCount = 1+ left.second + right.second;

        if (currentSum / currentCount == root->val) {
            matchingNodesCount++;

        }
        return {currentSum,currentCount};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchingNodesCount;
    }
};