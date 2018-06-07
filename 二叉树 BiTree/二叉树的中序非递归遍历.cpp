/*

  ���Ե�ַ��
			https://www.lintcode.com/problem/binary-tree-inorder-traversal/description

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
�㷨˼��:��ջ�ǿջ�ڵ�ǿյ������ִ��ѭ��
		 while()���Ƚ�����ڵ㣬����ջ���������������ȥ��������
		 if()���ȱ��涥��ڵ㣬�ٷ�����ڵ�ֵ��������pop��ȥ���������֮ǰ�ڵ��������
*/
class Solution {
public:
/**
* @param root: A Tree
* @return: Inorder in ArrayList which contains node values.
	*/
    vector<int> inorderTraversal(TreeNode * root) {
        // write your code here
        stack<TreeNode*> stack ;
        vector<int> ans;
        TreeNode *p=root;
        while(p||!stack.empty()){
            while(p){
                stack.push(p);
                p=p->left;
            }
            if(!stack.empty()){
                p=stack.top();
                ans.push_back(p->val);
                stack.pop();
                p=p->right;
            }
        }
        return ans;
    }
};