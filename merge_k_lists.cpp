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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* head = new ListNode;
        auto mergedList = head;


        priority_queue<int, vector<int>, greater<int>>q;

        for(const auto &l:lists){
            ListNode* temp = l;
            while(temp != nullptr){
                q.push(temp->val);
                temp = temp->next;
            }
        }

        while(!q.empty()){
            int val = q.top();
            ListNode* temp = new ListNode(val);
            mergedList->next = temp;
            mergedList = mergedList->next;
            q.pop();
        }
        return head->next;
    }
    
};

int main(){
    vector<ListNode*> lists;
    ListNode* list1 = new ListNode();
    ListNode* list2 = new ListNode();
    ListNode* list3 = new ListNode();

    vector<int> a = {2,4,6,8,10};
    vector<int> b = {3,5,7,9,11};
    vector<int> c = {5,10,15};

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
    for(auto i:b){
        list2->val = i;
        list2 = list2->next;
    }
    for(auto i:c){
        list3->val = i;
        list3 = list3->next;
    }
    lists = {list1,list2,list3};

    while(list1!= nullptr){
        cout << list1->val;
        list1 = list1->next;
    }


    priority_queue<int,vector<int>,greater<int>> q;
    for(const auto& l:lists){
        ListNode* t = l;
        cout << l->val;
        while(t != nullptr){
            q.push(t->val);
            t = t->next;
        }
    }

    while(!q.empty()){
        cout << q.top();
        q.pop();
    }

    //Solution* obj = new Solution;
    //cout << obj->mergeKLists(lists);
}