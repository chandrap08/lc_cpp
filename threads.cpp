#include <thread>
#include <iostream>

using namespace std;

class th{
    public:
        void f(){
            cout << "this is from class th" << endl;
        }
};
int main(){

    auto f = [](int x, int y){
        int sum = x+y;
        return sum;
    };
    cout << f(2,3);
    //std::thread t_1(th());
}