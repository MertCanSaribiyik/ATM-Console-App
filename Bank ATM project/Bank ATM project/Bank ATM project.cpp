#include <iostream>
#include <string>
#include <clocale>
#include <ctime>
#include <Windows.h>

using namespace std;

void ekranTemizleme(void);
int basamakSayisiHesaplama(unsigned long long int x);
bool ucretOdeme(long double* bakiye, double tutar);
void faturaOdemeIslemleri(void);
void kriptoParaIslemleri(void);
void istanbulkartIslemleri(void);
void hayirKurumlariIslemleri(void);
void sporTakimlariIslemleri(void);

class fatura {
public:
	unsigned long long int aboneNo = 0;
	string secim = "NULL";
	int elektrikSayac = 0, suSayac = 0, dogalgazSayac = 0;
	double elektrikTutar = 150 + rand() % 150;			//Elektrik faturas� random olarak belirlenir.
	double suTutar = 100 + rand() % 100;				//Su faturas� random olarak belirlenir.
	double dogalgazTutar = 200 + rand() % 300;			//Do�algaz faturas� random olarak belirlenir.

	void faturaListesi(void) {
		cout << "L�tfen �deyece�iniz fatura se�ene�i tu�lay�n�z ?" << endl;
		cout << "1.Elektrik Faturas�" << endl;
		cout << "2.Su Faturas�" << endl;
		cout << "3.Do�algaz Faturas�" << endl;
		cout << "4.Geri" << endl;
		cout << "Se�iminiz : ";
		cin >> secim;
		cout << endl;
	}

	bool elektrikFaturasi(void) {
		cout << "	Elektirk Faturas� �deme" << endl;
		cout << "L�tfen ba�ta 0 olmadan on haneli abone numaras�n� tu�lay�n�z : ";
		cin >> aboneNo;

		if (basamakSayisiHesaplama(aboneNo) == 10) {			//Basamak say�s�n� kontrol ediyorum.					
			cout << "Abone numaran�z do�ru! Sisteme giri� yap�l�yor... " << endl;
			cout << "Fatura tutar�n�z : " << elektrikTutar << " TL" << endl;
			return true;
		}

		else
			return false;
	}

	bool suFaturasi(void) {
		cout << "		Su Faturas� �deme" << endl;
		cout << "L�tfen ba�ta 0 olmadan on haneli abone numaras�n� tu�lay�n�z : ";
		cin >> aboneNo;

		if (basamakSayisiHesaplama(aboneNo) == 10) {					//Basamak say�s�n� kontrol ediyorum.	
			cout << "Abone numaran�z do�ru! Sisteme giri� yap�l�yor... " << endl;
			cout << "Fatura tutar�n�z : " << suTutar << " TL" << endl;
			return true;
		}

		else
			return false;
	}

	bool dogalgazFaturasi(void) {
		cout << "	Do�algaz Faturas� �deme" << endl;
		cout << "L�tfen ba�ta 0 olmadan on haneli abone numaras�n� tu�lay�n�z : ";
		cin >> aboneNo;

		if (basamakSayisiHesaplama(aboneNo) == 10) {					//Basamak say�s�n� kontrol ediyorum.
			cout << "Abone numaran�z do�ru! Sisteme giri� yap�l�yor... " << endl;
			cout << "Fatura tutar�n�z : " << dogalgazTutar << " TL" << endl;
			return true;
		}

		else
			return false;
	}
};

class kriptoPara {
public:
	double btcFiyat = 2500, ethFiyat = 300, xrpFiyat = 5;				//Kripto para fiyatlar�. 
	double btcMiktar = 0.0, ethMiktar = 0.0, xrpMiktar = 0.0;			//Hesaptaki kripto para miktarlar�.
	string menuSecim = "NULL", kriptoSatinAlmaSecim = "NULL";

	void menu(void) {
		cout << "L�tfen a�a��daki i�lemlerden yapmak istedi�iniz se�ene�i tu�lay�n�z ?" << endl;
		cout << "1.Kripto para sat�n alma." << endl;
		cout << "2.Kripto para c�zdan g�r�nt�leme." << endl;
		cout << "3.Geri." << endl;
		cout << "Se�imiz : ";
		cin >> menuSecim;
		cout << endl;
	}

