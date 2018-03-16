#include <iostream>
#include <string.h>
#include <Windows.h>
#define MAXSIZE 100000 
#define ElementType int 
typedef struct
{
    ElementType array[MAXSIZE];
    int last;
}SqList;
SqList a;
void creat_list (SqList *L)
{
    int i = 0;
    int num = 0;
    system("cls");
    std::cout << "How many numbers you want to input?" << std::endl;
    std::cin >> num;
    L->last = num;
    for (int i = 0; i < num; i++)
    {
        system("cls");
        std::cout << "Input the NO." << i + 1 << " element:" << std::endl;
        std::cin >> L->array[i];
    }
}
void output_list (SqList L)
{
	system("cls");
    for (int i = 0; i < L.last; i++)
    {
        std::cout << "The NO." << i + 1 << " element is:" << L.array[i] << std::endl;
    }
}
void insert_sq (SqList *L, int i, ElementType e);
int menu()
{
    int sel;
    do{
        system("cls");
        fflush(stdin);
        std::cout << "Choose an option" << '\n';
        std::cout << "1 - Creat a list" << '\n';
        std::cout << "2 - Output the list" << '\n';
        std::cout << "0 - Exit" << '\n';
        std::cin >> sel;
        switch (sel)
        {
            case 0: {return 0; break;}
            case 1: {creat_list(&a); break;}
            case 2: {output_list(a);
            		fflush(stdin);
					getchar();
					 break;}
            default: 
            {
                std::cout << "Invalid option" << '\n';
                Sleep(500);
                system("cls");
            }
        }
    }while (true);
}
int  main()
{
    menu();
}