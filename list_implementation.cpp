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
/*  template<typename T>
  struct ListNode {
      int val;
      ListNode *next;
      shared_ptr<ListNode<T>> _next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };  */

template<typename T>
struct ListNode {
    T data;
    shared_ptr<ListNode<T>> _next;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

/* class Solution{
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists){

        }

}; */

void insertAfter(shared_ptr<ListNode<int>>& node, shared_ptr<ListNode<int>>& new_node){
    new_node->_next = node->_next;
    node->_next = new_node;
}

shared_ptr<ListNode<int>> SearchList(shared_ptr<ListNode<int>> L, int key){
    while(L && L->data != key){
        L = L->_next;
    }
    return L;
}

int main(){
    vector<int> a = {3,12,4,6,1,9};
    vector<int> b = {1,4,6,8,10};

    shared_ptr<ListNode<int>> head(new ListNode<int>);
    head->data = 5;
    head->_next = nullptr;

    shared_ptr<ListNode<int>> second(new ListNode<int>);
    second->data = 6;

    shared_ptr<ListNode<int>> third(new ListNode<int>);
    third->data = 7;

    shared_ptr<ListNode<int>> fourth(new ListNode<int>);
    fourth->data = 7;

    insertAfter(head,second);
    insertAfter(second,third);
    insertAfter(third,fourth);
    //cout << third->data;

    cout << SearchList(head,8)->data;

    vector<vector<int>> lists = {a,b};

    priority_queue<int,vector<int>,greater<int>> q;
    for(const auto& l:lists){
        shared_ptr<ListNode<int>> t = l;
        while(t != nullptr){
            q.push(t->data);
            t = t->next;
        }
    }

    while(!q.empty()){
        cout << q.top();
        q.pop();
    }
}