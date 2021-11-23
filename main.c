#include "my_mat.h"
#include <stdio.h>

int main()
{
    char temp;
    int mat[10][10];
    do
    {
        scanf("%c", &temp);
        if(temp == 'A')
        {
            matrix(mat);
        }
        else if (temp == 'B')
        {
            int ans = hasPath(mat);
            if(ans == 1)
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
        }
        else if (temp == 'C')
        {
            printf("%d\n",shortestPath(mat));
        } 
    } while (temp != 'D');

    return 1;
}
