#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

// 清空输入缓冲区直到换行或 EOF（避免 EOF 时死循环）
static void clear_input(void){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main(){
    system("chcp 65001>nu1");            // 设置控制台为UTF-8编码
    setlocale(LC_ALL, "zh_CN.UTF-8");
    srand((unsigned int)time(NULL));
    int a = rand() % 100 + 1, b, c = 0;
    char y;

    // debug:
    // printf("%d\n", a);  

    // 游戏开始提示
    while (1){
        printf("按y开始:");
        if(scanf(" %c", &y) == 1 && y == 'y' && getchar() ==  '\n')
            break;
        printf("输入错误\n");
        clear_input();                   // 清除输入缓冲区中的换行符
    }

    do{
        printf("请输入一个整数:");
        if (scanf("%d", &b) != 1){
            printf("输入错误,请输入一个整数\n");
            clear_input();               // 清除输入缓冲区中的换行符
            continue;
        }
        if (b < 1 || b > 100){
            printf("输入错误,请输入1-100之间的整数\n");
            clear_input();               // 清除输入缓冲区中的换行符
            continue;
        }
        if (b > a)
            printf(b - a <= 3 ? "大了,快接近了\t" : "猜大了\t");
        else if (b < a)
            printf(a - b <= 3 ? "小了,快接近了\t" : "猜小了\t");
        else{
            printf("恭喜你，猜对了！\n");
            break;
        }
        if (++c >= 5){
            printf("你已经猜了5次了,游戏结束!\n");
            printf("答案是：%d\n", a);
            break;
        }
        printf("你已经猜了%d次了,还剩%d次机会\n", c, 5 - c);
    } while (1);
    return 0;
}

// Powered by DeepSeek V4 Flash
// 幽默的是，在上一行注释中，d4f将其补全为ChatGPT，似乎它也不承认这是它写的。
