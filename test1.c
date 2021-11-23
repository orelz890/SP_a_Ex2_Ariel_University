#include "my_mat.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    char temp;
    int mat[10][10];
    do
    {
        scanf("%c", &temp);
        if(temp == 'A')
        {
            int x = matrix(mat);
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
int matrix(int mat[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mat[i][j] = scanFromUser();
        }
    }
    int x = accurateMat(mat);
    return x;
}

int accurateMat(int mat[10][10])
{
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i != j)
                {
                    int ik = mat[i][k] == 0? INT_MAX - mat[k][j] : mat[i][k];
                    int kj = mat[k][j] == 0? INT_MAX - ik : mat[k][j];
                    int throwK = (ik + kj);
                    int ij = mat[i][j] == 0? INT_MAX : mat[i][j]; 
                    mat[i][j] = (ij <= throwK)? mat[i][j] : (mat[i][k] + mat[k][j]);
                }
            }
        }
        // for (int z = 0; z < 10; z++)
        // {
        //     for (int p = 0; p < 10; p++)
        //     {
        //         printf("%d ",mat[z][p]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");   
    }
    return 1;
}

int hasPath(int mat[10][10])
{
    int i = scanFromUser();
    int j = scanFromUser();
    int ans = ((mat[i][j]) > 0)? 1 : 0;
    return ans;
}

int shortestPath(int mat[10][10])
{
    int i = scanFromUser();
    int j = scanFromUser();
    int ans = (mat[i][j] <= 0)? -1 : mat[i][j];
    return ans;
}

int scanFromUser()
{
    int i=0;
    while(scanf("%d",&i) == 0)
    {
        char a;
        scanf("%c",&a);
    }
    return i;
}
