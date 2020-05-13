//snakes and ladders image from depositphotos.com

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
// snakes
					if(pos==17) pos = 7;
					if(pos==54) pos = 34;
					if(pos==64) pos = 60;
					if(pos==62) pos = 19;
					if(pos==93) pos = 73;
					if(pos==87) pos = 36;
					if(pos==95) pos = 75;
					if(pos==98) pos = 79;
//ladders
					if(pos==1)  pos = 38;
					if(pos==4)  pos = 14;
					if(pos==9)  pos = 31;
					if(pos==21) pos = 42;
					if(pos==28) pos = 84;
					if(pos==80) pos = 99;
					if(pos==72) pos = 91;
					if(pos==51) pos = 67;
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
