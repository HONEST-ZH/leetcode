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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> layer,next_layer;
        vector<int> layer_res;
        TreeNode* node;

        if (root != nullptr) layer.push(root);
        else return res;     
        //维护layer和next_layer
        while(1){
            //cout<<"nl"<<next_layer.size()<<"\n";
            while (!layer.empty()){
                //cout<<"l"<<layer.size()<<"\n";
                //节点从队头出队
                node = layer.front();
                //把该层内容添加到结果，子节点加入队列尾部
                layer_res.push_back(node->val);
                if (node->left != nullptr) next_layer.push(node->left);
                if (node->right != nullptr) next_layer.push(node->right); 
                layer.pop(); 
            }    
            res.push_back(layer_res);           
            layer_res.clear();
            if (next_layer.empty()) break;
            else  layer.swap(next_layer);      
        }
        return res;    
    }
};