#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* twoSum(int *nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
    *returnSize = 0;
    return NULL;
}

int main() {
    int n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    int returnSize;
    int* result = twoSum(nums, n, target, &returnSize);
    
    if (result != NULL) {
        printf("[%d,%d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found!\n");
    }
    
    free(nums);
    return 0;
}