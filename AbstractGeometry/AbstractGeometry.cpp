// AbstractGeometry.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<windows.h>
#include <iostream>
using std::cin;
using std::endl;
using std::cout;

enum Color
{
    red   = 0x000000FF,
    green = 0x0000ff00,
    blue  = 0x00FF0000,


    some_color,
    console_blue = 0x99,
    console_green = 0xAA,
    console_red = 0xCC,
    console_default = 0x07,
};

class Shape
{
protected:
    unsigned int start_x;
    unsigned int start_y;
    unsigned int line_width;
    Color color;
public:
    void set_start_x(unsigned int start_x)
    {
        if (start_x > 300)start_x = 300;
        this->start_x = start_x;   
    }
    void set_start_y(unsigned int start_y)
    {
        if (start_y > 300)start_y = 300;
        this->start_y = start_y;
    }
    void set_line_width(unsigned int line_width)
    {
        if (line_width > 20)line_width = 20;
        this->line_width = line_width;
    }
    Shape(Color color, unsigned int start_x, unsigned int start_y, unsigned int line_width) :color(color)
    {
        set_start_x(start_x);
        set_start_y(start_y);
        set_line_width(line_width);
    }
    virtual ~Shape() {}

    virtual double get_area()const = 0;
    virtual double get_perimeter()const = 0;
    virtual void draw()const = 0;
};

class Square : public Shape
{
    double side;
public:
    double get_side()const
    {
        return side;
    }
    void set_side(double side)
    {
        if (side <= 0)side = 10;
        this->side = side;
    }
    Square(
        double side, Color color, 
        unsigned int start_x, unsigned int start_y,
        unsigned int line_width) :Shape(color, start_x, start_y, line_width)
    {
        set_side(side);
    }
    ~Square(){}
    
    double get_area()const
    {
        return side * side;
    }
    double get_perimeter()const
    {
        return side * 4;
    }
    void draw()const
    {
        /*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
        for (size_t i = 0; i < side; i++)
        {
            for (size_t i = 0; i < side; i++)
            {
                cout << "* ";
            }
            cout << endl;
        }
      
        SetConsoleTextAttribute(hConsole, Color::console_default);*/

        HWND hConsole = GetConsoleWindow();
        HDC hdc = GetDC(hConsole);
        HPEN hPen = CreatePen(PS_SOLID, 5, color);
        SelectObject(hdc, hPen);
        HBRUSH hBrush = CreateSolidBrush(color);
        SelectObject(hdc, hBrush);

        Rectangle(hdc, start_x, start_y, start_x+side, start_y+side);

        DeleteObject(hBrush);
        DeleteObject(hPen);
        ReleaseDC(hConsole, hdc);
    }
};

class Rectanglee: public Shape
{
    double length;
    double width;
public:
    double get_length()const
    {
        return length;
    }
    double get_width()const
    {
        return width;
    }
    void set_length(double length)
    {
        this->length = length;
    }
    void set_width(double width)
    {
        this->width = width;
    }

    Rectanglee(
        double length, double width,
        Color color,
        unsigned int start_x, unsigned int start_y,
        unsigned int line_width):Shape(color, start_x, start_y, line_width)
    {
        set_length(length);
        set_width(width);
    }
    ~Rectanglee(){}

    double get_area()const
    {
        return length * width;
    }

    double get_perimeter()const
    {
        return (length + width) * 2;
    }

    void draw()const
    {

        HWND hConsole = GetConsoleWindow();
        HDC hdc = GetDC(hConsole);
        HPEN hPen = CreatePen(PS_SOLID, 5, color);
        SelectObject(hdc, hPen);
        HBRUSH hBrush = CreateSolidBrush(color);
        SelectObject(hdc, hBrush);

        Rectangle(hdc, start_x, start_y, start_x + width, start_y + length);

        DeleteObject(hBrush);
        DeleteObject(hPen);
        ReleaseDC(hConsole, hdc);
    }
};



int main()
{
    setlocale(LC_ALL, "");
    /*Square square(250, Color::green, 100, 300, 5);
    cout << "сторона квадрата: \t" << square.get_side() << endl;
    cout << "площадь квадрата:\t" << square.get_area() << endl;
    cout << "периметр квадрата:\t" << square.get_perimeter() << endl;
    square.draw();*/

    Rectanglee rectangle(250, 300, Color::green, 100, 300, 5);
    cout << "ширина квадрата: \t" << rectangle.get_width() << endl;
    cout << "длинна квадрата: \t" << rectangle.get_length() << endl;
    cout << "площадь квадрата:\t" << rectangle.get_area() << endl;
    cout << "периметр квадрата:\t" << rectangle.get_perimeter() << endl;
    rectangle.draw();

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
