class Solution {
public:
    int depth = -1;
    vector<vector<string>> res;
    int size = 0;
    void helper(TreeNode* node, int dep) {
        if (node == NULL) {
            depth = max(depth,dep);
            return;
        }
        helper(node->left,dep + 1);
        helper(node->right, dep +1);
    }
    
    void build(TreeNode* node, int depth, int mid) {
        if (node == NULL)
            return;
        //cout<<mid<<endl;
        res[depth-1][mid] = to_string(node->val);
        //cout<<(size>>(depth+1))<<endl;
        build(node->right,depth+1,mid+(size>>(depth+1)));
        build(node->left,depth+1,mid-(size>>(depth+1)));
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        helper(root,0);
        size = 1<<depth;
        res = vector<vector<string>>(depth,vector<string>((1<<depth)-1,""));
        build(root,1,size/2-1);
        return res;
    }
};