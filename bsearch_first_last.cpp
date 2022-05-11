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

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() -1;
        int start, end = -1;
        vector<int> ans{-1,-1};

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){ 
                if(nums[lo] != target){
                    lo++;
                }

                if(nums[hi] != target){
                    hi--;
                }
                if(nums[lo] == target && nums[hi] == target){
                    cout << "found";
                    start = lo;
                    end = hi;
                    ans.at(0) = start;
                    ans.at(1) = end;
                    return ans;
                }
            }
            if(nums[mid] > target){
                cout << "change hi" << hi << endl;
                hi = mid - 1;
            }
            if(nums[mid] < target){
                cout << "change lo" << endl;
                lo = mid + 1;
            }

        }
        return ans;
    }
};

int main(){
    
    vector<int> nums({1});
    Solution obj;
    int target = 1;
    vector<int> ans = obj.searchRange(nums,target);

    for(auto& i:ans){
        cout << i << " ";
    }

}