#include <sys/mman.h>

#define TABLE_ELEMS (1000000000 * 2)
#define TABLE_SIZE (TABLE_ELEMS * sizeof(short))

static unsigned short *table_base = MAP_FAILED;
static unsigned short *table = NULL;

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
	int *result = NULL;
	int nums_entered = 0;
	*returnSize = 0;

	if (table_base == MAP_FAILED) {
		table_base = mmap(NULL, TABLE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		if (table_base == MAP_FAILED) {
			fprintf(stderr, "Unable to allocate table\n");
			return NULL;
		}
		table = &table_base[TABLE_ELEMS / 2];
	}

	for (int i = 0; i < numsSize; i++) {
		int complement = target - nums[i];
		if (table[complement]) {
			result = malloc(sizeof(int) * 2);
			if (result) {
				result[0] = i;
				result[1] = table[complement] - 1;
				*returnSize = 2;
			}
			break;
		} else {
			table[nums[i]] = i + 1;
			nums_entered++;
		}
	}

	if (table_base != MAP_FAILED)
		for (int i = 0; i < nums_entered; i++)
			table[nums[i]] = 0;

	return result;
}
