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
printf("欢迎来到大富翁的世界！我们的世界因你更精彩！！！\n");
printf("1.新的旅程\n2.存档回忆\n");
scanf("%d", &a);
if (a == 2)
{
printf("请输入存档时1P的名字：\n");
getchar();
gets(p1.allname);
printf("%s", p1.allname);
fp = fopen(p1.allname, "rb");
fread(&p1, sizeof(struct player), 1, fp);
fread(&p2, sizeof(struct player), 1, fp);
fclose(fp);
goto turn;
}
printf("输入1P的名字：\n");
scanf("%d", &a);
gets(p1.allname);
p1.name = 1;
printf("输入2P的名字: \n");
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
printf("第%d天\n", p1.days);
if (p1.money<500)
{
printf("身份：贫民: ");
}
else if (p1.money<10000)
{
printf("身份：平民: ");
}
else if (p1.money<20000)
{
printf("身份：小资: ");
}
else if (p1.money<50000)
{
printf("身份：富人: ");
}
else if (p1.money<500000)
{
printf("身份：土豪: ");
}
else
{
printf("身份：首富: ");
}
puts(p1.allname);
printf("金钱:%d\n", p1.money);
weizhi[p1.dangqian] = ' ';
printf("请选择操作:0.存档 1.查看个人房产 2.前进\n");
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
case 0:printf("火星大道1号\n"); b = 1; break;
case 1:printf("火星大道2号\n"); b = 1; break;
case 2:printf("解放路1号\n"); b = 1; break;
case 3:printf("解放路2号\n"); b = 1; break;
case 4:printf("解放路3号\n"); b = 1; break;
case 5:printf("解放路4号\n"); b = 1; break;
case 6:printf("解放路5号\n"); b = 1; break;
case 7:printf("花炮大道1号\n"); b = 1; break;
case 8:printf("花炮大道2号\n"); b = 1; break;
case 9:printf("花炮大道3号\n"); b = 1; break;
case 10:printf("花炮大道4号\n"); b = 1; break;
case 11:printf("花炮大道5号\n"); b = 1; break;
case 12:printf("花炮大道6号\n"); b = 1; break;
case 13:printf("花炮大道7号\n"); b = 1; break;
case 14:printf("花炮大道8号\n"); b = 1; break;
case 15:printf("花炮大道9号\n"); b = 1; break;
case 16:printf("桂花路1号\n"); b = 1; break;
case 17:printf("桂花路2号\n"); b = 1; break;
case 18:printf("桂花路3号\n"); b = 1; break;
default:break;
}
if (b == 1)
{
if (p1.fangchan[1][a] == 1)
{
printf("建设旅馆一座：\n");
printf("旅馆等级：%d星级\n", p1.fangchan[2][a]);
printf("每次停留收取费用：%d\n", p1.fangchan[3][a]);
printf("\n");
}
else if (p1.fangchan[1][a] == 2)
{
printf("建设商店一座：\n");
switch (p1.fangchan[2][a])
{
case 1:printf("等级：小卖部\n"); break;
case 2:printf("等级：商店\n"); break;
case 3:printf("等级：超市\n"); break;
case 4:printf("等级：全国连锁超市\n"); break;
case 5:printf("等级：世界连锁贸易市场\n"); break;
default:break;
}
printf("每回合收入为:%d", p1.fangchan[4][a]);
printf("\n");
}
else
{
printf("仅有地皮一份。\n");
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
miji:printf("你投出了%d点！", qianjinbs);
p1.dangqian = qianjin(qianjinbs, p1.dangqian, weizhi, p1.name);
jintui:switch (p1.dangqian)
{
case 0:printf("停在起点奖励1000!\n"); p1.money += 1000; system("pause"); break;
case 3:printf("前进三格！\n"); c = 3; p1.dangqian = qianjin(c, p1.dangqian, weizhi, p1.name); goto jintui;
case 9:printf("进入人品驿站~~考验人品的时候到了！\n"); Sleep(1000); p1.money = renpin(p1.money);; break;
case 16:printf("后退两格！\n"); c = 2; p1.dangqian = houtui(c, p1.dangqian, weizhi, p1.name); goto jintui;
case 20: {printf("进入赌场！！\n");
Sleep(500);
p1.money = duchang(p1.money);
if (p1.days >= 100)
{
goto end;
}
break; }
case 21:printf("前进两格！\n"); c = 2; p1.dangqian = qianjin(c, p1.dangqian, weizhi, p1.name); goto jintui;
case 22:printf("进入人品驿站~~考验人品的时候到了！\n"); Sleep(1000); p1.money = renpin(p1.money);; break;
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
printf("%d号商店收益：%d ", a, p1.fangchan[4][a]);
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
printf("第%d天\n", p1.days);
if (p2.money<500)
{
printf("身份：贫民: ");
}
else if (p2.money<10000)
{
printf("身份：平民: ");
}
else if (p2.money<20000)
{
printf("身份：小资: ");
}
else if (p2.money<50000)
{
printf("身份：富人: ");
}
else if (p2.money<500000)
{
printf("身份：土豪: ");
}
else
{
printf("身份：首富: ");
}
puts(p2.allname);
printf("金钱:%d\n", p2.money);
weizhi[p2.dangqian] = ' ';
printf("请选择操作:0.存档 1.查看个人房产 2.前进\n");
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
/* 输出个人信息，真特么麻烦 */
for (a = 0; a <= 19; a++)
{
if (p2.fangchan[0][a] == 1)
{
switch (a)
{
case 0:printf("火星大道1号\n"); b = 1; break;
case 1:printf("火星大道2号\n"); b = 1; break;
case 2:printf("解放路1号\n"); b = 1; break;
case 3:printf("解放路2号\n"); b = 1; break;
case 4:printf("解放路3号\n"); b = 1; break;
case 5:printf("解放路4号\n"); b = 1; break;
case 6:printf("解放路5号\n"); b = 1; break;
case 7:printf("花炮大道1号\n"); b = 1; break;
case 8:printf("花炮大道2号\n"); b = 1; break;
case 9:printf("花炮大道3号\n"); b = 1; break;
case 10:printf("花炮大道4号\n"); b = 1; break;
case 11:printf("花炮大道5号\n"); b = 1; break;
case 12:printf("花炮大道6号\n"); b = 1; break;
case 13:printf("花炮大道7号\n"); b = 1; break;
case 14:printf("花炮大道8号\n"); b = 1; break;
case 15:printf("花炮大道9号\n"); b = 1; break;
case 16:printf("桂花路1号\n"); b = 1; break;
case 17:printf("桂花路2号\n"); b = 1; break;
case 18:printf("桂花路3号\n"); b = 1; break;
default:break;
}
if (b == 1)
{
if (p2.fangchan[1][a] == 1)
{
printf("建设旅馆一座：\n");
printf("旅馆等级：%d星级\n", p2.fangchan[2][a]);
printf("每次停留收取费用：%d\n", p2.fangchan[3][a]);
printf("\n");
}
else if (p2.fangchan[1][a] == 2)
{
printf("建设商店一座：\n");
switch (p2.fangchan[2][a])
{
case 1:printf("等级：小卖部\n"); break;
case 2:printf("等级：商店\n"); break;
case 3:printf("等级：超市\n"); break;
case 4:printf("等级：全国连锁超市\n"); break;
case 5:printf("等级：世界连锁贸易市场\n"); break;
default:break;
}
printf("每回合收入为:%d", p2.fangchan[4][a]);
printf("\n");
}
else
{
printf("仅有地皮一份。\n");
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
miji2:printf("你投出了%d点！", qianjinbs);
p2.dangqian = qianjin(qianjinbs, p2.dangqian, weizhi, p2.name);
jintui2:switch (p2.dangqian)
{
case 0:printf("停在起点奖励1000!\n"); p2.money += 1000; system("pause"); break;
case 3:printf("前进三格！\n"); c = 3; p2.dangqian = qianjin(c, p2.dangqian, weizhi, p2.name); goto jintui2;
case 9:printf("进入人品驿站~~考验人品的时候到了！\n"); Sleep(1000); p2.money = renpin(p2.money);; break;
case 16:printf("后退两格！\n"); c = 2; p2.dangqian = houtui(c, p2.dangqian, weizhi, p2.name); goto jintui2;
case 20: {printf("进入赌场！！\n");
Sleep(500);
p2.money = duchang(p2.money);
if (p1.days >= 100)
{
goto end;
}
break; }
case 21:printf("前进两格！\n"); c = 2; p2.dangqian = qianjin(c, p2.dangqian, weizhi, p2.name); goto jintui2;
case 22:printf("进入人品驿站~~考验人品的时候到了！\n"); Sleep(1000); p2.money = renpin(p2.money);; break;
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
printf("%d号商店收益：%d ", a, p2.fangchan[4][a]);
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
end:printf("名字：");
puts(p1.allname);
if (p1.money<3000)
{
printf("身份：贫民\n");
printf("弱爆了你，才这点钱~！\n");
m = 10;
}
else if (p1.money<5000)
{
printf("身份：平民\n");
printf("勉勉强强够糊口吧~~~\n");
m = 20;
}
else if (p1.money<10000)
{
printf("身份：小资\n");
printf("还好还好不算丢脸~~~\n");
m = 30;
}
else if (p1.money<20000)
{
printf("身份：富人\n");
printf("十分不错,RP棒棒哒~~！！\n");
m = 40;
}
else if (p1.money<50000)
{
printf("身份：土豪\n");
printf("土豪我们做朋友吧~");
m = 50;
}
else
{
printf("身份：首富\n");
printf("膜拜。。。");
m = 60;
}
printf("\n金钱:%d\n", p1.money);
for (a = 0, c = 0; a <= 19; a++)
{
if (p1.fangchan[0][a] == 1)
{
switch (a)
{
case 0:printf("火星大道1号\n"); b = 1; break;
case 1:printf("火星大道2号\n"); b = 1; break;
case 2:printf("解放路1号\n"); b = 1; break;
case 3:printf("解放路2号\n"); b = 1; break;
case 4:printf("解放路3号\n"); b = 1; break;
case 5:printf("解放路4号\n"); b = 1; break;
case 6:printf("解放路5号\n"); b = 1; break;
case 7:printf("花炮大道1号\n"); b = 1; break;
case 8:printf("花炮大道2号\n"); b = 1; break;
case 9:printf("花炮大道3号\n"); b = 1; break;
case 10:printf("花炮大道4号\n"); b = 1; break;
case 11:printf("花炮大道5号\n"); b = 1; break;
case 12:printf("花炮大道6号\n"); b = 1; break;
case 13:printf("花炮大道7号\n"); b = 1; break;
case 14:printf("花炮大道8号\n"); b = 1; break;
case 15:printf("花炮大道9号\n"); b = 1; break;
case 16:printf("桂花路1号\n"); b = 1; break;
case 17:printf("桂花路2号\n"); b = 1; break;
case 18:printf("桂花路3号\n"); b = 1; break;
default:break;
}
if (b == 1)
{
if (p1.fangchan[1][a] == 1)
{
printf("建设旅馆一座：\n");
printf("旅馆等级：%d星级\n", p1.fangchan[2][a]);
printf("每次停留收取费用：%d\n", p1.fangchan[3][a]);
printf("\n");
}
else if (p1.fangchan[1][a] == 2)
{
printf("建设商店一座：\n");
switch (p1.fangchan[2][a])
{
case 1:printf("等级：小卖部\n"); break;
case 2:printf("等级：商店\n"); break;
case 3:printf("等级：超市\n"); break;
case 4:printf("等级：全国连锁超市\n"); break;
case 5:printf("等级：世界连锁贸易市场\n"); break;
default:break;
}
printf("每回合收入为:%d", p1.fangchan[4][a]);
printf("\n");
}
else
{
printf("仅有地皮一份。\n");
}
c++;
}
}
}
if (c == 0)
{
printf("没地？别说我认识你啊。。。\n");
n = 10;
}
else if (c<5)
{
printf("啧啧。。怎么混的你竟然才这么点地？\n");
n = 20;
}
else if (c<10)
{
printf("算是勉强勉强够混口饭吃了吧。。。\n");
n = 30;
}
else if (c<18)
{
printf("没错你就是传说中无恶不作的房地产大商！！！\n");
n = 40;
}
else
{
printf("买下所有地皮，达成最高成就：城主！！\n");
n = 60;
}
p = m + n;
printf("最终积分为:%d", p);
system("pause");
system("cls");
printf("名字：");
puts(p2.allname);
if (p2.money<3000)
{
printf("身份：贫民\n");
printf("弱爆了你，才这点钱~！\n");
m = 10;
}
else if (p2.money<5000)
{
printf("身份：平民\n");
printf("勉勉强强够糊口吧~~~\n");
m = 20;
}
else if (p2.money<10000)
{
printf("身份：小资\n");
printf("还好还好不算丢脸~~~\n");
m = 30;
}
else if (p2.money<20000)
{
printf("身份：富人\n");
printf("十分不错,RP棒棒哒~~！！\n");
m = 40;
}
else if (p2.money<50000)
{
printf("身份：土豪\n");
printf("土豪我们做朋友吧~");
m = 50;
}
else
{
printf("身份：首富\n");
printf("膜拜。。。");
m = 60;
}
printf("\n金钱:%d\n", p2.money);
for (a = 0, c = 0; a <= 19; a++)
{
if (p2.fangchan[0][a] == 1)
{
switch (a)
{
case 0:printf("火星大道1号\n"); b = 1; break;
case 1:printf("火星大道2号\n"); b = 1; break;
case 2:printf("解放路1号\n"); b = 1; break;
case 3:printf("解放路2号\n"); b = 1; break;
case 4:printf("解放路3号\n"); b = 1; break;
case 5:printf("解放路4号\n"); b = 1; break;
case 6:printf("解放路5号\n"); b = 1; break;
case 7:printf("花炮大道1号\n"); b = 1; break;
case 8:printf("花炮大道2号\n"); b = 1; break;
case 9:printf("花炮大道3号\n"); b = 1; break;
case 10:printf("花炮大道4号\n"); b = 1; break;
case 11:printf("花炮大道5号\n"); b = 1; break;
case 12:printf("花炮大道6号\n"); b = 1; break;
case 13:printf("花炮大道7号\n"); b = 1; break;
case 14:printf("花炮大道8号\n"); b = 1; break;
case 15:printf("花炮大道9号\n"); b = 1; break;
case 16:printf("桂花路1号\n"); b = 1; break;
case 17:printf("桂花路2号\n"); b = 1; break;
case 18:printf("桂花路3号\n"); b = 1; break;
default:break;
}
if (b == 1)
{
if (p2.fangchan[1][a] == 1)
{
printf("建设旅馆一座：\n");
printf("旅馆等级：%d星级\n", p1.fangchan[2][a]);
printf("每次停留收取费用：%d\n", p1.fangchan[3][a]);
printf("\n");
}
else if (p2.fangchan[1][a] == 2)
{
printf("建设商店一座：\n");
switch (p2.fangchan[2][a])
{
case 1:printf("等级：小卖部\n"); break;
case 2:printf("等级：商店\n"); break;
case 3:printf("等级：超市\n"); break;
case 4:printf("等级：全国连锁超市\n"); break;
case 5:printf("等级：世界连锁贸易市场\n"); break;
default:break;
}
printf("每回合收入为:%d", p2.fangchan[4][a]);
printf("\n");
}
else
{
printf("仅有地皮一份。\n");
}
c++;
}
}
}
if (c == 0)
{
printf("没地？别说我认识你啊。。。\n");
n = 10;
}
else if (c<5)
{
printf("啧啧。。怎么混的你竟然才这么点地？\n");
n = 20;
}
else if (c<10)
{
printf("算是勉强勉强够混口饭吃了吧。。。\n");
n = 30;
}
else if (c<18)
{
printf("没错你就是传说中无恶不作的房地产大商！！！\n");
n = 40;
}
else
{
printf("买下所有地皮，达成最高成就：城主！！\n");
n = 60;
}
q = m + n;
printf("您的最终积分为:%d", q);
if (p>q)
{
printf("1P更胜一筹哦！\n");
}
else if (q>p)
{
printf("2P更强一些诶！\n");
}
else
{
printf("十分和谐有爱的平手！\n");
}
system("pause");
printf("想看彩蛋吗？输入1则继续！输入其他数字退出~\n");
scanf("%d", &a);
if (a)
{
caidan:system("cls");
for (a = 1; a <= 100; a++)
{
printf("壮哉我大622~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
printf("没错这就是彩蛋！\n");
printf("好啦游戏结束~~");
}
else
{
printf("不看也得看！！\n");
system("pause");
goto caidan;
}
system("pause");
return 0;
}
/*时间*/
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
/*定义界面函数*/
int qipan(char weizhi[28])
{
system("cls");
printf("_____________________________________________________________\n");
printf("|%c 1  |%c 2  |%c 3  |%c 4  |%c 5  |%c 6  |%c 7  |%c 8  |%c 9  |%c 10 |\n", weizhi[0], weizhi[1], weizhi[2], weizhi[3], weizhi[4], weizhi[5], weizhi[6], weizhi[7], weizhi[8], weizhi[9]);
printf("|开始 |火 星|大 道|前进 |     | 解  | 放  | 路  |     |人品 |\n");
printf("|     |1 号 |2 号 |3 格 |1 号 |2 号 |3 号 |4 号 |5 号 |驿站 |\n");
printf("-------------------------------------------------------------\n");
printf("|%c 26 |						      |%c 11 |\n", weizhi[25], weizhi[10]);
printf("|桂   | 					      |     |\n");
printf("|3 号 |						      |1 号 |\n");
printf("|-----|				            	      |-----|\n", weizhi[24], weizhi[11]);
printf("|%c 25 |         		 	              |%c 12 |\n", weizhi[24], weizhi[11]);
printf("|花   |                     大 富 翁	     	      |花   |\n");
printf("|2 号 |						      |2 号 |\n");
printf("|-----| 					      |-----|\n");
printf("|%c 24 | 				              |%c 13 |\n", weizhi[23], weizhi[12]);
printf("|路   |                                               |炮   |\n");
printf("|1 号 |                                               |3 号 |\n");
printf("-------------------------------------------------------------\n");
printf("|%c 23 |%c 22 |%c 21 |%c 20 |%c 19 |%c 18 |%c 17 |%c 16 |%c 15 |%c 14 |\n", weizhi[22], weizhi[21], weizhi[20], weizhi[19], weizhi[18], weizhi[17], weizhi[16], weizhi[15], weizhi[14], weizhi[13]);
printf("|人品 |前进 |赌场 |     |     |     |后退 |     |道   |大   |\n");
printf("|驿站 |2 格 |     |9 号 |8 号 |7 号 |2 格 |6 号 |5 号 |4 号 |\n");
printf("-------------------------------------------------------------\n");
return 0;
}
/*定义前进函数*/
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
/*定义后退函数*/
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
/*一大作死项目：房地产！*/
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
printf("1.购下该地皮，花费500， 其他任意数返回\n");
scanf("%d", &a);
if (a == 1)
{
p1.fangchan[0][fanghao] = 1;
p1.money -= 500;
}
}
else if (p1.fangchan[1][fanghao] == 0)
{
printf("1.升级成旅馆，花费200\n2.升级成商店，花费200\n输入其他任意数字返回\n");
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
printf("当前为%d星级旅馆\n1.花费%d升级旅馆\n输入其他任意数字返回\n", p1.fangchan[2][fanghao], 500 * (p1.fangchan[2][fanghao] + 1));
scanf("%d", &a);
if (a == 1)
{
if (p1.fangchan[2][fanghao] == 5)
{
printf("已是最高级别！\n");
system("pause");
goto zuigao;
}
p1.fangchan[2][fanghao]++;
p1.money = p1.money - 500 * p1.fangchan[2][fanghao];
p1.fangchan[3][fanghao] = p1.fangchan[3][fanghao] + 200 * p1.fangchan[2][fanghao];
printf("升级完毕，当前为%d星级旅馆\n", p1.fangchan[2][fanghao]);
printf("输入任意数字返回\n");
scanf("%d", &c);
}
}
else
{
printf("当前为%d级商店\n1.花费%d升级商店\n输入其他数字返回\n", p1.fangchan[1][fanghao], 500 * p1.fangchan[2][fanghao]);
scanf("%d", &a);
if (a == 1)
{
if (p1.fangchan[2][fanghao] == 5)
{
printf("已是最高级别！\n");
printf("输入任意数字返回\n");
scanf("%d", &c);
goto zuigao;
}
p1.fangchan[2][fanghao]++;
p1.money = p1.money - 500 * p1.fangchan[2][fanghao];
p1.fangchan[4][fanghao] = p1.fangchan[4][fanghao] + 10 * p1.fangchan[2][fanghao];
printf("升级完毕，当前为%d星级商店\n", p1.fangchan[2][fanghao]);
system("pause");
}
}
}
else if (p2.fangchan[1][fanghao] == 1)
{
printf("被收取过路费住宿费%d\n", p2.fangchan[3][fanghao]);
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
printf("1.购下该地皮，花费500， 其他任意数返回\n");
scanf("%d", &a);
if (a == 1)
{
p2.fangchan[0][fanghao] = 1;
p2.money -= 500;
}
}
else if (p2.fangchan[1][fanghao] == 0)
{
printf("1.升级成旅馆，花费200\n2.升级成商店，花费200\n输入其他任意数字返回\n");
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
printf("当前为%d星级旅馆\n1.花费%d升级旅馆\n输入其他任意数字返回\n", p2.fangchan[2][fanghao], 500 * (p2.fangchan[2][fanghao] + 1));
scanf("%d", &a);
if (a == 1)
{
if (p2.fangchan[2][fanghao] == 5)
{
printf("已是最高级别！\n");
system("pause");
goto zuigao;
}
p2.fangchan[2][fanghao]++;
p2.money = p2.money - 500 * p2.fangchan[2][fanghao];
p2.fangchan[3][fanghao] = p2.fangchan[3][fanghao] + 200 * p2.fangchan[2][fanghao];
printf("升级完毕，当前为%d星级旅馆\n", p2.fangchan[2][fanghao]);
printf("输入任意数字返回\n");
scanf("%d", &c);
}
}
else
{
printf("当前为%d级商店\n1.花费%d升级商店\n输入其他数字返回\n", p2.fangchan[1][fanghao], 500 * p2.fangchan[2][fanghao]);
scanf("%d", &a);
if (a == 1)
{
if (p2.fangchan[2][fanghao] == 5)
{
printf("已是最高级别！\n");
printf("输入任意数字返回\n");
scanf("%d", &c);
goto zuigao;
}
p2.fangchan[2][fanghao]++;
p2.money = p1.money - 500 * p2.fangchan[2][fanghao];
p2.fangchan[4][fanghao] = p2.fangchan[4][fanghao] + 10 * p2.fangchan[2][fanghao];
printf("升级完毕，当前为%d星级商店\n", p2.fangchan[2][fanghao]);
system("pause");
}
}
}
else if (p1.fangchan[1][fanghao] == 1)
{
printf("被收取过路费住宿费%d\n", p1.fangchan[3][fanghao]);
p2.money = p2.money - p1.fangchan[3][fanghao];
p1.money = p1.money + p1.fangchan[3][fanghao];
system("pause");
}
}
zuigao:return 0;
}
/*人品驿站！！*/
int renpin(int money)
{
int a, b;
a = rand() % 10;
b = rand() % 2000;
switch (a)
{
case 0:printf("路边捡到一个钱包，获得%d!!\n", b); money = money + b; break;
case 1:printf("路遇恶狗被咬，住院花费200!!\n"); money = money - 200; break;
case 2:printf("见到小偷行窃，见义勇为被奖励500!!\n"); money = money + 500; break;
case 3:printf("见到小偷行窃，见义勇为，军体拳耍了16套被砍了32刀，住院花费1000!!"); money = money - 1000; break;
case 4:printf("捡到彩票，花费50元打的前往彩票中心兑奖后发现是过期彩票，又打的返回~~\n"); money = money - 100; break;
case 5:printf("捡到彩票，花费50元打的前往彩票中心兑奖后发现是中奖彩票，获得1000元！\n"); money = money + 1000; break;
case 6:printf("人民币涨值，资金上涨20%！！\n"); money = money + money / 5; break;
case 7:printf("路遇乞丐，被强行勒索100元.\n"); money = money - 100; break;
case 8:printf("长得太丑被好心人施舍200\n"); money = money + 200; break;
case 9:printf("路边破解残局摊，获利100\n"); money = money + 100; break;
}
system("pause");
return money;
}
/*作死的加入赌场函数*/
/*此函数用于判断骰子猜测结果*/
int touzi(int touzi1, int touzi2, int a)
{
int b, daxiao;
int he;
he = touzi1 + touzi2;
if (he>6)
{
daxiao = 13;
printf("大！\n");
}
else
{
daxiao = 14;
printf("小！\n");
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
printf("**************************拉斯维加斯****************************\n输入您的赌场外号:\n");
gets(name);
/*此处用于清屏并输出当前个人档案*/
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
printf("********************拉斯维加斯********************\n");
puts(name);
printf("当前资产：%d", money);
if (money<500)
{
printf("\n身份：贫民\n");
}
else if (money<1000)
{
printf("\n身份：平民\n");
}
else if (money<2000)
{
printf("\n身份：小资\n");
}
else if (money<5000)
{
printf("\n身份：富人\n");
}
else if (money<50000)
{
printf("\n身份：土豪\n");
}
else
{
printf("\n身份：首富\n");
}
if (money<0)
{
printf("没钱还想进赌城~？\n");
goto ended;
}
/*此处开始选择赌博*/
printf("选择一种活动吧：\n1.掷骰子\n2.猜数\n3.炸金花\n4.21点\n5.退出赌城\n");
scanf("%d", &choice);
/*开始掷骰子*/
if (choice == 1)
{
system("cls");
printf("OOOOOOOOOOoooooooooo 掷骰子 ooooooooooOOOOOOOOOO\n");
touzi1 = rand() % 6 + 1;
touzi2 = rand() % 6 + 1;
printf("开始掷骰子，买定离手咯！\n");
printf("您要买的是：\n1-12.买点数\n13.买大\n14.买小\n15.买豹子\n");
scanf("%d", &a);
error3:printf("您买入多少钱呢：\n");
scanf("%d", &touru);
if (touru>money)
{
printf("没钱还敢乱喊价？ \n");
goto error3;
}
if (touru<0)
{
printf("你他妈是在逗我~？\n");
goto error3;
}
printf("开！骰子情况是%d,%d!", touzi1, touzi2);
b = touzi(touzi1, touzi2, a);
money = money - touru + touru*b;
system("pause");
}
/*开始猜数*/
else if (choice == 2)
{
system("cls");
printf("//////////////////// 猜数 \\\\\\\\\\\\\\\\\\\\\n");
error1:printf("请输入您的押金，将按您猜数次数呈倍数返还:\n");
scanf("%d", &touru);
if (touru>money)
{
printf("没钱还敢乱喊价？ \n");
goto error1;
}
if (touru<0)
{
printf("你他妈是在逗我~？\n");
goto error1;
}
num = rand() % 100;
for (times = 0; times <= 10; times++)
{
printf("第%d次猜数:", times + 1);
scanf("%d", &guess);
if (guess>num)
{
printf("\n猜的大了\n");
}
else if (guess<num)
{
printf("\n猜的小了\n");
}
else
{
printf("恭喜猜对啦！");
break;
}
}
if (times >= 10)
{
printf("10次都猜不出，弱爆了！！\n");
}
money = money - touru;
times = 22 - 2 * times;
beilv = times / 10.0;
money = money + touru*beilv;
system("pause");
}
/*开始炸金花*/
else if (choice == 3)
{
system("cls");
printf("xxxxxxxxxxXXXXXXXXXX 炸金花 XXXXXXXXXXxxxxxxxxxx\n");
printf("由于本行业为暴利行业，故收取手续费为总金额百分之五,两百元以内则扣十元\n");
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
/*在此进行排序*/
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
printf("您的手牌是：%d,%d,%d\n", z[0][0], z[0][1], z[0][2]);
error2:printf("您选择跟多少：\n");
scanf("%d", &touru);
if (touru>money)
{
printf("没钱还敢乱喊价？ \n");
goto error2;
}
if (touru<0)
{
printf("你他妈是在逗我~？\n");
goto error2;
}
money = money - touru;
/*此处开始比大小出结果*/
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
printf("摊牌：%d,%d,%d \n", z[1][0], z[1][1], z[1][2]);
printf("您获得%d \n", touru);
money = money + touru;
system("pause");
}
else if (choice == 4)
/*开始21点*/
{
system("cls");
printf("################### 21点 ###################\n");
error4:printf("请投入押金：\n");
scanf("%d", &touru);
if (touru>money)
{
printf("没钱还敢乱喊价？ \n");
goto error4;
}
if (touru<0)
{
printf("你他妈是在逗我~？\n");
goto error4;
}
money = money - touru;
/*双方发底牌*/
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
printf("您当前的手牌为:%d,%d", x[0][0], x[0][1]);
if (x[0][0] == 1 && x[0][1] == 1)
{
printf("玩家双龙！！！\n");
beilv = 5;
goto under;
}
if ((x[0][0] == 1 && x[0][1] == 10) || (x[0][0] == 10 && x[0][1] == 1))
{
printf("玩家21点！！\n");
beilv = 3;
goto under;
}
if ((x[1][0] == 1 && x[1][1] == 10) || (x[1][0] == 10 && x[1][1] == 1) || (x[1][0] == 1 && x[1][1] == 1))
{
printf("电脑21点！！\n");
beilv = 0;
goto under;
}
printf("\n输入1则摊牌，输入其他数字继续加牌 \n");
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
printf("您的手牌为：%d,%d,%d \n", x[0][0], x[0][1], x[0][2]);
x[0][5] = x[0][0] + x[0][1] + x[0][2];
if (x[0][5]>21)
{
beilv = 0;
printf("胀死了！");
goto under;
}
printf("\n输入1则摊牌，输入其他数字继续加牌 \n");
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
printf("您的手牌为：%d,%d,%d,%d \n", x[0][0], x[0][1], x[0][2], x[0][3]);
x[0][5] = x[0][5] + x[0][3];
if (x[0][5]>21)
{
beilv = 0;
printf("胀死了！！ \n");
goto under;
}
printf("\n输入1则摊牌，输入其他数字继续加牌 \n");
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
printf("您的手牌为：%d,%d,%d,%d,%d \n", x[0][0], x[0][1], x[0][2], x[0][3], x[0][4]);
x[0][5] = x[0][5] + x[0][4];
if (x[0][5]>21)
{
beilv = 0;
printf("胀死了！！ \n");
goto under;
}
printf("五小！！\n");
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
printf("电脑加牌：%d\n", x[1][b]);
x[1][5] = x[1][5] + x[1][b];
scanf("%d", &a);
}
printf("电脑手牌：%d,%d,%d,%d,%d\n", x[1][0], x[1][1], x[1][2], x[1][3], x[1][4]);
if (x[1][5]>21)
{
printf("电脑胀死！\n");
beilv = 2;
goto under;
}
if (x[1][5]>x[0][5])
{
printf("电脑大！\n");
beilv = 0;
}
else
{
printf("玩家大!!\n");
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
printf("\n资产用尽，您已被赶出拉斯维加斯\n");
}
else
{
goto xinxi;
}
ended: system("pause");
return money;
} 
