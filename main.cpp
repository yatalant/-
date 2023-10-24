#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Dish
{
    string name;
    int quantity;
    double price;
};

bool compareDishes(const Dish& dish1, const Dish& dish2)
{
    return dish1.name < dish2.name;
}

int main()
{
    int numDishes;
    cout << "Введите количество заказанных блюд: ";
    cin >> numDishes;

    Dish *dishes = new Dish[numDishes];

    for (int i = 0; i < numDishes; i++)
    {
        cout << "Введите название блюда " << i + 1 << ": ";
        cin.ignore();
        getline(cin, dishes[i].name);

        cout << "Введите количество порций блюда " << i + 1 << ": ";
        cin >> dishes[i].quantity;

        cout << "Введите стоимость за порцию блюда " << i + 1 << ": ";
        cin >> dishes[i].price;

        double totalPrice = dishes[i].quantity * dishes[i].price;
        cout << "Общая стоимость заказа: " << totalPrice << endl;
    }

    sort(dishes, dishes + numDishes, compareDishes);

    cout << "Список заказанных блюд:" << endl;
    for (int i = 0; i < numDishes; i++)
    {
        cout << i + 1 << " " << dishes[i].name << " - "
            << "Количество: " << dishes[i].quantity << ", "
            << "Стоимость за порцию: " << dishes[i].price << endl;
    }

    double totalCost = 0;
    for (int i = 0; i < numDishes; i++)
    {
        totalCost += dishes[i].quantity * dishes[i].price;
    }

    cout << "Общая сумма всех заказов: " << totalCost << endl;

    delete[] dishes;

    return 0;
}
