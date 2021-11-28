#include "my_mat.h"
#include <stdio.h>
#include <limits.h>

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
    }
    return 0;
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
