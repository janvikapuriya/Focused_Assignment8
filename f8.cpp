/*
 * FILE: f8.cpp
 * PROJECT: f8
 * PROGRAMMER: Janvi Kapuriya
 * FIRST VERSION: 31/03/2023
 * DESCRIPTION: Create a programme that will allow you to practise dealing with structs, files, command line arguments, and strings in the C style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UPPER_LIMIT_STRING_LENGTH 20
#define UPPER_LIMIT_PATH_LENGTH 256
#define UPPER_LIMIT_LINES 100

typedef struct
{
	int howMany;
	char text[UPPER_LIMIT_STRING_LENGTH + 1];
	char directoryLocation[UPPER_LIMIT_PATH_LENGTH + 1];
	char fileName[UPPER_LIMIT_STRING_LENGTH + 1];
} MyData;

size_t stringLengthCopy(char *dataSet, const char *source, size_t dataSetSize)
{
	size_t sourceLength = strlen(source);
	if (sourceLength < dataSetSize)
	{
		memcpy(dataSet, source, sourceLength + 1);
	}
	else if (dataSetSize != 0)
	{
		memcpy(dataSet, source, dataSetSize - 1);
		dataSet[dataSetSize - 1] = '\0';
	}
	return sourceLength;
}

int main(int argument, char *argumentData[])
{
	if (argument != 5)
	{
		printf("Usage: %s <howMany> <text> <directoryLocation> <fileName> \n", argumentData[0]);
		return 1;
	}

	MyData dataArguments;
	dataArguments.howMany = atoi(argumentData[1]);
	stringLengthCopy(dataArguments.text, argumentData[2], sizeof(dataArguments.text));
	stringLengthCopy(dataArguments.directoryLocation, argumentData[3], sizeof(dataArguments.directoryLocation));
	stringLengthCopy(dataArguments.fileName, argumentData[4], sizeof(dataArguments.fileName));

	char filePath[UPPER_LIMIT_PATH_LENGTH + UPPER_LIMIT_STRING_LENGTH + 2];
	snprintf(filePath, UPPER_LIMIT_PATH_LENGTH + UPPER_LIMIT_STRING_LENGTH + 2, "%s/%s", dataArguments.directoryLocation, dataArguments.fileName);

	{
		FILE *filepath = fopen(filePath, "s");
		if (filepath == NULL)
		{
			printf("Error: Cannot Create File %s \n ", filePath);
			return 1;
		}

		for (int i = 0; i < dataArguments.howMany; i++)
		{
			fputs(dataArguments.text, filepath);
			fputc('\n', filepath);
		}

		fclose(filepath);

		printf("File Created Successfully !! : %s \n ", filePath);

		return 0;
	}