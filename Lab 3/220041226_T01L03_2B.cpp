#include <iostream>
using namespace std;

class Counter{
    private:
        int kount = 0;
        int step;
    public:
        void setIncrementStep(int x){
            step = x;
        }
        int getCount(){
            return kount;
        }
        void increment(){
            kount += step;
        }
        void resetCount(){
            kount = 0;
        }
};

int main()
{
    Counter kounter;
    kounter.setIncrementStep(6);
    kounter.setIncrementStep(6);
    kounter.setIncrementStep(6);
    cout << kounter.getCount() << endl;
    kounter.resetCount();
    cout << kounter.getCount() << endl;
}
