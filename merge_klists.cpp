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

#define F first
#define L last
#define S second
#define PB push_back
#define MP make_pair
#define sz(x) = int(x.size())


 // Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void insertNode(ListNode *node, ListNode *new_node){
    new_node->next = node->next;
    node->next = new_node;

}
void AppendNode(ListNode* node, ListNode* tail){
    tail->next = node;
    tail = node;
    node = node->next;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    ListNode* head = new ListNode;
    auto tail = head;
    while(list1 && list2){
        //AppendNode(list1->val <= list2->val ? list1:list2, tail);
        if(list1->val <= list2->val){
            tail->next = list1;
            list1 = list1->next;
        }
        else{
            tail->next = list2;
            list2 = list2->next;
            }
        tail = tail->next;
    }

    tail->next = list1? list1:list2;
    return head->next;
    }
};


int main(){
    ListNode* L1 = new ListNode;
    ListNode* L2 = new ListNode;

    vector<int> a = {6,9,12,15,18};
    vector<int> c = {3,4,10,13};

    for(auto i:a){
        ListNode* b = new ListNode(i,L1);
        L1 = b;
        //insertNode(L1,b);
    }

    for(auto i:c){
        ListNode* d = new ListNode(i,L2);
        L2 = d;
        //insertNode(L2,d);
    }

    // while(L1){
    //     cout << L1->val << endl;
    //     L1 = L1->next;
    // }

    // while(L2){
    //     cout << L2->val << endl;
    //     L2 = L2->next;
    // }

    Solution* obj = new Solution;
    cout << obj->mergeTwoLists(L1,L2);
    
}