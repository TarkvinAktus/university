#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

int size;

void HandleEnter(int **array)
{
    for(int i = 0;i<size;i++)
    {
        array[i] = new int[size];
        for(int j = 0; j<size; j++)
        {
            cout << "\n" <<"\t\tВведите элемент номер [" << i+1 << "][" << j+1 << "] - ";
            cin >> array[i][j];
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Ошибка.повторите ввод!" << endl;
                cin >> array[i][j];
            }
        }
    }
}


void AutoEnter(int **array)
{

    for(int i = 0; i < size; i++)
    {
		array[i] = new int[size];
		for(int j = 0; j < size; j++)
		{
			array[i][j] = rand()%10;
		}
    }

}

void max_num_upper_fourth(int **array)
{
    int min = 100;

    for(int i = 0; i < size; i++)
    {
		for(int j = 0; j < size; j++)
		{
			if(i+j<=size-2&&j>i)
            {
                if(array[i][j]<min)
                min = array[i][j];
            }
            else{array[i][j] = 0;}
		}
    }
    cout << "\nМинимальный элемент = " << min << "\n\n";

}

void show_matrix(int **array)
{
    cout<<"\n";
    for(int i = 0;i<size;i++)
    {
        for(int j = 0; j<size; j++)
        {
            cout << " " << array[i][j] << " ";

        }
        cout<<"\n";
    }
}

void trans(int **array)
{
int s;
for(int i=0; i < size; i++)
{   for(int j=i+1; j < size; j++)
    {
        s=array[i][j];
        array[i][j]=array[j][i];
        array[j][i]=s;
    }
}
}


int main()
{
    int choice;

    cout << "\n_____----------------------------------------------------------------------____"
        << "\n___________________| Программа обработки двумерного массива |___________________"
        << "\n________________|  Найти макс элемент верхней четверти матрицы |________________"
        << "\n_____----------------------------------------------------------------------____"
        << "\n\n"
        << "\t\tВведите размер массива -  ";

    cin >> size;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "\t\tОшибка. Нужно ввести любое натуральное число - ";
        cin >> size;
    }


    int** array = new int*[size];


    cout << "\n" << "\t\tНажмите 0, чтобы запонить массив вручную,"
        << "\n"<< "\t\tили 1 , чтобы заполнить его автоматически - ";

    cin >> choice;
    while((choice !=0 && choice !=1) || cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "\t\tОшибка. Нажмите 1 или 0 - ";
        cin >> choice;
    }



    switch(choice)
    {
        case 0 :
            HandleEnter(array);
            break;
        case 1 :
            AutoEnter(array);
            break;
    }

    show_matrix(array);

    trans(array);

    cout << "\nТранспонированная матрица:"<<endl;

    show_matrix(array);

    return 0;
}





