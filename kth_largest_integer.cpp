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
        string kthLargestNumber(vector<string> &nums, int k){
/*          priority_queue<pair<int,string>, greater<int>> q;
            while(!nums.empty()){
                q.push(make_pair(nums.back().size(),nums.back()));
                nums.pop_back();
                if(q.size() > k)
                    q.pop();
            }
            int count = 1;
            while(count < k){
                q.pop();
                count++;
            }
            return q.top().second; */

// Faster than heaps is the priority sorting algorithm with nth-element.
/*         std::nth_element(nums.begin(), nums.end() - k, nums.end(), [](const auto& l, const auto& r){
            if (l.size() == r.size()){
               return l < r;
            } 
            return l.size() < r.size();    
          }); 
        
        return *(nums.end() - k);
*/
        
// Heap solution.
            priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> min_heap;
            
            while(!nums.empty()){
                min_heap.push(make_pair(nums.back().size(),nums.back()));
                nums.pop_back();
                if(min_heap.size() > k){
                    min_heap.pop();
                }
            }

            return min_heap.top().second;

        }
};

int main(){
    int p;
    string inputs;
    cin >> p;
    vector<string> nums;

    while(cin >> inputs){
        nums.push_back(inputs);
    }

    Solution* obj = new Solution;
    cout << obj->kthLargestNumber(nums,p);
}