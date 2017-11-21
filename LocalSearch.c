#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define VMAX 30
#define EMAX 70
#define MMAX 4
#define INF 1000000

typedef struct edge{
    int ecap;
    int eprice;
    int v1;
    int v2;
}e[EMAX];

int main()
{
    int vcap[VMAX],vprice[VMAX],map[VMAX][VMAX],path[VMAX][VMAX];
    int vt_vcap[VMAX],vt_vprice[VMAX],vt_map[VMAX][VMAX];
    int i,j,k,tempcap,tempprice,vnum,egnum,vt_vnum;
    FILE *fp,*f=fopen("PhyGragh.txt","r");
    fscanf(f,"%d %d\n",&vnum,&egnum);
    for(i=0;i<vnum;i++)
    {
        fscanf(f,"%d %d\n",&vcap[i],&vprice[i]);
        for(j=0;j<vnum;j++){
            map[i][j]=INF;
            path[i][j]=j;
        }
    }
    for(i=0;i<egnum;i++)
    {
        fscanf(f,"%d %d %d %d\n",&e[i].ecap,&e[i].eprice,&e[i].v1,&e[i].v2);
        map[e[i].v1][e[i].v2]=e[i].eprice;
        map[e[i].v2][e[i].v1]=e[i].eprice;
    }
    for(k=0;k<vnum;k++)
        for(i=0;i<vnum;i++)
            for(j=0;j<vnum;j++)
                if(map[i][k]+map[k][j]<map[i][j])
                {
                    map[i][j]=map[i][k]+map[k][j];
                    path[i][j]=path[i][k];
                }
    fp=fopen("VNetFlow.txt","r");
    fscanf(fp,"%d\n",&vt_vnum);
    for(i=0;i<vt_vnum;i++)
    {
        for(j=0;j<vt_vnum;j++)
        {
            fscanf(fp,"%d ",&vt_map[i][j]);
        }
    }
    return 0;
}
