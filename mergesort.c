#include <stdio.h>
#include <time.h>

double time1, timediff;

void pop(int vec[], int a){
    for (int i = 0; i < a; i++)  
        vec[i]=rand();
}
void printVec(int vec[], int a) {    
    //FILE *f = fopen("msUnsortMega","wb"); 
    for (int i = 0; i < a; i++){
        printf("| %d |", vec[i]);  
        // if (f == NULL) { 
	   // fprintf(stderr,"File exists.\n");}
    //int num = vec[i];
    //char tex[50];
    //snprintf(tex, 50, " | %d |,",num);
   // fprintf(f,tex); 
    };
   // fclose(f); 
}
void printVecB(int vec[], int a) {    
    FILE *f = fopen("msSortMega","wb"); 
    for (int i = 0; i < a; i++){
        printf("| %d |", vec[i]);  
         if (f == NULL) { 
	    fprintf(stderr,"File exists.\n");}
    int num = vec[i];
    char tex[50];
    snprintf(tex, 50, " | %d |,",num);
    fprintf(f,tex); 
    };
    fclose(f); 
}

//func separando array

void div(int vec[], int a, int b, int c){
    //index das sub vecs e mainvec
    int d, e, f;
    d=0;
    e=0;
    f=a;
    //tamanho sublistas
    int tamA = b - a + 1;
    int tamB = c - b;
    int D[tamB], E[tamA];
    //popular sublistas com val lista OG
    for(int i=0; i<tamA; i++){
        E[i] = vec[a + i];
    }for(int i=0; i<tamB; i++){
        D[i] = vec[b + 1 + i];
    }
    while(d<tamA && e<tamB){
        if(E[d]<=D[e]){
            vec[f]=E[d];
            d=d+1;
        }else{
            vec[f]= D[e];
            e=e+1;
        }
        f=f+1;
    }while(d<tamA){
        vec[f]=E[d];
        d++;
        f++;
    }while(e<tamB){
        vec[f]=D[e];
        e++;
        f++;
    }
}


//func juntando (merge) array
void mSort(int vec[], int E, int D){
    if(E<D){
        int h= E + (D-E)/2;
        mSort(vec,E,h);
        mSort(vec,h+1, D);
        div(vec, E, h, D);
    }
}

int main() {
    //val para 1000000 elementos
    //int num = 1000000;
    //static int arr[1000000];
    int num;
    printf("insira num:\n");
    scanf(" %d",&num);
    time1 = (double) clock();
    time1 = time1/CLOCKS_PER_SEC;
    int arr[num];
    pop(arr, num);
    int p = sizeof(arr) / sizeof(arr[0]);

    printVec(arr, p);
    //func org
    mSort(arr, 0, p-1);
    printf("\n\nc/ sort\n");
    printVec(arr, p);
    
    timediff = ((double) clock()/CLOCKS_PER_SEC)-time1;
    printf("tempo d execucao: %f.",timediff);
} 