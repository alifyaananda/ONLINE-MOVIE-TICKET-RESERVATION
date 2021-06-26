/*     SISTEM PEMESANAN TIKET BIOSKOP
        PROYEK AKHIR DASAR KOMPUTER
	
	AISYAH RAMADHANTI HASHMI (1906305511)
	ALIFYA ANANDA KHAIRANY   (1906384226)
	FANISSA ZAHRA ATALIA     (1906307624)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>

//DEFAULT VALUE
int r = 4;
int c = 8;

//FUNCTIONS
int print_jadwal();
int menu_pemesanan();
void print_bangku(int arrays[r][c]);
int tanya_bangku(int banyak_tiket);
int input_datadiri();
int pembayaran(int banyak_tiket);
void print_tiket();

void dayprice_generator(int* adress);
int baris_generator(char a);
void delay(int sec);

//STRUCT
struct Seat
{
    char row; //struct untuk baris
    int coll; //struct untuk kolom
}booked[100];



//VARIABLES
float hargatiket = 25.000;			//harga tiket
float hargatiket_weekdays = 25.000;
float hargatiket_weekends = 35.000;

int hari = 7;						//hari (ex:1 = senin), jika ingin mengubah hari maka ubah angkanya

float jamA[3] = {0, 11.30, 16.10};	//jam dan judul film
float jamB[3] = {0, 11.45, 17.20};
char judul_film[4][50] = {"Error", "CRUELLA    ", "CONJURING 3", "SPIDERMAN  "};

int film,jam, jumlah_tiket, i,j,k;

char nama[100];
char notelp[12];


//BANGKU
char baris[4] = {'A','B','C','D'}; //bangku berisi 4 baris dan 8 kolom
int bangku_cruella_1[4][8] = {
		{1,2,3,4,5,6,7,8}, 
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8}
		};
		
int bangku_cruella_2[4][8] = { //bangku berisi 4 baris dan 8 kolom
		{1,2,3,4,5,6,7,8}, 
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8}
		};
		
int bangku_conjuring_1[4][8] = { //bangku berisi 4 baris dan 8 kolom
		{1,2,3,4,5,6,7,8}, 
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8}
		};
		
int bangku_conjuring_2[4][8] = { //bangku berisi 4 baris dan 8 kolom
		{1,2,3,4,5,6,7,8}, 
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8}
		};
		
int bangku_spiderman_1[4][8] = { //bangku berisi 4 baris dan 8 kolom
		{1,2,3,4,5,6,7,8}, 
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8}
		};
		
int bangku_spiderman_2[4][8] = { //bangku berisi 4 baris dan 8 kolom
		{1,2,3,4,5,6,7,8}, 
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8}
		};

//MAIN FUNCTION
int main(){
	system ("color 60"); //60 merupakan warna kuning
	int status = 1; //1 menunjukan status aktif
	char status2[1];
	printf("\n\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\t\t Tugas Proyek Akhir Dasar Komputer\n\t\t                                  \n");
	printf("\t\t  Online Movie Ticket Reservation\n");
	printf("------------------------------------------------------------------------------\n\n");
	printf("\t\t            Diprogram oleh:\n");
	printf("\t\tAISYAH RAMADHANTI HASHMI (1906305511)\n");
	printf("\t\tALIFYA ANANDA KHAIRANY   (1906384226)\n");
	printf("\t\tFANISSA ZAHRA ATALIA     (1906307624)\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n\n");
	printf("                      PRESS ENTER TO CONTINUE                             \n");
	getch();
	system("cls");
	sleep(1);
		printf("\n Loading");
		delay(1);
	system("cls");
	
	do{
		print_jadwal();
		menu_pemesanan();
		system ("cls");
		tanya_bangku(jumlah_tiket);
		input_datadiri();
		system ("cls");
		pembayaran(jumlah_tiket);
		
		system ("cls");
		printf("\n");
		for(i=0; i<jumlah_tiket; i++){
			print_tiket(i);
		}
		
		//Menu pemesanan ulang
		printf("\n\n\n Ingin Pesan Kembali (Y/N)? ");
		scanf(" %s", &status2);
		if(status2[0] == 89 || status2[0] == 121){ //merupakan ASCII untuk huruf Y dimana berarti YES
			system("cls");
			status = 1;
		}
		else if(status2[0] == 78 || status2[0] == 110){ //merupakan ASCII untuk huruf N dimana berarti NO
			status = 0;
			printf(" Terima Kasih Telah Memesan, ditunggu kehadiran anda di XXI Pesona Square Depok :) "); //ini merupakan menu akhir jika program sudah selesai
		}
	}while(status);

	
	return 0;
}

//GENERATOR HARGA TIKET-Digunakan untuk pemilihan hari dengan harga tiket yang berbeda-beda
void dayprice_generator(int* adress){
	switch (*adress){
		case 1: hargatiket = hargatiket_weekdays;
				printf(" Harga Tiket Hari %s\n", "Senin");
				break;
		case 2: 
				hargatiket = hargatiket_weekdays;
				printf(" Harga Tiket Hari %s\n", "Selasa");
				break;
		case 3: 
				hargatiket = hargatiket_weekdays;
				printf(" Harga Tiket Hari %s\n", "Rabu");
				break;
		case 4: 
				hargatiket = hargatiket_weekdays;
				printf(" Harga Tiket Hari %s\n","Kamis");
				break;
		case 5: 
				hargatiket = hargatiket_weekdays;
				printf(" Harga Tiket Hari %s\n", "Jumat");
				break;
		case 6: 
				hargatiket = hargatiket_weekends;
				printf(" Harga Tiket Hari %s\n","Sabtu");
				break;
		default: 
				hargatiket = hargatiket_weekends;
				printf(" Harga Tiket Hari %s\n", "Minggu");
				break;
	}
}

//PRINT JADWAL
int print_jadwal(){
	printf(" \n *********************************************\n"); 
	printf(" \t\t   NOW SHOWING\n");
	printf(" \t      XXI PESONA SQUARE DEPOK\n"); 
	printf(" *********************************************\n\n");
	printf(" \t\tJADWAL FILM\n");
	printf(" +----------+----------------+---------------+ \n");
	printf(" |          |                |      JAM      |\n");
	printf(" |  STUDIO  |      FILM      +---------------+\n");
	printf(" |          |                |   1   |   2   |\n");
	printf(" +----------+----------------+---------------+ \n");
	printf(" |    1     |  CRUELLA       | 11.30 | 16.10 |\n");
	printf(" |    2     |  CONJURING 3   | 11.45 | 17.20 |\n");
	printf(" |    3     |  SPIDERMAN     | 11.45 | 17.20 |\n");
	printf(" +----------+----------------+---------------+ \n");
	printf(" Harga Tiket\n 1.Senin-Jumat\tRp.25.000 \n 2.Sabtu-Minggu\tRp.35.000\n\n");
	dayprice_generator(&hari);
	printf(" Harga Tiket\t\t: Rp%.3f\n", hargatiket); 
}

//MENU PEMESANAN
int menu_pemesanan(){
	int status = 1;
	
	do{
		printf(" Pilih Film (1-3)\t: "); //digunakan untuk pemilihan film
		scanf("%d", &film);
		printf(" Pilih Jam ke (1-2)\t: "); //digunakan untuk pemilihan jam tayang
		scanf("%d", &jam);
		printf("\n");
		
		if(film<1 || film >3 || jam < 1 || jam > 2){
			printf("Film dan Jam tidak valid, silahkan pilih ulang\n"); //merupakan error handling jika input yang dimasukan salah, selain 1, 2 dan 3
		}
		else{
			printf("\n\n Film : %s\n", judul_film[film]); //menggunaan [film] agar dapat sesuai dengan array input
			if(film == 1){
				printf(" Jam  : %.2f\n", jamA[jam]); // menggunakan [jam] agar sesuai dengan array input jam 
				status = 0;
			}
			else if(film == 2 | film == 3){
				printf(" Jam  : %.2f\n", jamB[jam]);
				status = 0;
			}
		}
	}while(status);

	printf(" Berapa Jumlah Tiket yang Anda Pesan: "); //digunakan untuk menn=anyakan jumlah tiket yang dipesan
	scanf("%d", &jumlah_tiket);
	printf("\n");
}

//BARIS BANGKU
int baris_generator(char a){
	if(a == 65 || a == 97){ // 65 = ASCII A ; 97 = ASCII-ASCII digunakan agar input huruf tetap terbaca baik huruf besar maupun kecil
		return 0;
	}
	else if(a == 66 || a == 98){ // B dan b
		return 1;
	}
	else if(a == 67 || a == 99){ // C dan c
		return 2;
	}
	else if(a == 68 || a == 100){ // D dan d
		return 3;
	}
	return 0;
}

//PRINT BANGKU
void print_bangku(int kolom[r][c]){
 printf("  _______________________________________\n"); //header
 printf(" |             LAYAR BIOSKOP             |\n"); //header
 printf(" |                                       |\n");
 
 for(j=0; j<4; j++){
  printf(" |"); // pinggir kiri
  for(k=0; k<8; k++){
   if(kolom[j][k] != 0){
    printf(" %c%d |",baris[j],kolom[j][k]);
    printf("");
   }
   else{
    printf(" \033[6;31mxx\033[30;43m |");
   }
  }
  printf("\n"); // pinggir kanan
 }
 printf(" |                                       |\n");
 printf(" |_______________STUDIO %d________________|\n", film); //print studio
 printf("\n");
}

//PILIH BANGKU
int tanya_bangku(int banyak_tiket){
	char baris_char;
	int kolom_int;
	int temp;
		
//film ke-1 jam ke-1
	if(film == 1 && jam == 1){
		print_bangku(bangku_cruella_1);
		
		for(i = 0; i < banyak_tiket; i++){
			printf(" Pilih Bangku Anda (A1 - D8):");
			scanf(" %c", &baris_char);
			scanf(" %d", &kolom_int);
			//berfungsi jika input yang dimasukan tidak sesuai
			if ((baris_char == 65 || baris_char == 97 || baris_char == 66 || baris_char == 98 || baris_char == 67|| baris_char == 99 || baris_char == 68 || baris_char == 100) && (kolom_int >= 1 && kolom_int <= 8)){
				temp = baris_generator(baris_char);
			}
			else{
				//error handing apabila input yang dimasukan tidak sesuai dengan ketersediaan nomor kursi
				printf(" Kursi Tidak Tersedia, Silahkan Masukkan Nomor Kursi dengan Benar!\n");
				i--;
				continue;
			}
			
			if(bangku_cruella_1[temp][kolom_int-1] != 0){
				bangku_cruella_1[temp][kolom_int-1] = 0;
				booked[i].row = baris_char;
				booked[i].coll = kolom_int;
				print_bangku(bangku_cruella_1); //print bangku dengan denah yang sudah terbooking tempatnya
				printf(" Bangku %c%d berhasil di booking \n\n", toupper(baris_char), kolom_int);
			}
			else{
				//untuk error handling jika input yang dimasukan sudah terisi
				i -= 1;
				printf(" Bangku yang anda pilih sudah terisi \n Silahkan pilih ulang Bangku Anda!\n\n");
			}			
		}
	}
//film ke-1 jam ke-2
	else if(film == 1 && jam == 2){
		print_bangku(bangku_cruella_2);
		
		for(i = 0; i < banyak_tiket; i++){
			printf(" Pilih Bangku Anda (A1 - D8):");
			scanf(" %c", &baris_char);
			scanf(" %d", &kolom_int);
			//berfungsi jika input yang dimasukan tidak sesuai
			if ((baris_char == 65 || baris_char == 97 || baris_char == 66 || baris_char == 98 || baris_char == 67|| baris_char == 99 || baris_char == 68 || baris_char == 100) && (kolom_int >= 1 && kolom_int <= 8)){
				temp = baris_generator(baris_char);
			}
			else{
				printf(" Kursi Tidak Tersedia, Silahkan Masukkan Nomor Kursi dengan Benar!\n");
				i--;
				continue;
			}
			
			if(bangku_cruella_2[temp][kolom_int-1] != 0){
				bangku_cruella_2[temp][kolom_int-1] = 0;
				booked[i].row = baris_char;
				booked[i].coll = kolom_int;
				print_bangku(bangku_cruella_2); //print bangku dengan denah yang sudah terbooking tempatnya
				printf(" Bangku %c%d berhasil di booking \n\n", toupper(baris_char), kolom_int);
			}
			else{
				//untuk error handling jika input yang dimasukan sudah terisi
				i -= 1;
				printf(" Bangku yang anda pilih sudah terisi \n Silahkan pilih ulang Bangku Anda!\n");
			}			
		}
	}
	
//film ke-2 jam ke-1
	else if(film == 2 && jam == 1){
		print_bangku(bangku_conjuring_1);
		
		for(i = 0; i < banyak_tiket; i++){
			printf(" Pilih Bangku Anda (A1 - D8):");
			scanf(" %c", &baris_char);
			scanf(" %d", &kolom_int);
			//berfungsi jika input yang dimasukan tidak sesuai
			if ((baris_char == 65 || baris_char == 97 || baris_char == 66 || baris_char == 98 || baris_char == 67|| baris_char == 99 || baris_char == 68 || baris_char == 100) && (kolom_int >= 1 && kolom_int <= 8)){
				temp = baris_generator(baris_char);
			}
			else{
				printf(" Kursi Tidak Tersedia, Silahkan Masukkan Nomor Kursi dengan Benar!\n");
				i--;
				continue;
			}
			
			if(bangku_conjuring_1[temp][kolom_int-1] != 0){
				bangku_conjuring_1[temp][kolom_int-1] = 0;
				booked[i].row = baris_char;
				booked[i].coll = kolom_int;
				print_bangku(bangku_conjuring_1); //print bangku dengan denah yang sudah terbooking tempatnya
				printf(" Bangku %c%d berhasil di booking \n\n", toupper(baris_char), kolom_int);
			}
			else{
				//untuk error handling jika input yang dimasukan sudah terisi
				i -= 1;
				printf(" Bangku yang anda pilih sudah terisi \n Silahkan pilih ulang Bangku Anda!\n");
			}			
		}
	}
//film ke-2 jam ke-2
	else if(film == 2 && jam == 2){
		print_bangku(bangku_conjuring_2);
		
		for(i = 0; i<banyak_tiket; i++){
			printf(" Pilih Bangku Anda (A1 - D8):");
			scanf(" %c", &baris_char);
			scanf(" %d", &kolom_int);
			//berfungsi jika input yang dimasukan tidak sesuai
			if ((baris_char == 65 || baris_char == 97 || baris_char == 66 || baris_char == 98 || baris_char == 67|| baris_char == 99 || baris_char == 68 || baris_char == 100) && (kolom_int >= 1 && kolom_int <= 8)){
				temp = baris_generator(baris_char);
			}
			else{
				//untuk error handling jika input yang dimasukan sudah terisi
				printf(" Kursi Tidak Tersedia, Silahkan Masukkan Nomor Kursi dengan Benar!\n");
				i--;
				continue;
			}
			
			if(bangku_conjuring_2[temp][kolom_int-1] != 0){
				bangku_conjuring_2[temp][kolom_int-1] = 0;
				booked[i].row = baris_char;
				booked[i].coll = kolom_int;
				print_bangku(bangku_conjuring_2); //print bangku dengan denah yang sudah terbooking tempatnya
				printf(" Bangku %c%d berhasil di booking \n\n", toupper(baris_char), kolom_int);
			}
			else{
				//untuk error handling jika input yang dimasukan sudah terisi
				i -= 1;
				printf(" Bangku yang anda pilih sudah terisi \n Silahkan pilih ulang Bangku Anda!\n");
			}			
		}
	}
//film ke-3 jam ke-1
	else if(film == 3 && jam == 1){
		print_bangku(bangku_spiderman_1);
		
		for(i = 0; i<banyak_tiket; i++){
			printf(" Pilih Bangku Anda (A1 - D8):");
			scanf(" %c", &baris_char);
			scanf(" %d", &kolom_int);
			//berfungsi jika input yang dimasukan tidak sesuai
			if ((baris_char == 65 || baris_char == 97 || baris_char == 66 || baris_char == 98 || baris_char == 67|| baris_char == 99 || baris_char == 68 || baris_char == 100) && (kolom_int >= 1 && kolom_int <= 8)){
				temp = baris_generator(baris_char);
			}
			else{
				printf(" Kursi Tidak Tersedia, Silahkan Masukkan Nomor Kursi dengan Benar!\n");
				i--;
				continue;
			}
			
			if(bangku_spiderman_1[temp][kolom_int-1] != 0){
				bangku_spiderman_1[temp][kolom_int-1] = 0;
				booked[i].row = baris_char;
				booked[i].coll = kolom_int;
				print_bangku(bangku_spiderman_1); //print bangku dengan denah yang sudah terbooking tempatnya
				printf(" Bangku %c%d berhasil di booking \n\n", toupper(baris_char), kolom_int);
			}
			else{
				//untuk error handling jika input yang dimasukan sudah terisi
				i -= 1;
				printf(" Bangku yang anda pilih sudah terisi \n Silahkan pilih ulang Bangku Anda!\n");
			}			
		}
	}
//film ke-3 jam ke-2
	else if(film == 3 && jam == 2){
		print_bangku(bangku_spiderman_2);
		
		for(i = 0; i<banyak_tiket; i++){
			printf(" Pilih Bangku Anda (A1 - D8):");
			scanf(" %c", &baris_char);
			scanf(" %d", &kolom_int);
			//berfungsi jika input yang dimasukan tidak sesuai
		if ((baris_char == 65 || baris_char == 97 || baris_char == 66 || baris_char == 98 || baris_char == 67|| baris_char == 99 || baris_char == 68 || baris_char == 100) && (kolom_int >= 1 && kolom_int <= 8)){
				temp = baris_generator(baris_char);
			}
			else{
				printf(" Kursi Tidak Tersedia, Silahkan Masukkan Nomor Kursi dengan Benar!\n");
				i--;
				continue;
			}
			
			if(bangku_spiderman_2[temp][kolom_int-1] != 0){
				bangku_spiderman_2[temp][kolom_int-1] = 0;
				booked[i].row = baris_char;
				booked[i].coll = kolom_int;
				print_bangku(bangku_spiderman_2); //print bangku dengan denah yang sudah terbooking tempatnya
				printf(" Bangku %c%d berhasil di booking \n\n", toupper(baris_char), kolom_int);
			}
			else{
				//untuk error handling jika input yang dimasukan sudah terisi
				i -= 1;
				printf(" Bangku yang anda pilih sudah terisi \n Silahkan pilih ulang Bangku Anda!\n");
			}			
		}
	}
	printf("\n");
}

//DATA DIRI
int input_datadiri(){
	//keperluan nama dan data nomer telepon untuk melakukan pembayaran via GOPAY, OVO, maupun VA Billing
	printf(" Masukkan data diri anda:\n");
	printf(" Nama\t: ");
	scanf("%s", &nama);
	printf(" No telp: ");
	scanf(" %s", &notelp);
}

//SISTEM PEMBAYARAN
int pembayaran(int banyak_tiket){
	int carabayar;
	printf("\n");
	printf("Total Pembayaran Anda: Rp%.3f", banyak_tiket*hargatiket);
	printf(" Menu Pembayaran:\n 1. Gopay\n 2. OVO\n 3. VA billing\n");
	printf(" Silakan Pilih Pembayaran: ");
	scanf("%d", &carabayar);
	//Gopay
	if(carabayar==1){ 
		printf("\n Pembayaran Anda: Gopay");
		printf("\n Tagihan akan dikirim ke akun Gopay anda, silahkan lakukan pembayaran");
		sleep(1);
		printf("\n Menunggu Konfirmasi");
		delay(1);
		printf("\n Pembayaran dengan Gopay berhasil");
	}
	//OVO
	else if(carabayar ==2){
		printf("\n Pembayaran Anda: Ovo");
		printf("\n Tagihan akan dikirim ke akun OVO anda, silahkan lakukan pembayaran");
		sleep(1);
		printf("\n Menunggu Konfirmasi");
		delay(1);
		printf("\n Pembayaran dengan Ovo berhasil");
	}
	//VA Billing
	else if(carabayar==3){
		printf("\n Pembayaran Anda  : VA Billing");
		printf("\n Nomor VA Billing : 8806%s",notelp);
		sleep(1);
		printf("\n Menunggu Konfirmasi");
		delay(1);
		printf("\n Pembayaran dengan nomer 8806%s Berhasil dilakukan", notelp);
	}
}

//DELAY PEMBAYARAN
void delay(int sec){
	for(i = 0; i <= 7; i++){ //7 merupakan banyaknya '.' dimana memakan waktu sama dengan detiknya
		printf(" .");
		sleep(sec); //dleay pembayaran berfungsi menunjukan bahwa pembayaran sedang diproses
	}
}

//PRINT TIKET
void print_tiket(int nomor_tiket){ //tiket diprint sesuai dengan jumlah yang diinput
	printf("\n\n");
	printf(" +-------------------------------------------------+\n"); 
	printf(" |    Cinema    |           TIKET BIOSKOP          |\n");
	printf(" |      XXI     |      XXI PESONA SQUARE DEPOK     |\n");
	printf(" |______________|__________________________________|\n");
	printf(" |              |                                  |\n");
	printf(" |   QR Code:   |Judul Film : %s          |\n", judul_film[film]); //judul film sesuai dengan yang diinput
	printf(" |   +-------+  |Studio     : %d                    |\n", film); // studio sesuai dengan yang diinput
	printf(" |   |::__..:|  |Jam        : "); 
	if(film == 1 ){
		printf("%.2f                |\n", jamA[jam]);
	}
	else if(film == 2 | film == 3){
		printf("%.2f                |\n", jamB[jam]);
	}
	printf(" |   |::__..:|  |Bangku     : %c%d                   |\n", booked[nomor_tiket].row, booked[nomor_tiket].coll); 
	printf(" |   |..::__:|  |                                  |\n");
	printf(" |   +-------+  |                       CINEMA XXI |\n");
	printf(" +-------------------------------------------------+\n"); 
}

//program selesai
