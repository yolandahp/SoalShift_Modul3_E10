#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

int lohan_h = 100, kepiting_h = 100;


void *lohanmin(void *arg){
	while(1){
		if(lohan_h <= 0 || lohan_h > 100){
			printf("Permainan berakhir\n");
			exit(EXIT_SUCCESS);
		}
		sleep(10);
		lohan_h -= 15;
	}
}

void *kepitingmin(void *arg){
	while(1){
		if(kepiting_h <= 0 || kepiting_h > 100){
			printf("Permainan berakhir\n");
			exit(EXIT_SUCCESS);
		}
		sleep(20);
		kepiting_h -= 10;
	}
}



/*

//ini dari kodingan soal no 4, hanya sebagai referensi penulisan


pthread_t threadid[10005];
int wait[10005];

struct passing{
    int numb;
    int idx;
};


void *fact(void *arg){
    struct passing *ps = (struct passing *)arg;

    int ag = ps->numb, id = ps->idx;

    while(wait[id]);

    int k;
    long long int ans = 1;

    for(k = 1; k <= ag; k++)
        ans*=(long long int)(k);

    printf("Hasil %d! = %lld\n", ag, ans);

    wait[id+1] = 0;
}


int main(void){
    char x;
    int num = 0, hit = 0, i,j, ret;
    int arr[10005], arr2[10005];

    for(i = 0; i < 10005; i++)
        arr[i] = 0;

    while(scanf("%c", &x)){
        if(x == '\n') break;
        if(x == ' '){
            arr[num]++;
            hit++;
            num = 0;
        }
        else{
            num = num*10 + x - '0';
        }
    }

    arr[num]++;
    hit++;

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
*/
