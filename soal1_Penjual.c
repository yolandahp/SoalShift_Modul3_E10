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
	int c;
	
	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	jlh_stok = shmat(shmid, NULL, 0);
	while (1){
		printf("Pilih	:\n1.Lihat Barang\n2.Tambah Stok\n");
		scanf("%d", &c)
		if(c==1){
			for(int i=0; i<6 ; i++){
				if(jlh_stok[i]>0){
				printf("Jumlah %s di stok = %d barang\n", barang[i], jlh_stok[i]);
				}
			}
		}
		else if(c==2){
			scanf("%s %d", n_barang, &tambah);
			for(i=0;i<6;i++){
				if(!strcmp(n_barang, barang[0]){
					jlh_stok[i]+=tambah;
				})
			}
		}
		else{
			printf("perintah salah!\n");
		}

	}
	shmdt(jlh_stok)	;
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
