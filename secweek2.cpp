#include <iostream>
#include <string.h>
#include <malloc.h>
#include <Windows.h>
#define MAXSIZE 100000
#define ElementType int
#define nullptr 0

typedef struct Node
{
    ElementType Data;
    Node *next;
}Node;
Node *a;
class NodeList
{
    public:
        Node *creat_list (int *length)
        {
            int num;
            Node *head, *a, *b;
            head = (Node *)malloc(sizeof(Node));
            a = (Node *)malloc(sizeof(Node));
            b = (Node *)malloc(sizeof(Node));
            system("cls");
            std::cout << "Input the number.(input -999 to stop)" << std::endl;
            std::cin >> num;
            head->Data = num;
            head->next = a;
            while(num != -999)
            {
                std::cout << "Input the number.(input -999 to stop)" << std::endl;
                std::cin >> num;
                a->Data = num;
                a->next = b;
                a = b;
                b = (Node *)malloc(sizeof(Node));
                (*length)++;
            }
            std::cout << "The creat operation is completed." << std::endl;
            return head;
            fflush(stdin);
            getchar();
        }

        void output_list (Node *L)
        {
            system("cls");
            Node *e = L;
            for (int i = 0; i > -1; i++)
            {
                std::cout << "The NO." << i + 1 << " element is:" << e->Data << std::endl;
                if ((e->next)->Data != -999)
                e = e->next;
                else
                return;
            }
            std::cout << "The output operation is completed." << std::endl;
        }

        void insert_sq (Node *L, int *length)
        {
            system("cls");
            Node *e = L;
            Node *p = (Node *)malloc(sizeof(Node));
            int num = 0;
            ElementType elem;
            std::cout << "Input the location of element you want to insert:" << std::endl;
            std::cin >> num;
            if(num == *length + 1)
            {
            	for (int i = 1; i < *length; i++)
	            {
	                e = e->next;
	            }
	            system("cls");
	            std::cout << "Input the value of element you want to insert:" << std::endl;
	            std::cin >> elem;
            	p->Data = elem;
				p->next = e->next;
				e->next = p;
				return;
			}
            if (num < 1 || num > *length)
            {
                std::cout << "Illegal location!" << '\n' << std::endl;
                return;
            }
            system("cls");
            std::cout << "Input the value of element you want to insert:" << std::endl;
            std::cin >> elem;
            if(num == 1)
            {
				p->Data = L->Data;
				L->Data = elem;
				p->next = L->next;
				L->next = p;
				return;
			}
            num --;
			for (int i = 1; i < num; i++)
            {
                e = e->next;
            }
            (*length)++;
            p->Data = elem;
            p->next = e->next;
            e->next = p;
            std::cout << "The insert operation is completed." << std::endl;
            fflush(stdin);
            getchar();
        }

        void delete_sq (Node *L, int *length)
        {
            system("cls");
            int num = 0;
            Node *e = L;
            std::cout << "Input the location of element you want to delete:" << std::endl;
            std::cin >> num;
            if(num == *length + 1)
            {
            	for (int i = 1; i < *length; i++)
	            {
	                e = e->next;
	            }
				e->next = (e->next)->next;
				return;
			}
            if (num < 1 || num > *length)
            {
                std::cout << "Illegal location!" << '\n' << std::endl;
                return;
            }
            system("cls");
            if(num == 1)
            {
            	L->Data = (L->next)->Data;
				L->next = (L->next)->next;
				return;
			}
            for (int i = 2; i < num; i++)
            {
                e = e->next;
            }
            e->next = (e->next)->next;
            (*length)--;
            std::cout << "The delete operation is completed." << std::endl;
            fflush(stdin);
            getchar();
        }

        void queryva (Node *L, int *length)
        {
            system("cls");
            Node *e = L;
            std::cout << "Input the value you want to query:" <<std::endl;
            int value = 0;
            std::cin >> value;
            for(int i = 0; i <= *length; i++)
            {
                if (value != e->Data && i == *length)
                std::cout << "There's no same value in the list." << '\n' <<std::endl;
                if (value == e->Data)
                {
                    std::cout << "The element " << value <<"'s No was " << i + 1 << '\n' <<std::endl;
                    return;
                }
                e = e->next;
            }
        }

        void queryno (Node *L, int *length)
        {
            system("cls");
            std::cout << "Input the No. you want to query:" <<std::endl;
            int no = 0;
            Node *e = L;
            std::cin >> no;
            for(int i = 1; i <= *length; i++)
            {
                if (no > *length || no < 1)
                std::cout << "The No. you input doesn't exist in the list." << '\n' <<std::endl;
                if (no == i)
                {
                    std::cout << "The No." << no <<" element's value was " << e->Data << '\n' <<std::endl;
                    return;
                }
                e = e->next;
            }
        }

        void query_sq (Node *L,int *length)
        {
            system("cls");
            int num = 0;
            std::cout << "Choose the way you want to query:" << '\n'
            << "1.Query by value." << '\n' << "2.Query by the No." << '\n' << std::endl;
            std::cin >> num;
            if (num == 1) queryva (L, length);
            else if (num == 2) queryno (L, length);
            else std::cout << "Invalid option." << '\n' <<std::endl;
        }
};

int  main()
{
    NodeList L;
    int length = 0;
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
            case 1: {a = L.creat_list(&length); break;}
            case 2: {L.output_list(a);
            		fflush(stdin);
					getchar();
					break;}
            case 3: {L.insert_sq(a, &length);
                fflush(stdin);
                break;}
            case 4: {L.delete_sq(a, &length);
                fflush(stdin);
                break;}
            case 5: {L.query_sq(a, &length);
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