#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
struct player
{
char allname[20];
int money, dangqian;
int fangchan[5][19];
char name;
int hours;
int days;
int turns;
}p1, p2;
int main(void)
{
FILE *fp;
int shijian(int a);
int qipan(char weizhi[28]);
int qianjin(int qianjinbs, int dangqian, char weizhi[28], char name);
int houtui(int houtuibs, int dangqian, char weizhi[28], char name);
int renpin(int money);
int duchang(int money);
int meiqian(int money);
int houtuibs;
int choice;
int qianjinbs;
int m, n, p, q;
int a, b, c;
char weizhi[28] = " ";
int fang(int turns);
srand((unsigned)time(NULL));
p1.turns = 1;
p1.hours = 0;
p1.days = 0;
p1.dangqian = 0;
p2.dangqian = 0;
b = 0;
p1.money = 5000;
p2.money = 5000;
printf("��ӭ�������̵����磡���ǵ�������������ʣ�����\n");
printf("1.�µ��ó�\n2.�浵����\n");
scanf("%d", &a);
if (a == 2)
{
printf("������浵ʱ1P�����֣�\n");
getchar();
gets(p1.allname);
printf("%s", p1.allname);
fp = fopen(p1.allname, "rb");
fread(&p1, sizeof(struct player), 1, fp);
fread(&p2, sizeof(struct player), 1, fp);
fclose(fp);
goto turn;
}
printf("����1P�����֣�\n");
scanf("%d", &a);
gets(p1.allname);
p1.name = 1;
printf("����2P������: \n");
scanf("%d", &a);
gets(p2.allname);
p2.name = 2;
turn:
if (p1.turns)
{
system("cls");
weizhi[p1.dangqian] = 1;
weizhi[p2.dangqian] = 2;
qipan(weizhi);
printf("��%d��\n", p1.days);
if (p1.money<500)
{
printf("��ݣ�ƶ��: ");
}
else if (p1.money<10000)
{
printf("��ݣ�ƽ��: ");
}
else if (p1.money<20000)
{
printf("��ݣ�С��: ");
}
else if (p1.money<50000)
{
printf("��ݣ�����: ");
}
else if (p1.money<500000)
{
printf("��ݣ�����: ");
}
else
{
printf("��ݣ��׸�: ");
}
puts(p1.allname);
printf("��Ǯ:%d\n", p1.money);
weizhi[p1.dangqian] = ' ';
printf("��ѡ�����:0.�浵 1.�鿴���˷��� 2.ǰ��\n");
scanf("%d", &choice);
if (choice == 0)
{
fp = fopen(p1.allname, "wb");
fwrite(&p1, sizeof(struct player), 1, fp);
fwrite(&p2, sizeof(struct player), 1, fp);
fclose(fp);
goto turn;
}
else if (choice == 1)
{
for (a = 0; a <= 19; a++)
{
if (p1.fangchan[0][a] == 1)
{
switch (a)
{
case 0:printf("���Ǵ��1��\n"); b = 1; break;
case 1:printf("���Ǵ��2��\n"); b = 1; break;
case 2:printf("���·1��\n"); b = 1; break;
case 3:printf("���·2��\n"); b = 1; break;
case 4:printf("���·3��\n"); b = 1; break;
case 5:printf("���·4��\n"); b = 1; break;
case 6:printf("���·5��\n"); b = 1; break;
case 7:printf("���ڴ��1��\n"); b = 1; break;
case 8:printf("���ڴ��2��\n"); b = 1; break;
case 9:printf("���ڴ��3��\n"); b = 1; break;
case 10:printf("���ڴ��4��\n"); b = 1; break;
case 11:printf("���ڴ��5��\n"); b = 1; break;
case 12:printf("���ڴ��6��\n"); b = 1; break;
case 13:printf("���ڴ��7��\n"); b = 1; break;
case 14:printf("���ڴ��8��\n"); b = 1; break;
case 15:printf("���ڴ��9��\n"); b = 1; break;
case 16:printf("��·1��\n"); b = 1; break;
case 17:printf("��·2��\n"); b = 1; break;
case 18:printf("��·3��\n"); b = 1; break;
default:break;
}
if (b == 1)
{
if (p1.fangchan[1][a] == 1)
{
printf("�����ù�һ����\n");
printf("�ùݵȼ���%d�Ǽ�\n", p1.fangchan[2][a]);
printf("ÿ��ͣ����ȡ���ã�%d\n", p1.fangchan[3][a]);
printf("\n");
}
else if (p1.fangchan[1][a] == 2)
{
printf("�����̵�һ����\n");
switch (p1.fangchan[2][a])
{
case 1:printf("�ȼ���С����\n"); break;
case 2:printf("�ȼ����̵�\n"); break;
case 3:printf("�ȼ�������\n"); break;
case 4:printf("�ȼ���ȫ����������\n"); break;
case 5:printf("�ȼ�����������ó���г�\n"); break;
default:break;
}
printf("ÿ�غ�����Ϊ:%d", p1.fangchan[4][a]);
printf("\n");
}
else
{
printf("���е�Ƥһ�ݡ�\n");
}
}
}
}
system("pause");
goto turn;
}
else if (choice == 9)
{
qianjinbs = 1;
goto miji;
}
else
{
shijian(12);
if (p1.days >= 100)
{
goto end;
}
qianjinbs = rand() % 6;
qianjinbs = qianjinbs + 1;
miji:printf("��Ͷ����%d�㣡", qianjinbs);
p1.dangqian = qianjin(qianjinbs, p1.dangqian, weizhi, p1.name);
jintui:switch (p1.dangqian)
{
case 0:printf("ͣ����㽱��1000!\n"); p1.money += 1000; system("pause"); break;
case 3:printf("ǰ������\n"); c = 3; p1.dangqian = qianjin(c, p1.dangqian, weizhi, p1.name); goto jintui;
case 9:printf("������Ʒ��վ~~������Ʒ��ʱ���ˣ�\n"); Sleep(1000); p1.money = renpin(p1.money);; break;
case 16:printf("��������\n"); c = 2; p1.dangqian = houtui(c, p1.dangqian, weizhi, p1.name); goto jintui;
case 20: {printf("����ĳ�����\n");
Sleep(500);
p1.money = duchang(p1.money);
if (p1.days >= 100)
{
goto end;
}
break; }
case 21:printf("ǰ������\n"); c = 2; p1.dangqian = qianjin(c, p1.dangqian, weizhi, p1.name); goto jintui;
case 22:printf("������Ʒ��վ~~������Ʒ��ʱ���ˣ�\n"); Sleep(1000); p1.money = renpin(p1.money);; break;
default:fang(p1.turns); break;
}
system("cls");
weizhi[p1.dangqian] = 1;
qipan(weizhi);
weizhi[p1.dangqian] = ' ';
for (b = 1, a = 0; a <= 18; a++)
{
if (p1.fangchan[1][a] == 2)
{
printf("%d���̵����棺%d ", a, p1.fangchan[4][a]);
p1.money = p1.money + p1.fangchan[4][a];
b++;
if (b == 4)
{
printf("\n");
b = 1;
}
}
}
system("pause");
p1.turns = 0;
goto turn;
}
}
else
{
system("cls");
weizhi[p1.dangqian] = 1;
weizhi[p2.dangqian] = 2;
qipan(weizhi);
printf("��%d��\n", p1.days);
if (p2.money<500)
{
printf("��ݣ�ƶ��: ");
}
else if (p2.money<10000)
{
printf("��ݣ�ƽ��: ");
}
else if (p2.money<20000)
{
printf("��ݣ�С��: ");
}
else if (p2.money<50000)
{
printf("��ݣ�����: ");
}
else if (p2.money<500000)
{
printf("��ݣ�����: ");
}
else
{
printf("��ݣ��׸�: ");
}
puts(p2.allname);
printf("��Ǯ:%d\n", p2.money);
weizhi[p2.dangqian] = ' ';
printf("��ѡ�����:0.�浵 1.�鿴���˷��� 2.ǰ��\n");
scanf("%d", &choice);
if (choice == 0)
{
fp = fopen(p1.allname, "wb");
fwrite(&p1, sizeof(struct player), 1, fp);
fwrite(&p2, sizeof(struct player), 1, fp);
fclose(fp);
goto turn;
}
else if (choice == 1)
{
/* ���������Ϣ������ô�鷳 */
for (a = 0; a <= 19; a++)
{
if (p2.fangchan[0][a] == 1)
{
switch (a)
{
case 0:printf("���Ǵ��1��\n"); b = 1; break;
case 1:printf("���Ǵ��2��\n"); b = 1; break;
case 2:printf("���·1��\n"); b = 1; break;
case 3:printf("���·2��\n"); b = 1; break;
case 4:printf("���·3��\n"); b = 1; break;
case 5:printf("���·4��\n"); b = 1; break;
case 6:printf("���·5��\n"); b = 1; break;
case 7:printf("���ڴ��1��\n"); b = 1; break;
case 8:printf("���ڴ��2��\n"); b = 1; break;
case 9:printf("���ڴ��3��\n"); b = 1; break;
case 10:printf("���ڴ��4��\n"); b = 1; break;
case 11:printf("���ڴ��5��\n"); b = 1; break;
case 12:printf("���ڴ��6��\n"); b = 1; break;
case 13:printf("���ڴ��7��\n"); b = 1; break;
case 14:printf("���ڴ��8��\n"); b = 1; break;
case 15:printf("���ڴ��9��\n"); b = 1; break;
case 16:printf("��·1��\n"); b = 1; break;
case 17:printf("��·2��\n"); b = 1; break;
case 18:printf("��·3��\n"); b = 1; break;
default:break;
}
if (b == 1)
{
if (p2.fangchan[1][a] == 1)
{
printf("�����ù�һ����\n");
printf("�ùݵȼ���%d�Ǽ�\n", p2.fangchan[2][a]);
printf("ÿ��ͣ����ȡ���ã�%d\n", p2.fangchan[3][a]);
printf("\n");
}
else if (p2.fangchan[1][a] == 2)
{
printf("�����̵�һ����\n");
switch (p2.fangchan[2][a])
{
case 1:printf("�ȼ���С����\n"); break;
case 2:printf("�ȼ����̵�\n"); break;
case 3:printf("�ȼ�������\n"); break;
case 4:printf("�ȼ���ȫ����������\n"); break;
case 5:printf("�ȼ�����������ó���г�\n"); break;
default:break;
}
printf("ÿ�غ�����Ϊ:%d", p2.fangchan[4][a]);
printf("\n");
}
else
{
printf("���е�Ƥһ�ݡ�\n");
}
}
}
}
system("pause");
goto turn;
}
else if (choice == 9)
{
qianjinbs = 1;
goto miji2;
}
else
{
shijian(12);
if (p1.days >= 100)
{
goto end;
}
a = rand() % 6;
qianjinbs = a + 1;
miji2:printf("��Ͷ����%d�㣡", qianjinbs);
p2.dangqian = qianjin(qianjinbs, p2.dangqian, weizhi, p2.name);
jintui2:switch (p2.dangqian)
{
case 0:printf("ͣ����㽱��1000!\n"); p2.money += 1000; system("pause"); break;
case 3:printf("ǰ������\n"); c = 3; p2.dangqian = qianjin(c, p2.dangqian, weizhi, p2.name); goto jintui2;
case 9:printf("������Ʒ��վ~~������Ʒ��ʱ���ˣ�\n"); Sleep(1000); p2.money = renpin(p2.money);; break;
case 16:printf("��������\n"); c = 2; p2.dangqian = houtui(c, p2.dangqian, weizhi, p2.name); goto jintui2;
case 20: {printf("����ĳ�����\n");
Sleep(500);
p2.money = duchang(p2.money);
if (p1.days >= 100)
{
goto end;
}
break; }
case 21:printf("ǰ������\n"); c = 2; p2.dangqian = qianjin(c, p2.dangqian, weizhi, p2.name); goto jintui2;
case 22:printf("������Ʒ��վ~~������Ʒ��ʱ���ˣ�\n"); Sleep(1000); p2.money = renpin(p2.money);; break;
default:fang(p1.turns); break;
}
system("cls");
weizhi[p2.dangqian] = 2;
qipan(weizhi);
weizhi[p2.dangqian] = ' ';
for (b = 1, a = 0; a <= 18; a++)
{
if (p2.fangchan[1][a] == 2)
{
printf("%d���̵����棺%d ", a, p2.fangchan[4][a]);
p2.money = p2.money + p2.fangchan[4][a];
b++;
if (b == 4)
{
printf("\n");
b = 1;
}
}
}
system("pause");
p1.turns = 1;
goto turn;
}
}
end:printf("���֣�");
puts(p1.allname);
if (p1.money<3000)
{
printf("��ݣ�ƶ��\n");
printf("�������㣬�����Ǯ~��\n");
m = 10;
}
else if (p1.money<5000)
{
printf("��ݣ�ƽ��\n");
printf("����ǿǿ�����ڰ�~~~\n");
m = 20;
}
else if (p1.money<10000)
{
printf("��ݣ�С��\n");
printf("���û��ò��㶪��~~~\n");
m = 30;
}
else if (p1.money<20000)
{
printf("��ݣ�����\n");
printf("ʮ�ֲ���,RP������~~����\n");
m = 40;
}
else if (p1.money<50000)
{
printf("��ݣ�����\n");
printf("�������������Ѱ�~");
m = 50;
}
else
{
printf("��ݣ��׸�\n");
printf("Ĥ�ݡ�����");
m = 60;
}
printf("\n��Ǯ:%d\n", p1.money);
for (a = 0, c = 0; a <= 19; a++)
{
if (p1.fangchan[0][a] == 1)
{
switch (a)
{
case 0:printf("���Ǵ��1��\n"); b = 1; break;
case 1:printf("���Ǵ��2��\n"); b = 1; break;
case 2:printf("���·1��\n"); b = 1; break;
case 3:printf("���·2��\n"); b = 1; break;
case 4:printf("���·3��\n"); b = 1; break;
case 5:printf("���·4��\n"); b = 1; break;
case 6:printf("���·5��\n"); b = 1; break;
case 7:printf("���ڴ��1��\n"); b = 1; break;
case 8:printf("���ڴ��2��\n"); b = 1; break;
case 9:printf("���ڴ��3��\n"); b = 1; break;
case 10:printf("���ڴ��4��\n"); b = 1; break;
case 11:printf("���ڴ��5��\n"); b = 1; break;
case 12:printf("���ڴ��6��\n"); b = 1; break;
case 13:printf("���ڴ��7��\n"); b = 1; break;
case 14:printf("���ڴ��8��\n"); b = 1; break;
case 15:printf("���ڴ��9��\n"); b = 1; break;
case 16:printf("��·1��\n"); b = 1; break;
case 17:printf("��·2��\n"); b = 1; break;
case 18:printf("��·3��\n"); b = 1; break;
default:break;
}
if (b == 1)
{
if (p1.fangchan[1][a] == 1)
{
printf("�����ù�һ����\n");
printf("�ùݵȼ���%d�Ǽ�\n", p1.fangchan[2][a]);
printf("ÿ��ͣ����ȡ���ã�%d\n", p1.fangchan[3][a]);
printf("\n");
}
else if (p1.fangchan[1][a] == 2)
{
printf("�����̵�һ����\n");
switch (p1.fangchan[2][a])
{
case 1:printf("�ȼ���С����\n"); break;
case 2:printf("�ȼ����̵�\n"); break;
case 3:printf("�ȼ�������\n"); break;
case 4:printf("�ȼ���ȫ����������\n"); break;
case 5:printf("�ȼ�����������ó���г�\n"); break;
default:break;
}
printf("ÿ�غ�����Ϊ:%d", p1.fangchan[4][a]);
printf("\n");
}
else
{
printf("���е�Ƥһ�ݡ�\n");
}
c++;
}
}
}
if (c == 0)
{
printf("û�أ���˵����ʶ�㰡������\n");
n = 10;
}
else if (c<5)
{
printf("����������ô����㾹Ȼ����ô��أ�\n");
n = 20;
}
else if (c<10)
{
printf("������ǿ��ǿ����ڷ����˰ɡ�����\n");
n = 30;
}
else if (c<18)
{
printf("û������Ǵ�˵���޶����ķ��ز����̣�����\n");
n = 40;
}
else
{
printf("�������е�Ƥ�������߳ɾͣ���������\n");
n = 60;
}
p = m + n;
printf("���ջ���Ϊ:%d", p);
system("pause");
system("cls");
printf("���֣�");
puts(p2.allname);
if (p2.money<3000)
{
printf("��ݣ�ƶ��\n");
printf("�������㣬�����Ǯ~��\n");
m = 10;
}
else if (p2.money<5000)
{
printf("��ݣ�ƽ��\n");
printf("����ǿǿ�����ڰ�~~~\n");
m = 20;
}
else if (p2.money<10000)
{
printf("��ݣ�С��\n");
printf("���û��ò��㶪��~~~\n");
m = 30;
}
else if (p2.money<20000)
{
printf("��ݣ�����\n");
printf("ʮ�ֲ���,RP������~~����\n");
m = 40;
}
else if (p2.money<50000)
{
printf("��ݣ�����\n");
printf("�������������Ѱ�~");
m = 50;
}
else
{
printf("��ݣ��׸�\n");
printf("Ĥ�ݡ�����");
m = 60;
}
printf("\n��Ǯ:%d\n", p2.money);
for (a = 0, c = 0; a <= 19; a++)
{
if (p2.fangchan[0][a] == 1)
{
switch (a)
{
case 0:printf("���Ǵ��1��\n"); b = 1; break;
case 1:printf("���Ǵ��2��\n"); b = 1; break;
case 2:printf("���·1��\n"); b = 1; break;
case 3:printf("���·2��\n"); b = 1; break;
case 4:printf("���·3��\n"); b = 1; break;
case 5:printf("���·4��\n"); b = 1; break;
case 6:printf("���·5��\n"); b = 1; break;
case 7:printf("���ڴ��1��\n"); b = 1; break;
case 8:printf("���ڴ��2��\n"); b = 1; break;
case 9:printf("���ڴ��3��\n"); b = 1; break;
case 10:printf("���ڴ��4��\n"); b = 1; break;
case 11:printf("���ڴ��5��\n"); b = 1; break;
case 12:printf("���ڴ��6��\n"); b = 1; break;
case 13:printf("���ڴ��7��\n"); b = 1; break;
case 14:printf("���ڴ��8��\n"); b = 1; break;
case 15:printf("���ڴ��9��\n"); b = 1; break;
case 16:printf("��·1��\n"); b = 1; break;
case 17:printf("��·2��\n"); b = 1; break;
case 18:printf("��·3��\n"); b = 1; break;
default:break;
}
if (b == 1)
{
if (p2.fangchan[1][a] == 1)
{
printf("�����ù�һ����\n");
printf("�ùݵȼ���%d�Ǽ�\n", p1.fangchan[2][a]);
printf("ÿ��ͣ����ȡ���ã�%d\n", p1.fangchan[3][a]);
printf("\n");
}
else if (p2.fangchan[1][a] == 2)
{
printf("�����̵�һ����\n");
switch (p2.fangchan[2][a])
{
case 1:printf("�ȼ���С����\n"); break;
case 2:printf("�ȼ����̵�\n"); break;
case 3:printf("�ȼ�������\n"); break;
case 4:printf("�ȼ���ȫ����������\n"); break;
case 5:printf("�ȼ�����������ó���г�\n"); break;
default:break;
}
printf("ÿ�غ�����Ϊ:%d", p2.fangchan[4][a]);
printf("\n");
}
else
{
printf("���е�Ƥһ�ݡ�\n");
}
c++;
}
}
}
if (c == 0)
{
printf("û�أ���˵����ʶ�㰡������\n");
n = 10;
}
else if (c<5)
{
printf("����������ô����㾹Ȼ����ô��أ�\n");
n = 20;
}
else if (c<10)
{
printf("������ǿ��ǿ����ڷ����˰ɡ�����\n");
n = 30;
}
else if (c<18)
{
printf("û������Ǵ�˵���޶����ķ��ز����̣�����\n");
n = 40;
}
else
{
printf("�������е�Ƥ�������߳ɾͣ���������\n");
n = 60;
}
q = m + n;
printf("�������ջ���Ϊ:%d", q);
if (p>q)
{
printf("1P��ʤһ��Ŷ��\n");
}
else if (q>p)
{
printf("2P��ǿһЩ����\n");
}
else
{
printf("ʮ�ֺ�г�а���ƽ�֣�\n");
}
system("pause");
printf("�뿴�ʵ�������1��������������������˳�~\n");
scanf("%d", &a);
if (a)
{
caidan:system("cls");
for (a = 1; a <= 100; a++)
{
printf("׳���Ҵ�622~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
printf("û������ǲʵ���\n");
printf("������Ϸ����~~");
}
else
{
printf("����Ҳ�ÿ�����\n");
system("pause");
goto caidan;
}
system("pause");
return 0;
}
/*ʱ��*/
int shijian(int a)
{
p1.hours += a;
if (p1.hours >= 12)
{
p1.hours -= 12;
p1.days++;
}
return 0;
}
/*������溯��*/
int qipan(char weizhi[28])
{
system("cls");
printf("_____________________________________________________________\n");
printf("|%c 1  |%c 2  |%c 3  |%c 4  |%c 5  |%c 6  |%c 7  |%c 8  |%c 9  |%c 10 |\n", weizhi[0], weizhi[1], weizhi[2], weizhi[3], weizhi[4], weizhi[5], weizhi[6], weizhi[7], weizhi[8], weizhi[9]);
printf("|��ʼ |�� ��|�� ��|ǰ�� |     | ��  | ��  | ·  |     |��Ʒ |\n");
printf("|     |1 �� |2 �� |3 �� |1 �� |2 �� |3 �� |4 �� |5 �� |��վ |\n");
printf("-------------------------------------------------------------\n");
printf("|%c 26 |						      |%c 11 |\n", weizhi[25], weizhi[10]);
printf("|��   | 					      |     |\n");
printf("|3 �� |						      |1 �� |\n");
printf("|-----|				            	      |-----|\n", weizhi[24], weizhi[11]);
printf("|%c 25 |         		 	              |%c 12 |\n", weizhi[24], weizhi[11]);
printf("|��   |                     �� �� ��	     	      |��   |\n");
printf("|2 �� |						      |2 �� |\n");
printf("|-----| 					      |-----|\n");
printf("|%c 24 | 				              |%c 13 |\n", weizhi[23], weizhi[12]);
printf("|·   |                                               |��   |\n");
printf("|1 �� |                                               |3 �� |\n");
printf("-------------------------------------------------------------\n");
printf("|%c 23 |%c 22 |%c 21 |%c 20 |%c 19 |%c 18 |%c 17 |%c 16 |%c 15 |%c 14 |\n", weizhi[22], weizhi[21], weizhi[20], weizhi[19], weizhi[18], weizhi[17], weizhi[16], weizhi[15], weizhi[14], weizhi[13]);
printf("|��Ʒ |ǰ�� |�ĳ� |     |     |     |���� |     |��   |��   |\n");
printf("|��վ |2 �� |     |9 �� |8 �� |7 �� |2 �� |6 �� |5 �� |4 �� |\n");
printf("-------------------------------------------------------------\n");
return 0;
}
/*����ǰ������*/
int qianjin(int qianjinbs, int dangqian, char weizhi[28], char name)
{
int a, b;
for (b = 0; b<qianjinbs; b++)
{
dangqian++;
if (dangqian >= 26)
{
dangqian = 0;
}
weizhi[dangqian] = name;
Sleep(1000);
qipan(weizhi);
weizhi[dangqian] = ' ';
}
return dangqian;
}
/*������˺���*/
int houtui(int houtuibs, int dangqian, char weizhi[28], char name)
{
int a, b;
for (b = 0, a = 0; b<houtuibs; b++)
{
if (dangqian <= 0)
{
dangqian = 0;
}
else
{
dangqian = dangqian - 1;
}
weizhi[dangqian] = name;
Sleep(1000);
qipan(weizhi);
weizhi[dangqian] = ' ';
}
return dangqian;
}
/*һ��������Ŀ�����ز���*/
int fang(int turns)
{
int fanghao;
int a, b, c;
if (p1.turns)
{
switch (p1.dangqian)
{
case 1:fanghao = 0; break;
case 2:fanghao = 1; break;
case 4:fanghao = 2; break;
case 5:fanghao = 3; break;
case 6:fanghao = 4; break;
case 7:fanghao = 5; break;
case 8:fanghao = 6; break;
case 10:fanghao = 7; break;
case 11:fanghao = 8; break;
case 12:fanghao = 9; break;
case 13:fanghao = 10; break;
case 14:fanghao = 11; break;
case 15:fanghao = 12; break;
case 17:fanghao = 13; break;
case 18:fanghao = 14; break;
case 19:fanghao = 15; break;
case 23:fanghao = 16; break;
case 24:fanghao = 17; break;
case 25:fanghao = 18; break;
default:break;
}
if (p2.fangchan[0][fanghao] == 0)
{
if (p1.fangchan[0][fanghao] == 0)
{
printf("1.���¸õ�Ƥ������500�� ��������������\n");
scanf("%d", &a);
if (a == 1)
{
p1.fangchan[0][fanghao] = 1;
p1.money -= 500;
}
}
else if (p1.fangchan[1][fanghao] == 0)
{
printf("1.�������ùݣ�����200\n2.�������̵꣬����200\n���������������ַ���\n");
scanf("%d", &a);
switch (a)
{
case 1:p1.fangchan[1][fanghao] = 1; p1.money = p1.money - 200; p1.fangchan[2][fanghao] = 1; p1.fangchan[3][fanghao] = 500; break;
case 2:p1.fangchan[1][fanghao] = 2; p1.money = p1.money - 200; p1.fangchan[2][fanghao] = 1; p1.fangchan[4][fanghao] = 50; break;
default:break;
}
}
else if (p1.fangchan[1][fanghao] == 1)
{
p1.fangchan[4][fanghao] = 0;
printf("��ǰΪ%d�Ǽ��ù�\n1.����%d�����ù�\n���������������ַ���\n", p1.fangchan[2][fanghao], 500 * (p1.fangchan[2][fanghao] + 1));
scanf("%d", &a);
if (a == 1)
{
if (p1.fangchan[2][fanghao] == 5)
{
printf("������߼���\n");
system("pause");
goto zuigao;
}
p1.fangchan[2][fanghao]++;
p1.money = p1.money - 500 * p1.fangchan[2][fanghao];
p1.fangchan[3][fanghao] = p1.fangchan[3][fanghao] + 200 * p1.fangchan[2][fanghao];
printf("������ϣ���ǰΪ%d�Ǽ��ù�\n", p1.fangchan[2][fanghao]);
printf("�����������ַ���\n");
scanf("%d", &c);
}
}
else
{
printf("��ǰΪ%d���̵�\n1.����%d�����̵�\n�����������ַ���\n", p1.fangchan[1][fanghao], 500 * p1.fangchan[2][fanghao]);
scanf("%d", &a);
if (a == 1)
{
if (p1.fangchan[2][fanghao] == 5)
{
printf("������߼���\n");
printf("�����������ַ���\n");
scanf("%d", &c);
goto zuigao;
}
p1.fangchan[2][fanghao]++;
p1.money = p1.money - 500 * p1.fangchan[2][fanghao];
p1.fangchan[4][fanghao] = p1.fangchan[4][fanghao] + 10 * p1.fangchan[2][fanghao];
printf("������ϣ���ǰΪ%d�Ǽ��̵�\n", p1.fangchan[2][fanghao]);
system("pause");
}
}
}
else if (p2.fangchan[1][fanghao] == 1)
{
printf("����ȡ��·��ס�޷�%d\n", p2.fangchan[3][fanghao]);
p1.money = p1.money - p2.fangchan[3][fanghao];
p2.money = p2.money + p2.fangchan[3][fanghao];
system("pause");
}
}
else
{
switch (p2.dangqian)
{
case 1:fanghao = 0; break;
case 2:fanghao = 1; break;
case 4:fanghao = 2; break;
case 5:fanghao = 3; break;
case 6:fanghao = 4; break;
case 7:fanghao = 5; break;
case 8:fanghao = 6; break;
case 10:fanghao = 7; break;
case 11:fanghao = 8; break;
case 12:fanghao = 9; break;
case 13:fanghao = 10; break;
case 14:fanghao = 11; break;
case 15:fanghao = 12; break;
case 17:fanghao = 13; break;
case 18:fanghao = 14; break;
case 19:fanghao = 15; break;
case 23:fanghao = 16; break;
case 24:fanghao = 17; break;
case 25:fanghao = 18; break;
default:break;
}
if (p1.fangchan[0][fanghao] == 0)
{
if (p2.fangchan[0][fanghao] == 0)
{
printf("1.���¸õ�Ƥ������500�� ��������������\n");
scanf("%d", &a);
if (a == 1)
{
p2.fangchan[0][fanghao] = 1;
p2.money -= 500;
}
}
else if (p2.fangchan[1][fanghao] == 0)
{
printf("1.�������ùݣ�����200\n2.�������̵꣬����200\n���������������ַ���\n");
scanf("%d", &a);
switch (a)
{
case 1:p2.fangchan[1][fanghao] = 1; p2.money = p1.money - 200; p2.fangchan[2][fanghao] = 1; p2.fangchan[3][fanghao] = 500; break;
case 2:p2.fangchan[1][fanghao] = 2; p2.money = p1.money - 200; p2.fangchan[2][fanghao] = 1; p2.fangchan[4][fanghao] = 50; break;
default:break;
}
}
else if (p2.fangchan[1][fanghao] == 1)
{
p2.fangchan[4][fanghao] = 0;
printf("��ǰΪ%d�Ǽ��ù�\n1.����%d�����ù�\n���������������ַ���\n", p2.fangchan[2][fanghao], 500 * (p2.fangchan[2][fanghao] + 1));
scanf("%d", &a);
if (a == 1)
{
if (p2.fangchan[2][fanghao] == 5)
{
printf("������߼���\n");
system("pause");
goto zuigao;
}
p2.fangchan[2][fanghao]++;
p2.money = p2.money - 500 * p2.fangchan[2][fanghao];
p2.fangchan[3][fanghao] = p2.fangchan[3][fanghao] + 200 * p2.fangchan[2][fanghao];
printf("������ϣ���ǰΪ%d�Ǽ��ù�\n", p2.fangchan[2][fanghao]);
printf("�����������ַ���\n");
scanf("%d", &c);
}
}
else
{
printf("��ǰΪ%d���̵�\n1.����%d�����̵�\n�����������ַ���\n", p2.fangchan[1][fanghao], 500 * p2.fangchan[2][fanghao]);
scanf("%d", &a);
if (a == 1)
{
if (p2.fangchan[2][fanghao] == 5)
{
printf("������߼���\n");
printf("�����������ַ���\n");
scanf("%d", &c);
goto zuigao;
}
p2.fangchan[2][fanghao]++;
p2.money = p1.money - 500 * p2.fangchan[2][fanghao];
p2.fangchan[4][fanghao] = p2.fangchan[4][fanghao] + 10 * p2.fangchan[2][fanghao];
printf("������ϣ���ǰΪ%d�Ǽ��̵�\n", p2.fangchan[2][fanghao]);
system("pause");
}
}
}
else if (p1.fangchan[1][fanghao] == 1)
{
printf("����ȡ��·��ס�޷�%d\n", p1.fangchan[3][fanghao]);
p2.money = p2.money - p1.fangchan[3][fanghao];
p1.money = p1.money + p1.fangchan[3][fanghao];
system("pause");
}
}
zuigao:return 0;
}
/*��Ʒ��վ����*/
int renpin(int money)
{
int a, b;
a = rand() % 10;
b = rand() % 2000;
switch (a)
{
case 0:printf("·�߼�һ��Ǯ�������%d!!\n", b); money = money + b; break;
case 1:printf("·���񹷱�ҧ��סԺ����200!!\n"); money = money - 200; break;
case 2:printf("����С͵���ԣ�������Ϊ������500!!\n"); money = money + 500; break;
case 3:printf("����С͵���ԣ�������Ϊ������ȭˣ��16�ױ�����32����סԺ����1000!!"); money = money - 1000; break;
case 4:printf("�񵽲�Ʊ������50Ԫ���ǰ����Ʊ���Ķҽ������ǹ��ڲ�Ʊ���ִ�ķ���~~\n"); money = money - 100; break;
case 5:printf("�񵽲�Ʊ������50Ԫ���ǰ����Ʊ���Ķҽ��������н���Ʊ�����1000Ԫ��\n"); money = money + 1000; break;
case 6:printf("�������ֵ���ʽ�����20%����\n"); money = money + money / 5; break;
case 7:printf("·����ؤ����ǿ������100Ԫ.\n"); money = money - 100; break;
case 8:printf("����̫�󱻺�����ʩ��200\n"); money = money + 200; break;
case 9:printf("·���ƽ�о�̯������100\n"); money = money + 100; break;
}
system("pause");
return money;
}
/*�����ļ���ĳ�����*/
/*�˺��������ж����Ӳ²���*/
int touzi(int touzi1, int touzi2, int a)
{
int b, daxiao;
int he;
he = touzi1 + touzi2;
if (he>6)
{
daxiao = 13;
printf("��\n");
}
else
{
daxiao = 14;
printf("С��\n");
}
if (a <= 12)
{
if (a == he)
{
b = 5;
}
else
{
b = 0;
}
}
else if (a <= 14)
{
if (a == daxiao)
{
b = 2;
}
else
{
b = 0;
}
}
else
{
if (touzi1 == touzi2)
{
b = 3;
}
else
{
b = 0;
}
}
return b;
}
int duchang(int money)
{
int z[2][5];
int x[2][6] = { 0 };
double beilv;
int a, b, c, n, d, e, m, choice;
int touzi1, touzi2, touzi0;
int num, times, guess, p, q;
int result;
int touru;
char name[20];
int touzi(int touzi1, int touzi2, int a);
touzi0 = 0;
printf("**************************��˹ά��˹****************************\n�������Ķĳ����:\n");
gets(name);
/*�˴����������������ǰ���˵���*/
xinxi:
touzi0++;
if (touzi0>3)
{
goto ended;
}
shijian(3);
if (p1.days >= 100)
{
goto ended;
}
system("cls");
printf("********************��˹ά��˹********************\n");
puts(name);
printf("��ǰ�ʲ���%d", money);
if (money<500)
{
printf("\n��ݣ�ƶ��\n");
}
else if (money<1000)
{
printf("\n��ݣ�ƽ��\n");
}
else if (money<2000)
{
printf("\n��ݣ�С��\n");
}
else if (money<5000)
{
printf("\n��ݣ�����\n");
}
else if (money<50000)
{
printf("\n��ݣ�����\n");
}
else
{
printf("\n��ݣ��׸�\n");
}
if (money<0)
{
printf("ûǮ������ĳ�~��\n");
goto ended;
}
/*�˴���ʼѡ��Ĳ�*/
printf("ѡ��һ�ֻ�ɣ�\n1.������\n2.����\n3.ը��\n4.21��\n5.�˳��ĳ�\n");
scanf("%d", &choice);
/*��ʼ������*/
if (choice == 1)
{
system("cls");
printf("OOOOOOOOOOoooooooooo ������ ooooooooooOOOOOOOOOO\n");
touzi1 = rand() % 6 + 1;
touzi2 = rand() % 6 + 1;
printf("��ʼ�����ӣ������ֿ���\n");
printf("��Ҫ����ǣ�\n1-12.�����\n13.���\n14.��С\n15.����\n");
scanf("%d", &a);
error3:printf("���������Ǯ�أ�\n");
scanf("%d", &touru);
if (touru>money)
{
printf("ûǮ�����Һ��ۣ� \n");
goto error3;
}
if (touru<0)
{
printf("���������ڶ���~��\n");
goto error3;
}
printf("�������������%d,%d!", touzi1, touzi2);
b = touzi(touzi1, touzi2, a);
money = money - touru + touru*b;
system("pause");
}
/*��ʼ����*/
else if (choice == 2)
{
system("cls");
printf("//////////////////// ���� \\\\\\\\\\\\\\\\\\\\\n");
error1:printf("����������Ѻ�𣬽��������������ʱ�������:\n");
scanf("%d", &touru);
if (touru>money)
{
printf("ûǮ�����Һ��ۣ� \n");
goto error1;
}
if (touru<0)
{
printf("���������ڶ���~��\n");
goto error1;
}
num = rand() % 100;
for (times = 0; times <= 10; times++)
{
printf("��%d�β���:", times + 1);
scanf("%d", &guess);
if (guess>num)
{
printf("\n�µĴ���\n");
}
else if (guess<num)
{
printf("\n�µ�С��\n");
}
else
{
printf("��ϲ�¶�����");
break;
}
}
if (times >= 10)
{
printf("10�ζ��²����������ˣ���\n");
}
money = money - touru;
times = 22 - 2 * times;
beilv = times / 10.0;
money = money + touru*beilv;
system("pause");
}
/*��ʼը��*/
else if (choice == 3)
{
system("cls");
printf("xxxxxxxxxxXXXXXXXXXX ը�� XXXXXXXXXXxxxxxxxxxx\n");
printf("���ڱ���ҵΪ������ҵ������ȡ������Ϊ�ܽ��ٷ�֮��,����Ԫ�������ʮԪ\n");
if (money <= 200)
{
money = money - 10;
}
else
{
money = money*0.95;
}
for (m = 0; m <= 2; m++)
{
z[0][m] = rand() % 13 + 1;
z[1][m] = rand() % 13 + 1;
}
/*�ڴ˽�������*/
for (d = 0; d <= 1; d++)
{
if (z[d][1]>z[d][0])
{
e = z[d][0];
z[d][0] = z[d][1];
z[d][1] = e;
}
if (z[d][2]>z[d][1])
{
e = z[d][1];
z[d][1] = z[d][2];
z[d][2] = e;
}
if (z[d][1]>z[d][0])
{
e = z[d][0];
z[d][0] = z[d][1];
z[d][1] = e;
}
}
printf("���������ǣ�%d,%d,%d\n", z[0][0], z[0][1], z[0][2]);
error2:printf("��ѡ������٣�\n");
scanf("%d", &touru);
if (touru>money)
{
printf("ûǮ�����Һ��ۣ� \n");
goto error2;
}
if (touru<0)
{
printf("���������ڶ���~��\n");
goto error2;
}
money = money - touru;
/*�˴���ʼ�ȴ�С�����*/
for (d = 0; d <= 1; d++)
{
if (z[d][0] == z[d][1] && z[d][1] == z[d][2])
{
z[d][3] = 4;
z[d][4] = z[d][0];
}
else if (z[d][0] == z[d][1] || z[d][1] == z[d][2] || z[d][0] == z[d][2])
{
z[d][3] = 2;
if (z[d][0] == z[d][1])
{
z[d][4] = z[d][0];
}
else if (z[d][1] == z[d][2])
{
z[d][4] = z[d][1];
}
else
{
z[d][4] = z[d][2];
}
}
else
{
if (z[d][0] - z[d][1] == 1 && z[d][1] - z[d][2] == 1)
{
z[d][3] = 3;
z[d][4] = z[d][0];
}
else
{
z[d][3] = 1;
z[d][4] = z[d][0];
}
}
}
if (z[0][3] == z[1][3])
{
if (z[0][4] >= z[1][4])
{
n = 2;
}
else
{
n = 0;
}
}
else if (z[0][3]>z[1][3])
{
n = 2;
}
else
{
n = 0;
}
touru = touru*n;
printf("̯�ƣ�%d,%d,%d \n", z[1][0], z[1][1], z[1][2]);
printf("�����%d \n", touru);
money = money + touru;
system("pause");
}
else if (choice == 4)
/*��ʼ21��*/
{
system("cls");
printf("################### 21�� ###################\n");
error4:printf("��Ͷ��Ѻ��\n");
scanf("%d", &touru);
if (touru>money)
{
printf("ûǮ�����Һ��ۣ� \n");
goto error4;
}
if (touru<0)
{
printf("���������ڶ���~��\n");
goto error4;
}
money = money - touru;
/*˫��������*/
for (m = 0; m <= 1; m++)
{
for (n = 0; n <= 1; n++)
{
x[m][n] = rand() % 13;
if (x[m][n] == 0 || x[m][n] == 11 || x[m][n] == 12)
{
x[m][n] = 10;
}
}
}
printf("����ǰ������Ϊ:%d,%d", x[0][0], x[0][1]);
if (x[0][0] == 1 && x[0][1] == 1)
{
printf("���˫��������\n");
beilv = 5;
goto under;
}
if ((x[0][0] == 1 && x[0][1] == 10) || (x[0][0] == 10 && x[0][1] == 1))
{
printf("���21�㣡��\n");
beilv = 3;
goto under;
}
if ((x[1][0] == 1 && x[1][1] == 10) || (x[1][0] == 10 && x[1][1] == 1) || (x[1][0] == 1 && x[1][1] == 1))
{
printf("����21�㣡��\n");
beilv = 0;
goto under;
}
printf("\n����1��̯�ƣ������������ּ������� \n");
scanf("%d", &a);
if (a == 1)
{
goto tanpai;
}
x[0][2] = rand() % 13;
if (x[0][2] == 0 || x[0][2] == 11 || x[0][2] == 12)
{
x[0][2] = 10;
}
printf("��������Ϊ��%d,%d,%d \n", x[0][0], x[0][1], x[0][2]);
x[0][5] = x[0][0] + x[0][1] + x[0][2];
if (x[0][5]>21)
{
beilv = 0;
printf("�����ˣ�");
goto under;
}
printf("\n����1��̯�ƣ������������ּ������� \n");
scanf("%d", &a);
if (a == 1)
{
goto tanpai;
}
x[0][3] = rand() % 13;
if (x[0][3] == 0 || x[0][3] == 11 || x[0][3] == 12)
{
x[0][3] = 10;
}
printf("��������Ϊ��%d,%d,%d,%d \n", x[0][0], x[0][1], x[0][2], x[0][3]);
x[0][5] = x[0][5] + x[0][3];
if (x[0][5]>21)
{
beilv = 0;
printf("�����ˣ��� \n");
goto under;
}
printf("\n����1��̯�ƣ������������ּ������� \n");
scanf("%d", &a);
if (a == 1)
{
goto tanpai;
}
x[0][4] = rand() % 13;
if (x[0][4] == 0 || x[0][4] == 11 || x[0][3] == 12)
{
x[0][4] = 10;
}
printf("��������Ϊ��%d,%d,%d,%d,%d \n", x[0][0], x[0][1], x[0][2], x[0][3], x[0][4]);
x[0][5] = x[0][5] + x[0][4];
if (x[0][5]>21)
{
beilv = 0;
printf("�����ˣ��� \n");
goto under;
}
printf("��С����\n");
beilv = 3;
goto under;
tanpai:x[1][5] = x[1][0] + x[1][1];
for (b = 2; (x[1][5] <= 17 && b <= 4); b++)
{
x[1][b] = rand() % 13;
if (x[1][b] == 0 || x[1][b] == 11 || x[1][b] == 12)
{
x[1][b] = 10;
}
printf("���Լ��ƣ�%d\n", x[1][b]);
x[1][5] = x[1][5] + x[1][b];
scanf("%d", &a);
}
printf("�������ƣ�%d,%d,%d,%d,%d\n", x[1][0], x[1][1], x[1][2], x[1][3], x[1][4]);
if (x[1][5]>21)
{
printf("����������\n");
beilv = 2;
goto under;
}
if (x[1][5]>x[0][5])
{
printf("���Դ�\n");
beilv = 0;
}
else
{
printf("��Ҵ�!!\n");
beilv = 2;
}
under:money = money + touru*beilv;
system("pause");
}
else
{
goto ended;
}
if (money <= 0)
{
printf("\n�ʲ��þ������ѱ��ϳ���˹ά��˹\n");
}
else
{
goto xinxi;
}
ended: system("pause");
return money;
} 