	void kriptoSatinAlma(void) {
		cout << "	Kripto Para Ma�azas�" << endl;
		cout << "L�tfen almak istedi�iniz kripto paray� tu�lay�n�z ?" << endl;
		cout << "1.Bitcoin Fiyat : " << btcFiyat << " TL" << endl;
		cout << "2.Ethereum Fiyat : " << ethFiyat << " TL" << endl;
		cout << "3.Ripple (XRP) Fiyat : " << xrpFiyat << " TL" << endl;
		cout << "4.�ptal." << endl;
		cout << "Se�imiz : ";
		cin >> kriptoSatinAlmaSecim;
		cout << endl;
	}

	void kriptoCuzdanGoruntuleme(void) {
		cout << "  Kripto C�zdan�m" << endl;
		cout << "Bitcoin (BTC) = " << btcMiktar << " adet" << endl;
		cout << "Ethereum (ETH) = " << ethMiktar << " adet" << endl;
		cout << "Ripple (XRP) = " << xrpMiktar << " adet" << endl;
		cout << "-------------------------------------------------------------" << endl << endl;
	}
};

class istanbulkart {
public:
	string secim = "NULL";
	unsigned long long int kartNo = 0;
	long double kartBakiye = 0.0;
	double tutar = 0.0;

	void menu(void) {
		cout << "L�tfen a�a��daki i�lemlerden yapmak istedi�iniz se�ene�i tu�lay�n�z ?" << endl;
		cout << "1.Kart�n�za bakiye y�kleme." << endl;
		cout << "2.Kart�n�z�n�n bakiyesini sorgulama." << endl;
		cout << "3.Geri." << endl;
		cout << "Se�iminiz : ";
		cin >> secim;
		cout << endl;
	}

	bool paraYukleme(void) {
		cout << "					�stanbulkart Bakiye Y�kleme" << endl;
		cout << "L�tfen istanbulkart�n�z�n�n �n y�z�ndeki 16 haneli numaran�n son 8 hanesini tu�lay�n�z : ";
		cin >> kartNo;
		cout << endl << endl;

		if (basamakSayisiHesaplama(kartNo) == 8) {			//Basamak say�s�n� kontrol ediyorum.
			cout << "Kart numaran�z do�ru! Sisteme giri� yap�l�yor... " << endl;
			cout << "�stanbulkart�n�z�n mevcut bakiyesi : " << kartBakiye << " TL" << endl;
			cout << "�stanbul karta y�klemek istedi�iniz miktar� tu�lay�n�z : ";
			cin >> tutar;
			cout << endl;

			return true;
		}

		else {
			cout << "Yanl�� kart numaras� tu�lad�n�z..." << endl;
			cout << "-------------------------------------------------------------" << endl << endl;
			return false;
		}
	}

	void bakiyeSorgulama(void) {
		cout << "					�stanbulkart Bakiye Sorgulama" << endl;
		cout << "L�tfen istanbulkart�n�z�n�n �n y�z�ndeki 16 haneli numaran�n son 8 hanesini tu�lay�n�z : ";
		cin >> kartNo;
		cout << endl;

		if (basamakSayisiHesaplama(kartNo) == 8) {			//Basamak say�s�n� kontrol ediyorum.
			cout << "Kart numaran�z do�ru! Sisteme giri� yap�l�yor... " << endl;
			cout << "�stanbulkart�n�z�n mevcut bakiyesi : " << kartBakiye << " TL" << endl;
			cout << "-------------------------------------------------------------" << endl << endl;
		}

		else {
			cout << "Yanl�� kart numaras� tu�lad�n�z..." << endl;
			cout << "-------------------------------------------------------------" << endl << endl;
		}
	}
};

class hayirKurumlari {
public:
	double tutar = 0.0;
	string secim = "NULL";

	void menu(void) {
		cout << "L�tfen ba��� yapaca��n�z hay�r kurumunu tu�lay�n�z ?" << endl;
		cout << "1.TEMA.     2.L�SEV.     3.AKUT.     4.K�z�lay.     5.Geri." << endl;
		cout << "Se�imiz = ";
		cin >> secim;
		cout << endl;
	}

	void bagisMenusu(void) {
		cout << "		Ba��� Ekran�" << endl;
		cout << "Yapmak istedi�iniz ba��� miktar�n� tu�lay�n�z : ";
		cin >> tutar;
		cout << endl;
	}
};

