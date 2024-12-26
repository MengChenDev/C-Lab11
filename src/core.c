// core.c
#include "core.h"

// 输入学生成绩
void InputScores(SystemInfo *systemInfo, Student *students, int studentCount)
{
  for (int i = 0; i < studentCount; i++)
  {
    printf("请输入学生 %s (ID: %d) 的成绩:\n", students[i].name, students[i].id);
    for (int j = 0; j < systemInfo->subjectCount; j++)
    {
      printf("%s 的成绩: ", systemInfo->subjectNames[j]);
      scanf("%f", &students[i].scores[j]);
    }
  }
  SaveData(systemInfo, students, studentCount, FileName);
}

// 计算每门课程的总分和平均分
void CalculateCourseTotalAndAverage(SystemInfo *systemInfo, Student *students, int studentCount)
{
  for (int j = 0; j < systemInfo->subjectCount; j++)
  {
    float total = 0;
    for (int i = 0; i < studentCount; i++)
    {
      total += students[i].scores[j];
    }
    float average = total / studentCount;
    printf("%s 的总分: %.2f, 平均分: %.2f\n", systemInfo->subjectNames[j], total, average);
  }
}

// 计算每个学生的总分和平均分
void CalculateStudentTotalAndAverage(SystemInfo *systemInfo, Student *students, int studentCount)
{
  for (int i = 0; i < studentCount; i++)
  {
    float total = 0;
    for (int j = 0; j < systemInfo->subjectCount; j++)
    {
      total += students[i].scores[j];
    }
    float average = total / systemInfo->subjectCount;
    printf("学生 %s (ID: %d) 的总分: %.2f, 平均分: %.2f\n", students[i].name, students[i].id, total, average);
  }
}

