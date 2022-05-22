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

#define F first
#define L last
#define S second
#define PB push_back
#define MP make_pair
#define sz(x) = int(x.size())

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        for(auto i = nums.begin(); i < prev(nums.end(), 2); i++){
            auto j = next(i);
            auto k = prev(nums.end());
            if(i > nums.begin() && *i == *(i-1))
                continue;
            while( j < k){                                
                if(* i + *j + *k < 0){
                    j++;
                    while(*j == *(j-1) && j < k)
                        j++;
                }
                else if(* i + *j + *k > 0){
                    k--;
                    while(*k == *(k+1) && j < k)
                        k--;
                }                    
                else{
                    result.push_back({* i , *j , *k});
                    j++;
                    k--;
                    while(*j == *(j-1) && j < k)
                        j++;
                    while(*k == *(k+1) && j < k)
                        k--;
                }
                    
            }
        }
        return result;
    }
};

int main(){

    Solution obj;
    vector<int> nums = {-2,0,0,2,2};
    // -1,-1,0,1,2,4
    vector<vector<int>> ans = obj.threeSum(nums);
    
    //vector<vector<int>> ans = {{1,2,3,},{4,5,6}};

    for(int i=ans.size()-1; i>=0; i--){
        while(!ans[i].empty()){
            cout << ans[i].back() << " ";
            ans[i].pop_back();
        }
        ans.pop_back();
        cout << endl;
    }
}