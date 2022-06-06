#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0x11223344;//16進制數
    //指針變量也有類型，他們佔用的字節數相同在32位裡面是4個字節，在64位裡面是8個字節
    //不同類型的指針變量的區別：
    int* pi = &a;
    char* pc = &a;
    *pi = 0xAA000011;
    printf("更改pi：%x\n",a);//輸出結果：aa000011 把原本的a改成了想要的值
    a = 0x11223344;
    *pc = 0xAA000022;
    printf("更改pc：%x\n",a);//輸出結果：11223322 只是改變了最後兩位的值

    printf("pi:%p\n",pi);//輸出結果：000000000061FE0C
    printf("pi+1:%p\n",pi+1);//輸出結果：000000000061FE10   （+4）
    printf("pc:%p\n",pc);//輸出結果：000000000061FE0C
    printf("pc+1:%p\n",pc+1);//輸出結果：000000000061FE0D   （+1）

//總結：
//1. 指針類型決定了指針進行解引用操作的時候，能夠訪問空間的大小
//int* p 能夠訪問4個字節
//char* p 能夠訪問1個字節
//double* p 能夠訪問8個字節
//2. 指針類型決定了指針步長


//野指針概念
//1. 如果指針在宣告的時候沒有初始化，那它就會隨機尋找一個空間，這個動作的非法的
//如果不知道初始化成什麼，可以初始化為NULL
//2. 如果在變量生命週期結束前定義的指針，在變量生命結束後就會變成野指針
//3. 指針越界後也會變成野指針



//利用指針來對數組進行操作

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = arr;  //單純一個數組名代表數組第一個元素的地址
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i<size; ++i)
    {
        printf("%d ",*p);
        p++;
    }
    printf("\n");
//指針減去指針得到的是指針之間的元素個數，但是一般會用在一個數組裡
//如果是不同數組的指針相減，則結果就不可預測

    int *p1 = &arr[0],*p2 = &arr[7];
    printf("p2-p1:%d\n",p2-p1);


//注意：允許指向數組元素的指針與指向數組最後一個元素後面的那個內存的指針比較
//但不允許與指向第一個元素之前的那個內存位置的指針進行比較
//說人話就是能在數組內存後面的位置溢出，但是不能在數組內存前面的位置溢出
//所以比較推薦使用方法一，因為方法二在最後一個循環結束後會去比較數組內存前面的位置
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int *vp = &arr1[size];
//方法一：
    printf("方法一：");
    for(vp = &arr1[size]; vp>&arr1[0];)
    {
        *--vp = 1;
    }
//打印結果
    for(int i=0; i<size; ++i)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");

//方法二：
    printf("方法二：");
    for(vp = &arr1[size]; vp>=&arr1[0]; vp--)
    {
        *vp=2;
    }
//打印結果
    for(int i=0; i<size; ++i)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");


//二級指針
    a = 10;
    int *pp1 = &a;  //一級指針
    int **pp2 = &pp1;  //二級指針
//二級指針存放的是一級指針的地址
printf("pp2  :%p\n",pp2);
printf("*pp2 :%p\n",*pp2);
printf("**pp2:%d\n",**pp2);


//指針數組
//存放指針的數組
int b = 20,c = 30;
int *arr2[3] = {&a,&b,&c};
for(int i=0;i<3;i++){
    printf("%d ",*arr2[i]);
}
printf("\n");






    return 0;
}