// 按总分降序排序学生
void SortStudentsByTotalScoreDesc(SystemInfo *systemInfo, Student *students, int studentCount)
{
  for (int i = 0; i < studentCount - 1; i++)
  {
    for (int j = 0; j < studentCount - i - 1; j++)
    {
      float total1 = 0, total2 = 0;
      for (int k = 0; k < systemInfo->subjectCount; k++)
      {
        total1 += students[j].scores[k];
        total2 += students[j + 1].scores[k];
      }
      if (total1 < total2)
      {
        Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
  SaveData(systemInfo, students, studentCount, FileName);
  printf("学生总分降序排名:\n");
  DisplayAllStudentScores(systemInfo, students, studentCount);
}

// 按总分升序排序学生
void SortStudentsByTotalScoreAsc(SystemInfo *systemInfo, Student *students, int studentCount)
{
  for (int i = 0; i < studentCount - 1; i++)
  {
    for (int j = 0; j < studentCount - i - 1; j++)
    {
      float total1 = 0, total2 = 0;
      for (int k = 0; k < systemInfo->subjectCount; k++)
      {
        total1 += students[j].scores[k];
        total2 += students[j + 1].scores[k];
      }
      if (total1 > total2)
      {
        Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
  SaveData(systemInfo, students, studentCount, FileName);
  printf("学生总分升序排名:\n");
  DisplayAllStudentScores(systemInfo, students, studentCount);
}

// 按学生ID升序显示成绩
void DisplayScoresByIDAsc(SystemInfo *systemInfo, Student *students, int studentCount)
{
  for (int i = 0; i < studentCount - 1; i++)
  {
    for (int j = 0; j < studentCount - i - 1; j++)
    {
      if (students[j].id > students[j + 1].id)
      {
        Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
  printf("按学生ID升序排序后的学生成绩:\n");
  DisplayAllStudentScores(systemInfo, students, studentCount);
  SaveData(systemInfo, students, studentCount, FileName);
}

// 按学生姓名升序显示成绩
void DisplayScoresByNameAsc(SystemInfo *systemInfo, Student *students, int studentCount)
{
  for (int i = 0; i < studentCount - 1; i++)
  {
    for (int j = 0; j < studentCount - i - 1; j++)
    {
      if (strcmp(students[j].name, students[j + 1].name) > 0)
      {
        Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
  printf("按姓名升序排序后的学生成绩:\n");
  DisplayAllStudentScores(systemInfo, students, studentCount);
  SaveData(systemInfo, students, studentCount, FileName);
}

// 根据学生ID查询排名
void SearchRankingByID(SystemInfo *systemInfo, Student *students, int studentCount)
{
  int id;
  printf("请输入要查询的学生ID: ");
  scanf("%d", &id);
  for (int i = 0; i < studentCount; i++)
  {
    if (students[i].id == id)
    {
      printf("学生 %s (ID: %d) 的排名是 %d\n", students[i].name, students[i].id, i + 1);
      float total = 0;
      for (int j = 0; j < systemInfo->subjectCount; j++)
      {
        printf("%s: %.2f\n", systemInfo->subjectNames[j], students[i].scores[j]);
        total += students[i].scores[j];
      }
      float average = total / systemInfo->subjectCount;
      printf("总分: %.2f, 平均分: %.2f\n", total, average);
      return;
    }
  }
  printf("未找到ID为 %d 的学生。\n", id);
}

// 根据学生姓名查询排名
void SearchRankingByName(SystemInfo *systemInfo, Student *students, int studentCount)
{
  char name[50];
  printf("请输入要查询的学生姓名: ");
  scanf("%s", name);
  for (int i = 0; i < studentCount; i++)
  {
    if (strcmp(students[i].name, name) == 0)
    {
      printf("学生 %s (ID: %d) 的排名是 %d\n", students[i].name, students[i].id, i + 1);
      float total = 0;
      for (int j = 0; j < systemInfo->subjectCount; j++)
      {
        printf("%s: %.2f\n", systemInfo->subjectNames[j], students[i].scores[j]);
        total += students[i].scores[j];
      }
      float average = total / systemInfo->subjectCount;
      printf("总分: %.2f, 平均分: %.2f\n", total, average);
      return;
    }
  }
  printf("未找到姓名为 %s 的学生。\n", name);
}

// 按类别统计成绩
void StatisticsByCategory(SystemInfo *systemInfo, Student *students, int studentCount)
{
  for (int j = 0; j < systemInfo->subjectCount; j++)
  {
    int excellent = 0, good = 0, average = 0, pass = 0, fail = 0;
    for (int i = 0; i < studentCount; i++)
    {
      if (students[i].scores[j] >= 90)
        excellent++;
      else if (students[i].scores[j] >= 80)
        good++;
      else if (students[i].scores[j] >= 70)
        average++;
      else if (students[i].scores[j] >= 60)
        pass++;
      else
        fail++;
    }
    printf("%s 的统计:\n", systemInfo->subjectNames[j]);
    printf("优秀 (90-100): %d 人, 占比: %.2f%%\n", excellent, (excellent * 100.0) / studentCount);
    printf("良好 (80-89): %d 人, 占比: %.2f%%\n", good, (good * 100.0) / studentCount);
    printf("中等 (70-79): %d 人, 占比: %.2f%%\n", average, (average * 100.0) / studentCount);
    printf("及格 (60-69): %d 人, 占比: %.2f%%\n", pass, (pass * 100.0) / studentCount);
    printf("不及格 (0-59): %d 人, 占比: %.2f%%\n", fail, (fail * 100.0) / studentCount);
  }
}

// 显示所有学生成绩
void DisplayAllStudentScores(SystemInfo *systemInfo, Student *students, int studentCount)
{
  for (int i = 0; i < studentCount; i++)
  {
    float total = 0;
    printf("学生 %s (ID: %d):\n", students[i].name, students[i].id);
    for (int j = 0; j < systemInfo->subjectCount; j++)
    {
      printf("%s: %.2f\n", systemInfo->subjectNames[j], students[i].scores[j]);
      total += students[i].scores[j];
    }
    float average = total / systemInfo->subjectCount;
    printf("总分: %.2f, 平均分: %.2f\n", total, average);
  }

  for (int j = 0; j < systemInfo->subjectCount; j++)
  {
    float total = 0;
    for (int i = 0; i < studentCount; i++)
    {
      total += students[i].scores[j];
    }
    float average = total / studentCount;
    printf("%s 的总分: %.2f, 平均分: %.2f\n", systemInfo->subjectNames[j], total, average);
  }
}

// 设置系统信息
void SetSystemInfo(SystemInfo *systemInfo, Student **students, int *studentCount)
{
  printf("请输入科目数量: ");
  scanf("%d", &systemInfo->subjectCount);
  systemInfo->subjectNames = (char **)malloc(systemInfo->subjectCount * sizeof(char *));
  for (int i = 0; i < systemInfo->subjectCount; i++)
  {
    systemInfo->subjectNames[i] = (char *)malloc(50 * sizeof(char));
    printf("请输入第 %d 个科目的名称: ", i + 1);
    scanf("%s", systemInfo->subjectNames[i]);
  }
  printf("请输入班级人数: ");
  scanf("%d", &systemInfo->classSize);
  *studentCount = systemInfo->classSize;
  *students = (Student *)malloc(*studentCount * sizeof(Student));
  for (int i = 0; i < *studentCount; i++)
  {
    printf("请输入学生 %d 的姓名: ", i + 1);
    scanf("%s", (*students)[i].name);
    (*students)[i].id = i + 1;
    (*students)[i].scores = (float *)malloc(systemInfo->subjectCount * sizeof(float));
  }
  SaveData(systemInfo, *students, *studentCount, FileName);
}

// 导出学生成绩到文件
void ExportDataToFile(SystemInfo *systemInfo, Student *students, int studentCount)
{
  char filename[100];
  printf("请输入导出文件的名称: ");
  scanf("%s", filename);
  SaveData(systemInfo, students, studentCount, filename);
}

// 从文件导入学生成绩
void ImportDataFromFile(SystemInfo *systemInfo, Student **students, int *studentCount)
{
  char filename[100];
  printf("请输入导入文件的名称: ");
  scanf("%s", filename);
  if (IsDataExists(filename))
  {
    LoadData(systemInfo, students, studentCount, filename);
  } else {
    printf("文件不存在，导入失败！\n");
  }
}