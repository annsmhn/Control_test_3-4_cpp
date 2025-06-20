#include <iostream>
#include <time.h>

using namespace std;

void main(void)
{
    int size = 20, dx, dy;
    char symbol = '#';
    float cx, cy;
    time_t timeStamp;

    cx = (float)size / 2;
    cy = (float)size / 2;

    for (int x = 0; x < 50; x++)
    {
        timeStamp = time(NULL);
        system("cls");

        for (int i = 0; i < size + 1; i++)
        {
            for (int j = 0; j < x; j++)
                cout << ' ';

            for (int j = 0; j < (size + 1) * 2; j++)
            {
                dx = cx - (float)j / 2;
                dy = cy - (float)i;

                if (sqrt(dx * dx + dy * dy) <= size / 2)
                    cout << symbol;
                else
                    cout << ' ';
            }

            cout << endl;
        }

        while (timeStamp == time(NULL));
    }

    system("pause");
}
