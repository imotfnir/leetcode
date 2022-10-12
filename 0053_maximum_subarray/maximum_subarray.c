#include <stdio.h>

int get_sum_of_array(int array[], size_t len);
int get_max_sum_of_subarray(int super_array[], size_t len);

int
get_sum_of_array(int array[], size_t len) {
    int sum = 0;

    for (size_t i = 0; i < len; i++) {
        sum += array[i];
    }
    return sum;
}

int
get_max_sum_of_subarray(int super_array[], size_t len) {
    int maximum_sum = 0;
    int current_sum = 0;

    for (size_t subarray_len = 1; subarray_len <= len; subarray_len++) {
        for (size_t subarray_start_pos = 0; subarray_start_pos < len - subarray_len + 1; subarray_start_pos++) {
            for (size_t i = 0; i < subarray_len; i++) {
                current_sum += super_array[subarray_start_pos + i];
                // printf("%02d ", super_array[subarray_start_pos + i]);
            }
            // printf("\t%d\n", current_sum);
            if (current_sum > maximum_sum) {
                maximum_sum = current_sum;
            }
            current_sum = 0;
        }
    }
    return maximum_sum;
}

int
main() {
    int nums[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    printf("max sum of subarray is: %d\n",get_max_sum_of_subarray(nums, (sizeof(nums) / sizeof(int))));
    return 0;
}