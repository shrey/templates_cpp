
#include <stdio.h>

int main()
{
      int m_s[10][2], p_s[10][3];
      int i, j, t_p = 0, t_m = 0;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &t_p);
      printf("\nEnter the Size of Each Process\n");
      for(int i = 0; i < t_p; i++)
      {
            printf("Enter Size of Process %d:\t", i + 1);
            scanf("%d", &p_s[i][0]);
            p_s[i][1] = 0;
            p_s[i][2] = i;
      }
      printf("\nEnter Total Memory Blocks:\t");
      scanf("%d", &t_m);
      printf("\nEnter the Size of Each Block:\n");
      for(i = 0; i < t_m; i++)
      {
            printf("Enter Size of Block %d:\t", i + 1);
            scanf("%d", &m_s[i][0]);
            m_s[i][1] = 0;
      }
      for(i = 0; i < t_p; i++)
      {
            while(j < t_m)
            {
                  if(m_s[j][1] == 0 && p_s[i][0] <= m_s[j][0])
                  {
                        p_s[i][1] = 1;
                        m_s[j][1] = 1;
                        printf("\nProcess (%d) Allocated to Memory Block:\t%d", i + 1, j + 1);
                        break;
                  }
                  j++;
            }
      }
      for(i = 0; i < t_p; i++)
      {
            if(p_s[i][1] == 0)
            {
                  printf("\nProcess (%d) Unallocated\n", i + 1);
            }
      }
      printf("\n");
      return 0;
}