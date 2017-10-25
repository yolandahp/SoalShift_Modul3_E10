#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

char nama1[100], nama2[100];
int score1 = 0, score2 = 0;
int tunggu = 1;

int ranjau[17][2];

pthread_t threadid[3]; // 0 player 1 main player 2 nebak, 1 player 2 main player 1 nebak, 2 nilai tiap pemain  

void* play(void *arg){
	int n, j;
	char c;
    pthread_t id=pthread_self();
    
    if(pthread_equal(id,threadid[0])){
		printf("%s's turn!\nUntuk %s silahkan masukkan 1-4 lubang yang akan diisi ranjau (1-16):\n", nama1, nama1);
		while(scanf("%d%c", &n, &c)){
			ranjau[n][0] = 1;
			if(c == '\n') break;
		}

		printf("Silahkan %s untuk menebak 4 lubang yang aman (1-16):\n", nama2);

		int hit = 0;
		for(j = 0; j < 4; j++){
			scanf("%d", &n);
			if(ranjau[n][0] == 1) hit++;
		}

		if(hit == 0){
			printf("Selamat %s berhasil melewati ranjau!^^ Score+1\n", nama2);
			score2++;
		}
		else{
			printf("Tidaaaak %s menginjak ranjau :(\n", nama2);
			exit(EXIT_SUCCESS);
		}

		if(score2 >= 10){
			printf("%s WIN!\n", nama2);
			exit(EXIT_SUCCESS);
		}

		tunggu = 0;
    }
    else if(pthread_equal(id,threadid[1])){
        while(tunggu);
        printf("%s's turn!\nUntuk %s silahkan masukkan 1-4 lubang yang akan diisi ranjau (1-16):\n", nama2, nama2);
		while(scanf("%d%c", &n, &c)){
			ranjau[n][1] = 1;
			if(c == '\n') break;
		}

		printf("Silahkan %s untuk menebak 4 lubang yang aman (1-16):\n", nama1);

		int hit = 0;
		for(j = 0; j < 4; j++){
			scanf("%d", &n);
			if(ranjau[n][1] == 1) hit++;
		}

		if(hit == 0){
			printf("Selamat %s berhasil melewati ranjau!^^ Score+1\n", nama1);
			score1++;
		}
		else{
			printf("Tidaaaak %s menginjak ranjau :(\n", nama1);
			exit(EXIT_SUCCESS);
		}

		if(score1 >= 10){
			printf("%s WIN!\n", nama1);
			exit(EXIT_SUCCESS);
		}

		tunggu = 1;
    }

    return NULL;
}

void* cek_status(void *arg){
	printf("Score %s: %d\n", nama1, score1);
	printf("Score %s: %d\n", nama2, score2);
	
    return NULL;
}

int main(){
	printf("Masukkan nama untuk player1: "); scanf("%s", nama1);
	printf("Masukkan nama untuk player2: "); scanf("%s", nama2);

	printf("Menu:\n1. untuk cek status per pemain\n2. untuk lanjut ke permainan\n3. untuk keluar dari permainan\n");

	while(1){
		int ret, i, x;

		for(i = 0; i < 17; i++){
			ranjau[i][0] = 0;
			ranjau[i][1] = 0;
		}

		ret = pthread_create(&(threadid[0]),NULL,&play,NULL);
    	if(ret) exit(EXIT_FAILURE);

		ret = pthread_create(&(threadid[1]),NULL,&play,NULL);
    	if(ret) exit(EXIT_FAILURE);

    	pthread_join(threadid[0], NULL);
    	pthread_join(threadid[1], NULL);

    	printf("Menu: "); scanf("%d", &x); getchar();
    	
    	if(x == 1){
    		ret = pthread_create(&(threadid[2]),NULL,&cek_status,NULL);
    		pthread_join(threadid[2], NULL);
    	}
    	else if(x == 2) continue;
    	else if(x == 3){
    		printf("Bye Bye!");
    		exit(EXIT_SUCCESS);
    	}
	}

	return 0;
}