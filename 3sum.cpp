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
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int k=0; k< n; k++){
            int sum = 0 - nums[k];
            int i = k+1, j = n-1;

            while(i<j){
                if(nums[i] + nums[j] < sum){
                    i++;
                }
                else if(nums[i] + nums[j] > sum){
                    j--;
                }
                else{
                    vector<int> a = {nums[i], nums[j], nums[k]};
                    ans.push_back(a);
                    while(i<j && nums[i] == nums[i+1])
                        i++;
                    
                    while(i>j && nums[j] == nums[j-1])
                        j--;
                    i++; j--;
                }
            }
            while(k+1<n && nums[k+1] == nums[k])
                k++;
        }
        return ans;
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