#include <iostream>

using namespace std;

int rows;
int rows_length;



int main()
{

    cout << "\n_____----------------------------------------------------------------------____"
        << "\n__________________| Программа для показа свободных мест в зале |________________"
        << "\n_____________________|  Подсчёт занятых мест в каждом ряду. |___________________"
        << "\n_____----------------------------------------------------------------------____"
        << "\n\n";

    cout << "  Введите число рядов: ";
    cin >> rows;
    cout << "  Введите число мест: ";
    cin >> rows_length;

    while(rows<0|| rows_length<0||cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "  Ошибка ввода, введите заново.\n";
            cout << "  Введите число рядов: ";
            cin >> rows;
            cout << "  Введите число мест: ";
            cin >> rows_length;
        }



    int cinema_hall [rows][rows_length];
    //заполнение массива нулями
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows_length;j++)
        {
            cinema_hall [i][j] = 0;
        }
    }
    //вывод массива
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows_length;j++)
        {
            cout << "|"<<cinema_hall [i][j]<< "|";
        }
        cout<< "\n";
    }


    bool filling_array = true; // флаг продолжения заполнения массива
    int row; //буфер для выбранного ряда
    int seat; //буфер для выбранного места
    char add_seat; //переменная выбора продолжения заполнения массива

    int select_row; // переменная выбранного ряда для подсчёта занятых мест
    int row_counter=0; //Счётчик занятых мест в ряду

    cout<<"  Введите занятые места\n";



    while(filling_array==true)
    {

        cout<<"  Введите ряд: ";
        cin >> row;
        row--;
        cout << "  Введите место: ";
        cin >> seat;
        seat--;

        while(row<0|| row>rows|| seat<0||seat>rows_length||cin.fail())
        {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "  Ошибка ввода, повторите ввод";
                cout<<"  Введите ряд: ";
                cin >> row;
                row--;
                cout << "  Введите место: ";
                cin >> seat;
                seat--;

        }
        cout << "  Хотите ввести ещё?\n y - да  n - нет\n";
        cin >> add_seat;

        if(add_seat == 'n')
        {
            filling_array = false;
            cinema_hall [row][seat] = 1;
        }

        cinema_hall [row][seat] = 1;

        while((add_seat != 'y' && add_seat != 'n') || cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "  Ошибка, введите 'y' или 'n'\n";
            cin >> add_seat;
        }



    }


    //вывод массива
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows_length;j++)
        {
            cout << "|"<<cinema_hall [i][j]<< "|";
        }
        cout<< "\n";
    }



    cout << "  Введите ряд, в котором вы хотите посчитать проданные места: ";
    cin >> select_row;

    while(select_row < 0 || select_row>rows || cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "  Ошибка ввода, попробуйте ещё раз: ";
            cin >> select_row;
        }
    select_row--;

    for(int i=0;i<rows_length;i++)
    {
        if(cinema_hall[select_row][i]==1)
        row_counter++;
    }



    string ending1 = " место.";
    string ending2 = " места.";
    string ending3 = " мест. ";

    if(row_counter%10==1)
        ending3=ending1;
    if(row_counter%10==2 || row_counter%10==3 || row_counter%10==4)
        ending3=ending2;


    cout << "  В выбранном ряде занято "<<row_counter<<ending3<<endl;



    return 0;
}
