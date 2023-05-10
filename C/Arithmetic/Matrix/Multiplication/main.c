#include <stdio.h>
#include <time.h>

int
main()
{
	clock_t start_time, end_time;
	double cpu_time_used;
	
	int arr[2][2] = {{3, 4}, {1, 2}};
	int arr1[2][2] = {{5, 4}, {1, 3}};
	int arr2[2][2];

	start_time = clock();
	
	for (int i = 0; i < 1000000000; i++) {
		arr2[0][0] = ((arr[0][0] * arr1[0][0]) + (arr[0][1] * arr1[1][0]));
		arr2[0][1] = ((arr[0][0] * arr1[0][1]) + (arr[0][1] * arr1[1][1]));
		arr2[1][0] = ((arr[0][1] * arr1[0][0]) + (arr[1][1] * arr1[1][0]));
		arr2[1][1] = ((arr[0][1] * arr1[0][1]) + (arr[1][1] * arr1[1][1]));
	}

	end_time = clock();
	cpu_time_used = (((double) (end_time - start_time)) / CLOCKS_PER_SEC);
	printf("Time: %f\n", cpu_time_used);
	return 0;
}
