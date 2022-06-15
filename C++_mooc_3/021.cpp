#include <iostream>
#include <map>
using namespace std;
map<string, int> id;
map<int, string> red = {
    {1, "iceman"}, {2, "lion"}, {3, "wolf"}, {4, "ninja"}, {5, "dragon"}};
map<int, string> blue = {
    {1, "lion"}, {2, "dragon"}, {3, "ninja"}, {4, "iceman"}, {5, "wolf"}};
map<int, string> weapons = {
    {0, "sword"}, {1, "bomb"}, {2, "arrow"}};

int main()
{
    int t;
    cin >> t;
    int cnt = 1;
    while (t--)
    {
        int cnt1 = 0, cnt2 = 0;
        
        map<string, int> red_number = {
            {"iceman", 0}, {"lion", 0}, {"wolf", 0}, {"ninja", 0}, {"dragon", 0}};

        map<string, int> blue_number = red_number;

        int M;
        cin >> M;
        int bluem = M, redm = M;
        cin >> id["dragon"] >> id["ninja"] >> id["iceman"];
        cin >> id["lion"] >> id["wolf"];
        printf("Case:%d\n", cnt++);
        for (int times = 0; bluem >= 0 || redm >= 0; times++, cnt1++, cnt2++)
        {


            int strength_red = id[red[cnt1 % 5 + 1]], strength_blue = id[blue[cnt2 % 5 + 1]];
            for (int i = 0; redm-strength_red < 0&& i < 10; i++) strength_red = id[red[(++cnt1)%5 + 1]];
            string red_name = red[cnt1%5 + 1];

            redm -= strength_red;
            for(int i = 0; bluem-strength_blue < 0&&i < 10; i++) strength_blue = id[blue[(++cnt2)%5 + 1]];
            bluem -= strength_blue;
            string blue_name = blue[cnt2%5 + 1];

            int b_l = ++blue_number[blue_name], r_l = ++red_number[red_name];
            if (redm >= 0)
            {
                printf("%03d red %s %d born with strength %d,%d %s in red headquarter\n", times, red_name.c_str(), times + 1, strength_red, r_l, red_name.c_str());
                if (red_name == "dragon")
                {
                    string wea = weapons[(times+1) % 3];
                    double shi_qi = redm * 1.0 / strength_red;
                    printf("It has a %s,and it's morale is %.2f\n", wea.c_str(), shi_qi);
                }
                else if (red_name == "ninja")
                {
                    string wea1 = weapons[(times+1) % 3], wea2 = weapons[(times+2) % 3];
                    printf("It has a %s and a %s\n", wea1.c_str(), wea2.c_str());
                }
                else if (red_name == "iceman")
                {
                    string wea = weapons[(times+1) % 3];
                    printf("It has a %s\n", wea.c_str());
                }
                else if (red_name == "lion")
                {
                    printf("It's loyalty is %d\n", redm);
                }
            }
            else if(redm>-1e8)printf("%03d red headquarter stops making warriors\n", times), redm = -1e9;
            else redm = -1e9;

            if (bluem >= 0)
            {
                printf("%03d blue %s %d born with strength %d,%d %s in blue headquarter\n", times, blue_name.c_str(), times + 1, strength_blue, b_l, blue_name.c_str());
                if (blue_name == "dragon")
                {
                    string wea = weapons[(times+1) % 3];
                    double shi_qi = bluem * 1.0 / strength_blue;
                    printf("It has a %s,and it's morale is %.2f\n", wea.c_str(), shi_qi);
                }
                else if (blue_name == "ninja")
                {
                    string wea1 = weapons[(times+1) % 3], wea2 = weapons[(times+2) % 3];
                    printf("It has a %s and a %s\n", wea1.c_str(), wea2.c_str());
                }
                else if (blue_name == "iceman")
                {
                    string wea = weapons[(times+1)% 3];
                    printf("It has a %s\n", wea.c_str());
                }
                else if (blue_name == "lion")
                {
                    printf("It's loyalty is %d\n", bluem);
                }
            }
            else if(bluem>-1e8)printf("%03d blue headquarter stops making warriors\n", times), bluem = -1e9;
            else bluem = -1e9;
        }
    }

    return 0;
}