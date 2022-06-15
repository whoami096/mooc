#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int hour, minute;
int N, M, K, T;

string warrior[] = {"dragon", "ninja", "iceman", "lion", "wolf"};
map<string, int> HP, POWER;
string weapons[] = {"sword", "bomb", "arrow"};

string blue_order[] = {"lion", "dragon", "ninja", "iceman", "wolf"};
string red_order[] = {"iceman", "lion", "wolf", "ninja", "dragon"};

class Weapon
{
public:
    multimap<int, int> all_weapon;
    Weapon(int _t1 = 3, int _t2 = 3)
    {
        switch (_t1)
        {
        case 0:
            all_weapon.insert({0, 1e9});
            break;
        case 1:
            all_weapon.insert({1, 1});
            break;
        case 2:
            all_weapon.insert({2, 2});
        default:
            break;
        }
        switch (_t2)
        {
        case 0:
            all_weapon.insert({0, 1e9});
            break;
        case 1:
            all_weapon.insert({1, 1});
            break;
        case 2:
            all_weapon.insert({2, 2});
        default:
            break;
        }
    }
};
bool cmp2(pair<int, int> i)
{
    return i.second <= 0;
}
class People
{
public:
    int id, hp, power, pos;
    int loyal;
    bool group;//blue is true, red is false;
    virtual string name(){return "people";}
    People(int _t1, int _t2, int _t3, bool st):id(_t1), hp(_t2), power(_t3)
    {
        loyal = -1e9;
        if(st) pos = N + 1;
        else pos = 0;
        group = st;
    }
    virtual void grub_weapon(People *tmp_wolf, People *tmp_other, int city_id){}
    Weapon *weapon;

    void win_grub_weapon(People *first_guy, People *second_guy)
    {
        auto first_guy_weapon = first_guy->weapon->all_weapon.begin();
        auto second_guy_weapon = second_guy->weapon->all_weapon.begin();
        while(first_guy->weapon->all_weapon.size() < 10 && second_guy->weapon->all_weapon.size() > 0)
        {
            if((*second_guy_weapon).first != 2)
            {
                second_guy_weapon = second_guy->weapon->all_weapon.begin();
                first_guy->weapon->all_weapon.insert(*second_guy_weapon);
                auto tmp = second_guy->weapon->all_weapon;
                auto &tmp1 = second_guy->weapon->all_weapon;
                tmp1.clear();
                for(auto i=tmp.begin();i!=tmp.end();i++) if(i!=tmp.begin())tmp1.insert(*i);
            }
            else
            {
                second_guy_weapon = second_guy->weapon->all_weapon.end();
                second_guy_weapon --;
                first_guy->weapon->all_weapon.insert(*second_guy_weapon);
                auto tmp = second_guy->weapon->all_weapon;
                auto &tmp1 = second_guy->weapon->all_weapon;
                tmp1.clear();
                for(auto i=tmp.rbegin();i!=tmp.rend();i++) if(i!=tmp.rbegin()) tmp1.insert(*i);

            }
        }
    }

