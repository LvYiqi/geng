#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define VNUM 30
#define ENUM 70
#define MNUM 4

typedef struct edge{
    int ecap;
    int eprice;
    int v1;
    int v2;
}e[ENUM];

int main()
{
    int vcap[VNUM],vprice[VNUM],map[VNUM][VNUM];
    int i,j,temp;
    srand(time(NULL));
    for(i=0;i<VNUM;i++)
    {
        vprice[i]=rand()%11+10;
        for(j=0;j<VNUM;j++)
            map[i][j]=0;
    }
    for(i=0;i<ENUM;i++)
    {
        e[i].ecap=rand()%51+100;
        e[i].eprice=rand()%11+10;
        e[i].v1=rand()%VNUM;
        while(1){
            temp=rand()%(VNUM-1);
            if(temp==e[i].v1) temp=VNUM-1;
            if(map[e[i].v1][temp]==0) break;
        }
        e[i].v2=temp;
        map[e[i].v1][temp]=e[i].eprice;
    }
    printfFILE();
    return 0;
}
