#include<stdio.h>
#include<stdlib.h>
void modn(int);
void main()
{
	int n=1;
	FILE *fptr=fopen("in.txt", "r");//in.txt is input file where numbers are stored
	while(fscanf(fptr, "%d", &n) == 1)
	{
		modn(n);//calls modn function for every  number stord in file
	}
	fclose(fptr);
}
void modn(int n)
{
	FILE *fptr=fopen("out.txt", "a");//opens out.txt in append mode to store the output.
	int i,j,temp_num,go_0,go_1,big,small;
	int*a;
	fprintf(fptr,"%d -> ",n);//prints the number for which we We want to output the DFA
	fprintf(fptr,"{");//prints "{" at first
	for(i=0;i<n;i++)
	{
		/*n is divisible by n. now if it is in state i that means now the number is having remainder i.It is good
		to take the number as n+i. Now if a 0 comes the number is actually doubled and if a 1 comes it is dounled
		and an 1 added. In temp_num doubled number is stored. After that added one will be taken care in calculating
		the value of go_1*/
		
		/*Ststes are actually defining the remainder of the input number and n*/
		temp_num=2*(n+i);
		go_0=temp_num%n;//go_0 takes the remainder if a 0 comes.
		go_1=(temp_num+1)%n;//go_1 takes the remainder if a 1 comes.
		
		
		/*small keeps track of the smaller state of go_0 and go_1 and big keeps track of the bogger one*/
		(go_0 < go_1)? (small=go_0,big=go_1) : (small=go_1,big=go_0);
		j=0;
		while(j<small)//till small comes print {} as no transition in these states.
		{
			fprintf(fptr,"{}");
			j++;
		}
		(small==go_0)? (fprintf(fptr,"{0}")):(fprintf(fptr,"{1}"));//if there is a transition in small for 0 print {0} if in 1 print {1}
		j++;
		while(j<big)//from small+1 to big-1 print {} as no transition in these states.
		{
			fprintf(fptr,"{}");
			j++;
		}
		(big==go_0)? (fprintf(fptr,"{0}")):(fprintf(fptr,"{1}"));//if there is a transition in big for 0 print {0} if in 1 print {1}
		j++;
		while(j<n)//from big+1 to last state print {} as no transition on these states.
		{
			fprintf(fptr,"{}");
			j++;
		}
		if(i!=(n-1))//put a "," when transition from a state is complete except the last step.
		{
			fprintf(fptr,", ");
		}
	}
	fprintf(fptr,"}\n");//print "}" when everything is finished.
	fclose(fptr);
}
