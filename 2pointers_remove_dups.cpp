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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *cur = head;

        if(cur == NULL || cur->next == NULL){return head;}

        while(cur != NULL){
            if(cur != NULL && cur->next != NULL && cur->val == cur->next->val){
                while(cur->next != NULL && cur->val == cur->next->val){
                    cur = cur->next;
                }
                if(prev == NULL){
                    head = cur->next;
                }else{
                    prev->next = cur->next;
                }
            }else{
                prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};

int main(){
    vector<ListNode*> lists;
    ListNode* list1 = new ListNode();
    vector<int> a = {2,4,4,4,4,6,8,10};
    auto tail = list1;

    for(auto i:a){
        ListNode* tmp = new ListNode(i);
        if(list1 == nullptr){
            list1 = tmp;
            tail = tmp;
        }
        tmp->val = i;
        tmp->next = nullptr;
        tail->next = tmp;
        tail = tail->next;
    }

    Solution obj;
    ListNode* result = obj.deleteDuplicates(list1);

    while(result->next){
        cout << "print result";
        cout << result->val << endl;
        result = result->next;
    }
}