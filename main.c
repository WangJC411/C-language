#include <stdio.h>
#include <stdlib.h>

int main()
{


    //Ӌ��n���A��

    int num=0;
    long long sum=1;
    printf("input a number:");
    scanf("%d",&num);
    for(int i = num; i>0; --i)
    {
        sum = sum * i;
    }
    printf("%d! = %d\n",num,sum);


//--------------------------------------------------------------------------


    //Ӌ��1!+2!+3!+4!+5!+6!+7!+8!+9!+10!
    int total = 1;
    sum = 0;

    //����һ�������^������ķ�����
    for(int j=1; j<=10; ++j)
    {
        total = 1; //��Ҫ��Ӌ��΂������A��֮ǰҪ�ȳ�ʼ��total����Ȼ����֮ǰ��total�����
        for(int i=j; i>0; --i)
        {

            total = total * i;
        }
        sum = total+sum;
    }
    printf("1!+2!+3!+4!+5!+6!+7!+8!+9!+10! = %d\n",sum);

    //�������������a���^�����ķ�����
    total = 1;
    sum = 0;
    for(int i = 1; i<=10; ++i)
    {
        total = total * i;  //����׃total�ĽY����ÿ�����ϳ�һ�����ߵĔ���������һ�������A��
        sum = total + sum;
    }
    printf("1!+2!+3!+4!+5!+6!+7!+8!+9!+10! = %d\n",sum);

//---------------------------------------------------------------------------------

    //��һ������Ĕ��M�e���ҵ���Ҫ��ֵ

    //����һ�������^�����ķ�����
    const int arr[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int target = 0,flag = 0;
    printf("input the number what you find:");
    scanf("%d",&target);

    const int size = sizeof(arr)/sizeof(arr[0]);  //sizeof����׃���ăȴ��С�����M���ăȴ��С���Ԇ΂����M�ăȴ��С��추��M����
    printf("size = %d\n",size);
    for(; flag<size; ++flag)
    {
        if(arr[flag] == target)
        {
            printf("�ҵ�����%d��λ����%d\n",target,flag);
            break;
        }
    }
    if(flag == size)   //�Ҳ�������r�����������ᶼ�Ҳ������tflagһ�������size
    {
        printf("�]���������Ĕ��֣�\n");
    }


    //�����������ֲ����㷨����ÿ�����M�����g�_ʼ�ң�Ȼ�ᰴ�մ�С�ٌ�����,ǰ���ǔ��M�������
    flag = 0;
    int start = 0,end = size-1;
    flag = (end+start)/2;
    while(arr[flag] != target)
    {
        if(arr[flag] > target)
        {
            end = flag;
            flag = (end + start)/2;
        }
        else if(arr[flag] < target)
        {
            start = flag;
            flag = (end + start)/2+1; //+1�Ǟ��˱���start=12,end=13�r��һֱ��ѭ�h
        }
        if(start == end)
        {
            printf("�]���������Ĕ���!\n");
            break;
        }

    }
    if(arr[flag] == target)
    {
        printf("�ҵ�����%d��λ����%d\n",target,flag);
    }


//-------------------------------------------------------------------------

    //һ�_ʼ�ǵڶ����ַ�����Ȼ���_ʼ�@ʾ�^һ��βһ�������^����β����ֱ��ȫ���@ʾ��
    //QYZ wo bu xiang zai ai ni le !!!!!!!
    //************************************
    char target1[] = "QYZ wo bu xiang zai ai ni le !!!!!!!!!";
    char shield[] = "**************************************";
    int size1 = sizeof(target1)/sizeof(target1[0]);
    printf("size1 = %d\n",size1);
    end = size1 - 2;  //�p2������ַ���������һ��\n������Ҫ�~����pһ��
    start = 0;
    do
    {
        printf("shield = %s\n",shield);
        shield[start] = target1[start];
        shield[end] = target1[end];
        start++;
        end--;
    }
    while(start <= end+2);  //��2��Ŀ����ѭ�h�������xֵ��++��--�����Ԯ�size1��even�r�������g��ֵ������ȡ��
    //////////////////////////������ĳ���++��--���xֵ��Ԓ����һ��ֵ������һ��ֵ�͛]�k����ȡ��


//------------------------------------------------------------------------------------------------


    //  ֻ��ݔ�������ܴa���������ʧ�����tֹͣ���
    //  " == " ���ܱ��^�ɂ��ַ����Ƿ���ȣ�Ҫ��һ������strcmp

    char password1[] = "123456789",password2[20]= {0}; //password2�@�NҪݔ����ַ���Ҫ�ȳ�ʼ��һ��
    for(int a=0; a<3; a++)
    {
        printf("input your password:");
        scanf("%s",&password2);
        if (strcmp(password1,password2) == 0)
        {
            printf("��䛳ɹ���\n");
            break;
        }
        if(a == 2)
        {
            printf("���ʧ����\n");
        }


    }


//----------------------------------------------------------
//�ҳ�100~200֮�g���ؔ�
//
    int r=0,s=0,count = 0;
    for (r=100; r<=200; ++r)
    {
        for(s=2; s<r; ++s)
        {
            if(r%s == 0)
            {
                break;
            }

        }
        if(s == r)
        {
            printf("%d ",r);
            count++;

        }
    }

    printf("\ncount = %d\n",count);

//����Ĵ��a������⣬����߀���ԏĔ��W�����M�Ѓ���
//���磺even�����ܞ��ؔ�������ֱ�Ӱ�r++�ĳ�r+=2��r��101���l
//s����׃��С춵�춸�̖r���������й��s����һ������һ��С춵�춸�̖r��һ����춵�춸�̖r

    r = 0;
    s = 0;
    count = 0;
    for (r=101; r<=200; r+=2)
    {
        for(s=2; s<=sqrt(r); ++s)
        {
            if(r%s == 0)
            {
                break;
            }

        }
        if(s > sqrt(r))
        {
            printf("%d ",r);
            count++;

        }
    }

    printf("\ncount = %d\n",count);


    return 0;
}