class sporTakimlari {
public:
	double tutar = 0.0;
	string secim = "NULL";

	void menu(void) {
		cout << "L�tfen tuttu�unuz tak�m� tu�lay�n�z ?" << endl;
		cout << "1.BE��KTA�.     2.FENERBAH�E.     3.GALATASARAY.     4.TRABZONSPOR.     5.Geri." << endl;
		cout << "Se�imiz = ";
		cin >> secim;
		cout << endl;
	}

	void bagisMenusu(void) {
		cout << "		Ba��� Ekran�" << endl;
		cout << "Yapmak istedi�iniz ba��� miktar�n� tu�lay�n�z : ";
		cin >> tutar;
		cout << endl;
	}
};

class atmMakinesi {
public:
	unsigned long long int hesapNo[1000], sifre[1000];
	string menuSecim = "NULL", islemSecim = "NULL", digerIslemlerSecim = "NULL";
	long double bakiye = 0.0;

	void menu(void) {
		cout << "L�tfen a�a��daki men�den yapmak istedi�iniz se�ene�i tu�lay�n�z ?" << endl;
		cout << "1.Giri� Yapma			2.Hesap Olu�turma.			3.��k��." << endl;
		cout << "Se�iminiz : ";
		cin >> menuSecim;
		cout << endl;
	}

	bool girisYapma(int* indeks) {
		unsigned long long int hesapNoKontrol, sifreKontrol;

		cout << "	G�R�� YAPMA" << endl;
		cout << "Hesap numaran�z� tu�lay�n�z : ";
		cin >> hesapNoKontrol;
		cout << "�ifrenizi tu�lay�n�z : ";
		cin >> sifreKontrol;
		cout << endl;

		for (int k = 1; k < 1000; k++) {
			if (hesapNoKontrol == hesapNo[k] && sifreKontrol == sifre[k]) {
				cout << "Ho�geldiniz! Sisteme ba�land�n�z..." << endl;
				*indeks = k;	//indeks de�i�kenini maindeki i de�i�kenine e�itliyoruz. Bu sayede her kullan�c�n�n hesap i�lemleri farkl� oluyor.
				return true;
			}
		}

		cout << "Hesap numaran�z veya �ifreniz yanl��. Giri� ba�ar�s�z oldu..." << endl;
		cout << "-----------------------------------------------------------------------------" << endl << endl;
		return false;

	}

	int j = 1;		//Hesap olu�turma fonksiyonunda kullan�lacak.

	void hesapOlusturma(void) {
		cout << "	  M��TER� KAYIT" << endl;
		cout << "Hesap numaras� tu�lay�n�z : ";
		cin >> hesapNo[j];
		cout << "�ifre tu�lay�n�z : ";
		cin >> sifre[j];
		cout << "Te�ekk�rler banka hesab�n�z ba�ar�yla olu�turulmu�tur..." << endl;
		cout << "-------------------------------------------------------------------------------------" << endl << endl;
		j++;
	}

	void islemler(void) {
		cout << "L�tfen a�a��daki i�lemlerden yapmak istedi�iniz se�ene�i tu�lay�n�z ?" << endl;
		cout << "1.Hesab�n�za para yat�rma." << endl;
		cout << "2.Hesab�n�zdan para �ekme." << endl;
		cout << "3.Hesap bakiyesini g�r�nt�leme." << endl;
		cout << "4.Di�er i�lemler." << endl;
		cout << "5.Hesab�n�zdan ��k�� yapma." << endl;
		cout << "Se�iminiz : ";
		cin >> islemSecim;
		cout << endl;
	}

	void paraYatirma(void) {
		long double para;

		cout << "Hesab�n�z�n mevcut bakiyesi : " << bakiye << " TL" << endl;
		cout << "Yat�rmak istedi�iniz miktar� tu�lay�n�z : ";
		cin >> para;

		bakiye += para;

		cout << "Hesab�n�z�n yeni bakiyesi : " << bakiye << " TL" << endl;
		cout << "---------------------------------------------------------------------------" << endl << endl;

		ekranTemizleme();
	}

