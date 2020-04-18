#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void bimodal_function(int mbits);
int no_of_predictions;
int number_of_mispredictions;
void prediction_table(int,char,int *);
int size;
FILE *file;
int *ptr;
int main(int argc,char *argv[]){
    int choice;
    char *input=argv[1];
    int m=atoi(argv[2]); //arg 2
    char *inputfile= argv[3];
	file = fopen(inputfile, "rb");
   if(strcmp(input,"bimodal")==0){
    	choice=1;
    }
    size=pow(2,m);
    int indexarray[size];
    ptr=&indexarray[0];
    for(int i=0;i<size;i++){
        indexarray[i]=4;
    }
    
    //scanf("%d",&choice);
    switch(choice){
        case 1: bimodal_function(m);
                break; 
        }
    return 0;
    }

void bimodal_function(int mbits){  
//file = fopen("gcc_trace.txt", "rb");
if (file) {
	long int branch_decimal = 0;
	char branch[6], c;
	
	int index;
    while (1){
    	fscanf(file, "%s %c", branch, &c);
    	branch_decimal = strtol(branch, NULL, 16);
    	branch_decimal = branch_decimal >> 2;
    	index = ((1<<mbits)-1) & branch_decimal;
    	//printf("%i %c\n", index, c);
        prediction_table(index,c,ptr);
        if( feof(file) ) { 
             break ;
        }
    }
    
    fclose(file);
}
printf("OUTPUT\n");
printf("number of predictions :%d\n",no_of_predictions-1);
printf("number of mispredictions: %d\n",number_of_mispredictions);
char a[2];
a[0]='%';
a[1]='\0';
float result=(float)number_of_mispredictions/(float)no_of_predictions ;
result=result * 100;
printf("misprediction rate:	%0.2f%s \n",result,a);

printf("FINAL BIMODAL CONTENTS\n");
for(int i=0;i<size;i++){
	
		printf("%d\t%d\n",i,*(ptr+i));
	}

}

void prediction_table(int index,char c,int *ptr){
    no_of_predictions+=1;

    int a=*(ptr + index);
        if(c=='t'){
        	if(a<4 && a>=0){
               number_of_mispredictions+=1;
        	}
            if(a<7){
                a=a+1;
            *(ptr + index)=a;
            }
        }else{
        	if(a>=4 && a<=7){
        		number_of_mispredictions+=1;
        	}
            if(a>0){
                a=a-1;
                *(ptr + index)=a;
            }
        }

}


