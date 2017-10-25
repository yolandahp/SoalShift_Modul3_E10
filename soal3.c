#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

int lohan_h = 100, kepiting_h = 100;
pthread_t threadid[3];


void *lohanmin(void *arg){
	while(1){
		sleep(10);
		lohan_h -= 15;
		if(lohan_h <= 0){
			printf("Permainan berakhir\n");
			exit(EXIT_SUCCESS);
		}
		printf("Lohan Status = %d\n", lohan_h);
		printf("Kepiting Status = %d\n", kepiting_h);
	}
}

void *kepitingmin(void *arg){
	while(1){
		sleep(20);
		kepiting_h -= 10;
		if(kepiting_h <= 0){
			printf("Permainan berakhir\n");
			exit(EXIT_SUCCESS);
		}
		printf("Lohan Status = %d\n", lohan_h);
		printf("Kepiting Status = %d\n", kepiting_h);
		
	}
}

void *memberimakan(void *arg){
	while(1){
		printf("Lohan Status = %d\n", lohan_h);
		printf("Kepiting Status = %d\n", kepiting_h);

		printf("Tekan 1 jika ingin memberi makan lohan (+10)\nTekan 2 jika ingin memberi makan kepiting (+10)\n");
		int x;
		scanf("%d", &x);

		if(x == 1) lohan_h +=10;
		else kepiting_h +=10;

		if(lohan_h>100 || kepiting_h>100){
			printf("Permainan berakhir\n");
			exit(EXIT_SUCCESS);
		}
	}
}

int main(){
	int ret, i;

	ret = pthread_create(&(threadid[0]), NULL, &lohanmin, NULL);
	if(ret) exit(EXIT_FAILURE);

	ret = pthread_create(&(threadid[1]), NULL, &kepitingmin, NULL);
	if(ret) exit(EXIT_FAILURE);

	ret = pthread_create(&(threadid[2]), NULL, &memberimakan, NULL);
	if(ret) exit(EXIT_FAILURE);

	for(i = 0; i < 3; i++){
        pthread_join(threadid[i], NULL);
    }

	exit(EXIT_SUCCESS);
    return 0;
}