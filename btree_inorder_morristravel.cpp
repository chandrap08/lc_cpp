#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using str = string;
using pii = pair<int,int>;
using pll = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vector<int>>;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Morris travel
// stacks

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* curr = root;

// Stack method
/*         while(curr != NULL || !s.empty()){
            while(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            res.push_back(curr->val);
            curr = curr->right;
            s.pop();
        } */

// Morris travel - start with curr as root then find the right most node of the right subtree. 
// Make curr as the right child of the right most node.
// Move the curr to left child
// Assign curr left child as null to avoid infinite loops.

        TreeNode* temp;
        while(curr != NULL ){
            if(curr->left != NULL){
                temp = curr->left;
                while(temp->right != NULL){
                    temp = temp->right;
                }
                temp->right = curr;
                TreeNode* t = curr;
                curr = curr->left;
                t->left = NULL;
            }else{
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        return res;
    }
};

int main(){
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n7 = new TreeNode(7);
    n1->val = 1;
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n7;

    Solution* obj;
    vector<int> r = obj->inorderTraversal(n1);
    for(auto i: r){
        cout << i << endl;
    }
}