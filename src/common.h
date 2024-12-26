#ifndef COMMON_H
#define COMMON_H

typedef struct
{
  int id;
  char name[50];
  float *scores; // 动态分配的数组
} Student;

typedef struct
{
  int classSize;
  char **subjectNames; // 动态分配的数组
  int subjectCount;
} SystemInfo;

extern SystemInfo systemInfo;
extern Student *students; // 动态分配的数组
extern int studentCount;

#endif // COMMON_H

