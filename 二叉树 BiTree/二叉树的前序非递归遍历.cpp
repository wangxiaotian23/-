/*

  测试地址：https://www.lintcode.com/problem/binary-tree-preorder-traversal/description

*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
/*
算法思想:在栈非空或节点非空的情况下执行循环
		 while()中先进入根节点，访问根节点值，并进栈，而后向左下去访问其左子树
		 if()中先保存顶点节点，再pop出去，而后访问之前节点的右子树
*/
class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
        stack<TreeNode*> stack ;
        vector<int> ans;
        TreeNode *p=root;
        while(p||!stack.empty()){
            while(p){
                ans.push_back(p->val);
                stack.push(p);
                p=p->left;
            }
            if(!stack.empty()){
                p=stack.top();
                stack.pop();
                p=p->right;
            }
        }
        return ans;
    }
};