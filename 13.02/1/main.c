#include <stdio.h>

int main()
{
    float sum, percentage;
    unsigned int period_mounths;

    printf("Enter sum: ");
    scanf("%f", &sum);
    printf("%f\n", sum);

    printf("Enter percentage: ");
    scanf("%f", &percentage);
    printf("%f%%\n", percentage);
    
    printf("Enter period in mounths: ");
    scanf("%ud", &period_mounths);
    printf("%ud\n", period_mounths);
    
    percentage = percentage / 100;

    float profit = sum;

    for (int i = period_mounths; i > 0; i--)
    {
        profit += profit * percentage;
    }

    printf("Profit: %f\n", profit - sum);
    printf("Full Profit: %f\n", profit);


    return 0;
}
