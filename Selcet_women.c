
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

int main()
{
    //printf("%d",5);
  //  PlaySound(TEXT("sounds\\"));
    char myname[20];

    char names[6][20] = {"����","����","���Ѿ�","��ʩ","��֪����"};
    char level[5][10] = {"����","����","����","�ʹ���","�ʺ�"};
    int levels[] = {1,2,0,3,0,-1};
    int love[] = {90,58,80,95,45,-1};

    int count = 5;

    char TempName[20];
    int Temp = -1;
    // int SearchTemp = -1;

    int choice,i,j;

    printf("�������������֣�");
    scanf("%s",myname);
    printf("1ѡ��\t����\n");printf("2����\t�޸�\n");
    printf("3����\tɾ��\n");printf("4�ټ�\t����\n");
    
    // for(i=0;i<count;i++)
    // {
    //     printf("%s\t%s\t%d\n",names[i],level[levels[i]],love[i]);
    // } 


    while (1)
    {
        printf("��ѡ��");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                if(count<6)
                {
                    printf("����ѡ���ˣ�\n");
                    count++;
                    printf("��������������֣�");
                    scanf("%s",&names[count-1]);
                    levels[count-1] = 0;
                    love[count-1] = 100;
                    for(i=0;i<count;i++)
                    {
                        printf("%s\t%s\t%d\n",names[i],level[levels[i]],love[i]);
                    } 
                }
                else
                {
                    printf("��װ�����ˣ����ϣ�\n");
                }
                break;
            case 2:
                printf("�����ټ���\n");
                printf("��������������֣�");
                scanf("%s",TempName);
                for ( i = 0; i < count; i++)
                {
                    if(!strcmp(TempName,names[i]))
                    {
                        Temp = i;
                    }
                    else
                    {
                        love[i] = love[i]<0? 0 : love[i]-10;
                    }
                }
                if(Temp != -1)
                {
                    printf("��ϲ��������%s����������\n",names[Temp]);
                    levels[Temp] = levels[Temp]>=4? 4 : levels[Temp]+1;
                    love[Temp] += 10;
                    Temp = -1;
                }
                else
                {
                    printf("���£���û�н�%s�����ӣ�\n",TempName);
                    Temp = -1;
                }
                    
                for(i=0;i<count;i++)
                {
                    printf("%s\t%s\t%d\n",names[i],level[levels[i]],love[i]);
                } 
                break;
            case 3:
                printf("��ѡ��Ҫ�����乬����������֣�");
                scanf("%s",TempName);
                for( i = 0;i < count; i++)
                {
                    if(!strcmp(TempName,names[i]))
                    {
                        Temp = i;
                        break;
                    }
                }
                if(Temp != -1)
                {
                    for ( i = Temp; i < count-1; i++)
                    {
                        strcpy(names[i],names[i+1]);
                        levels[i] = levels[i+1];
                        love[i] = love[i+1];
                    }
                    count--;
                }
                else
                {
                    printf("�龪һ����\n");
                }
                for(i=0;i<count;i++)
                {
                    printf("%s\t%s\t%d\n",names[i],level[levels[i]],love[i]);
                } 
                break;
            default:
                break; 
        }
        for ( i = 0; i < count - 1; i++)
        {
            for ( j = 0; j < count - 1 -i; j++)
            {
                if(levels[j] < levels[j+1])
                {
                    Temp = levels[j];
                    levels[j] = levels[j+1];
                    levels[j+1] = Temp;
                    strcpy(TempName,names[j]);
                    strcpy(names[j],names[j+1]);
                    strcpy(names[j+1],TempName);
                    Temp = love[j];
                    love[j] = love[j+1];
                    love[j+1] = Temp;
                }
                
                }
                
        }
        printf("\n");
        for(i=0;i<count;i++)
        {
            printf("%s\t%s\t%d\n",names[i],level[levels[i]],love[i]);
        }
    }
    

    
    system("pause");
    return 0;

}