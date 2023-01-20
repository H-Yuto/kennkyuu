// 完全ランダムで使い回しの割合

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct device
{

    int place; // 端末の状態
    int date;  // 休止後の日にち
    int evi;   // 使い回された形跡
    int var;   // ランダム変数
};
int main()
{ // 初期化
    int w = 0;
    int x[50665];
    int z = 0;
    srand(3);
    struct device device[25000];

    for (int i = 0; i < 18000; i++) // 使用数
    {

        int d = rand() % 1000;
        int e;
        if (d < 500)
        {
            e = 0;
        }
        else if (d < 750)
        {
            e = 1;
        }
        else if (d < 875)
        {
            e = 2;
        }
        else if (d < 938)
        {
            e = 3;
        }
        else if (d < 969)
        {
            e = 4;
        }
        else if (d < 985)
        {
            e = 5;
        }
        else if (d < 1000)
        {
            e = 6;
        }

        device[i].place = 2;
        device[i].date = 0;
        device[i].evi = 1;
        device[i].var = e;
    }
    for (int i = 18000; i < 24000; i++) // 未使用数
    {

        device[i].place = 0;
        device[i].date = 0;
        device[i].evi = 0;
    }
    for (int i = 24000; i < 25000; i++) // 休止数
    {
        int a = rand() % 2;
        int b = rand() % 2;
        int c = rand() % 2;

        device[i].place = 1;
        device[i].date = rand() % 180;
        device[i].evi = 1;
    }

    // サイクル
    for (int j = 0; j < 10000; j++) // 日数
    {

        for (int i = 0; i < 25000; i++) // エージェント数
        {
            if (device[i].place == 0) // 未使用数
            {
                device[i].date++;
                int a = rand() % 1080;
                if (a == 1)
                {
                    if (device[i].evi >= 1)
                    {
                        x[w] = device[i].date;
                        w++;
                        z = z + device[i].date;
                    }

                    device[i].date = 0;
                    device[i].place = device[i].place + 2;
                    device[i].evi++;

                    int d = rand() % 1800;
                    int e;

                    if (d < 450)
                    {
                        e = 1;
                    }
                    else if (d < 900)
                    {
                        e = 2;
                    }
                    else if (d < 1238)
                    {
                        e = 3;
                    }
                    else if (d < 1463)
                    {
                        e = 4;
                    }
                    else if (d < 1620)
                    {
                        e = 5;
                    }
                    else if (d < 1800)
                    {
                        e = 6;
                    }
                    device[i].var = e;
                }
            }
            if (device[i].place == 1) // 休止数
            {
                device[i].date++;
                if (device[i].date == 180)
                {

                    device[i].place--;
                }
            }
            if (device[i].place == 2) // 使用数
            {
                if (device[i].var != 0)
                {

                    int b = rand() % (3240 / device[i].var);
                    if (b == 1)
                    {
                        device[i].place--;
                    }
                }
            }
        }
    }

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;

    printf("%d\n%d\n%d\n", w, z, z / w);

    for (int y = 0; y < 50666; y++)
    {
        if (x[y] < 360)
        {
            a++;
        }
        else if (x[y] < 720)
        {
            b++;
        }
        else if (x[y] < 1080)
        {
            c++;
        }
        else if (x[y] < 1440)
        {
            d++;
        }
        else if (x[y] < 1800)
        {
            e++;
        }
        else if (x[y] < 2160)
        {
            f++;
        }
        else
        {
            g++;
        }
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e, f, g);
}