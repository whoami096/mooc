#include <iostream>
#include <cstring>
using namespace std;

class Head
{
public:
    int hp;
    int a[6];
    int b[6];
    char name[6][10];
};

int
main()
{
    Head blue, red;
    
    //blue.name = {"nonthing", "lion", "dragon", "ninja", "iceman", "wolf"};
    strcpy(blue.name[1], "lion");
    strcpy(blue.name[2], "dragon");
    strcpy(blue.name[3], "ninja");
    strcpy(blue.name[4], "iceman");
    strcpy(blue.name[5], "wolf");
    //red.name = {"nonthing", "iceman", "lion", "wolf", "ninja", "dragon"};
    strcpy(red.name[1], "iceman");
    strcpy(red.name[2], "lion");
    strcpy(red.name[3], "wolf");
    strcpy(red.name[4], "ninja");
    strcpy(red.name[5], "dragon");
    int T, tmp;
    cin >> T;
    tmp = T;
    while(T--)
    {
        memset(blue.b, 0, sizeof(blue.b));
        memset(red.b, 0, sizeof(red.b));
        int cnt = 0;
        cin >> blue.hp;
        red.hp = blue.hp;
        cin >> blue.a[2] >> blue.a[3] >> blue.a[4] >> blue.a[1] >> blue.a[5];
        red.a[1] = blue.a[4], red.a[2] = blue.a[1], red.a[3] = blue.a[5];
        red.a[4] = blue.a[3], red.a[5] = blue.a[2];
        int ret_b = 1, ret_r = 1;
        printf("Case:%d\n", tmp-T);
        for(int i_b=1, i_r=1;;i_b++, i_r++)
        {
            if(i_b>5) i_b -= 5;
            if(i_r>5) i_r -= 5;
            for(int i=1;i<=10;i_r++,i++)
            {
                if(i_r>5) i_r -= 5;
                if(red.hp>=red.a[i_r]) break;
                
            }
            if(i_r>5) i_r -= 5;
            red.hp -= red.a[i_r];
            if(red.hp<0&&ret_r)
            {
                printf("%03d red headquarter stops making warriors\n", cnt);
                ret_r = 0;
            }
            red.b[i_r] ++;
            if(red.hp>=0) printf("%03d red %s %d born with strength %d,%d %s in red headquarter\n", cnt, red.name[i_r], cnt+1, red.a[i_r], red.b[i_r],red.name[i_r]);
            for(int i=1;i<=10;i_b++,i++)
            {
                if(i_b>5) i_b -= 5;
                if(blue.hp>=blue.a[i_b]) break;
                
            }
            if(i_b>5) i_b -= 5;
            blue.hp -= blue.a[i_b];
            if(blue.hp<0&&ret_b)
            {
                printf("%03d blue headquarter stops making warriors\n", cnt);
                ret_b = 0;
            }
            blue.b[i_b] ++;
            if(blue.hp>=0) printf("%03d blue %s %d born with strength %d,%d %s in blue headquarter\n", cnt, blue.name[i_b], cnt+1, blue.a[i_b], blue.b[i_b],blue.name[i_b]);
            cnt ++;
            if(blue.hp<0&&red.hp<0) break;
        }
    }
    return 0;
}