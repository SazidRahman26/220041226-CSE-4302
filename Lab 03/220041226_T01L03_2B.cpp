#include <iostream>
using namespace std;

class Counter{
    private:
        int kount;
        int step;
    public:
        Counter()
        {
            kount = 0;
        }
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
    kounter.increment();
    cout << kounter.getCount() << endl;
    kounter.resetCount();
    cout << kounter.getCount() << endl;
    return 0;
}
