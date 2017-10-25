/*

INI TEMPLATE KODINGAN DARI KODINGAN SENDIRI SOAL LATIHAN MODUL NO 1


*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int wait = 1;
pthread_t threadid[2];

void* copy_file(void *arg){

    pthread_t id=pthread_self();
    
    if(pthread_equal(id,threadid[0])){
        char c;
    
        FILE* finp=fopen("baca.txt","r");
        FILE* fout=fopen("salin1.txt","w");
    
        if(finp!=NULL){
            while(c=fgetc(finp)){
                if(c==EOF) break;
                fputc(c, fout);
            }
            wait = 0;
            fclose(finp);
        }

        fclose(fout);
    }
    else if(pthread_equal(id,threadid[1])){
        while(wait);
        char c;
    
        FILE* finp=fopen("salin1.txt","r");
        FILE* fout=fopen("salin2.txt","w");
    
        if(finp!=NULL){
            while(c=fgetc(finp)){
                if(c==EOF) break;
                fputc(c, fout);
            }
            fclose(finp);
        }

        fclose(fout);
    }

    return NULL;
}

int main(){

    int i;
    int ret;

    for(i = 0; i < 2; i++){
        ret = pthread_create(&(threadid[i]),NULL,&copy_file,NULL);
        if(ret)
            exit(EXIT_FAILURE);
    }

    pthread_join(threadid[0], NULL);
    pthread_join(threadid[1], NULL);

    exit(EXIT_SUCCESS);
}