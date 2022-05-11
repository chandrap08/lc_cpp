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

class Solution{
    public:
        int findKthLargest(vector<int> &nums,int k){
            priority_queue<int, vector<int>> q(nums.begin(),nums.end());
            int i = 1;
            while(i<k){
                q.pop();
                i++;
            }
            return q.top();
        }
};


int main(){
    int k, inputs;
    vector<int> V;
    cin >> k;

    while(cin >> inputs){
        V.push_back(inputs);
    }
    Solution* obj = new Solution;
    cout << obj->findKthLargest(V,k);
    
}