	void paraCekme(void) {
		long double para;

		cout << "Hesab�n�z�n mevcut bakiyesi : " << bakiye << " TL" << endl;
		cout << "L�tfen �ekmek istedi�iniz miktar� tu�lay�n�z : ";
		cin >> para;

		if (bakiye >= para) {
			bakiye -= para;
			cout << "Hesab�n�z�n yeni bakiyesi : " << bakiye << " TL" << endl;
			cout << "---------------------------------------------------------------------------" << endl << endl;
		}
		else
			cout << "Yetesiz bakiye..." << endl << endl;

		ekranTemizleme();
	}

	void bakiyeSorgulama(void) {
		cout << "Hesab�n�z�n�n mevcut bakiyesi : " << bakiye << " TL" << endl;
		cout << "---------------------------------------------------------------------------" << endl << endl;
	}

	void digerIslemler(void) {
		cout << "L�tfen a�a��daki i�lemlerden istedi�iniz se�ene�i tu�lay�n�z ?" << endl;
		cout << "1.Fatura �deme." << endl;
		cout << "2.Kripto Para ��lemleri." << endl;
		cout << "3.�stanbulkart ��lemleri." << endl;
		cout << "4.Ba��� yapma. (TEMA, L�SEV, AKUT, K�z�lay)" << endl;
		cout << "5.Tak�m�na destek olma. (Be�ikta�, Fenerbah�e, Galatasaray, Trabzonspor)" << endl;
		cout << "6.Geri." << endl;
		cout << "Se�iminiz : ";
		cin >> digerIslemlerSecim;
		cout << endl;
	}

	fatura musteriFatura;							//Fatura nesnesini �a��r�r.
	kriptoPara musteriKriptoPara;					//KriptoPara nesnesini �a��r�r.
	istanbulkart musteriIstanbulkart;				//istanbulkart nesnesini �a��r�r.
	hayirKurumlari musteriHayirKurumuYardim;		//hayirKurumlari nesnesini �a��r�r.
	sporTakimlari musteriTakimi;					//sporTakimlari nesnesini �a��r�r.
}ATM[1000];		//Birden fazla kullan�c� i�lem yapabilmesi i�in ekledim. 999 farkl� ki�i girebiliyor. ��nk� 0. indeks men� i�in.

int i = 0;

int main() {
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));

	int sayac = 0;

	cout << "*************** ZAMAR BANKASI ***************" << endl;
	cout << "Merhaba! Zamar Bankas� ATM makinesine ho�geldiniz..." << endl << endl;

	while (1) {
		ATM[i].menu();
		if (ATM[i].menuSecim == "1") {				//Giri� yapma
			if (ATM[i].girisYapma(&i) == true) {	//Hesaba ba�ar�l� giri� yap�lm��t�r.
				ekranTemizleme();
				while (1) {
					ATM[i].islemler();

					if (ATM[i].islemSecim == "1") 		//Para yat�rma ekran�.
						ATM[i].paraYatirma();
					else if (ATM[i].islemSecim == "2") 			//Para �ekme ekran�.
						ATM[i].paraCekme();
					else if (ATM[i].islemSecim == "3") { 			//Bakiye sorgulama ekran�.
						ATM[i].bakiyeSorgulama();
					}
					else if (ATM[i].islemSecim == "4") {
						ekranTemizleme();

						while (1) {
							ATM[i].digerIslemler();

							if (ATM[i].digerIslemlerSecim == "1") {				//Fatura listesi g�r�nt�leme ekran�.
								ekranTemizleme();
								faturaOdemeIslemleri();
							}

							else if (ATM[i].digerIslemlerSecim == "2") {		//Kripto para i�lemleri g�r�nt�leme ekran�.
								ekranTemizleme();
								kriptoParaIslemleri();
							}

							else if (ATM[i].digerIslemlerSecim == "3") {		//�stanbulkart i�lemleri g�r�nt�leme  ekran�.
								ekranTemizleme();
								istanbulkartIslemleri();
							}

							else if (ATM[i].digerIslemlerSecim == "4") {		//Ba��� yapma g�r�nt�leme ekran�.
								ekranTemizleme();
								hayirKurumlariIslemleri();
							}

							else if (ATM[i].digerIslemlerSecim == "5") {		//Tak�m�na destek olma g�r�nt�leme ekran�.
								ekranTemizleme();
								sporTakimlariIslemleri();
							}

							else if (ATM[i].digerIslemlerSecim == "6") {
								cout << "Geri d�n�l�yor..." << endl << endl;
								ekranTemizleme();
								break;
							}

							else {
								cout << "Tan�ms�z tu�lama..." << endl << endl;
								ekranTemizleme();
							}
						}
					}

					else if (ATM[i].islemSecim == "5") {
						cout << "Hesab�n�zdan ��k�� yap�l�yor..." << endl;
						i = 0;
						sayac = 0;
						ekranTemizleme();
						break;
					}

					else {
						cout << "Tan�ms�z tu�lama..." << endl << endl;
						ekranTemizleme();
					}
				}
			}

			else {						//Ba�ar�s�z giri� yap�ld���nda saya� bir artar.
				ekranTemizleme();
				sayac++;

				if (sayac == 3) {		//E�er 3 kez ba�ar�s�z giri� yap�l�rsa i�lem sonlan�r.
					cout << "3 kez ba�ar�s�z giris yapt�n�z. G�venlik �nlemleri nedeniyle ��k�� yap�l�yor..." << endl;
					break;
				}
			}
		}

		else if (ATM[i].menuSecim == "2") {
			ATM[i].hesapOlusturma();
			ekranTemizleme();
		}

		else if (ATM[i].menuSecim == "3") {
			cout << "Ho��akal�n! Yine bekleriz...";
			break;
		}

		else {
			cout << "Tan�ms�z tu�lama..." << endl << endl;
			ekranTemizleme();
		}

	}

	return 0;
}

