    #include <iostream>
    #include <string>
    #include <cstdio>
    #include <cstring>
    #include <sstream>
    #include <cstdlib>
    using namespace std;

    class Student {
        private:
        char name[22];
        int id, age, score1, score2, score3, score4;
        double ave;
        public:
        void input()
        {
            cin.getline(name, 21, ',');
            scanf("%d,%d,%d,%d,%d,%d", &age, &id, &score1, &score2, &score3, &score4);

        }
        void calculate()
        {
            ave = (score1+score2+score3+score4)*1.0/4;
        }
        void output()
        {
            
            printf("%s,%d,%d,", name, age, id);
            cout << ave;
        }
        


    };

    int main() {
        Student student;        // 定义类的对象
        student.input();        // 输入数据
        student.calculate();    // 计算平均成绩
        student.output();       // 输出数据
    }