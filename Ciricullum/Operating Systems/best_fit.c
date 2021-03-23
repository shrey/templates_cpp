#include<stdio.h>

#define M 25

int main()
{
    int fragment[M], b[M], f[M], i, j, nb, nf, temp, lowest = 10000;
    int bf[M], block_num[M];
    printf("\nNumber of blocks? ");
    scanf("%d", & nb);
    printf("Number of files? :");
    scanf("%d", & nf);
    printf("\nSize of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", & b[i]);
    }
       printf("Size of the files?\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d:", i);
        scanf("%d", & f[i]);
    }
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (lowest > temp)
                {
                    block_num[i] = j;
                    lowest = temp;
                }
            }
        }
        fragment[i] = lowest;
        bf[block_num[i]] = 1;
        lowest = 10000;
    }
    printf("\nF_NO:\tF_SIZE :\tBLOCK_NUMBER:\tBLOCK_SIZE:\tFRAGMENT");
    for (i = 1; i <= nf && block_num[i] != 0; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], block_num[i], b[block_num[i]], fragment[i]);
    printf("\n");
}