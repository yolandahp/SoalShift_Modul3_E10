#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include <string.h>

	
void main(){
	key_t key=7667;
	int *jlh_stok;
	int c, i, tambah;


char barang[6][10]={"MP4A1", "PM2-V1", "SPR-3", "SS2-V5", "SPG1_V3", "MINE"};
	
	int shmid = shmget(key, 6*sizeof(int), IPC_CREAT | 0666);
	jlh_stok = shmat(shmid, NULL, 0);
	while (1){

		printf("Pilih	:\n1.Lihat Barang\n2.Tambah Stok\n");
		scanf("%d", &c);
		if(c==1){
			for(int i=0; i<6 ; i++){
				if(jlh_stok[i]>0){
				printf("%s 		%d\n", barang[i], jlh_stok[i]);
				}
			}
		}
		else if(c==2){
			char n_barang[10];
			scanf("%s %d", n_barang, &tambah);
			for(i=0;i<6;i++){
				if(!strcmp(n_barang, barang[i])){
					jlh_stok[i]+=tambah;
					printf("Jumlah %s di stok = %d barang\n", barang[i], jlh_stok[i]);
				}
			}
		}
		else{
			printf("perintah salah!\n");
		}

	}
	shmdt(jlh_stok)	;
	shmctl(shmid,IPC_RMID,NULL);
}
