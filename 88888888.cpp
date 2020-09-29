/*************************************************

** 源文件   : score.c

** 功能说明 : Function Definitions

** 创建版本 : v1.0

/**************************************************/



/*----------------头文件--------------*/

#define  _CRT_SECURE_NO_WARNINGS

#include <math.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>


typedef struct student

{

	char number[20];  //学号

	char name[20];    //姓名

	float dailyScore;   //平时成绩

	float finalScore;   //期末成绩

	float generalScore; //总评成绩



}SS;
/*----------------函数定义-------------*/



//1.1手动输入学生基本数据

void readData(SS stu[], int N)

{



	printf("请按照如下格式输入学生信息：学号,姓名,平时成绩,期末成绩\n");



	for (int i = 0; i < N; i++)

	{

		printf("第%d个学生:", i + 1);

		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);

		printf("\n");

	}



	printf("------成绩录入完毕!--------\n");



}



//1.2从文件里读取学生基本数据

SS* readDataFromFile(int *N)

{



	printf("\n\n------第一步: 从文件读取学生的成绩信息--------\n\n");



	SS *stu;// 开辟新空间,存取文件中的每个学生信息



	FILE *fp = NULL;

	int count = 0;

	int index = 0;



	fp = fopen("data.txt", "r");



	//1.获取学生数目

	if (fp != NULL)

	{

		fscanf(fp, "%d", &count);

		*N = count;

	}

	else

	{

		printf("failed to open the info file\n");

		getchar();

	}



	printf("学生数目为:%d\n", count);





	//2.给所有学生分配存储空间

	stu = (SS*)malloc(count * sizeof(SS));





	//3.读取每条学生的信息

	while ((!feof(fp)))

	{

	
	fscanf(fp,"%s %s %f %f\n", &stu[index].number, &stu[index].name, &stu[index].dailyScore, &stu[index].finalScore);
		printf("%-10s %-10s %-10.1f %-10.1f\n",stu[index].number, stu[index].name, stu[index].dailyScore, stu[index].finalScore);	
		index++;
		

		

		

	}



	getchar();



	fclose(fp);



	return stu;

}



//2.计算N个学生各自的总评成绩

void calcuScore(SS stu[], int N)

{





	printf("\n\n------第二步: 计算每个学生的总评成绩--------\n\n");



	for(int i=0;i<N;i++)
	{
		stu[i].generalScore=0.2*stu[i].dailyScore+0.8*stu[i].finalScore;
		printf("%-10s %-10s %-10.1f %-10.1f %-10.1f\n",stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].finalScore,stu[i].generalScore);
	}

	

}





//3.根据总评成绩排名

int cmpBigtoSmall(const void *a, const void *b)

{



	SS *aa = (SS *)(a);

	SS *bb = (SS *)(b);







	if ((*aa).generalScore < (*bb).generalScore)  return 1;



	else if ((*aa).generalScore > (*bb).generalScore)  return -1;



	else

		return 0;



}



void sortScore(SS stu[], int N)

{



	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);



}



//4.按照一定的格式输出N个学生的信息

void printOut(SS stu[], int N)

{



	printf("\n------第三步: 根据总成绩输出学生排名信息!------\n\n");

  for(int i=0;i<N;i++)
    	printf("%-10s %-10s %-10.1f %-10.1f %-10.1f\n",stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].finalScore,stu[i].generalScore);









	getchar();



}


//5.输入学号查询某个学生的成绩信息
void query(SS stu[],int N)
{
	printf("\n------第四步: 输入学号查询某个学生的成绩信息!------\n\n");
	char number[20];
	int i;
	printf("输入待查询学生学号:");
	scanf("%s",&number); 
	for(i=0;i<N;i++)
	{
		if(strcmp(number,stu[i].number)==0){
			printf("%-10s %-10s %-10.1f %-10.1f %-10.1f\n",stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].finalScore,stu[i].generalScore);
			break;
		}
	}
	if(i==N)
		printf("未查到该学生成绩！\n");
} 
//6.统计全班学生成绩的均值和标准方差
void analyse(SS stu[],int N)
{
	printf("\n------第五步: 统计全班学生成绩的均值和标准方差!------\n\n");
	double sum=0;
	for(int i=0;i<N;i++)
		sum+=stu[i].generalScore;
	double average=sum/N;
	double variance=0;
	for(i=0;i<N;i++)
		variance+=pow(average-stu[i].generalScore,2);
	printf("均值:%.1f 方差:%.1f\n",average,variance/N);
}

#define  _CRT_SECURE_NO_WARNINGS



/*************************************************

** 功能 : 学生成绩管理系统

** 作者 : Qingke Zhang/tsingke@sdnu.edu.cn

** 版本 : v1.0

** 版权 : GNU General Public License(GNU GPL)

/**************************************************/





#include <stdio.h>

#include <stdlib.h>

#include <windows.h>
#include <string.h>




/*----------------------------------*

		主函数 

*-----------------------------------*/



int main()

{



	printf("******************************\n");

	printf("       学生成绩管理分析系统        \n");

	printf("         Qingke Zhang            \n");

	printf("******************************\n\n");



	/*-1.变量初始化-*/

	int N = 0;            //学生总数

	SS  *pstu = NULL;    //学生数组-结构体数组指针实现



	//2.读取学生信息

	pstu = readDataFromFile(&N);



	/*-3.计算学生总成绩（总成绩 = 0.2*平时成绩 + 0.8*期末成绩)--*/

	calcuScore(pstu, N);



	/*-4.根据学生成绩排名-*/

	sortScore(pstu, N);



	/*-5.按照排名输出学生信息-*/

	printOut(pstu, N);


	/*-6.根据学号查询学生信息!-*/
	query(pstu,N);


	/*-7.计算均值和方差!-*/
	analyse(pstu,N);


	/*-8.释放动态内存空间-*/

	free(pstu);





	system("pause");

	return 0;

}