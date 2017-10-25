#include<cstdio>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

char barang[6][20];
	barang[0] = "MP4A1";
	barang[1] = "PM2-V1";
	barang[2] = "SPR-3";
	barang[3] = "SS2-V5";
	barang[4] = "SPG1_V3";
	barang[5] = "MINE"
	
void main(){
	key_t key=7667;
	int *jlh_stok;


	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	jlh_stok = shmat(shmid, NULL, 0);
	while (1){



	}




}
