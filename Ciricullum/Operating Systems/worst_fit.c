#include<stdio.h>


#define M 25

int main()
{
    int frag[M], b[M], f[M], i, j, nb, nf, temp, highest = 0;
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
            if (bf[j] != 1) //if bf[j] is not allocated
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (highest < temp)
                {
                    ff[i] = j;
                    highest = temp;
                }
            }
        }
        frag[i] = highest;
        bf[ff[i]] = 1;
        highest = 0;
    }
    printf("\nF_NO:\tF_SIZE :\tBLOCK_NUMBER:\tBLOCK_SIZE:\tFRAGMENT");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    printf("\n");
}