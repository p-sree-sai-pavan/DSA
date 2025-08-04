#include <stdio.h>

int main()
{
    int n;
    printf("ENter Size of the array: ");
    scanf("%d", &n);
    int arr[ n ];
    printf("enter arr: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter a number to check: ");
    int a, found = 0;
    scanf("%d", &a);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            printf("a = arr[%d] ", i);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("It is not in the array");
    }

    return 0;
}