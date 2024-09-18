#include <iostream>
#include <string.h>

using namespace std;

class Medicine{
    private:
        char trad[30];
        char gen[30];
        double price = 0;
        double sell = 0;
        double discount = 5;
    public:
        void assignName(char name[], char genericName[])
        {
            strcpy(trad, name);
            strcpy(gen, genericName);
        }
        void assignPrice(double cost)
        {
            price = cost;
        }
        void setDiscountPercent(double percent)
        {
            discount = percent;
        }
        double getSellingPrice(int nos)
        {
            sell = price - (discount * 1.0 /100.0) * price;
            return nos * sell;
        }
        double getUnitPrice()
        {
            sell = price - (discount * 1.0 /100.0) * price;
            return sell;
        }
        void display()
        {
            cout << "MRP. of " << trad << " (" << gen <<") is BDT " << price << ". Current discount " << discount << "%. Selling price BDT " << getUnitPrice() << ".\n";
        }
};

int main()
{
    Medicine m;
    char name[] = "Napa";
    char gen[] = "Paracetemol";
    m.assignName(name, gen);
    m.assignPrice(1);
    m.setDiscountPercent(10);
    m.display();
    cout << m.getSellingPrice(5) << endl;
    return 0;
}
