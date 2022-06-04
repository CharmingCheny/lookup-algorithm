#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define STUNUM 3
typedef struct
{
	int number; //�ؼ���
	char name[5];
	char sex[2];
	int age;
}record;
typedef struct
{
	record stu[STUNUM+1];
	int num;
}seqlist;
void Init()
{
	printf("ѧ��\t����\t�Ա�\t����\n");
}
int InitList(seqlist &L)
{
	L.stu==new record[MAXSIZE];
	if(!L.stu) exit(0);
	L.num=0;
	return 1;
}
void create(seqlist &L)
{
	printf("����������<����ѧ��Ϊ0��Ϊ��ֹ����>:\n");
	int k,i,j;
	k=InitList(L);
	if(k==1)
	{
		for(i=1;i<STUNUM+1;i++)
		{
			printf("�������%d��ѧ��ѧ��:",i);
			scanf("%d",&L.stu[i].number);
			if(L.stu[i].number==0) break;
			else
			{
				printf("�������%d��ѧ���������Ա�����:",i); 
				scanf("%s%s%d",&L.stu[i].name,&L.stu[i].sex,&L.stu[i].age);
				L.num++;
			}
		}
	}
}
void print(seqlist L,int n)
{
	int i;
	if(n==0)
	{
		for(i=1;i<STUNUM+1;i++)
			printf("%d\t%s\t%s\t%d\n",L.stu[i].number,L.stu[i].name,L.stu[i].sex,L.stu[i].age);
	}
	else
	{
		printf("%d\t%s\t%s\t%d\n",L.stu[n].number,L.stu[n].name,L.stu[n].sex,L.stu[n].age);
	}

}
int find(seqlist L,int number)
{
	int i; 
	L.stu[0].number=number;
	for(i=L.num;L.stu[i].number!=number;i--);
	return i;
}
int halffind(seqlist L,int number)
{
	int low=1,high=L.num,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(number==L.stu[mid].number)
			return mid;
		else if(number<L.stu[mid].number)
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
 } 
int search(int i)
{
	int number;
	if(i==1)
		printf("����������Ҫ˳����ҵ�ѧ�����(1-%d):",STUNUM);
	else
		printf("����������Ҫ�۰���ҵ�ѧ�����(1-%d):",STUNUM);
	while(1)
	{
		scanf("%d",&number);
		if(number>0&&number<STUNUM+1) break;
		else
			printf("���������Ų��Ϸ�������������:");
	}
	return number;
}
int main()
{
	seqlist L;
	int a,number;
	create(L);
	printf("ѧ���Ļ�����Ϣ:\n");
	Init();
	print(L,0);
	number=search(1);
	a=find(L,number);
	print(L,a);
	number=search(2);
	a=halffind(L,number);
	print(L,a);
	return 0;
}
