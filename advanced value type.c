#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    //大端存儲和小端存儲
    //大端存儲模式：是指數據的低位保存在內存的高地址中，而數據的高位保存在內存的低地址中
    //小端存儲模式：是指數據的低位保存在內存的低地址中，而數據的高位保存在內存的高地址中
    int a = 255;  // 在記憶體的存儲形式為：0a 00 00 00
    //10的二進位形式為0000 0000 0000 1010，也就是00 00 00 0a （從左往右由高到低）
    //但是實際存放的形式是0a 00 00 00，所以這種是大端存儲模式

//寫一個程式，判斷字節序的大端還是小端


    char *p = &a;//只要a<128就可以正確判斷
    if(*p == a)
    {
        printf("大端\n");
    }
    else
    {
        printf("小端\n");
    }



//求以下程式的輸出結果
    char a1 = -1;
    signed char a2 = -1;
    unsigned char a3 = -1;
    printf("int a1:%d\nint a2:%d\nint a3:%d\n",a1,a2,a3);

//解釋：

//原碼：最高位是正負值，其他是正常二進制數（正是0，負是1）
//反碼：把原碼最高位（符號位）不變，其他位按位取反
//補碼：反碼+1得到補碼
//例如：
//原碼---> 1000 0000 0000 0000 0000 0000 1110
//反碼---> 1111 1111 1111 1111 1111 1111 0001
//補碼---> 1111 1111 1111 1111 1111 1111 0010
//補碼是在電腦裡面的存放的形式
//正數的原碼就是補碼，負數才要進行上面的計算

//整數-1在記憶體中儲存形式為1111 1111 1111 1111 1111 1111 1111 1111
//因為char本身只有1個字節，所以在儲存-1（補碼）時，是以1111 1111的形式,只取最後8位，前面的丟掉
//同理signed char和unsigned char也是一樣
//雖然儲存在記憶體中的（補碼）形式相同，但是在打印成整數時（解碼）時過程不同
//char和signed char是在前面補符號位（這裡的符號位為1），11111111111111111111111111111111
//但是unsigned char因為本身沒有符號位，所以補0，也就是00000000000000000000000011111111
//最後翻譯成原碼的結果為 -1  -1  255  （最後一個如果以%d形式打印的話，第一位就是符號位（0）所以原碼和補碼相同）

    char b = -128;
    printf("unsigned int b = %u\n",b);
//解釋：
//整數-128 原碼 1000 0000 0000 0000 0000 0000 1000 0000
//在記憶體中儲存形式為 1111 1111 1111 1111 1111 1111 1000 0000
//存儲到char裡面為 1000 0000
//在以%u形式讀取時，先要用整形提升，也就是用符號位補齊前面的位置
//結果為 1111 1111 1111 1111 1111 1111 1000 0000
//如果是%d的話還要進行解碼操作，但是這裡是以%u的形式，所以最高位不是符號位，它本身就會被認為是一個正數
//所以直接把 1111 1111 1111 1111 1111 1111 1000 0000打印出來（十進制為4,294,967,168）



    /*
    unsigned int c;
    for(c = 9;c>=0;c--){
        printf("%u\n",c);
        Sleep(500);
    }
    */

//解釋：
//輸出結果為9 8 7 6 5 4 3 2 1 0 4294967295 4294967294...
//因為c是unsigned int類型，所以在0之後再減1會變成4294967295
//unsigned int的值永遠大於等於0，所以會進入死循環




    char arr[1000];
    for(int i = 0; i<1000; i++)
    {
        arr[i] = -1-i;
    }
    printf("strlen of arr = %d\n",strlen(arr));


//解釋：
//strlen是去找到\0的位置，如果在字符串中有一個值為0，則strlen只會找到那個位置之前的長度
//arr從-1(-1-0)開始
//1111 1111  -->  -1
//1111 1110
//1111 1101
//...
//1000 0000  -->  -128
//0111 1111  -->  127
//0111 1110
//...
//0000 0001
//0000 0000  -->  0
//到0結束
//所以字符串長度是128+127=255
//



//浮點數の存儲
//浮點數存儲是以(-1)^s * M * 2^E 的形式
//如果是正數，s = 0，如果是負數 s = 1
//M是把浮點數改成二進制數並移動至[1,2)範圍裡後小數點後面的數
//E是浮點數改成二進制數並移動至[1,2)範圍裡時移動的位數,但是！！！
//E為unsigned類型，範圍在0-255，但是在實際儲存時，E會等於原本的數+127
//在32位記憶體中第1位是s（共1位），第2-9位是E（共8位），第10-32位是M（共23位）
//在64位記憶體中第1位是s（共1位），第2-12位是E（共11位），第13-64位是M（共52位）
//具體看以下例子

    float e = 5.5;
//先把小數點前的整數轉成二進制5 --> 101
//再轉小數點後的數  0.5 --> 0.1(這邊的0.1是指2^-1,並不是真的0.1)
//合起來是101.1
//然後移動到[1,2)範圍裡  --> 1.011*2^2
//改成(-1)^s * M * 2^E 的形式的話就是：(-1)^0*1.011*2^(2+127)
//s = 0 , M = 0110 0000 0000 0000 0000 000 , E = 1000 0001   (共32位)
//在記憶體中存放的順序為s-E-M
//也就是0100 0000 1011 0000 0000 0000 0000 0000
//顯示在記憶體中為16進制也就是 40 b0 00 00
//大端存儲的話就是00 00 b0 40


int f = 9;
float *pfloat = (float*)&f;
printf("int f = %d\n",f);
printf("float* pfloat = %f\n",*pfloat);
*pfloat = 9.0;
printf("int f = %d\n",f);
printf("float* pfloat = %f\n",*pfloat);


//解釋：
//int f = 9 在記憶體中儲存的形式為 0000 0000 0000 0000 0000 0000 0000 1001
//如果以float的形式解碼的話就是 0 0000 0000 0000 0000 0000 0000 0001 001
//也就是s = 0 E = 0 M = 0000 0000 0000 0000 0001 001
//這裡的E是-127+127的結果，所以本身應該是2^-127
//所以這個數字非常小，用浮點數表示就是0.000000，也就是printf("float* pfloat = %f\n",*pfloat);的結果
//
//經過*pfloat = 9.0;之後，儲存在f中的數字發生了改變，變成了9.0以浮點數的形式儲存
//9.0 --> 1001.0 --> 1.001*2^3
//s = 0 , E = 3+127（1000 0010） , M = 001 0000 0000 0000 0000 0000
//也就是0100 0001 0001 0000 0000 0000 0000 0000
//以十進制形式打印就是1,091,567,616




















    return 0;
}
