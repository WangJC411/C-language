#include <stdio.h>
#include <stdlib.h>

int main()
{


// strlen 是求字符串長度，只能針對字符串使用，需要引用頭文件（#include <string.h>）
// sizeof 是計算變量、數組、類型的大小，單位是字節，它屬於操作符

//一維數組
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    for(int i=0; i<size; i++)
    {
        printf("arr1[%d] = %d\n",i,arr1[i]);
    }
    for(int i=0; i<size; i++)
    {
        printf("arr1[%d] = %p\n",i,&arr1[i]); //得到結果一維的數組每個位置的大小是4個字節
    }


//二維數組
//二維數組在定義的時候第一個[]裡面是有幾組一維數組，第二個[]裡面是一個一維數組中有幾個位置
//所以第二個[]中必須要定義數量
    int arr2[][5] = {{1,2,3},{4,5,6},{7,8,9}};//第一組：1,2,3,0,0 第二組：4,5,6,0,0 第三組：7,8,9,0,0
    size = sizeof(arr2[0])/sizeof(arr2[0][0]);
    printf("%d",size);
    printf("\n");




//冒泡排序
/*
假設原本數組為{9,8,7,6,5,4,3,2,1}，需要把數組從小到大排列
步驟為：
{9,8,7,6,5,4,3,2,1}
{8,9,7,6,5,4,3,2,1}
{8,7,9,6,5,4,3,2,1}
{8,7,6,9,5,4,3,2,1}
...
{8,7,6,5,4,3,2,1,9}
...
{7,6,5,4,3,2,1,8,9}
...
{1,2,3,4,5,6,7,8,9}
*/

int arr3[] = {9,8,5,2,3,4,7,1,6,0};
int temp = 0,size1 = sizeof(arr3)/sizeof(arr3[0]),flag = 1;
for(int i = 0;i<size1-1;++i){
    for(int j = 0;j<size1-i-1;++j){
        if(arr3[j]>arr3[j+1]){
            temp = arr3[j];
            arr3[j] = arr3[j+1];
            arr3[j+1] =temp;
            flag = 0;
        }
    }
    if (flag == 1){
        break;
    }
}
printf("冒泡排序：");
for(int i = 0;i<size1;i++){
    printf("%d ",arr3[i]);
}
printf("\n");

//數組名取地址
//特殊情況：
//1、sizeof(數組名)--->計算整個數組的大小
//2、&數組名--->取出的是整個數組的地址(雖然顯示的還是首元素的地址，但是如果+1的話就會變成整個數組之後的地址)
//除了以上兩種情況之外，所有的數組名都表示首元素的地址

printf("(arr)--->%p\n",arr3);
printf("(&arr[0])--->%p\n",&arr3[0]);
printf("(&arr)--->%p\n",&arr3);
printf("(arr+1)--->%p\n",arr3+1);
printf("(&arr[1])--->%p\n",&arr3[1]);
printf("(&arr+1)--->%p\n",&arr3+1);//這個結果就是取整個數組結束之後的地址














    return 0;
}
