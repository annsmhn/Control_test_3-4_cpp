#include <iostream>
#include <Windows.h> 
using namespace std;

class Running_Dot
{
public:
    Running_Dot() :x(0), y(0), width(600), height(600) {}
    Running_Dot(int X, int Y, int console_width, int console_height) :x(X), y(Y), width(console_width), height(console_height) {}

    void getConsoleSize(int& width, int& height) {
        CONSOLE_SCREEN_BUFFER_INFO csbi; //структура, которая содержит информацию о текущем размере окна консоли
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) //выполняется для того, чтобы убедиться, что удалось получить информацию о текущем состоянии консоли (буфера и окна)
        {
            width = csbi.srWindow.Right - csbi.srWindow.Left + 1;  // Ширина окна
            height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // Высота окна
        }
        else {
            width = 0;
            height = 0;
            cout << "Ошибка при определении размера консоли" << endl;
        }
    }
    void Draw_Running_Dot(HDC hdc, RECT& paint_area)
    {
        RECT intersection_rect;
        if (!(IntersectRect(&intersection_rect, &paint_area, &Ball_Rect)))
            return;
        //очищаем фон
        SelectObject(hdc, Bg_Pen);
        SelectObject(hdc, Bg_Brush);
        Ellipse(hdc, Prev_Ball_Rect.left, Prev_Ball_Rect.top, Prev_Ball_Rect.right - 1, Prev_Ball_Rect.bottom - 1);
        //рисуем шар
        SelectObject(hdc, Ball_Pen);
        SelectObject(hdc, Ball_Brush);
        Ellipse(hdc, Ball_Rect.left, Ball_Rect.top, Ball_Rect.right - 1, Ball_Rect.bottom - 1);
    }
    void Move_Ball(int width, int height)
    {
        int next_x_pos, next_y_pos;
        int max_x_pos = width - Ball_Size;
        int max_y_pos = height - Ball_Size;
        Prev_Ball_Rect = Ball_Rect;

        next_x_pos = Ball_X_Pos + Ball_Speed;
        // next_y_pos = Ball_Y_Pos - (int)(Ball_Speed * sin(Ball_Direction));

         //Корректировка позиций шара при отражении от рамки 
        if (next_x_pos >= max_x_pos)
        {
            next_x_pos = max_x_pos;
            next_y_pos += 1;
        }
        if (next_x_pos <= 1)
        {
            next_x_pos = 1;
            next_y_pos += 1;
        }
        if (next_y_pos >= max_y_pos)
        {
            return;
        }
    }

private:
    int x, y, width, height;
    RECT Ball_Rect, Prev_Ball_Rect;
    HPEN Bg_Pen = CreatePen(PS_SOLID, 0, RGB(3, 37, 21));
    HPEN Ball_Pen = CreatePen(PS_SOLID, 0, RGB(85, 255, 255));
    HBRUSH Bg_Brush = CreateSolidBrush(RGB(3, 37, 21));
    HBRUSH Ball_Brush = CreateSolidBrush(RGB(85, 255, 255));
    static const int Ball_Size = 4;
    int Ball_X_Pos = 1, Ball_Y_Pos = 3, Ball_Speed = 6;
};

int main()
{
    //RECT paint_area;
    Running_Dot r;
    int width, height;
    r.getConsoleSize(width, height);
    cout<<width;
    //r.Draw_Running_Dot(hdc, paint_area);
    //r.Move_Ball(width, height);


}
