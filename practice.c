#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of students:\n");
    scanf("%d", &n);

    char names[n][50];
    int scores[n];

    for (int i = 0; i < n; i++){
        printf("Enter name of student %d\n", i + 1);
        scanf("%s", names[i]);
        printf("Enter score of student %d\n", i+1);
        scanf("%d", &scores[i]);
    }
    int max = scores[0];
    int min = scores[0];
    int sum = 0;


    for (int i = 0; i < n; i++){
        if (scores[i] > max)
        max = scores[i];
        if (scores[i] < min)
        min = scores[i];
        sum += scores[i];
    }
    float avg = (float)sum / n;
    printf("\n Maximum score : %d\n", max);
    printf("Minimum score: %d\n", min);
    printf("Average score : %.2f\n", avg);
    
    char grades[n];
    for(int i = 0; i < n; i++){
        if(scores[i] >= 90) 
        grades[i] = 'A';
        else if (scores[i] >= 80)
        grades[i] = 'B';
        else if(scores[i] >= 70)
        grades[i] = 'C';
        else if (scores[i] >= 60)
        grades[i]= 'D';
        else grades[i] = 'F';
    }
    printf("\n Student Report:\n");
    printf("Name \t Score\tGfade\n");
    for(int i = 0; i < n; i++){
        printf("%s\t%d\t%c\n", names[i], scores[i], grades[i]);

    }
    return 0;
}