#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int menu();  //宣告一個函數
void game();
int main()
{

//計算1~100之間數字9的數量
    int ge = 0,shi = 0, count = 0;
    for (int i = 1; i<=100; ++i)
    {
        if(ge = i%10 == 9)
        {
            count++;
            printf("%d ",i);
        }
        if(shi = i/10 == 9)
        {
            count++;
            printf("%d ",i);
        }

    }
    printf("\ncount = %d\n",count);



//---------------------------------------------------------------
//猜數字的遊戲
//2個要求：
//1 有一個遊戲主菜單，裡面有開始遊戲和結束遊戲的功能
//2 遊戲本身,猜1~100之間的數字（提供猜大或者猜小的提示）


    int a;


    do
    {
        a = menu();
        if(a == 1)
        {
            printf("遊戲開始！\n");
            game();

        }
        else if(a == 2)
        {
            printf("遊戲結束！\n");
            break;
        }
        else
        {
            printf("輸入錯誤！請重新輸入...\n");

        }
    }
    while(1);


    return 0;
}


//-------------副程式-----------------

int menu()
{
    int a=0;
    printf("****************************************************\n");
    printf("************   1 -> play    2 -> exit   ************\n");
    printf("****************************************************\n");
    scanf("%d",&a);
    return a;

}

void game()
{
    int input,result ;
    srand(time(NULL));
    result = rand()%100+1;
    while(1){
        printf("input a number：");
        scanf("%d",&input);
        if (input > result){
            printf("猜大了！\n");
        }
        else if(input < result){
            printf("猜小了！\n");
        }
        else{
            printf("猜對了！\n");
            break;
        }
    }
}
