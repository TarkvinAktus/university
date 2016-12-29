#include <iostream>
#include <fstream>
#include <cstring>
#include <fstream>
#include <cstdlib>



using namespace std;


void HandleEnter (char *array)
{
    cout << "\t\tВведите строку (макс 256 символов)";
    fflush(stdin);
    fgets(array,256,stdin);
}

void FileUpload (char *array)
{
    ifstream myFile("DZ6.txt");

    char buff[256];
    myFile.getline(buff,256);
    myFile.close();


    for (int i = 0 ; i<256; i++)
    {
        array[i] = buff [i];
    }
}

void initialization ( char *array)
{

    char choice;
    cout << "\t\tНажмите 0 для печати вручную," << "\n"
         <<"\t\tНажмите 1 для загрузки из файла - ";
    cin >> choice;
    cout << "\n\n";
    while ((choice != '0' && choice != '1' )|| cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "\t\tОшибка. Нажмите 0 или 1 - ";
        cin >> choice;
    }

    if(choice == '0')
    {
        HandleEnter(array);
    }
    else
    {
        FileUpload(array);
    }
}

void SubstringEnter (char *substring)
{
    cout << "\n\n" << "\t\tВведите подстроку: ";
    fflush(stdin);
    gets(substring);
}

int BM_Alg (char *array,char *substring)
{
    int  sl, ssl;
    int res = -1;

    sl = strlen(array);
    ssl = strlen(substring);

    if ( sl == 0 )
    cout << "\nОшибка, пустая строка\n";
    else if ( ssl == 0 )
    cout << "\nОшибка, пустая подстрокаn";
    else {
    int  i, Pos;

    int  BMT[256];
    for ( i = 0; i < 256; i ++ )
      BMT[i] = ssl;

    for ( i = ssl-1; i >= 0; i-- )
      if ( BMT[(short)(substring[i])] == ssl )
        BMT[(short)(substring[i])] = ssl - i - 1;
    Pos = ssl - 1;

    while ( Pos < sl )
      if ( substring[ssl - 1] != array[Pos] )
        Pos = Pos + BMT[(short)(array[Pos])];

      else
        for ( i = ssl - 2; i >= 0; i-- )
        {
            if ( substring[i] != array[Pos - ssl + i + 1] )
                {
                Pos += BMT[(short)(array[Pos - ssl + i + 1])] - 1;
                break;
                }
          else
            if ( i == 0 )
              {cout<<"\n\n"<<"\t\tПодстрока начинается с элемента № ";return Pos - ssl + 1;}
        }
  }
  cout << "\n\n" << "\t\tПодстрока не найдена.Ошибка ";
  return res;

}




int main()
{

    cout << "\n_____----------------------------------------------------------------------____"
        << "\n_________| Работа со строками.Поиск подстроки алгоритмом Бойера-Мура |__________"
        << "\n_____----------------------------------------------------------------------____"
        << "\n\n";

    char array[256];
    char substring[30];
    initialization(array);
    cout << array;
    SubstringEnter(substring);
    cout << "\n" << "\t\t" << "Подстрока - " << substring;
    cout << "\n" << "\t\t" << "Длина подстроки - "<< strlen(substring);
    cout << "\n" << "\t\t" << "Длина строки - " << strlen(array);

    cout << BM_Alg (array,substring);
    cout << "\n\n";
    system("PAUSE");
    return 0;
}
