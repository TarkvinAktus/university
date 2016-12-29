#include <iostream>

using namespace std;

int rows;
int rows_length;



int main()
{

    cout << "\n_____----------------------------------------------------------------------____"
        << "\n__________________| �ணࠬ�� ��� ������ ᢮������ ���� � ���� |________________"
        << "\n_____________________|  ������� ������� ���� � ������ ���. |___________________"
        << "\n_____----------------------------------------------------------------------____"
        << "\n\n";

    cout << "  ������ �᫮ �冷�: ";
    cin >> rows;
    cout << "  ������ �᫮ ����: ";
    cin >> rows_length;

    while(rows<0|| rows_length<0||cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "  �訡�� �����, ������ ������.\n";
            cout << "  ������ �᫮ �冷�: ";
            cin >> rows;
            cout << "  ������ �᫮ ����: ";
            cin >> rows_length;
        }



    int cinema_hall [rows][rows_length];
    //���������� ���ᨢ� ��ﬨ
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows_length;j++)
        {
            cinema_hall [i][j] = 0;
        }
    }
    //�뢮� ���ᨢ�
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows_length;j++)
        {
            cout << "|"<<cinema_hall [i][j]<< "|";
        }
        cout<< "\n";
    }


    bool filling_array = true; // 䫠� �த������� ���������� ���ᨢ�
    int row; //���� ��� ��࠭���� �鸞
    int seat; //���� ��� ��࠭���� ����
    char add_seat; //��६����� �롮� �த������� ���������� ���ᨢ�

    int select_row; // ��६����� ��࠭���� �鸞 ��� ������� ������� ����
    int row_counter=0; //����稪 ������� ���� � ���

    cout<<"  ������ ������ ����\n";



    while(filling_array==true)
    {

        cout<<"  ������ ��: ";
        cin >> row;
        row--;
        cout << "  ������ ����: ";
        cin >> seat;
        seat--;

        while(row<0|| row>rows|| seat<0||seat>rows_length||cin.fail())
        {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "  �訡�� �����, ������ ����";
                cout<<"  ������ ��: ";
                cin >> row;
                row--;
                cout << "  ������ ����: ";
                cin >> seat;
                seat--;

        }
        cout << "  ���� ����� ���?\n y - ��  n - ���\n";
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
            cout << "  �訡��, ������ 'y' ��� 'n'\n";
            cin >> add_seat;
        }



    }


    //�뢮� ���ᨢ�
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows_length;j++)
        {
            cout << "|"<<cinema_hall [i][j]<< "|";
        }
        cout<< "\n";
    }



    cout << "  ������ ��, � ���஬ �� ��� ������� �த���� ����: ";
    cin >> select_row;

    while(select_row < 0 || select_row>rows || cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "  �訡�� �����, ���஡�� ��� ࠧ: ";
            cin >> select_row;
        }
    select_row--;

    for(int i=0;i<rows_length;i++)
    {
        if(cinema_hall[select_row][i]==1)
        row_counter++;
    }



    string ending1 = " ����.";
    string ending2 = " ����.";
    string ending3 = " ����. ";

    if(row_counter%10==1)
        ending3=ending1;
    if(row_counter%10==2 || row_counter%10==3 || row_counter%10==4)
        ending3=ending2;


    cout << "  � ��࠭��� �拉 ����� "<<row_counter<<ending3<<endl;



    return 0;
}
