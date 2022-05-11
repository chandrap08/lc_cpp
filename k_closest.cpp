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

// class k_closest{
//     public:
//          vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
//              priority_queue<int> bool min_heap(int a, int b){
//                  return a >= b;
//              }
//          }
// };
template<typename T>

void print_queue(T p){
    while(!p.empty()){
        cout << p.top() << " ";
        p.pop();
    }
}
int main(){
    auto d = {3,4,5,2,1,9,7,8,6};
    priority_queue<int> q;

    for(auto a:d){
        q.push(a);
    }

    print_queue(q);
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> q2(d.begin(),d.end());
    print_queue(q2); cout << endl;
    cout << "top element" << q2.top() << "last element" << q2.empty();
 
    priority_queue<int, vector<int>, less<int>> q3(d.begin(),d.end());
    print_queue(q3); cout << endl;

    auto cmp = [](int left, int right){ return (left ^ 1) < (right ^ 1);};
    priority_queue<int, vector<int>, decltype(cmp)> q4(cmp);

    for(int n:d)
        q4.push(n);

    print_queue(q4);

}