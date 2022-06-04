#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int prime(int);
int search(int arr3[],int,int);
void print(int n);
int cal(char*);
int cal1(char* str);
int fib1(int n);
int fib2(int n);

int main()
{

// strcpy����   �ַ����}�u
// strcpy(arr1,arr2);  ��arr2�e���ַ����}�u��arr1�e��ȥ
    printf("---strcpy---\n");
    char arr1[20] = "qwertyui";
    char arr2[20] = "asdfghjk";
    printf("�}�uǰ��\narr1 = %s\narr2 = %s\n",arr1,arr2);
    strcpy(arr1,arr2);
    printf("�}�u�᣺\narr1 = %s\narr2 = %s\n",arr1,arr2);


// memset����   �O�Ãȴ�ǰ��Ĳ��փ���
// memset(arr1,'*',5);   ��arr1ǰ��5���ַ��ĳ�*
    printf("---memset---\n");
    memset(arr1,'*',5);
    printf("arr1 = %s\n",arr1);


//�Զ��x����
//�������{��
//��ֵ�{�ã��������΅��͌����քe���в�ͬ�ăȴ�K�����΅����޸Ĳ���Ӱ푌���
//��ַ�{�ã��Ѻ����ⲿ����׃���ăȴ��ַ���f�o�������@�N������ʽ����׌�����ͺ�����߅��׃���������������M��Ҳ���Ǻ����Ȳ�ֱ�ӿ��Բ��������ⲿ��׃��

//�ú�������100~200֮�g���ؔ�

    int i = 0,count = 0;
    for(i=100; i<=200; ++i)
    {
        if(prime(i) == 1)
        {
            printf("%d ",i);
            count += 1;
        }
    }
    printf("\ncount = %d\n",count);


//�ú������Ҕ��M�e��ָ�����֣����ַ���
    int arr3[] = {1,2,3,4,5,6,7,8,9,10};
    int target = 0,size = 0,result = 0;
    size = sizeof(arr3)/sizeof(arr3[0]);
    printf("input a target:");
    scanf("%d",&target);
    result = search(arr3,target,size);
    if(result == -1)
    {
        printf("�]�ҵ�ָ���Ĕ���\n");
    }
    else
    {
        printf("�ҵ�ָ�����֣��˞�%d\n",result);
    }




//�f�w
//�f�w�������Ɨl�������M���@�����Ɨl���ĕr���f�w�㲻���^�m
//ÿ���f�w�{��֮��Խ��Խ�ӽ��@�����Ɨl��


//�ú������f�w����һ����λ���������һ��һ��ݔ������

    int num = 0;
    printf("input a number:");
    scanf("%d",&num);
    print(num);
    printf("\n");



//�Լ���һ����ʽ������strlen������
    char str[20] = "asfgsgenrszsgthsgee";
    int len=0;
    len = cal(str);
    printf("len = %d\n",len);

//�����f�w�ķ���
    len = cal1(str);
    printf("len = %d\n",len);




//쳲���������Ӌ��

//���f�w�ķ�ʽ����Ԓ���^45�͕�׃�úܛ]��Ч�ʣ������@�����m�����f�w�ķ���ȥ��
    int n1;
    scanf("%d",&n1);
    int result2 = fib1(n1);
    printf("쳲���������result = %d\n",result2);

//��ѭ�h�ķ���ȥ���ٶȕ����^��

    result2 = fib2(n1);
    printf("�Ʋ����Д���result = %d\n",result2);





    return 0;
}


//----------����ʽ-----------


int prime(int n)
{
    int a = 0;
    for(a = 2; a<=sqrt(n); ++a)
    {
        if(n%a==0)
        {
            break;
        }
    }
    if(a > sqrt(n))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int search(int arr3[],int target,int size)
{
    int flag = 0,start = 0,end = size-1 ;
    flag = (start + end)/2;

    while(start <= end)
    {
        if(arr3[flag]<target)
        {
            start = flag+1;
            flag = (start+end)/2;
        }
        else if(arr3[flag]>target)
        {
            end = flag-1;
            flag = (start+end)/2;
        }
        else
        {
            return flag;
        }

    }
    return -1;
}

void print(int n)
{
    if(n>9)
    {
        print(n/10);
        printf("%d ",n%10);
    }
    else
    {
        printf("%d ",n);
    }

}

int cal(char* str)  //�ַ�������ĕr���ǂ������ַ��ĵ�ַ������Ҫ��char*����
{
    int len = 0;
    while(*str != '\0')   // �Д�*str��һ����ĸ�ǲ��ǽY����
    {
        len++;
        str++;   //��ַ+1���ǰ�ԭ�����ַ��ĵ�ַ׃�ɵڶ����ַ��ĵ�ַ
    }
    return len;

}


int cal1(char* str)  // �@�N�������Բ���������׃��
{
    if(*str != '\0')
    {
        return 1+cal1(str+1);
    }
    else
    {
        return 0;
    }
}


int fib1(int n)
{

    if(n>2)
    {
        return fib1(n-1)+fib1(n-2);
    }
    else
    {
        return 1;
    }
}


int fib2(int n)
{

    int i = 1,j = 1,k = 1;
    while(n>2){
        k = i+j;
        i = j;
        j = k;
        n--;
    }
    return k;

}
