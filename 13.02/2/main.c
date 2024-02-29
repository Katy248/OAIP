#include <stdio.h>
#include <stdbool.h>
#define uint unsigned int

int main()
{
    uint n;

    printf("Enter n: ");
    scanf("%ud", &n);

    for (uint i = 1; i <= n; i++)
    {
        bool check = true;
        
        int p = i;
        while (p > 0) 
        {
            int digit = p % 10;
            if (digit == 0 || i % digit != 0) 
                check = false;
            p /= 10;
        }

        if (check)
            printf("%d\n", i);
    }


    return 0;
}