    void fight(People* first_guy, People* second_guy)
    {
        auto first_guy_weapon = first_guy->weapon->all_weapon.begin();
        auto second_guy_weapon = second_guy->weapon->all_weapon.begin();
        
        for(int i = 1; 1 ;i++)
        {
            if(i&1 && first_guy->weapon->all_weapon.size() > 0)
            {
                int tmp_weapon_id = (*first_guy_weapon).first;
                do
                {
                    

                    switch ((*first_guy_weapon).first)
                    {
                    case 0:
                        second_guy->hp -= POWER[first_guy->name()] * 2 / 10;
                        break;
                    case 1:
                        second_guy->hp -= POWER[first_guy->name()] * 2 / 5;
                        if(first_guy->name() != "ninja") first_guy->hp -= POWER[first_guy->name()] * 2 / 5 / 2;
                        (*first_guy_weapon).second --;
                        break;
                    case 2:
                        second_guy->hp -= POWER[first_guy->name()] * 3 / 10;
                        (*first_guy_weapon).second --;
                        break;
                    default:
                        break;
                    }
                    if((*first_guy_weapon).second <= 0)
                    {
                        auto &tmp2 = first_guy->weapon->all_weapon;
                        multimap<int, int> tmp1 = tmp2;
                        tmp2.clear();
                        for(auto i=tmp1.begin();i!=tmp1.end();++i)
                            if((*i).second > 0)
                                tmp2.insert(*i);
                            else
                            {
                                if(tmp2.size() == 0) first_guy_weapon = tmp2.begin();
                                else 
                                {
                                    for(auto j=tmp2.begin();;j++) 
                                    if(++j == tmp2.end()) 
                                    {first_guy_weapon = --j;break;}
                                    else --j;
                                }
                                
                            }
                        if(tmp2.size() == 0)break;
                    }

                    first_guy_weapon ++;
                } while (0 && first_guy->hp > 0 && second_guy->hp > 0 && first_guy->weapon->all_weapon.size() > 0 && (*first_guy_weapon).first == tmp_weapon_id);
                
            }
            else if(second_guy->weapon->all_weapon.size() > 0)
            {
                int tmp_weapon_id = (*second_guy_weapon).first;
                do
                {
                    

                    switch ((*second_guy_weapon).first)
                    {
                    case 0:
                        first_guy->hp -= POWER[second_guy->name()] * 2 / 10;
                        break;
                    case 1:
                        first_guy->hp -= POWER[second_guy->name()] * 2 / 5;

                        if(second_guy->name() != "ninja") second_guy->hp -= POWER[second_guy->name()] * 2 / 5 / 2;
                        (*second_guy_weapon).second --;
                        break;
                    case 2:
                        first_guy->hp -= POWER[second_guy->name()] * 3 / 10;
                        (*second_guy_weapon).second --;
                        break;
                    default:
                        break;
                    }
                    if((*second_guy_weapon).second <= 0)
                    {
                        auto &tmp2 = second_guy->weapon->all_weapon;
                        multimap<int, int> tmp1 = tmp2;
                        tmp2.clear();
                        for(auto i=tmp1.begin();i!=tmp1.end();++i)
                            if((*i).second > 0) tmp2.insert(*i);
                            else
                            {
                                if(tmp2.size() == 0)second_guy_weapon = tmp2.begin();
                                else
                                {
                                    for(auto j=tmp2.begin();;j++)
                                        if(++j == tmp2.end()) 
                                        {second_guy_weapon = --j; break;}
                                        else --j;
                                }
                                
                            }
                    if(tmp2.size() == 0)break;
                    }
                    
                    second_guy_weapon ++;
                } while (0 && first_guy->hp > 0 && second_guy->hp > 0 && second_guy->weapon->all_weapon.size() > 0 && (*second_guy_weapon).first == tmp_weapon_id);
            }
            if(first_guy->hp <= 0 || second_guy->hp <= 0) return;
            if(first_guy->weapon->all_weapon.size() == 0 && second_guy->weapon->all_weapon.size() == 0) return;
            if(i>1e4) return;
            if(first_guy_weapon == first_guy->weapon->all_weapon.end()) first_guy_weapon = first_guy->weapon->all_weapon.begin();
            if(second_guy_weapon == second_guy->weapon->all_weapon.end()) second_guy_weapon = second_guy->weapon->all_weapon.begin();//restart the attack
        }
    }

    void report()
    {
        cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
        int n1 = 0, n2 = 0, n3 = 0;
        for(auto i:weapon->all_weapon)
        {
            if(i.second <= 0) continue;
            switch (i.first)
            {
            case 0:
                n1 ++;
                break;
            case 1:
                n2 ++;
                break;
            case 2:
                n3 ++;
            default:
                break;
            }
        }
        if(group) cout << " blue ";
        else cout << " red ";
        cout << this->name() << ' ' << id << " has " << n1 << " sword " << n2 <<" bomb ";
        cout << n3 << " arrow and " << hp << " elements\n";
    }
};

vector<People*> blue_warrior, red_warrior;

