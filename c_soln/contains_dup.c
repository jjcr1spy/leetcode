//#include <stdlib.h>

int compare_vals(const void * a, const void * b) {
    if (*((int *) a) > *((int *) b)) return 1;
    if (*((int *) a) < *((int *) b)) return -1;
    return 0;
}

bool containsDuplicate(int * nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), &compare_vals);

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i+1]) return true;
    }

    return false;
}