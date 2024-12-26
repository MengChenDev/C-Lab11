// file.h
#ifndef FILE_H
#define FILE_H

#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "ScoreSystem.bin"

extern char FileName[100];

int IsDataExists();
int SaveData(SystemInfo *systemInfo, Student *students, int studentCount, const char *fileName);
int LoadData(SystemInfo *systemInfo, Student **students, int *studentCount, const char *fileName);
#endif // FILE_H