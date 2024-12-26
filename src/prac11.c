// prac11.c
#include "common.h"
#include "menu.h"
#include "file.h"

SystemInfo systemInfo;
Student *students; // 动态分配的数组
int studentCount;

void DisplayInitialMenu()
{
  printf("从哪里加载数据？\n");
  printf("1. 使用默认数据源\n");
  printf("2. 使用指定数据源\n");
  printf("请输入序号>> ");
}

int main()
{
  int choice;
  do
  {
    DisplayInitialMenu();
    scanf("%d", &choice);

    if (choice == 1)
    {
      if (IsDataExists())
      {
        if(LoadData(&systemInfo, &students, &studentCount, FILE_NAME)) {
          break;
        } else {
          printf("数据加载失败，请重新选择。\n");
        }
      } else {
        break;
      }
    }
    else if (choice == 2)
    {
      char fileName[100];
      printf("请输入文件名: ");
      scanf("%s", fileName);
      if (IsDataExists())
      {
        LoadData(&systemInfo, &students, &studentCount, fileName);
        break;
      }
      else
      {
        printf("文件不存在，请重新输入。\n");
      }
    }
    else
    {
      printf("无效选择，请重新输入。\n");
    }
  } while (1);

  while (1)
  {
    Menu();
  }
}