void ekranTemizleme(void) {
	Sleep(1100);		//��lemleri geciktirir.
	system("cls");		//Terminaldeki yaz�lar� temizler.

}

int basamakSayisiHesaplama(unsigned long long int x) {
	int sayac = 0;

	while (x != 0) {		//Say�y� 10`a b�l�p tekrar say�ya e�itler ve saya�� da art�r�r.
		x /= 10;			//Say� = 0 oldu�unda d�ng� sonlan�r. Saya� de�eri basamak say�s�n� verir.
		sayac++;
	}

	return sayac;
}

bool ucretOdeme(long double* bakiye, double tutar) {
	if (*bakiye >= tutar) {
		cout << "Tutar�n�z �deniyor..." << endl;

		*bakiye -= tutar;

		cout << "Hesab�n�z�n yeni bakiyesi : " << *bakiye << " TL" << endl;
		cout << "-------------------------------------------------------------" << endl << endl;

		return true;
	}

	else {
		cout << "Bakiyeniz yetersiz oldu�undan tutar�n�z �denememi�tir..." << endl;
		cout << "-------------------------------------------------------------" << endl << endl;

		return false;
	}
}

void faturaOdemeIslemleri(void) {
	while (1) {
		ATM[i].musteriFatura.faturaListesi();

		if (ATM[i].musteriFatura.secim == "1") {		//Elektrik faturas� g�r�nt�leme ekran�."		
			if (ATM[i].musteriFatura.elektrikFaturasi() == true) {				//Her �ey do�ruysa �deme alan�na gidilir.
				if (ATM[i].musteriFatura.elektrikTutar == 0) {					//Elektrik faturas� borcu yoksa ucretOdeme fonksiyonuna girilmez.
					cout << "Elektrik faturas� borcunuz yoktur..." << endl;
					cout << "Hesab�n�z�n�n mevcut bakiyesi : " << ATM[i].bakiye << " TL" << endl;
					cout << "-------------------------------------------------------------" << endl << endl;
				}

				else if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriFatura.elektrikTutar) == true) 	//�cret do�ru �denirse elektrik faturas� borcu s�f�rlan�r.
					ATM[i].musteriFatura.elektrikTutar = 0;
			}

			else {
				cout << "Yanl�� abone numaras� tu�lad�n�z..." << endl;
				cout << "-------------------------------------------------------------" << endl << endl;
			}
		}

		else if (ATM[i].musteriFatura.secim == "2") {						//Su faturas� g�r�nt�leme ekran�.		
			if (ATM[i].musteriFatura.suFaturasi() == true) {				//Her �ey do�ruysa �deme alan�na gidilir.
				if (ATM[i].musteriFatura.suTutar == 0) {					//Su faturas� borcu yoksa ucretOdeme fonksiyonuna girilmez.				
					cout << "Su faturas� borcunuz yoktur..." << endl;
					cout << "Hesab�n�z�n�n mevcut bakiyesi : " << ATM[i].bakiye << " TL" << endl;
					cout << "-------------------------------------------------------------" << endl << endl;
				}

				else if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriFatura.suTutar) == true) 	//�cret do�ru �denirse su faturas� borcu s�f�rlan�r.
					ATM[i].musteriFatura.suTutar = 0;
			}

			else {
				cout << "Yanl�� abone numaras� tu�lad�n�z..." << endl;
				cout << "-------------------------------------------------------------" << endl << endl;
			}
		}

		else if (ATM[i].musteriFatura.secim == "3") {						//Do�algaz faturas� g�r�nt�leme ekran�.
			if (ATM[i].musteriFatura.dogalgazFaturasi() == true) {			//Her �ey do�ruysa �deme alan�na gidilir.
				if (ATM[i].musteriFatura.dogalgazTutar == 0) {				//Do�algaz faturas� borcu yoksa ucretOdeme fonksiyonuna girilmez.				
					cout << "Do�algaz faturas� borcunuz yoktur..." << endl;
					cout << "Hesab�n�z�n�n mevcut bakiyesi : " << ATM[i].bakiye << " TL" << endl;
					cout << "-------------------------------------------------------------" << endl << endl;
				}

				else if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriFatura.dogalgazTutar) == true) 	//�cret do�ru �denirse elektrik faturas� borcu s�f�rlan�r.
					ATM[i].musteriFatura.dogalgazTutar = 0;
			}

			else {
				cout << "Yanl�� abone numaras� tu�lad�n�z..." << endl;
				cout << "-------------------------------------------------------------" << endl << endl;
			}
		}

		else if (ATM[i].musteriFatura.secim == "4") {
			cout << "Geri d�n�l�yor..." << endl << endl;
			ekranTemizleme();
			break;
		}

		else {
			cout << "Tan�ms�z tu�lama..." << endl << endl;
			ekranTemizleme();
		}
	}
}