class Dragon:public People
{
public:
    virtual string name(){return "dragon";}
    Dragon(int _t1, int _t2, int _t3, int _t4, bool st):People(_t1, _t2, _t3, st)
    {
        weapon = new Weapon(_t4);
        cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
        if(st) cout << " blue ";
        else cout << " red ";
        cout << "dragon " << id << " born\n";
    }
};
class Ninja:public People
{
public:
    virtual string name(){return "ninja";}
    Ninja(int _t1, int _t2, int _t3, int _t4, int _t5, bool st):People(_t1, _t2, _t3, st)
    {
        weapon = new Weapon(_t4, _t5);
        cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
        if(st) cout << " blue ";
        else cout << " red ";
        cout << "ninja " << id << " born\n";
    }
};
class Iceman:public People
{
public:
    virtual string name(){ return "iceman";}
    Iceman(int _t1, int _t2, int _t3, int _t4, bool st):People(_t1, _t2, _t3, st)
    {
        weapon = new Weapon(_t4);
        cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
        if(st) cout << " blue ";
        else cout << " red ";
        cout << "iceman " << id << " born\n";
    }
};
class Lion:public People
{
public:
    virtual string name(){return "lion";}
    Lion(int _t1, int _t2, int _t3, int _t4, int _t5, bool st):People(_t1, _t2, _t3, st)
    {
        loyal = _t5;
        weapon = new Weapon(_t4);
        cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
        if(st) cout << " blue ";
        else cout << " red ";
        cout << "lion " << id << " born\n";
        cout << "Its loyalty is " << loyal << endl;
    }
};
class Wolf:public People
{
public:
    virtual string name(){ return "wolf";}
    Wolf(int _t1, int _t2, int _t3, bool st):People(_t1, _t2, _t3, st)
    {
        weapon = new Weapon();
        cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
        if(st) cout << " blue ";
        else cout << " red ";
        cout << "wolf " << id << " born\n";
    }
    virtual void grub_weapon(People *tmp_wolf, People *tmp_other, int city_id)
    {
        auto & t_wolf = tmp_wolf->weapon->all_weapon;
        auto & t_other = tmp_other->weapon->all_weapon;
        
        auto weapon_id = (*t_other.begin()).first;

        
        
        if(t_other.size() > 0 && t_wolf.size() < 10)
        {
            cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
            if(tmp_wolf->group) cout << " blue wolf ";
            else cout << " red wolf ";
            cout << tmp_wolf->id << " took ";

            int weapon_cnt = 0;
            string weapon_name;

            if(weapon_id < 2)
            {
                while (t_wolf.size() < 10 && t_other.size() > 0 && weapon_id == (*t_other.begin()).first)
                {
                    weapon_cnt ++;
                    auto tmp_iterator = t_other.begin();
                    t_wolf.insert(*t_other.begin());
                    t_other.erase(t_other.begin(), ++tmp_iterator);

                } 
            }
            else
            {
                weapon_id = (*t_other.rbegin()).first;
                while (t_wolf.size() < 10 && t_other.size() > 0 && weapon_id == (*t_other.rbegin()).first)
                {
                    weapon_cnt ++;
                    auto tmp_iterator = t_other.end();
                    tmp_iterator --;
                    t_wolf.insert(*tmp_iterator);
                    t_other.erase(tmp_iterator, t_other.end());
                } 
                
            }
            weapon_name = weapons[weapon_id];
            cout << weapon_cnt << ' ' << weapon_name << " from ";
            if(tmp_other->group) cout << "blue ";
            else cout << "red ";
            cout << tmp_other->name() << ' ' << tmp_other->id << " in city " << city_id << endl;
        }
    }
};

bool cmp1(People *i, People *j)
{
    return i->pos < j->pos;
}

