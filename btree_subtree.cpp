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

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(isIdentical(root, subRoot)) return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

    bool isIdentical(TreeNode* s, TreeNode* t){
        if(s == NULL && t == NULL) return true;
        if(s == NULL || t == NULL) return false;
        if(s->val != t->val) return false;
        return isIdentical(s->left,t->left) && isIdentical(s->right, t->right);
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
    bool r = obj->isSubtree(n1,n1);
    cout << r;

}