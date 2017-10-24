#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t threadid[10005];
int wait[10005];

struct passing(){
    int numb;
    int idx;
};

/*
void *prime(void *arg){
    struct rentang *rg = (struct rentang *)arg;

    int aw = rg->awal, ak = rg->akhir, ind = rg->idx;

    if(ind != 0)
        while(wait[ind]);

    int j, k;
    for(j = aw; j <= ak; j++){
        if(j == 2) printf("2\n");
        else{
            int status = 1;
            for(k = 2; k*k <= j; k++){
                if(j%k == 0){
                    status = 0;
                    break;
                }
            }

            if(status) printf("%d\n", j);
        }
    }

    wait[ind+1] = 0;
}
*/

int main(void){
    char x;
    int num = 0, hit = 0, i,j, ret;
    int arr[10005], arr2[10005];

    for(i = 0; i < 10005; i++)
        arr[i] = 0;

    while(scanf("%c", &x) != '\n'){
        if(x == ' '){
            arr[num]++;
            hit++;
            num = 0;
        }
        else{
            num = num*10 + x - '0';
        }
    }

    hit = 0;

    for(i = 0; i < 10005; i++)
        wait[i] = i;

    for(i = 0; i < 10005; i++){
        for(j = 0; j < arr[i]; j++){
            struct passing *pass = malloc(sizeof(struct passing));
            pass->numb = i;
            pass->idx = hit;

            ret = pthread_create(&(threadid[hit]), NULL, fact, (void *) pass);

            if(ret) exit(EXIT_FAILURE);

            hit++;
        }
    }

    for(i = 0; i < hit; i++){
        pthread_join(threadid[i], NULL);
    }

    exit(EXIT_SUCCESS);
    
    return 0;
}
