//
// Created by aldlss on 2022/6/2.
//

//450. 删除二叉搜索树中的节点
//不懂，首先想到旋转节点到叶子然后删除了
//看起来似乎有比较不一样的方法（？或者是不同的理解方法（？
//这种题不好调试，搞死人，只能嗯print，太谔谔了

class Solution {
public:
    TreeNode* rightZip(TreeNode* root)
    {
        TreeNode* temp=root->left->right;
        root->left->right=root;
        root=root->left;
        root->right->left=temp;
        return root;
    }
    TreeNode* leftZip(TreeNode* root)
    {
        TreeNode* temp=root->right->left;
        root->right->left=root;
        root=root->right;
        root->left->right=temp;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(root->val!=key)
        {
            if(root->val>key)
            {
                root->left=deleteNode(root->left,key);//这里要更新子节点啊
                return root;
            }
            else
            {
                root->right=deleteNode(root->right,key);
                return root;
            }
        }
        if(root->left)
        {
            root=rightZip(root);//要更新自己
            root->right=deleteNode(root->right,key);//这里也要更新子节点
            return root;
        }
        if(root->right)
        {
            root=leftZip(root);
            root->left=deleteNode(root->left,key);
            return root;
        }
        delete root;
        root = nullptr;
        return root;
    }
};