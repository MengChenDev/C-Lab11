#include "common.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef CORE_H
#define CORE_H

void InputScores(SystemInfo *systemInfo, Student *students, int studentCount);
void CalculateCourseTotalAndAverage(SystemInfo *systemInfo, Student *students, int studentCount);
void CalculateStudentTotalAndAverage(SystemInfo *systemInfo, Student *students, int studentCount);
void SortStudentsByTotalScoreDesc(SystemInfo *systemInfo, Student *students, int studentCount);
void SortStudentsByTotalScoreAsc(SystemInfo *systemInfo, Student *students, int studentCount);
void DisplayScoresByIDAsc(SystemInfo *systemInfo, Student *students, int studentCount);
void DisplayScoresByNameAsc(SystemInfo *systemInfo, Student *students, int studentCount);
void SearchRankingByID(SystemInfo *systemInfo, Student *students, int studentCount);
void SearchRankingByName(SystemInfo *systemInfo, Student *students, int studentCount);
void StatisticsByCategory(SystemInfo *systemInfo, Student *students, int studentCount);
void DisplayAllStudentScores(SystemInfo *systemInfo, Student *students, int studentCount);
void SetSystemInfo(SystemInfo *systemInfo, Student **students, int *studentCount);
void ExportDataToFile(SystemInfo *systemInfo, Student *students, int studentCount);
void ImportDataFromFile(SystemInfo *systemInfo, Student **students, int *studentCount);
#endif
