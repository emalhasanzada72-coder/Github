#include <stdio.h>
int main()
{
    int p[] = {1, 2, 3, 4, 5, 6, 8, 5, 9, 0};
    int N= sizeof(p)/sizeof(p[0]);

     printArray(p, N);
     float m = Mean(p, N);
     printf("Mean of Array Elemente = %f\n", m);
    return 0;
}
void printArray(int a[], int N)
{
    printf("List of array members:\n");
    int i;
    for (i = 0; i<N; i++)
    {
        printf("%d", a[i]);
        if (i < N-1) 
        {
            printf(", ");
        }
        printf("\n\n");
    }
}
float Mean(int p[], int N)
{
    int sum = 0;
    int i;
    for (i = 0; i < N; i++)
    {
        sum += a[i];
    }
    
    return (float)sum/N;

}