void kriptoParaIslemleri(void) {
	int miktar;

	while (1) {
		ATM[i].musteriKriptoPara.menu();

		if (ATM[i].musteriKriptoPara.menuSecim == "1") {				//Kripto para sat�n alma i�lemi
			while (1) {
				ATM[i].musteriKriptoPara.kriptoSatinAlma();

				if (ATM[i].musteriKriptoPara.kriptoSatinAlmaSecim == "1") {			//Bitcoin sat�n alma.
					cout << "Ka� tane bitcoin alaca��n�z� tu�lay�n�z : ";
					cin >> miktar;

					cout << "�denecek �cret : " << ATM[i].musteriKriptoPara.btcFiyat * miktar << " TL" << endl;

					if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriKriptoPara.btcFiyat * miktar) == true)
						ATM[i].musteriKriptoPara.btcMiktar += miktar;
				}

				else if (ATM[i].musteriKriptoPara.kriptoSatinAlmaSecim == "2") {			//Ethereum sat�n alma.
					cout << "Ka� tane ethereum alaca��n�z� tu�lay�n�z : ";
					cin >> miktar;

					cout << "�denecek �cret : " << ATM[i].musteriKriptoPara.ethFiyat * miktar << " TL" << endl;

					if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriKriptoPara.ethFiyat * miktar) == true)
						ATM[i].musteriKriptoPara.ethMiktar += miktar;
				}

				else if (ATM[i].musteriKriptoPara.kriptoSatinAlmaSecim == "3") {			//Ripple sat�n alma.
					cout << "Ka� tane ripple (XRP) alaca��n�z� tu�lay�n�z : ";
					cin >> miktar;

					cout << "�denecek �cret : " << ATM[i].musteriKriptoPara.xrpFiyat * miktar << " TL" << endl;

					if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriKriptoPara.xrpFiyat * miktar) == true)
						ATM[i].musteriKriptoPara.xrpMiktar += miktar;
				}

				else if (ATM[i].musteriKriptoPara.kriptoSatinAlmaSecim == "4") {
					cout << "�ptal ediliyor..." << endl << endl;
					ekranTemizleme();
					break;
				}

				else
					cout << "Tan�ms�z tu�lama..." << endl << endl;
			}
		}

		else if (ATM[i].musteriKriptoPara.menuSecim == "2") {			//Kripto c�zdan g�r�nt�leme.			
			ATM[i].musteriKriptoPara.kriptoCuzdanGoruntuleme();
		}

		else if (ATM[i].musteriKriptoPara.menuSecim == "3") {
			cout << "Geri d�n�l�yor..." << endl << endl;
			ekranTemizleme();
			break;
		}

		else {
			cout << "Tan�ms�z tu�lama..." << endl << endl;
			ekranTemizleme();
		}
	}
}

