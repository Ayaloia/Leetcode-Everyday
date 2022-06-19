//
// Created by aldlss on 2022/6/19.
//

//508. 出现次数最多的子树元素和
//草，原本想着使用哈希mutiset的
//结果发现判断的时候不好判断，时间复杂度也挺高，最后看题解是用哈希map？？？
//不得不说确实也是物尽其用了，还是你们会玩

#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>sums{};
        int maxx=0;
        vector<int>ans{};
        function<int(TreeNode* root)>f=[&](TreeNode* root)->int {
            if(!root)return 0;
            int sum=f(root->left)+f(root->right)+root->val;
//            sums.emplace(sum);
            ++sums[sum];
            maxx=max(maxx,sums[sum]);
            /*int temp=static_cast<int>(sums.count(sum));
            if(temp>maxx)
            {
                ans.clear();
                ans.emplace_back(sum);
                maxx=temp;
            }
            else if(temp==maxx)
                ans.emplace_back(sum);*/
            return sum;
        };
        f(root);
        for(auto &[num,count]:sums)
        {
            if(count==maxx)
                ans.emplace_back(num);
        }
        return ans;
    }
};