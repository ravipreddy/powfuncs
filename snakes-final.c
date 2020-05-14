//snakes and ladders - monte-carlo simulation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#define NUMRUNS 100000

int main()
{
	int irun, jroll, kturn,dieroll,pos=1,newpos;
	long int seed;
	int minturns=1000, minrolls=1000;
	double avgturns=0, avgrolls=0;
	FILE * outfile,*logfile;

	outfile=fopen("snakes.txt","w");
	logfile=fopen("snakeslog.txt","w");

	jroll=0;
	kturn=0;
	seed = (long)time(NULL);
	srand(seed);

	for(irun=0;irun<NUMRUNS;irun++)
		{
			do{
				kturn++;
				do
				{
					jroll++;
					dieroll = 1+6*rand()/(RAND_MAX+1.0);
					newpos = pos + dieroll;
					if(newpos<=100)pos=newpos;
					//printf("%d %d %d %d  ",kturn, jroll,dieroll, pos);
					fprintf(logfile,"%d %d %d %d  ",kturn, jroll,dieroll, pos);
// 10 snakes
					if(pos==65) pos =  2;
					if(pos==37) pos = 15;
					if(pos==41) pos = 19;
					if(pos==48) pos = 10;
					if(pos==93) pos = 53;
					if(pos==95) pos = 74;
					if(pos==97) pos = 29;
					if(pos==77) pos = 44;
					if(pos==79) pos = 22;
					if(pos==83) pos = 61;
//ladders
					if(pos==6)  pos = 14;
					if(pos==4)  pos = 38;
					if(pos==12) pos = 27;
					if(pos==33) pos = 51;
					if(pos==71) pos = 92;
					if(pos==80) pos = 99;
					if(pos==67) pos = 88;
					if(pos==64) pos = 94;
					if(pos==21) pos = 78;
					if(pos==80) pos = 99;
					//printf(": %d \n",pos);
					fprintf(logfile,": %d \n",pos);

				}
				while(dieroll==6);

			} while (pos<100);
		//printf("\n %d %d ",kturn,jroll);
		fprintf(logfile,"\n[[%d\t%d]]\n",kturn,jroll);
		fprintf(outfile,"%d\t%d\n",kturn,jroll);
		avgrolls += (jroll-avgrolls)/(irun+1);
		avgturns += (kturn-avgturns)/(irun+1);
		if(kturn < minturns) minturns = kturn;
		if(jroll < minrolls) minrolls = jroll;
		//printf("%d %d %lf %lf\n",minturns,minrolls,avgturns,avgrolls);
		jroll=0;
		kturn=0;
		pos=1;
		}

	fclose(outfile);
	fclose(logfile);
	printf("\n\nFinal Values\n");
	printf("Number of games simulated   = %d\n",NUMRUNS);
    printf("Minimum number of turns     = %d\n",minturns);
    printf("Minimum number of rolls     = %d\n",minrolls);
    printf("Average number of turns     = %lf\n",avgturns);
    printf("Average number of rolls     = %lf\n",avgrolls);
    printf("Average rolls/Average turns = %lf",avgrolls/avgturns);
	return 0;
}
