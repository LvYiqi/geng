#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MNUM 10
#define MAX 10

int main()
{
    int vnum,vcap[MAX],map[MAX][MAX];
    int i,j,temp;
    srand(time(NULL));
    vnum=rand()%6+5;
    for(i=0;i<vnum;i++)
    {
        vcap[i]=rand()%20+1;
        for(j=i+1;j<vnum;j++)
        {
            if(rand()%100>49){
                map[i][j]=0;
                map[j][i]=0;
            }
            else{
                map[i][j]=rand()%20+1;
                map[j][i]=map[i][j];
            }
        }
    }
    printfFILE();
    return 0;
}
