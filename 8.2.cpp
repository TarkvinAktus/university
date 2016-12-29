#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{

    string str1 = "234597245645675";
    string str2 = "838363463355776";

    cout << "\n\n1 строка: " << str1 << "\n2 cтрока: " << str2<<endl;
    long long int n1,n2;

    //Строка -> число
    istringstream ist1(str1);
    ist1 >> n1;

    istringstream ist2(str2);
    ist2 >> n2;

    long long int n3 = n1+n2;

    cout << "          ---------------\n"<<"сумма:   "<<n3 << endl;

    //Число -> строка
    ostringstream ost;
    ost << n3;
    string s_num = ost.str();
    cout << "\n\nВ формате строки:\n         " <<s_num << endl;

    return 0;
}
