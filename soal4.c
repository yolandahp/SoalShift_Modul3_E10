#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t threadid[10005];
int wait[10005];
int start, end, n, t;

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
    int num = 0, hit = 0, i;
    int arr[10005];

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


    /*
    int i, ret, batch;

    for(i = 0; i < 10005; i++)
        wait[i] = 1;

    batch = n/t;

    for(i = 0; i < t; i++){
        struct rentang *range = malloc(sizeof(struct rentang));

        if(batch*i + 1 > 2) start = batch*i +1;
        else start = 2;

        if(batch*(i+1) < n) end = batch*(i+1);
        else end = n;

        range->awal = start;
        range->akhir = end;
        range->idx = i;

        //printf("%d %d\n", range->awal, range->akhir);

        ret = pthread_create(&(threadid[i]), NULL, prime, (void *) range);
        
        if(ret) exit(EXIT_FAILURE);
    }

    
    for(i = 0; i < t; i++){
        pthread_join(threadid[i], NULL);
    }

    */
    exit(EXIT_SUCCESS);
    
    return 0;
}
