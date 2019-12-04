#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	double science[20] = {65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70};
	double english[20] = {44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84};
	double aves,avee,devs,deve,sums,sums2,sume,sume2;
	double stus[20],stue[20],nums[20],nume[20],sorts[20],sorte[20];
	int i,j,temp1,temp2;

	//計算
	for(i=0;i<20;i++)
	{
		sums += science[i];
		sume += english[i];
		sums2 += science[i]*science[i];
		sume2 += english[i]*english[i];
	}
	aves = sums /20;
	avee = sume /20;
	devs = sqrt(sums2/20 - aves*aves);
	deve = sqrt(sume2/20 - avee*avee);

	for(i=0;i<20;i++)
	{
		nums[i] = (science[i] - aves) *10 / devs;
		nume[i] = (english[i] - avee) *10 / deve;

		if(science[i] < aves)
			stus[i] = 50 - nums[i];
		else if(science[i] > aves)
			stus[i] = 50 + nums[i];
		else	
			stus[i] = 50;

		if(english[i] < avee)
			stue[i] = 50 - nume[i];
		else if(english[i] > avee)
			stue[i] = 50 + nume[i];
		else 
			stue[i] = 50;

	}

	
	for(i=0;i<20;i++)
	{
		for(j=20-1;j>i;j--)
		{
			if(science[j]>science[j-1])
			{
				temp1 = science[j];
				science[j] = science[j-1];
				science[j-1] = temp1;
			}
			if(english[j]>english[j-1])
			{
				temp2 = english[j];
				english[j] = english[j-1];
				english[j-1] = temp2;
			}
		}
	} 


	//表示
	printf("理科(平均：%f)(標準偏差：%f)(合計：%f)\n",aves,devs,sums);
	printf("英語(平均：%f)(標準偏差：%f)(合計：%f)\n",avee,deve,sume);

	for(int i=0;i<20;i++)
	{
		printf("学生%d 理科(偏差値：%f) 英語(偏差値：%f)\n",i+1,stus[i],stue[i]);
	}
	printf("-------------理科順位一覧------------\n");
	for(i=0;i<20;i++)
	{
		printf("%d位：%f点\n",i+1,science[i]);
	}
	printf("-------------英語順位一覧----------- \n");
	for(i=0;i<20;i++)
	{
		printf("%d位：%f点\n",i+1,english[i]);
	}
	return 0;
}
