#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAT_SIZE 1000

int main(){

	int n=MAT_SIZE;
	int i,j,k;
	int index1,index2,line_flag;

	//int upper[MAT_SIZE][MAT_SIZE];
	//int lower[MAT_SIZE][MAT_SIZE];
	//int multp[MAT_SIZE][MAT_SIZE];
	int **upper,**lower,**multp;

	upper=malloc(sizeof(int*)*MAT_SIZE);
	lower=malloc(sizeof(int*)*MAT_SIZE);
	multp=malloc(sizeof(int*)*MAT_SIZE);

	for(i=0;i<MAT_SIZE;i++)
	{
		upper[i]=malloc(sizeof(int)*MAT_SIZE);
		lower[i]=malloc(sizeof(int)*MAT_SIZE);
		multp[i]=malloc(sizeof(int)*MAT_SIZE);
	}


	srand(time(NULL));

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i>j)
				upper[i][j]=0;
			else
			{
				upper[i][j]=random()%20;
				while(upper[i][j]==0)
					upper[i][j]=random()%20;
			}
		}
	}

	for(i=0;i<MAT_SIZE*MAT_SIZE*4.5;i++)
	{
		index1=random()%MAT_SIZE;
		index2=random()%MAT_SIZE;
		if(index1!=index2)
		{
			upper[index1][index2]=0;
		}
	}

	/*for(i=0;i<MAT_SIZE;i++)
	{
		line_flag=1;
		for(j=i+1;j<MAT_SIZE;j++)
		{
			if(upper[i][j]!=0)
			{
				line_flag=0;
				break;
			}
		}
		if(line_flag==1)
		{
			upper[i][MAT_SIZE-1]=random()%20+1;
		}
	}*/

	FILE* fp1 = fopen("/home/andrew/CLionProjects/Belphegor-Generator/cmake-build-debug/lower.txt","w");
	//FILE *fp1 = fopen("lower.txt","w");
	//fprintf(fp1,"%d\n",MAT_SIZE);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			lower[i][j]=upper[j][i];
			fprintf(fp1,"%d ",lower[i][j]);
		}
		//fprintf(fp1,"\n");
	}

	fclose(fp1);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			multp[i][j]=0;
			for(k=0;k<n;k++)
			{
				multp[i][j]=multp[i][j]+lower[i][k]*upper[k][j];
			}
		}
	}

	FILE *fp2 = fopen("/home/andrew/CLionProjects/Belphegor-Generator/cmake-build-debug/res.txt","w");
	//FILE *fp2 = fopen("res.txt","w");
	//fprintf(fp2,"%d\n",MAT_SIZE);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(fp2,"%d ",multp[i][j]);
		}
		//fprintf(fp2,"\n");
	}

	fclose(fp2);

	if(MAT_SIZE<50){
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				lower[i][j]=upper[j][i];
				printf("%3d ",upper[i][j]);
			}
			printf("\n");
		}


		printf("\n");

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%3d ",lower[i][j]);
			}
			printf("\n");
		}

		printf("\n");

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%4d ",multp[i][j]);
			}
			printf("\n");
		}

		printf("\n");

		for(i=0;i<n;i++)
		{
			printf("{");
			for(j=0;j<n;j++)
			{
				printf("%4d, ",multp[i][j]);
			}
			printf("},\n");
		}
	}
}