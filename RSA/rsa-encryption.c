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

 
	printf("\nENTER FIRST PRIME NUMBER\n"); 
	scanf("%d",&p); 
	flag=prime(p); 
	if(flag==0) 
	{ 
		printf("\nWRONG INPUT\n"); 
		exit(1); 
	}
 
	printf("\nENTER ANOTHER PRIME NUMBER\n"); 
	scanf("%d",&q); 
	flag=prime(q); 
	if(flag==0||p==q) 
	{ 
		printf("\nWRONG INPUT\n"); 
		exit(1); 
	}
	double time_spent = 0.0;
	clock_t begin = clock();
	printf("Reading content from file:-  plain.txt\n ***********************************************************************\n\n");
	FILE *fp = fopen("plain.txt", "r+");
	fscanf(fp, "%s", msg);
	printf("Text to be Encrypted is: -  ");
	for (i=0;msg[i]!=NULL;i++)
	{
		m[i]=msg[i];
		printf("%c",msg[i]);
	} 
	printf("\n");
	n=p*q; 
	t=(p-1)*(q-1); 
	ce(); 
	fclose(fp);	
	encrypt(); 
	printf("\n Writing content to cipher.txt\n********************************************************************************\n\n");
	FILE *fcipher = fopen("cipher.txt", "w+");
	fprintf(fcipher, "%d\n%d\n", p, q);
	for (i=0;en[i]!=-1;i++) 
	fprintf(fcipher,"%c",en[i]);
	fclose(fcipher);
	int length = strlen(msg);
	FILE *depend = fopen("dependency.txt", "w+");
	fprintf(depend ,"%d", length);
	for(i=0; i < length; i++)
	{
		fprintf(depend,"\n%d",temp[i]);
	}
	fclose(depend);
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time elpased is %f seconds", time_spent);
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
 
void encrypt() 
{ 
	long int pt,ct,key=e[0],k,len; 
	i=0; 
	len=strlen(msg); 
	while(i!=len) 
	{ 
		pt=m[i]; 
		pt=pt-96; 
		k=1; 
		for (j=0;j<key;j++) 
		{ 
			k=k*pt; 
			k=k%n; 
		} 
		temp[i]=k; 
		ct=k+96; 
		en[i]=ct; 
		i++; 
	} 
	en[i]=-1; 
	printf("\nTHE ENCRYPTED MESSAGE IS\n"); 
	for (i=0;en[i]!=-1;i++) 
	printf("%c",en[i]); 
}