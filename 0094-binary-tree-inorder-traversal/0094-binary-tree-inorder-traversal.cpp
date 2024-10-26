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
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;

        while (current != nullptr || !st.empty()) {
            // Reach the leftmost node of the current node
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            
            // Current must be null at this point
            current = st.top();
            st.pop();
            result.push_back(current->val); // Visit the root
            
            // Visit the right subtree
            current = current->right;
        }

        return result;
    }
};
