#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int tunggu = 1;
pthread_t threadid[2];

void* cari(void *arg){

    pthread_t id=pthread_self();
    
    if(pthread_equal(id,threadid[0])){
        pid_t child_id;
        int status;

        child_id = fork();

        if(child_id == 0) printf("Ifah = ");
        else{
            while((wait(&status)) > 0);
            system("grep -o Ifah Novel.txt | wc -l");
        }
        tunggu = 0;
    }
    else if(pthread_equal(id,threadid[1])){
        while(tunggu);

        pid_t child_id;
        int status;

        child_id = fork();

        if(child_id == 0) printf("Fina = ");
        else{
            while((wait(&status)) > 0);
            system("grep -o Fina Novel.txt | wc -l");
        }
    }

    return NULL;
}

int main(){
    int i;
    int ret1, ret2;

    ret1 = pthread_create(&(threadid[0]),NULL,&cari,NULL);
    if(ret1) exit(EXIT_FAILURE);

    ret2 = pthread_create(&(threadid[1]),NULL,&cari,NULL);
    if(ret2) exit(EXIT_FAILURE);

    pthread_join(threadid[0], NULL);
    pthread_join(threadid[1], NULL);

    exit(EXIT_SUCCESS);
}