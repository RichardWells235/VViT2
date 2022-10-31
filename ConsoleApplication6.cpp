#include<iostream>//подключаем стандартную библиотеку ввода-вывода
#include<math.h>//библиотека для мат операций 

class Polynomial {// создаём класс с именем...
private:    //объявляем его закрыты члены-коэффициенты и корни соответственно
    int a;
    int b;
    int c;
    double x1;
    double x2;
public://общедоступные ф-ии
    Polynomial(int x, int y, int z) :a(x), b(y), c(z) {};//конструктор для инициализации коэфициентов
    int korni() {//подсчёт корней уравнения (this - обращение к текущему обьекту)
        double D;//дискриминант
        if (this->b % 2 == 0) {//возможность подсчёта через чётный Д
            D = pow((this->b / 2), 2) - (this->a) * (this->c);
            if (D < 0) {//адгебра
                std::cerr << "Дискриминант <0";//вывод в поток ошибок
                exit(-1);//аварийное завершение программы
            }
            x1 = (((-1) * this->b / 2) + sqrt(D)) / this->a;
            x2 = (((-1) * this->b / 2) - sqrt(D)) / this->a;
        }
        else {
            D = (double)((double)(this->b) * (double)(this->b) - 4 * ((double)this->a * (double)this->c));
            if (D < 0) {
                std::cerr << "Дискриминант <0";
                exit(-1);
            }
            x1 = (((-1) * this->b / 2) + sqrt(D)) / 2 * this->a;
            x2 = (((-1) * this->b / 2) - sqrt(D)) / 2 * this->a;
        }
        return 0;
    }
    double Get_x1() {//Гетер-возвращает значение
        return x1;//вовзврат корня
    }
    double Get_x2() {
        return x2;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "Введите через пробел коэффициенты квадратного уравнения(a b c)" << std::endl;
    int a; int c; int b;
    if (!(std::cin >> a >> b >> c)) {//ввод и его проверка
        std::cerr << "Error cin";//вывод в поток ошибок
        return -2;//аварийное завершение программы
    }
    Polynomial objj1(a, b, c);//создаём обьект класса и инициализируем его 3 параметрами
    objj1.korni();//вызываем ф-и. подсчётак корней
    std::cout << "x1=" << objj1.Get_x1() << "\t" << "x2=" << objj1.Get_x2()<<"\n";//вывод
    return 0;
}
