#include<stdio.h>


#define M 30

int main()
{
    int fragment[M], b[M], f[M], i, j, nb, nf, temp;
    int bf[M], ff[M];
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
                {
                    ff[i] = j;
                    break;
                }
            }
        }
        fragment[i] = temp;
        bf[ff[i]] = 1;
    }
    printf("\nF_NO:\tF_SIZE :\tBLOCK_NUMBER:\tBLOCK_SIZE:\tFRAGMENT");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], fragment[i]);
    printf("\n");
}