#include <stdio.h>
#include <stdlib.h>

#define COLUMN_MAX 100
#define BASE 10

void show_data(int *src, int count)
{
    for(int i = 0; i < count; i++)
    {
        if(i != 0) printf(" ");
        printf("%d", src[i]);
    }
    printf("\n");
}

void radix_sort(int *src, int count, int order)
{
    static int buf[BASE][COLUMN_MAX];
    int num[BASE];
    int idx = 0;

    // 初期化
    for(int i = 0; i < BASE; i++){num[i] = 0;}
    
    // バケツに入れる
    for(int i = 0; i < count; i++)
    {
        int n = src[i];
        int k = (n / order) % BASE;
        buf[k][num[k]++] = n;
    }
    
    // データをコピー
    for(int k = 0; k < BASE; k++)
    {
        for(int n = 0; n < num[k]; n++)
        {
            src[idx++] = buf[k][n];
        }
    }
}

int main(int argc, char *argv[]) 
{
    char str[9];
    int src[COLUMN_MAX];
    int count = 0;
    
    // データの読み込み
    while(fgets(str, sizeof(str), stdin)){
        src[count++] = atoi(str);
    }
    
    // 入力データの表示
    show_data(src, count);

    // 整列
    radix_sort(src, count, 1);
    show_data(src, count);
    radix_sort(src, count, BASE);
    show_data(src, count);
    radix_sort(src, count, BASE*BASE);
    show_data(src, count);
    
    return 0;
}