int main()
{
    int t, n_t;
    cin >> t;
    n_t = t;
    while (t--)
    {
        bool st = false;
        blue_warrior.clear();
        red_warrior.clear();
        cout << "Case " << n_t - t << ':' << endl;
        hour = 0, minute = 0;
        cin >> M >> N >> K >> T;
        int blue_hp = M, red_hp = M, blue_id = 1, red_id = 1;
        bool blue_st = true, red_st = true;
        for (int i = 0; i < 5; i++)
        {
            int x;
            cin >> x;
            HP[warrior[i]] = x;
        }
        for (int i = 0; i < 5; i++)
        {
            int x;
            cin >> x;
            POWER[warrior[i]] = x;
        }
        for(;;hour++)
        {
            minute = 0;
            People *blue_one = nullptr;
            People *red_one = nullptr;
            


            if(red_hp >= HP[red_order[hour%5]] && red_st)
            {
                switch (hour%5)
                {
                case 1:
                    red_one = new Lion(red_id, HP["lion"], POWER["lion"], red_id%3, red_hp-HP["lion"], false);
                    red_id ++, red_hp -= HP["lion"];
                    break;
                case 4:
                    red_one = new Dragon(red_id, HP["dragon"], POWER["dragon"], red_id%3, false);
                    red_id ++, red_hp -= HP["dragon"];
                    break;
                case 3:
                    red_one = new Ninja(red_id, HP["ninja"], POWER["ninja"], red_id%3,(red_id+1)%3, false);
                    red_id ++, red_hp -= HP["ninja"];
                    break;
                case 0:
                    red_one = new Iceman(red_id, HP["iceman"], POWER["iceman"], red_id%3, false);
                    red_id ++, red_hp -= HP["iceman"];
                    break;
                case 2:
                    red_one = new Wolf(red_id, HP["wolf"], POWER["wolf"], false);
                    red_id ++, red_hp -= HP["wolf"];
                    break;
                default:
                    break;
                }
            }
            else red_st = false;
            if(red_one) red_warrior.push_back(red_one);

            if(blue_hp >= HP[blue_order[hour%5]] && blue_st)
            {
                switch (hour%5)
                {
                case 0:
                    blue_one = new Lion(blue_id, HP["lion"], POWER["lion"], blue_id%3, blue_hp-HP["lion"], true);
                    blue_id ++, blue_hp -= HP["lion"];
                    break;
                case 1:
                    blue_one = new Dragon(blue_id, HP["dragon"], POWER["dragon"], blue_id%3, true);
                    blue_id ++, blue_hp -= HP["dragon"];
                    break;
                case 2:
                    blue_one = new Ninja(blue_id, HP["ninja"], POWER["ninja"], blue_id%3,(blue_id+1)%3, true);
                    blue_id ++, blue_hp -= HP["ninja"];
                    break;
                case 3:
                    blue_one = new Iceman(blue_id, HP["iceman"], POWER["iceman"], blue_id%3, true);
                    blue_id ++, blue_hp -= HP["iceman"];
                    break;
                case 4:
                    blue_one = new Wolf(blue_id, HP["wolf"], POWER["wolf"], true);
                    blue_id ++, blue_hp -= HP["wolf"];
                    break;
                default:
                    break;
                }
            }
            else blue_st = false;
            if(blue_one) blue_warrior.push_back(blue_one);
            
            if(hour * 60 + minute >= T) break;

            minute = 5;
            


            map<int, pair<bool, int> > run_lion;
            for(auto i = red_warrior.begin();i != red_warrior.end();i++)
                if((*i) -> loyal <= 0 && (*i)->name() == "lion")
                {
                    run_lion.insert({(*i)->pos, {(*i)->group, (*i)->id}});
                    red_warrior.erase(i, i+1);
                    i = red_warrior.begin() - 1;
                }
            for(auto i = blue_warrior.begin();i != blue_warrior.end();i++)
                if((*i) -> loyal <= 0 && (*i)->name() == "lion")
                {
                    run_lion.insert({(*i)->pos, {(*i)->group, (*i)->id}});
                    blue_warrior.erase(i, i+1);
                    i = blue_warrior.begin() - 1;
                }
            for(auto i:run_lion)
            {
                cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
                if(i.second.first) cout << " blue ";
                cout << "lion " << i.second.second << ' ' << "ran away\n";
            }


            minute = 10;
            if(hour * 60 + minute >= T) break;

            sort(red_warrior.begin(), red_warrior.end(), cmp1);
            for(auto i=0;i<red_warrior.size();i++)
            {
                if(red_warrior[i]->hp > 0)
                {
                    if(red_warrior[i]->name() == "lion") red_warrior[i]->loyal -= K;

                    if(red_warrior[i]->name() == "iceman") red_warrior[i]->hp -= (red_warrior[i]->hp / 10);
                    red_warrior[i]->pos ++;
                }
            }
            sort(blue_warrior.begin(), blue_warrior.end(), cmp1);
            for(auto i=0;i<blue_warrior.size();i++)
            {
                if(blue_warrior[i]->hp > 0)
                {
                    if(blue_warrior[i]->name() == "lion") blue_warrior[i]->loyal -= K;

                    if(blue_warrior[i]->name() == "iceman") blue_warrior[i]->hp -= (blue_warrior[i]->hp / 10);
                    blue_warrior[i]->pos --;
                }
            }
            

            vector<People*> city[N+2];//an array of pointer
            for (int i = 0; i <= N+1; i++)
            {
                for(auto j:red_warrior) if(j->pos == i) city[i].push_back(j);
                for(auto j:blue_warrior) if(j->pos == i) city[i].push_back(j);
            }
            for(int i=0;i<=N+1;i++)
            {
                for(auto j:city[i])
                {
                    cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
                    if(j->group) cout << " blue ";
                    else cout << " red ";
                    cout << j->name() << ' ' << j->id;
                    if(j->group && j->pos == 0) cout << " reached red headquarter";
                    else if(j->group == false && j->pos == N + 1) cout << " reached blue headquarter";
                    else cout << " marched to city " << j->pos;
                    cout << " with " << j->hp << " elements and force " << j->power << endl;
                    if(j->group == false && j->pos > N)
                    {
                        cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
                        cout << " blue headquarter was taken\n"; 
                        st = true;
                        
                    }
                    if(j->group && j->pos < 1)
                    {
                        cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
                        cout << " red headquarter was taken\n";
                        st = true;
                        
                    }
                    
                }
                //if(st) break;
            }
            if(st) break;
            if(hour * 60 + minute >= T) break;

            minute = 35;
            
            
            for (int i = 1; i <= N; i++)
            {
                if(city[i].size() > 1)
                {
                    if(city[i][0]->name() == "wolf" && city[i][1]->name() != "wolf")
                    {
                        city[i][0]->grub_weapon(city[i][0], city[i][1], i);
                    }
                    else if(city[i][0]->name() != "wolf" && city[i][1]->name() == "wolf")
                    {
                        city[i][1]->grub_weapon(city[i][1], city[i][0], i);
                    }
                }
            }
            if(hour * 60 + minute >= T) break;
            minute = 40;//fight

            for (int i = 1; i <= N; i++)
            {
                if(city[i].size() > 1 && city[i][0]->hp > 0 && city[i][1]->hp > 0)//hp isn't zero then fight
                {
                    if(i&1) city[i][0]->fight(city[i][0], city[i][1]);//red warrior must be the first.
                    else city[i][0]->fight(city[i][1], city[i][0]);

                    //report
                    cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
                    if(city[i][0]->hp > 0 && city[i][1]->hp <= 0)//red win
                    {
                        city[i][0]->win_grub_weapon(city[i][0], city[i][1]);
                        cout << " red " << city[i][0]->name() << ' ' << city[i][0]->id << " killed blue ";
                        cout << city[i][1]->name() << ' ' << city[i][1]->id << " in city "<<  city[i][0]->pos <<" remaining " << city[i][0]->hp << " elements\n";
                    }
                    else if(city[i][0]->hp <= 0 && city[i][1]->hp > 0)//blue win
                    {
                        city[i][0]->win_grub_weapon(city[i][1], city[i][0]);
                        cout << " blue " << city[i][1]->name() << ' ' << city[i][1]->id << " killed red ";
                        cout << city[i][0]->name() << ' ' << city[i][0]->id << " in city "<<  city[i][0]->pos <<" remaining " << city[i][1]->hp << " elements\n";
                    }
                    else if(city[i][0]->hp <= 0 && city[i][1]->hp <= 0)//both died
                    {
                        cout << " both red " << city[i][0]->name() << ' ' << city[i][0]->id << " and blue ";
                        cout << city[i][1]->name() << ' ' << city[i][1]->id << " died in city " << city[i][0]->pos << endl;
                    }
                    else if(city[i][0]->hp > 0 && city[i][1]->hp > 0)//both alive
                    {
                        cout << " both red " << city[i][0]->name() << ' ' << city[i][0]->id << " and blue ";
                        cout << city[i][1]->name() << ' ' << city[i][1]->id << " were alive in city " << city[i][0]->pos << endl;
                    }
                
                    //dragon yelled
                    if(city[i][0]->hp > 0 && city[i][0]->name() == "dragon")
                    {
                        cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute << " red dragon ";
                        cout << city[i][0]->id << " yelled in city " << city[i][0]->pos << endl;
                    }
                    if(city[i][1]->hp > 0 && city[i][1]->name() == "dragon")
                    {
                        cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute << " blue dragon ";
                        cout << city[i][1]->id << " yelled in city " << city[i][1]->pos << endl;
                    }
                }
                if(city[i].size() > 1)
                {
                    if(city[i][1]->hp <= 0)city[i].pop_back();
                    if(city[i][0]->hp <= 0)
                    {
                        swap(city[i][0], city[i][1]);
                        city[i].pop_back();
                    }
                }
                if(city[i].size() == 1) if(city[i][0]->hp <= 0) city[i].pop_back();
            }
            if(hour * 60 + minute >= T) break;
            minute = 50;
            cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
            cout << ' ' << red_hp << " elements in red headquarter\n";
            cout << setw(3) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
            cout << ' ' << blue_hp << " elements in blue headquarter\n";
            if(hour * 60 + minute >= T) break;//mintue 50
            minute = 55;
            for(int i=0;i<=N+1;i++)
                for(auto j:city[i]) j->report();
            

            red_warrior.clear(), blue_warrior.clear();
            for(int i=0;i<=N+1;i++)
            {
                for(auto j:city[i])
                {
                    if(j->hp <= 0) continue;//backup
                    if(j->group) blue_warrior.push_back(j);
                    else red_warrior.push_back(j);
                }
            }
            if(hour * 60 + minute >= T) break;//minute 55

        }
        
    }
    
    return 0;
}