#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class A{
    public:
        int x;
        void pu(int x){
            cout << "i am public from A " << x<<  endl;
        }
    protected:
        int y;
        void pr(){
            cout << "I am protected from A" << endl;
            }
    private:
        int z;
        void pv(){
            cout << "I am pvt from A" << endl;
        }
};

class D
{
    private:
        int a;
    public:
        int g;
        void pub(int x){
            cout << "i am public from D " << x<<  endl;
        }
};

class B: public A, public D
{

};

class E: public B{};

int main(){
    B b;
    //b.x = 5;
    b.pu(5);
    b.pub(6);
    
    E e;
    e.pu(8);
}