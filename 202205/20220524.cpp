//
// Created by aldlss on 2022/5/24.
//

//965. 单值二叉树
//简单题，嗯递归

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root->left)
            if(root->left->val!=root->val||!isUnivalTree(root->left))
                return false;
        if(root->right)
            if(root->right->val!=root->val||!isUnivalTree(root->right))
                return false;
        return true;
    }
};
