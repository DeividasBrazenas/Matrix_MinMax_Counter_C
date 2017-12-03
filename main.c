#include <stdio.h>
#include <stdlib.h>

void Read(int ***ptr, int *size);
int MinRow(int **ptr, int size, int row);
int MaxRow(int **ptr, int size, int row);
int MinCol(int **ptr, int size, int col);
int MaxCol(int **ptr, int size, int col);
int HowMany(int **ptr, int size);

int main()
{
    int **ptr;
    int size;
    int y;
    int a;

    Read(&ptr,&size);
    a = HowMany(ptr,size);

    printf("%d",a);

    for(y = 0; y < size; y++)
    {
        free(ptr[y]);
    }

    free(ptr);

    return 0;
}

void Read(int ***ptr, int *size)
{
    int y,x;

    scanf("%d", size);

    (*ptr) = (int**)malloc(*size * sizeof(int*));

    for(y = 0; y < *size; y++)
    {
        (*ptr)[y] = (int*)malloc(*size * sizeof(int));
    }

    for(y = 0; y < *size; y++)
    {
        for(x = 0; x < *size; x++)
        {
            scanf("%d",&(*ptr)[y][x]);
        }
    }
}

int MinRow(int **ptr, int size, int row)
{
    int min = ptr[row][0];
    int x;

    for(x = 0; x < size; x++)
    {
        if(min > ptr[row][x])
        {
            min = ptr[row][x];
        }
    }
    return min;
}

int MaxRow(int **ptr, int size, int row)
{
    int max = ptr[row][0];
    int x;

    for(x = 0; x < size; x++)
    {
        if(max < ptr[row][x])
        {
            max = ptr[row][x];
        }
    }
    return max;
}

int MinCol(int **ptr, int size, int col)
{
    int min = ptr[0][col];
    int y;

    for(y = 0; y < size; y++)
    {
        if(min > ptr[y][col])
        {
            min = ptr[y][col];
        }
    }

    return min;
}

int MaxCol(int **ptr, int size, int col)
{
    int max = ptr[0][col];
    int y;

    for(y = 0; y < size; y++)
    {
        if(max < ptr[y][col])
        {
            max = ptr[y][col];
        }
    }

    return max;
}

int HowMany(int **ptr, int size)
{
    int a = 0;
    int y,x;
    int minRow,maxRow;

    for(y = 0; y < size; y++)
    {
        minRow = MinRow(ptr,size,y);
        maxRow = MaxRow(ptr,size,y);

        for(x = 0; x < size; x++)
        {
            if(minRow == MaxCol(ptr,size,x) || maxRow == MinCol(ptr,size,x))
                a++;
        }
    }
    return a;
}
