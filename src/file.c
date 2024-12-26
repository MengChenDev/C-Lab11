#include "file.h"

char FileName[100] = FILE_NAME;

int IsDataExists()
{
  FILE *file = fopen(FILE_NAME, "rb");
  if (file != NULL)
  {
    fclose(file);
    return 1; // 文件存在
  }
  else
  {
    return 0; // 文件不存在
  }
}

int SaveData(SystemInfo *systemInfo, Student *students, int studentCount, const char *fileName)
{
  FILE *file = fopen(fileName, "wb");
  if (file == NULL)
  {
    perror("无法打开文件进行写入");
    return 0;
  }

  // 写入系统信息
  fwrite(&systemInfo->subjectCount, sizeof(int), 1, file);
  for (int i = 0; i < systemInfo->subjectCount; i++)
  {
    fwrite(systemInfo->subjectNames[i], sizeof(char), 50, file);
  }
  fwrite(&systemInfo->classSize, sizeof(int), 1, file);

  // 写入学生信息
  fwrite(&studentCount, sizeof(int), 1, file);
  for (int i = 0; i < studentCount; i++)
  {
    fwrite(&students[i].id, sizeof(int), 1, file);
    fwrite(students[i].name, sizeof(char), 50, file);
    fwrite(students[i].scores, sizeof(float), systemInfo->subjectCount, file);
  }

  fclose(file);
  printf("数据已成功保存到 %s\n", fileName);
  return 1;
}

int LoadData(SystemInfo *systemInfo, Student **students, int *studentCount, const char *fileName)
{
  FILE *file = fopen(fileName, "rb");
  if (file == NULL)
  {
    perror("无法打开文件进行读取");
    return 0;
  }

  strcpy(FileName, fileName);

  // 读取系统信息
  fread(&systemInfo->subjectCount, sizeof(int), 1, file);
  systemInfo->subjectNames = (char **)malloc(systemInfo->subjectCount * sizeof(char *));
  for (int i = 0; i < systemInfo->subjectCount; i++)
  {
    systemInfo->subjectNames[i] = (char *)malloc(50 * sizeof(char));
    fread(systemInfo->subjectNames[i], sizeof(char), 50, file);
  }
  fread(&systemInfo->classSize, sizeof(int), 1, file);

  // 读取学生信息
  fread(studentCount, sizeof(int), 1, file);
  *students = (Student *)malloc(*studentCount * sizeof(Student));
  for (int i = 0; i < *studentCount; i++)
  {
    fread(&(*students)[i].id, sizeof(int), 1, file);
    fread((*students)[i].name, sizeof(char), 50, file);
    (*students)[i].scores = (float *)malloc(systemInfo->subjectCount * sizeof(float));
    fread((*students)[i].scores, sizeof(float), systemInfo->subjectCount, file);
  }

  fclose(file);
  printf("数据已成功从 %s 加载\n", fileName);
  return 1;
}