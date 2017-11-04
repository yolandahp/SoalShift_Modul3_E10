#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
	
void main(){
	key_t key=7667;
	int *jlh_stok;
	int c, i, kurang, temp;

	char barang[6][10]={"MP4A1", "PM2-V1", "SPR-3", "SS2-V5", "SPG1_V3", "MINE"};
	
	int shmid = shmget(key, 6*sizeof(int), IPC_CREAT | 0666);
	jlh_stok = shmat(shmid, NULL, 0);
	while (1){
		printf("Pilih	:\n1.Lihat Barang\n2.Beli Barang\n");
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
			scanf("%s %d", n_barang, &kurang);
			for(i=0;i<6;i++){
				if(!strcmp(n_barang, barang[i])){
					temp=jlh_stok[i]-kurang;
					if(temp>=0){
						jlh_stok[i]-=kurang;
					printf("Jumlah %s di stok = %d barang\n", barang[i], jlh_stok[i]);
				}
				else{
					printf("Barang di stok tidak cukup\n\n");
						}
				break;
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
