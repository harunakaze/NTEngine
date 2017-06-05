#include "MainUtil.h"
#include <stdio.h>
#include <stdlib.h>

void logMessage(const char *formatStr, ...)
{
	printf(formatStr);
	printf("\n");
}