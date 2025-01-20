
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void solve(TreeNode * root, vector<int> & resultArray){
         if(root == nullptr){
            return;
         }
         // go to left subTree
         solve(root->left,resultArray);
         // store the node->data 
         resultArray.push_back(root->val);
         // go to right subTree
         solve(root->right,resultArray);

    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> resultArray;
         solve(root,resultArray);
         return resultArray;
    }
};