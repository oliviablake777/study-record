#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>

#define MAXSIZE 50 
#define DATA_FILE_PATH "E:\\gdpdata.txt" 

// 省市 GDP 信息结构体
typedef struct {
    char province[10]; 
    float gdp;         
} KeyType;

// GDP 表结构体
typedef struct {
    KeyType R[MAXSIZE]; 
    int length;         
} GDPTable;


// 函数声明
void displayMenu();
void read_char(const char filename[], GDPTable* L);
void displayOriginalData(const GDPTable* L);
void DPQuickSort(KeyType* arr, int left, int right);
void swap(KeyType* a, KeyType* b);
void displaySortedData(const GDPTable* L);
void runSystem(GDPTable* L);


/*
  从文件读取各省市 GDP 数据到 GDPTable 结构体中。
  filename 文件路径字符串
  L 指向 GDPTable 结构体的指针
 */
void read_char(const char filename[], GDPTable* L) {
    FILE* fp;
    // 使用 "r" 模式打开文件进行读取
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("错误：无法打开文件 %s 或文件不存在。\n", filename);
        // 确保文件指针为 NULL
        fp = NULL;
        L->length = 0; // 长度设为0
        return;
    }

    L->length = 0;

    // 按行读取数据，直到文件末尾或达到最大存储容量
    while (L->length < MAXSIZE &&fscanf(fp, "%s %f", L->R[L->length].province, &L->R[L->length].gdp) == 2) {
        L->length++;
    }

    fclose(fp); // 关闭文件
    printf("文件导入成功 (来自: %s)！共导入 %d 条记录。\n", filename, L->length);
}



// 菜单显示函数
void displayMenu() {
    printf("\n");
    printf("**********************************************\n");
    printf("* —— 全国各省市GDP排名系统 ——           *\n");
    printf("* *\n");
    printf("* 1: 数据导入                    *\n");
    printf("* 2: 原始数据                    *\n");
    printf("* 3: GDP排名                     *\n");
    printf("* 0: 系统退出                    *\n");
    printf("* *\n");
    printf("**********************************************\n");
    printf("请根据菜单提示输入选项 (0-3): ");
}


// 显示原始数据函数
void displayOriginalData(const GDPTable* L) {
    if (L->length == 0) {
        printf("警告：当前无数据，请先执行 '1: 数据导入'。\n");
        return;
    }
    printf("\n--- 原始数据列表 (单位：亿元) ---\n");
    printf("--------------------------------\n");
    for (int i = 0; i < L->length; i++) {
        // %-10s 用于左对齐省市名称
        printf("%-10s: %.2f\n", L->R[i].province, L->R[i].gdp);
    }
    printf("--------------------------------\n");
}


// 数据元素交换函数
void swap(KeyType* a, KeyType* b) {
    KeyType temp = *a;
    *a = *b;
    *b = temp;
}


/*
 使用双轴快排算法对 GDP 数据进行降序排序。
 arr 待排序的 KeyType 数组
 left 待排序区间的起始下标
 right 待排序区间的结束下标
 */
void DPQuickSort(KeyType* arr, int left, int right) {
    if (left < right) {
        // 选轴并确保 pivot1 <= pivot2
        float pivot1 = arr[left].gdp;
        float pivot2 = arr[right].gdp;

        // 选择小的元素作为 pivot1，大的作为 pivot2
        if (pivot1 < pivot2) {
            swap(&arr[left], &arr[right]);
            pivot1 = arr[left].gdp;
            pivot2 = arr[right].gdp;
        }

        int lower = left + 1;
        int upper = right - 1;
        int index = left + 1;

        // 3. 划分过程
        // 待考察区间为 [index, upper]
        while (index <= upper) {
            // 区间 1: < pivot1
            if (arr[index].gdp > pivot1) {
                swap(&arr[index], &arr[lower]);
                lower++;
                index++;
            }
            // 区间 3: > pivot2
            else if (arr[index].gdp < pivot2) {
                swap(&arr[index], &arr[upper]);
                upper--;
            }
            // 区间 2: >= pivot1 && <= pivot2
            else {
                index++;
            }
        }

        // 放置 pivot1 和 pivot2
        swap(&arr[left], &arr[lower] - 1);  // 放置 pivot1
        swap(&arr[right], &arr[upper] + 1); // 放置 pivot2

        // 递归排序三个子区间
        DPQuickSort(arr, left, lower - 2);   // 递归左边的部分
        DPQuickSort(arr, upper + 2, right);  // 递归右边的部分

        // 如果 pivot1 != pivot2，可以继续对中间的部分排序
        if (pivot1 != pivot2) {
            DPQuickSort(arr, lower, upper);
        }
    }
}

// 显示排序后数据函数
void displaySortedData(const GDPTable* L) {
    if (L->length == 0) {
        printf("警告：当前无数据，请先执行 '1: 数据导入'。\n");
        return;
    }

    // 复制原始数据，对副本进行排序，不改变原始数据的顺序
    GDPTable sortedL = *L;

    // 执行双轴快排
    // 排序范围是 R[0] 到 R[length-1]
    DPQuickSort(sortedL.R, 0, sortedL.length - 1);

    printf("\n--- GDP 排名结果 (单位：亿元) ---\n");
    printf("排名 | 省市名称   | GDP (亿元)\n");
    printf("-----|------------|-------------\n");
    for (int i = 0; i < sortedL.length; i++) {
        // %-4d 排名，%-10s 省市名称，%.2f GDP
        printf("%-4d | %-10s | %.2f\n", i + 1, sortedL.R[i].province, sortedL.R[i].gdp);
    }
    printf("--------------------------------\n");
}


// 系统运行主逻辑
void runSystem(GDPTable* L) {
    int choice;
    do {
        displayMenu();
        // 确保输入的是整数
        if (scanf("%d", &choice) != 1) {
            // 清空输入缓冲区中的非法字符
            while (getchar() != '\n');
            choice = -1; // 设置一个非法值重新循环
            printf("输入无效，请输入数字 0 到 3。\n");
            continue;
        }

        switch (choice) {
        case 1:
            // 1: 数据导入
            read_char(DATA_FILE_PATH, L);
            break;
        case 2:
            // 2: 原始数据
            displayOriginalData(L);
            break;
        case 3:
            // 3: GDP排名
            displaySortedData(L);
            break;
        case 0:
            // 0: 系统退出
            printf("感谢使用，系统已退出。\n");
            break;
        default:
            printf("无效选项，请输入 0 到 3 之间的数字。\n");
            break;
        }
    } while (choice != 0);
}


// 主函数
int main() {
    //设置控制台输入输出编码为UTF-8
    
     // 初始化 GDPTable 结构体
    GDPTable L;
    L.length = 0; // 初始时数据长度为 0

    runSystem(&L);

    // 等待用户按键，防止窗口立即关闭 (仅在非 IDE 环境中可能需要)
    // printf("\n按任意键退出...");
    // getchar(); 
    // getchar(); // 吸收上一个输入留下的换行符
    return 0;
}