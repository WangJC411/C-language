#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int menu();  //����һ������
void game();
int main()
{

//Ӌ��1~100֮�g����9�Ĕ���
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
//���ֵ��[��
//2��Ҫ��
//1 ��һ���[�����ˆΣ��e�����_ʼ�[��ͽY���[��Ĺ���
//2 �[����,��1~100֮�g�Ĕ��֣��ṩ�´���߲�С����ʾ��


    int a;


    do
    {
        a = menu();
        if(a == 1)
        {
            printf("�[���_ʼ��\n");
            game();

        }
        else if(a == 2)
        {
            printf("�[��Y����\n");
            break;
        }
        else
        {
            printf("ݔ���e�`��Ո����ݔ��...\n");

        }
    }
    while(1);


    return 0;
}


//-------------����ʽ-----------------

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
        printf("input a number��");
        scanf("%d",&input);
        if (input > result){
            printf("�´��ˣ�\n");
        }
        else if(input < result){
            printf("��С�ˣ�\n");
        }
        else{
            printf("���ˣ�\n");
            break;
        }
    }
}
