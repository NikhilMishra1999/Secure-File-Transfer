#include<stdio.h> 
#include<ncurses.h> 
#include<stdlib.h> 
#include<math.h> 
#include<string.h>
#include<time.h> 
long int p,q,n,t,flag,e[100],d[100],temp[100],j,m[100],en[100],i; 
char msg[100]; 
int prime(long int); 
void ce(); 
long int cd(long int); 
void encrypt(); 
void decrypt();

void main() {
 
	FILE *fpp = fopen("cipher.txt", "a+");
    fscanf(fpp, "%d\n%d\n", &p, &q);
	printf("Reading content from file :-  cipher.txt\n ***********************************************************************\n\n");
	fscanf(fpp, "%s", en);
	double time_spent = 0.0;
	clock_t begin = clock();
	n=p*q; 
	t=(p-1)*(q-1); 
	ce(); 
	printf("\nPOSSIBLE VALUES OF e AND d ARE\n"); 
	for (i=0;i<j-1;i++) 
	printf("\n%ld\t%ld",e[i],d[i]);
	fclose(fpp);
    int length;
	FILE *depend = fopen("dependency.txt", "a+");
	fscanf(depend ,"%d\n", &length);
	en[length] = -1;
	for(i=0; i < length; i++)
	{
		fscanf(depend,"%d",&temp[i]);
	}                 
	fclose(depend);
    decrypt();
	printf("Writing content to file :-  decipher.txt\n ***********************************************************************\n\n");

	FILE *fdecipher = fopen("decipher.txt", "w+");
	for(i=0;i<length;i++)
	{
		fprintf(fdecipher,"%c", m[i]);
	}
	fclose(fdecipher);
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime elpased is %f seconds", time_spent);
	printf("\n");
 
}
 
int prime(long int pr) {
 
	int i; 
	j=sqrt(pr); 
	for (i=2;i<=j;i++) 
	{ 
		if(pr%i==0) 
		    return 0; 
	} 
	return 1; 
}
 
void ce() 
{ 
	int k; 
	k=0; 
	for (i=2;i<t;i++) 
	{ 
		if(t%i==0) 
		    continue;
 
		flag=prime(i); 
		if(flag==1&&i!=p&&i!=q) 
		{ 
			e[k]=i; 
			flag=cd(e[k]); 
			if(flag>0) 
			{ 
				d[k]=flag; 
				k++; 
			} 
			if(k==99) 
			        break; 
		} 
	} 
}
 
long int cd(long int x) {
 
	long int k=1; 
	while(1) 
	{
		k=k+t; 
		if(k%x==0) 
		    return(k/x);
	} 
}
 
void decrypt() { 
	long int pt,ct,key=d[0],k; 
	i=0; 
	while(en[i]!=-1) 
	{ 
		ct=temp[i]; 
		k=1; 
		for (j=0;j<key;j++) 
		{ 
			k=k*ct; 
			k=k%n; 
		} 
		pt=k+96; 
		m[i]=pt; 
		i++;
	} 
	m[i]=-1; 
	printf("\nTHE DECRYPTED MESSAGE IS\n"); 
	for (i=0;m[i]!=-1;i++) 
	printf("%c",m[i]);
	printf("\n"); 
}