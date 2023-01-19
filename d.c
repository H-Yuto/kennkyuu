//ランダムで使い回しの割合

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct device
{
    int fac;   // facebookの利用
    int num;   // 番号での利用
    int hik;   // 引き継ぎをするか
    int place; // 端末の状態
    int date;  // 休止後の日にち
    int evi;   // 使い回された形跡
    int var;   // ランダム変数
};
int main()
{ // 初期化
    struct device device[25000];
    for (int i = 0; i < 18000; i++) // 使用数
    {
        int a = rand() % 2;
        int b = rand() % 2;
        int c = rand() % 2;
        int d = rand() % 4;
        device[i].fac = a;
        device[i].num = b;
        device[i].hik = c;
        device[i].place = 2;
        device[i].date = 0;
        device[i].evi = 1;
        device[i].var = d;
    }
    for (int i = 18000; i < 24000; i++) // 未使用数
    {
        device[i].fac = 0;
        device[i].num = 0;
        device[i].hik = 0;
        device[i].place = 0;
        device[i].date = 0;
        device[i].evi = 0;
    }
    for (int i = 24000; i < 25000; i++) // 休止数
    {
        int a = rand() % 2;
        int b = rand() % 2;
        int c = rand() % 2;
        device[i].fac = a;
        device[i].num = b;
        device[i].hik = c;
        device[i].place = 1;
        device[i].date = rand() % 180;
        device[i].evi = 1;
    }

    // サイクル
    for (int j = 0; j < 3600; j++) // 日数
    {

        for (int i = 0; i < 25000; i++) // エージェント数
        {
            if (device[i].place == 0) // 未使用数
            {
                int a = rand() % 1080;
                if (a == 1)
                {
                    device[i].place = device[i].place + 2;
                    device[i].evi++;
                    device[i].fac = rand() % 2;
                    device[i].hik = rand() % 2;
                    device[i].num = rand() % 2;
                    device[i].var = rand() % 4;
                }
            }
            if (device[i].place == 1) // 休止数
            {
                device[i].date++;
                if (device[i].date == 180)
                {
                    device[i].date = 0;
                    device[i].place--;
                }
            }
            int d;
            if (device[i].place == 2) // 使用数
            {
                if (device[i].var == 0 || 1)
                {
                    d = 1;
                }
                else if (device[i].var == 2)
                {
                    d = 2;
                }
                else if (device[i].var == 3)
                {
                    d = 2 / 3;
                }

                int b = rand() % (3240 * d);
                if (b == 1)
                {
                    device[i].place--;
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

    
    for (int i = 0; i < 25000; i++) // 結果の出力
    {
        if (device[i].place == 0)
        {
            a++;
            if (device[i].evi == 0)
            {
                b++;
            }
            else if (device[i].evi == 1)
            {
                c++;
            }
            else if (device[i].evi == 2)
            {
                d++;
            }
            else if (device[i].evi == 3)
            {
                e++;
            }
            else if (device[i].evi == 4)
            {
                f++;
            }
            else if (device[i].evi >= 5)
            {
                g++;
            }
        }
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e, f, g);
}