void istanbulkartIslemleri(void) {
	while (1) {
		ATM[i].musteriIstanbulkart.menu();

		if (ATM[i].musteriIstanbulkart.secim == "1") {					//�stanbulkart bakiye y�kleme ekran�.
			if (ATM[i].musteriIstanbulkart.paraYukleme() == true) {	//E�er kart numaras� do�ruysa para y�kleme sistemine giri� yap�l�r.	
				if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriIstanbulkart.tutar) == true)			//E�er bakiyeniz yeterliyse kart�n�za �cret �denir.
					ATM[i].musteriIstanbulkart.kartBakiye += ATM[i].musteriIstanbulkart.tutar;
			}
		}

		else if (ATM[i].musteriIstanbulkart.secim == "2")		//�stanbulkart bakiye sorgulama ekran�.
			ATM[i].musteriIstanbulkart.bakiyeSorgulama();

		else if (ATM[i].musteriIstanbulkart.secim == "3") {
			cout << "Geri d�n�l�yor..." << endl << endl;
			ekranTemizleme();
			break;
		}

		else {
			cout << "Tan�ms�z tu�lama..." << endl << endl;
			ekranTemizleme();
		}
	}
}

void hayirKurumlariIslemleri(void) {
	while (1) {
		ATM[i].musteriHayirKurumuYardim.menu();

		if (ATM[i].musteriHayirKurumuYardim.secim == "1") {					//TEMA ba��� ekran�.
			ATM[i].musteriHayirKurumuYardim.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriHayirKurumuYardim.tutar);
		}

		else if (ATM[i].musteriHayirKurumuYardim.secim == "2") {				//L�SEV ba��� ekran�.
			ATM[i].musteriHayirKurumuYardim.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriHayirKurumuYardim.tutar);
		}

		else if (ATM[i].musteriHayirKurumuYardim.secim == "3") {				//AKUT ba��� ekran�.
			ATM[i].musteriHayirKurumuYardim.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriHayirKurumuYardim.tutar);
		}

		else if (ATM[i].musteriHayirKurumuYardim.secim == "4") {				//K�z�lay ba��� ekran�.
			ATM[i].musteriHayirKurumuYardim.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriHayirKurumuYardim.tutar);
		}

		else if (ATM[i].musteriHayirKurumuYardim.secim == "5") {
			cout << "Geri d�n�l�yor..." << endl << endl;
			ekranTemizleme();
			break;
		}

		else {
			cout << "Tan�ms�z tu�lama..." << endl << endl;
			ekranTemizleme();
		}
	}
}

void sporTakimlariIslemleri(void) {
	while (1) {
		ATM[i].musteriTakimi.menu();

		if (ATM[i].musteriTakimi.secim == "1") {								//Be�ikta� ba��� ekran�.
			ATM[i].musteriTakimi.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriTakimi.tutar);
		}

		else if (ATM[i].musteriTakimi.secim == "2") {						//Fenerbah�e ba��� ekran�.
			ATM[i].musteriTakimi.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriTakimi.tutar);
		}

		else if (ATM[i].musteriTakimi.secim == "3") {						//Galatasaray ba��� ekran�.
			ATM[i].musteriTakimi.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriTakimi.tutar);
		}

		else if (ATM[i].musteriTakimi.secim == "4") {						//Trabzonspor ba��� ekran�.
			ATM[i].musteriTakimi.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriTakimi.tutar);
		}

		else if (ATM[i].musteriTakimi.secim == "5") {
			cout << "Geri d�n�l�yor..." << endl << endl;
			ekranTemizleme();
			break;
		}

		else {
			cout << "Tan�ms�z tu�lama..." << endl << endl;
			ekranTemizleme();
		}
	}
}