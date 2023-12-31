#include <stdio.h>
#include <cjson/cJSON.h>

int
main()
{
	cJSON *json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "name", "John Doe");
	cJSON_AddNumberToObject(json, "age", 30);
	cJSON_AddStringToObject(json, "email", "john.doe@example.com");

	char *json_str = cJSON_Print(json);

	FILE *fp = fopen("data.json", "w");
	if (fp == NULL) {
		printf("Error: Unable to open the file.\n");
		return 1;
	}

	printf("%s\n", json_str);
	fputs(json_str, fp);
	fclose(fp);

	cJSON_free(json_str);
	cJSON_Delete(json);

	return 0;
}
