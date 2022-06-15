
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

    char names[6][20] = {"貂蝉","杨玉环","王昭君","西施","不知火舞"};
    char level[5][10] = {"贵人","嫔妃","贵妃","皇贵妃","皇后"};
    int levels[] = {1,2,0,3,0,-1};
    int love[] = {90,58,80,95,45,-1};

    int count = 5;

    char TempName[20];
    int Temp = -1;
    // int SearchTemp = -1;

    int choice,i,j;

    printf("请输入您的名字：");
    scanf("%s",myname);
    printf("1选妃\t增加\n");printf("2翻牌\t修改\n");
    printf("3抛弃\t删除\n");printf("4召见\t查找\n");
    
    // for(i=0;i<count;i++)
    // {
    //     printf("%s\t%s\t%d\n",names[i],level[levels[i]],love[i]);
    // } 


    while (1)
    {
        printf("请选择：");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                if(count<6)
                {
                    printf("陛下选妃了！\n");
                    count++;
                    printf("请输入娘娘的名字：");
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
                    printf("后宫装不下了，皇上！\n");
                }
                break;
            case 2:
                printf("陛下召见！\n");
                printf("请输入娘娘的名字：");
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
                    printf("恭喜皇上您和%s共度良宵！\n",names[Temp]);
                    levels[Temp] = levels[Temp]>=4? 4 : levels[Temp]+1;
                    love[Temp] += 10;
                    Temp = -1;
                }
                else
                {
                    printf("陛下，您没有叫%s的妃子！\n",TempName);
                    Temp = -1;
                }
                    
                for(i=0;i<count;i++)
                {
                    printf("%s\t%s\t%d\n",names[i],level[levels[i]],love[i]);
                } 
                break;
            case 3:
                printf("请选择要打入冷宫的娘娘的名字：");
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
                    printf("虚惊一场！\n");
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