#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {45,32,12,34,10};
    std::nth_element(a.begin(),a.begin() -3,a.end());
    cout << "4th element is " << a[3];
}