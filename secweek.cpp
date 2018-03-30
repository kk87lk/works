#include <iostream>
#include <string.h>
#include <Windows.h>
#define MAXSIZE 100000
#define ElementType int
#define nullptr 0

typedef struct
{
    ElementType array[MAXSIZE];
    int last;
}SqList;
SqList a;
class List
{
    public:
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
            std::cout << "The creat operation is completed." << std::endl;
            fflush(stdin);
            getchar();
        }

        void output_list (SqList L)
        {
            system("cls");
            for (int i = 0; i < L.last; i++)
            {
                std::cout << "The NO." << i + 1 << " element is:" << L.array[i] << std::endl;
            }
            std::cout << "The output operation is completed." << std::endl;
        }

        void insert_sq (SqList *L)
        {
            system("cls");
            int num = 0;
            ElementType elem;
            std::cout << "Input the location of element you want to insert:" << std::endl;
            std::cin >> num;
            if (num < 1 || num > L->last + 1)
            {
                std::cout << "Illegal location!" << '\n' << std::endl;
                return;
            }
            system("cls");
            num --;
            std::cout << "Input the value of element you want to insert:" << std::endl;
            std::cin >> elem;
            for (int i = 0; i < L->last - num; i++)
            {
                L->array[L->last - i] = L->array[L->last - i -1];
            }
            L->last ++;
            L->array[num] = elem;
            std::cout << "The insert operation is completed." << std::endl;
            fflush(stdin);
            getchar();
        }

        void delete_sq (SqList *L)
        {
            system("cls");
            int num = 0;
            std::cout << "Input the location of element you want to delete:" << std::endl;
            std::cin >> num;
            if (num < 1 || num > L->last + 1)
            {
                std::cout << "Illegal location!" << '\n' << std::endl;
                return;
            }
            system("cls");
            for (int i = num; i < L->last; i++)
            {
                L->array[i - 1] = L->array[i];
            }
            L->array[L->last] = nullptr;
            L->last--;
            std::cout << "The delete operation is completed." << std::endl;
            fflush(stdin);
            getchar();
        }

        void queryva (SqList *L)
        {
            system("cls");
            std::cout << "Input the value you want to query:" << '\n' <<std::endl;
            int value = 0;
            std::cin >> value;
            for(int i = 0; i <= L->last; i++)
            {
                if (value != L->array[i] && i == L->last)
                std::cout << "There's no same value in the list." << '\n' <<std::endl;
                if (value == L->array[i])
                {
                    std::cout << "The element " << value <<"'s No was " << i + 1 << '\n' <<std::endl;
                    return;
                }
            }
        }

        void queryno (SqList *L)
        {
            system("cls");
            std::cout << "Input the No. you want to query:" << '\n' <<std::endl;
            int no = 0;
            std::cin >> no;
            for(int i = 0; i <= L->last; i++)
            {
                if (no != i && i == L->last)
                std::cout << "The No. you input doesn't exist in the list." << '\n' <<std::endl;
                if (no == i)
                {
                    std::cout << "The No." << no <<" element's value was " << L->array[i] << '\n' <<std::endl;
                    return;
                }
            }
        }

        void query_sq (SqList *L)
        {
            system("cls");
            int num = 0;
            std::cout << "Choose the way you want to query:" << '\n'
            << "1.Query by value." << '\n' << "2.Query by the No." << '\n' << std::endl;
            std::cin >> num;
            if (num == 1) queryva (L);
            else if (num == 2) queryno (L);
            else std::cout << "Invalid option." << '\n' <<std::endl;
        }
};

int  main()
{
    List L;
    int sel;
    do{
        system("cls");
        fflush(stdin);
        std::cout << "Choose an option" << '\n';
        std::cout << "1 - Creat a list" << '\n';
        std::cout << "2 - Output the list" << '\n';
        std::cout << "3 - Insert an element" << '\n';
        std::cout << "4 - Delete an element" << '\n';
        std::cout << "5 - Query an element" << '\n';
        std::cout << "0 - Exit" << '\n';
        std::cin >> sel;
        switch (sel)
        {
            case 0: {return 0; break;}
            case 1: {L.creat_list(&a); break;}
            case 2: {L.output_list(a);
            		fflush(stdin);
					getchar();
					break;}
            case 3: {L.insert_sq(&a);
                fflush(stdin);
                break;}
            case 4: {L.delete_sq(&a);
                fflush(stdin);
                break;}
            case 5: {L.query_sq(&a);
            fflush(stdin);
            getchar();
            break;}
            default:
            {
                std::cout << "Invalid option." << '\n';
                Sleep(500);
                system("cls");
            }
        }
    }while (true);
}