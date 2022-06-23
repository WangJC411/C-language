#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{

    //strlen
    //strlen 就是在找字符串中的\0，如果没找到，就一直往下找，求找到的\0后的长度
    int length = strlen("abcdef");  //这变得length等于6，常量字符串的后面会跟一个\0
    printf("strlen abcdef = %d\n",length);
    char arr[] = {'a','b','c'};
    length = strlen(arr);   //这边的length应该是一个随机值，因为在arr后面不知道什么时候能够找到\0
    printf("strlen arr = %d\n",length);

    //尝试写一个自定义的strlen函数（之前的讲义里面有）


    //做一个有坑的小题目

    if(strlen("ABC")-strlen("ABCDEF")>0)
    {
        printf("result = 1\n");
    }
    else
    {
        printf("result = 2\n");
    }

    //问上面的代码打印的值为1还是为2
    //解释：
    //上述的代码打印的为1
    //因为strlen函数的返回类型为unsigned int，当两个无符号数相减时，得到的还是一个无符号数
    //所以即使是短的字符串减去长的字符串，得到的还是正数



    //strcpy
    //strcpy可以进行字符串复制
    char arr1[] = "abcdef";
    char arr2[] = "wang";
    strcpy(arr1,arr2);//把arr2里面的字符串复制到arr1里面去
    printf("strcpy arr1 = %s\n",arr1);

    //尝试写一个自定义的strcpy函数



    //strcat
    //strcat可以在一个字符串后面(\0)再追加一个字符串
    //但是不能自己给自己追加
    char arr3[] = "hello ";
    char arr4[] = "world!";
    strcat(arr3,arr4);//在arr3后面追加arr4
    printf("strcat arr3 = %s\n",arr3);

    //尝试写一个自定义的strcat函数



    //strcmp
    //字符串比较,比较的是字符的ASCII值
    //第一个 > 第二个 -> 1
    //第一个 = 第二个 -> 0
    //第一个 < 第二个 -> -1
    //不同编译器结果不同，但是如果第一个 > 第二个时一定会返回一个大于0的数
    char arr5[] = "sadf";
    char arr6[] = "sawq";
    printf("strcmp %d\n",strcmp(arr5,arr6));

    //尝试写一个自定义的strcmp函数



    //strncpy
    //指定字符数复制，如果复制的字符数达不到要求的数量，就会用\0去补

    //strncat
    //指定字符数追加，在追加完之后会自动在字符串后面补\0，但如果追加的字符数量达不到要求的数量，则不会继续追加（但是\0还是会存在）

    //strncmp
    //指定字符数比较，返回值跟strcmp原理一致



    //strstr
    //查找在字符串中查找指定字符串，如果存在，返回第一次出现的字符串地址，如果不存在，返回NULL
    //如果查找的是\0就会返回首个字符的地址
    char arr7[] = "abcdefghijklmn";
    char arr8[] = "\0";
    printf("strstr %p\n",strstr(arr7,arr8));

    //尝试写一个自定义的strstr函数（有难度）



    //strtok
    //分隔字符串，实际上是把目标字符串中需要分隔的符号换成\0然后再打印字符串
    //所以使用这个函数的话最好是把目标字符串进行复制，否则原本的字符串被更改就找不回来了
    //这个函数还有一个规则：
    //当strtok第一个参数不为NULL时，函数将找到str中第一个分隔符，strtok函数将保存它在字符串中的位置
    //当strtok第二个参数为NULL时，函数将在同一个字符串中被保存的位置开始，查找下一个分隔符
    char arr9[] = "192.161.34.684.796.32";  //目标字符串（要被分隔的字符串）
    char sign[] = ".";   //分隔符
    //这边可以利用for循环的特性，使用strtok
    char arr11[100] = " ";
    strcpy(arr11,arr9);//备份一份，防止原本的字符串丢失
    for(char* ret = strtok(arr11,sign); ret != NULL; ret = strtok(NULL,sign))
    {
        printf("strtok : %s\n",ret);
    }

    //尝试写一个自定义的strtok函数(暂时还没解决）



    //strerror
    //errno是一个全局的错误码变量
    //当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码赋值给errno
    //再把errno丢进strerror函数中，就能得到相应的错误信息。
    printf("strerror : %s",strerror(1));//这边的数字1应该是要写errno，也就是交给编译器去判断有没有错误，如果直接写1的话就是写出错误码1所代表的错误类型
    //这个知道就好，不重要




    return 0;
}
