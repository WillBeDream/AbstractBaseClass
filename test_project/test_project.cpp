// test_project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using std::cin;
using std::endl;
using std::cout;


class Vehicle
{
    int speed;
public:
    virtual void move() = 0;
    
};

class GroundVehicle : private Vehicle {};

class FlyerVehicle: public Vehicle{};

class MarineVehicle: public Vehicle{};

class Car : public GroundVehicle
{
public:
    void move()
    {
        cout << "Машина едет на четырех колесах"<<endl;
    }
};

class Bike :public GroundVehicle
{
public:
    void move()
    {
        cout << "Мотоцикл едет на двух колесах" << endl;
    }
};

class Boat : public MarineVehicle
{
public:
    void move()
    {
        cout << "Катер плывет";
    }
};

class Yacht : public MarineVehicle
{
public:
    void move()
    {
        cout << "Яхта плывет";
    }
};

class Plane :public FlyerVehicle
{
public:
    void move()
    {
        cout << "Cамолет летит";
    }
};

class Helicopter : public FlyerVehicle
{
public:
    void move()
    {
        cout << "самолет летит";
    }
};

int main()
{
    setlocale(LC_ALL, "");
    Car bmw;
    bmw.move();
    Bike harley_devidson;
    harley_devidson.move();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
