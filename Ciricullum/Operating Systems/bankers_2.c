#include<stdio.h>
int main() {
	int k=0,out[10],d=0,t=0,ins[5],i,avail[5],allocated[10][5],need[10][5],mx[10][5],pno,P[10],j,rz, count=0;
	printf("\n Number of resources? : ");
	scanf("%d", &rz);
	printf("\n Max instances of each resources\n");
	for (i=0;i<rz;i++) {
		avail[i]=0;
		printf("%c= ",(i+97));
		scanf("%d",&ins[i]);
	}
	printf("\n Enter the number of processes : ");
	scanf("%d", &pno);
	printf("\n Enter the allocation matrix \n     ");
	for (i=0;i<rz;i++)
	printf(" %c",(i+97));
	printf("\n");
	for (i=0;i <pno;i++) {
		P[i]=i;
		printf("Process[%d]  ",P[i]);
		for (j=0;j<rz;j++) {
			scanf("%d",&allocated[i][j]);
			avail[j]+=allocated[i][j];
		}
	}
	printf("\nInput the mx matrix \n     ");
	for (i=0;i<rz;i++) {
		printf(" %c",(i+97));
		avail[i]=ins[i]-avail[i];
	}
	printf("\n");
	for (i=0;i <pno;i++) {
		printf("P[%d]  ",i);
		for (j=0;j<rz;j++)
		 scanf("%d", &mx[i][j]);
	}
	printf("\n");
	A: d=-1;
	for (int i=0;i <pno;i++) {
		count=0;
		t=P[i];
        printf("%d\n",i);
		for (j=0;j<rz;j++) {
			need[t][j] = mx[t][j]-allocated[t][j];
			if(need[t][j]<=avail[j])
			 count++;
		}
		if(count==rz) {
			out[k++]=P[i];
			for (j=0;j<rz;j++)
			avail[j]+=allocated[t][j];
		} else
		 P[++d]=P[i];
	}
	if(d!=-1) {
		pno=d+1;
		goto A;
	}
	printf("\t <");
	for (i=0;i<k;i++)
	printf(" P%d , ",out[i]);
	printf(">");
}


/*
4
10 15 20 25
4
2 0 4 5
3 4 0 5
1 2 4 5
5 6 2 1

10 15 20 20
9 10 11 12
13 14 15 16
18 19 20 21
*/