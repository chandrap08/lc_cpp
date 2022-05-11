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
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() -1;
        int ans = -1;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                cout << "mid " << nums[mid] << endl;
                if(nums[mid] == target){
                    return mid;
                }
                if(nums[lo] <= nums[mid]){
                    // if mid > target and lo < target its in the left half.
                    if(nums[mid] >= target && nums[lo] <= target){
                        hi = mid;
                    }
                    else{ lo = mid + 1; }
                } 
                else if(nums[lo] > nums[mid]){
                    // right half.
                    if(nums[mid] <= target && nums[hi] >= target){
                        lo = mid + 1;
                    }else{
                        hi = mid;
                    }
                }
            }
        return ans;
    }
};

int main(){
    
    vector<int> nums({4,5,6,7,0,1,2});
    Solution obj;
    int target = 6;
    cout <<  obj.search(nums,target);


}