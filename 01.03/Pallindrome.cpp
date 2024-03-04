/*
1)	Багаж пассажира характеризуется количеством вещей и указанием веса каждой вещи. 
Вывести на экран общий вес багажа каждого пассажира, найти багаж, средний вес одной вещи в котором 
отличается не более чем на 0,3 кг от общего среднего веса вещей, 
определить количество пассажиров, имеющих более трех вещей в багаже.
*/
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

class Passanger {
private:
    vector<int> baggage;
public:
    void printBaggage() {
        for (auto x : baggage) {
            cout << x << " ";
        }
    }

    int size() {
        return baggage.size();
    }

    double sredniyVes() {
        double result = 0.0;
        for (auto x : baggage) {
            result += x;
        }
        result /= baggage.size();
        return result;
    }

    void addParameters(vector<int> a) {
        for (auto x: a)
            baggage.push_back(x);
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");

    Passanger a[4];
    double allVes = 0.0;
    a[0].addParameters({4,2,2,1});
    a[1].addParameters({2,2,3});
    a[2].addParameters({5,5,4,1});
    a[3].addParameters({3,3,2,2});

    for (int i = 0; i < 4; i++) {
        cout << "Средний вес баггажа пассажира "<< i + 1 << " :" << a[i].sredniyVes() << endl;
        allVes += a[i].sredniyVes();
    }
    allVes /= 4;

    cout << "\nСредний вес багажа всех пассажиров:" << allVes<<endl;

    double allVesMin = allVes - 0.3; //Средний вес нижний диапазон
    double allVesMax = allVes + 0.3; //Средний вес верхний диапазон

    cout << "Пассажиры, средний вес баггажа которых не првышает отклонения 0.3 кг: ";
    for (int i = 0; i < 4; i++) {

        double srd = a[i].sredniyVes(); //Средний вес по индексу

        if (srd >= allVesMin && srd <= allVesMax)
            cout << i + 1 <<" ";
    }

    cout << "Пассажиры, имеющие больше трёх вещей: ";
    for (int i = 0; i < 4; i++) {
        if (a[i].size() > 3) {
            cout << i + 1 << " ";
        } 
    }
}

