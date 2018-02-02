#include <stdio.h>
#include <stdlib.h>
struct student{
	int num;
	char name[20];
	float score;
	struct student *next;
};
#define len sizeof(struct student)
struct student *creat(void){
	struct student *p1,*p2,*head;
	int n=0;
	p1=p2=(struct student*)malloc(len);
	head=NULL;
	scanf("%d%s%f",&p1->num,&p1->name,&p1->score);
	if(p1->num==0){
	printf("error");
	return 1;}
	while(p1->num!=0){
		n+=1;
		if(n==1)	head=p1;
		else	p2->next=p1;
		p2=p1;
		p1=(struct student*)malloc(len);
		scanf("%d%s%f",&p1->num,&p1->name,&p1->score);
	}p2->next=NULL;
	return(head); 
}
void change(struct student *p,int number,float score){
	while(p!=NULL){
		if(p->num==number){
			p->score=score;
			break;
		}
			else p=p->next;
	}	
}
void print(struct student *pt){
	if(pt->num!=0){
		do{
			printf("学号:%d 姓名:%s 分数:%5.2f\n",pt->num,pt->name,pt->score);
			pt=pt->next;
		}while(pt!=NULL);
	}
}
int main() {
	struct student *p,*p3,*head;
	char c;
	int number1,ret=0;
	float score1;
	printf("分别输入8个学生的学号，姓名，分数。输入0 0 0表示输入完成！\n");
	p=creat();
	if(p==1)return 0;
	print(p);
	printf("需要修改信息输入1，不需要修改输入2\n");
	scanf("%d",&ret);
	if(ret==1){
		printf("输入学号以及需要改的分数：\n");
		scanf("%d%f",&number1,&score1);
		change(p,number1,score1);
		print(p);
		return 0;
	}else return 0;
}
