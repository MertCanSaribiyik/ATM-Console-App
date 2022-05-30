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
	double elektrikTutar = 150 + rand() % 150;			//Elektrik faturasý random olarak belirlenir.
	double suTutar = 100 + rand() % 100;				//Su faturasý random olarak belirlenir.
	double dogalgazTutar = 200 + rand() % 300;			//Doðalgaz faturasý random olarak belirlenir.

	void faturaListesi(void) {
		cout << "Lütfen ödeyeceðiniz fatura seçeneði tuþlayýnýz ?" << endl;
		cout << "1.Elektrik Faturasý" << endl;
		cout << "2.Su Faturasý" << endl;
		cout << "3.Doðalgaz Faturasý" << endl;
		cout << "4.Geri" << endl;
		cout << "Seçiminiz : ";
		cin >> secim;
		cout << endl;
	}

	bool elektrikFaturasi(void) {
		cout << "	Elektirk Faturasý Ödeme" << endl;
		cout << "Lütfen baþta 0 olmadan on haneli abone numarasýný tuþlayýnýz : ";
		cin >> aboneNo;

		if (basamakSayisiHesaplama(aboneNo) == 10) {			//Basamak sayýsýný kontrol ediyorum.					
			cout << "Abone numaranýz doðru! Sisteme giriþ yapýlýyor... " << endl;
			cout << "Fatura tutarýnýz : " << elektrikTutar << " TL" << endl;
			return true;
		}

		else
			return false;
	}

	bool suFaturasi(void) {
		cout << "		Su Faturasý Ödeme" << endl;
		cout << "Lütfen baþta 0 olmadan on haneli abone numarasýný tuþlayýnýz : ";
		cin >> aboneNo;

		if (basamakSayisiHesaplama(aboneNo) == 10) {					//Basamak sayýsýný kontrol ediyorum.	
			cout << "Abone numaranýz doðru! Sisteme giriþ yapýlýyor... " << endl;
			cout << "Fatura tutarýnýz : " << suTutar << " TL" << endl;
			return true;
		}

		else
			return false;
	}

	bool dogalgazFaturasi(void) {
		cout << "	Doðalgaz Faturasý Ödeme" << endl;
		cout << "Lütfen baþta 0 olmadan on haneli abone numarasýný tuþlayýnýz : ";
		cin >> aboneNo;

		if (basamakSayisiHesaplama(aboneNo) == 10) {					//Basamak sayýsýný kontrol ediyorum.
			cout << "Abone numaranýz doðru! Sisteme giriþ yapýlýyor... " << endl;
			cout << "Fatura tutarýnýz : " << dogalgazTutar << " TL" << endl;
			return true;
		}

		else
			return false;
	}
};

class kriptoPara {
public:
	double btcFiyat = 2500, ethFiyat = 300, xrpFiyat = 5;				//Kripto para fiyatlarý. 
	double btcMiktar = 0.0, ethMiktar = 0.0, xrpMiktar = 0.0;			//Hesaptaki kripto para miktarlarý.
	string menuSecim = "NULL", kriptoSatinAlmaSecim = "NULL";

	void menu(void) {
		cout << "Lütfen aþaðýdaki iþlemlerden yapmak istediðiniz seçeneði tuþlayýnýz ?" << endl;
		cout << "1.Kripto para satýn alma." << endl;
		cout << "2.Kripto para cüzdan görüntüleme." << endl;
		cout << "3.Geri." << endl;
		cout << "Seçimiz : ";
		cin >> menuSecim;
		cout << endl;
	}

	void kriptoSatinAlma(void) {
		cout << "	Kripto Para Maðazasý" << endl;
		cout << "Lütfen almak istediðiniz kripto parayý tuþlayýnýz ?" << endl;
		cout << "1.Bitcoin Fiyat : " << btcFiyat << " TL" << endl;
		cout << "2.Ethereum Fiyat : " << ethFiyat << " TL" << endl;
		cout << "3.Ripple (XRP) Fiyat : " << xrpFiyat << " TL" << endl;
		cout << "4.Ýptal." << endl;
		cout << "Seçimiz : ";
		cin >> kriptoSatinAlmaSecim;
		cout << endl;
	}

	void kriptoCuzdanGoruntuleme(void) {
		cout << "  Kripto Cüzdaným" << endl;
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
		cout << "Lütfen aþaðýdaki iþlemlerden yapmak istediðiniz seçeneði tuþlayýnýz ?" << endl;
		cout << "1.Kartýnýza bakiye yükleme." << endl;
		cout << "2.Kartýnýzýnýn bakiyesini sorgulama." << endl;
		cout << "3.Geri." << endl;
		cout << "Seçiminiz : ";
		cin >> secim;
		cout << endl;
	}

	bool paraYukleme(void) {
		cout << "					Ýstanbulkart Bakiye Yükleme" << endl;
		cout << "Lütfen istanbulkartýnýzýnýn ön yüzündeki 16 haneli numaranýn son 8 hanesini tuþlayýnýz : ";
		cin >> kartNo;
		cout << endl << endl;

		if (basamakSayisiHesaplama(kartNo) == 8) {			//Basamak sayýsýný kontrol ediyorum.
			cout << "Kart numaranýz doðru! Sisteme giriþ yapýlýyor... " << endl;
			cout << "Ýstanbulkartýnýzýn mevcut bakiyesi : " << kartBakiye << " TL" << endl;
			cout << "Ýstanbul karta yüklemek istediðiniz miktarý tuþlayýnýz : ";
			cin >> tutar;
			cout << endl;

			return true;
		}

		else {
			cout << "Yanlýþ kart numarasý tuþladýnýz..." << endl;
			cout << "-------------------------------------------------------------" << endl << endl;
			return false;
		}
	}

	void bakiyeSorgulama(void) {
		cout << "					Ýstanbulkart Bakiye Sorgulama" << endl;
		cout << "Lütfen istanbulkartýnýzýnýn ön yüzündeki 16 haneli numaranýn son 8 hanesini tuþlayýnýz : ";
		cin >> kartNo;
		cout << endl;

		if (basamakSayisiHesaplama(kartNo) == 8) {			//Basamak sayýsýný kontrol ediyorum.
			cout << "Kart numaranýz doðru! Sisteme giriþ yapýlýyor... " << endl;
			cout << "Ýstanbulkartýnýzýn mevcut bakiyesi : " << kartBakiye << " TL" << endl;
			cout << "-------------------------------------------------------------" << endl << endl;
		}

		else {
			cout << "Yanlýþ kart numarasý tuþladýnýz..." << endl;
			cout << "-------------------------------------------------------------" << endl << endl;
		}
	}
};

class hayirKurumlari {
public:
	double tutar = 0.0;
	string secim = "NULL";

	void menu(void) {
		cout << "Lütfen baðýþ yapacaðýnýz hayýr kurumunu tuþlayýnýz ?" << endl;
		cout << "1.TEMA.     2.LÖSEV.     3.AKUT.     4.Kýzýlay.     5.Geri." << endl;
		cout << "Seçimiz = ";
		cin >> secim;
		cout << endl;
	}

	void bagisMenusu(void) {
		cout << "		Baðýþ Ekraný" << endl;
		cout << "Yapmak istediðiniz baðýþ miktarýný tuþlayýnýz : ";
		cin >> tutar;
		cout << endl;
	}
};

class sporTakimlari {
public:
	double tutar = 0.0;
	string secim = "NULL";

	void menu(void) {
		cout << "Lütfen tuttuðunuz takýmý tuþlayýnýz ?" << endl;
		cout << "1.BEÞÝKTAÞ.     2.FENERBAHÇE.     3.GALATASARAY.     4.TRABZONSPOR.     5.Geri." << endl;
		cout << "Seçimiz = ";
		cin >> secim;
		cout << endl;
	}

	void bagisMenusu(void) {
		cout << "		Baðýþ Ekraný" << endl;
		cout << "Yapmak istediðiniz baðýþ miktarýný tuþlayýnýz : ";
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
		cout << "Lütfen aþaðýdaki menüden yapmak istediðiniz seçeneði tuþlayýnýz ?" << endl;
		cout << "1.Giriþ Yapma			2.Hesap Oluþturma.			3.Çýkýþ." << endl;
		cout << "Seçiminiz : ";
		cin >> menuSecim;
		cout << endl;
	}

	bool girisYapma(int* indeks) {
		unsigned long long int hesapNoKontrol, sifreKontrol;

		cout << "	GÝRÝÞ YAPMA" << endl;
		cout << "Hesap numaranýzý tuþlayýnýz : ";
		cin >> hesapNoKontrol;
		cout << "Þifrenizi tuþlayýnýz : ";
		cin >> sifreKontrol;
		cout << endl;

		for (int k = 1; k < 1000; k++) {
			if (hesapNoKontrol == hesapNo[k] && sifreKontrol == sifre[k]) {
				cout << "Hoþgeldiniz! Sisteme baðlandýnýz..." << endl;
				*indeks = k;	//indeks deðiþkenini maindeki i deðiþkenine eþitliyoruz. Bu sayede her kullanýcýnýn hesap iþlemleri farklý oluyor.
				return true;
			}
		}

		cout << "Hesap numaranýz veya þifreniz yanlýþ. Giriþ baþarýsýz oldu..." << endl;
		cout << "-----------------------------------------------------------------------------" << endl << endl;
		return false;

	}

	int j = 1;		//Hesap oluþturma fonksiyonunda kullanýlacak.

	void hesapOlusturma(void) {
		cout << "	  MÜÞTERÝ KAYIT" << endl;
		cout << "Hesap numarasý tuþlayýnýz : ";
		cin >> hesapNo[j];
		cout << "Þifre tuþlayýnýz : ";
		cin >> sifre[j];
		cout << "Teþekkürler banka hesabýnýz baþarýyla oluþturulmuþtur..." << endl;
		cout << "-------------------------------------------------------------------------------------" << endl << endl;
		j++;
	}

	void islemler(void) {
		cout << "Lütfen aþaðýdaki iþlemlerden yapmak istediðiniz seçeneði tuþlayýnýz ?" << endl;
		cout << "1.Hesabýnýza para yatýrma." << endl;
		cout << "2.Hesabýnýzdan para çekme." << endl;
		cout << "3.Hesap bakiyesini görüntüleme." << endl;
		cout << "4.Diðer iþlemler." << endl;
		cout << "5.Hesabýnýzdan çýkýþ yapma." << endl;
		cout << "Seçiminiz : ";
		cin >> islemSecim;
		cout << endl;
	}

	void paraYatirma(void) {
		long double para;

		cout << "Hesabýnýzýn mevcut bakiyesi : " << bakiye << " TL" << endl;
		cout << "Yatýrmak istediðiniz miktarý tuþlayýnýz : ";
		cin >> para;

		bakiye += para;

		cout << "Hesabýnýzýn yeni bakiyesi : " << bakiye << " TL" << endl;
		cout << "---------------------------------------------------------------------------" << endl << endl;

		ekranTemizleme();
	}

	void paraCekme(void) {
		long double para;

		cout << "Hesabýnýzýn mevcut bakiyesi : " << bakiye << " TL" << endl;
		cout << "Lütfen çekmek istediðiniz miktarý tuþlayýnýz : ";
		cin >> para;

		if (bakiye >= para) {
			bakiye -= para;
			cout << "Hesabýnýzýn yeni bakiyesi : " << bakiye << " TL" << endl;
			cout << "---------------------------------------------------------------------------" << endl << endl;
		}
		else
			cout << "Yetesiz bakiye..." << endl << endl;

		ekranTemizleme();
	}

	void bakiyeSorgulama(void) {
		cout << "Hesabýnýzýnýn mevcut bakiyesi : " << bakiye << " TL" << endl;
		cout << "---------------------------------------------------------------------------" << endl << endl;
	}

	void digerIslemler(void) {
		cout << "Lütfen aþaðýdaki iþlemlerden istediðiniz seçeneði tuþlayýnýz ?" << endl;
		cout << "1.Fatura Ödeme." << endl;
		cout << "2.Kripto Para Ýþlemleri." << endl;
		cout << "3.Ýstanbulkart Ýþlemleri." << endl;
		cout << "4.Baðýþ yapma. (TEMA, LÖSEV, AKUT, Kýzýlay)" << endl;
		cout << "5.Takýmýna destek olma. (Beþiktaþ, Fenerbahçe, Galatasaray, Trabzonspor)" << endl;
		cout << "6.Geri." << endl;
		cout << "Seçiminiz : ";
		cin >> digerIslemlerSecim;
		cout << endl;
	}

	fatura musteriFatura;							//Fatura nesnesini çaðýrýr.
	kriptoPara musteriKriptoPara;					//KriptoPara nesnesini çaðýrýr.
	istanbulkart musteriIstanbulkart;				//istanbulkart nesnesini çaðýrýr.
	hayirKurumlari musteriHayirKurumuYardim;		//hayirKurumlari nesnesini çaðýrýr.
	sporTakimlari musteriTakimi;					//sporTakimlari nesnesini çaðýrýr.
}ATM[1000];		//Birden fazla kullanýcý iþlem yapabilmesi için ekledim. 999 farklý kiþi girebiliyor. Çünkü 0. indeks menü için.

int i = 0;

int main() {
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));

	int sayac = 0;

	cout << "*************** ZAMAR BANKASI ***************" << endl;
	cout << "Merhaba! Zamar Bankasý ATM makinesine hoþgeldiniz..." << endl << endl;

	while (1) {
		ATM[i].menu();
		if (ATM[i].menuSecim == "1") {				//Giriþ yapma
			if (ATM[i].girisYapma(&i) == true) {	//Hesaba baþarýlý giriþ yapýlmýþtýr.
				ekranTemizleme();
				while (1) {
					ATM[i].islemler();

					if (ATM[i].islemSecim == "1") 		//Para yatýrma ekraný.
						ATM[i].paraYatirma();
					else if (ATM[i].islemSecim == "2") 			//Para çekme ekraný.
						ATM[i].paraCekme();
					else if (ATM[i].islemSecim == "3") { 			//Bakiye sorgulama ekraný.
						ATM[i].bakiyeSorgulama();
					}
					else if (ATM[i].islemSecim == "4") {
						ekranTemizleme();

						while (1) {
							ATM[i].digerIslemler();

							if (ATM[i].digerIslemlerSecim == "1") {				//Fatura listesi görüntüleme ekraný.
								ekranTemizleme();
								faturaOdemeIslemleri();
							}

							else if (ATM[i].digerIslemlerSecim == "2") {		//Kripto para iþlemleri görüntüleme ekraný.
								ekranTemizleme();
								kriptoParaIslemleri();
							}

							else if (ATM[i].digerIslemlerSecim == "3") {		//Ýstanbulkart iþlemleri görüntüleme  ekraný.
								ekranTemizleme();
								istanbulkartIslemleri();
							}

							else if (ATM[i].digerIslemlerSecim == "4") {		//Baðýþ yapma görüntüleme ekraný.
								ekranTemizleme();
								hayirKurumlariIslemleri();
							}

							else if (ATM[i].digerIslemlerSecim == "5") {		//Takýmýna destek olma görüntüleme ekraný.
								ekranTemizleme();
								sporTakimlariIslemleri();
							}

							else if (ATM[i].digerIslemlerSecim == "6") {
								cout << "Geri dönülüyor..." << endl << endl;
								ekranTemizleme();
								break;
							}

							else {
								cout << "Tanýmsýz tuþlama..." << endl << endl;
								ekranTemizleme();
							}
						}
					}

					else if (ATM[i].islemSecim == "5") {
						cout << "Hesabýnýzdan çýkýþ yapýlýyor..." << endl;
						i = 0;
						sayac = 0;
						ekranTemizleme();
						break;
					}

					else {
						cout << "Tanýmsýz tuþlama..." << endl << endl;
						ekranTemizleme();
					}
				}
			}

			else {						//Baþarýsýz giriþ yapýldýðýnda sayaç bir artar.
				ekranTemizleme();
				sayac++;

				if (sayac == 3) {		//Eðer 3 kez baþarýsýz giriþ yapýlýrsa iþlem sonlanýr.
					cout << "3 kez baþarýsýz giris yaptýnýz. Güvenlik önlemleri nedeniyle çýkýþ yapýlýyor..." << endl;
					break;
				}
			}
		}

		else if (ATM[i].menuSecim == "2") {
			ATM[i].hesapOlusturma();
			ekranTemizleme();
		}

		else if (ATM[i].menuSecim == "3") {
			cout << "Hoþçakalýn! Yine bekleriz...";
			break;
		}

		else {
			cout << "Tanýmsýz tuþlama..." << endl << endl;
			ekranTemizleme();
		}

	}

	return 0;
}

void ekranTemizleme(void) {
	Sleep(1100);		//Ýþlemleri geciktirir.
	system("cls");		//Terminaldeki yazýlarý temizler.

}

int basamakSayisiHesaplama(unsigned long long int x) {
	int sayac = 0;

	while (x != 0) {		//Sayýyý 10`a bölüp tekrar sayýya eþitler ve sayaçý da artýrýr.
		x /= 10;			//Sayý = 0 olduðunda döngü sonlanýr. Sayaç deðeri basamak sayýsýný verir.
		sayac++;
	}

	return sayac;
}

bool ucretOdeme(long double* bakiye, double tutar) {
	if (*bakiye >= tutar) {
		cout << "Tutarýnýz ödeniyor..." << endl;

		*bakiye -= tutar;

		cout << "Hesabýnýzýn yeni bakiyesi : " << *bakiye << " TL" << endl;
		cout << "-------------------------------------------------------------" << endl << endl;

		return true;
	}

	else {
		cout << "Bakiyeniz yetersiz olduðundan tutarýnýz ödenememiþtir..." << endl;
		cout << "-------------------------------------------------------------" << endl << endl;

		return false;
	}
}

void faturaOdemeIslemleri(void) {
	while (1) {
		ATM[i].musteriFatura.faturaListesi();

		if (ATM[i].musteriFatura.secim == "1") {		//Elektrik faturasý görüntüleme ekraný."		
			if (ATM[i].musteriFatura.elektrikFaturasi() == true) {				//Her þey doðruysa ödeme alanýna gidilir.
				if (ATM[i].musteriFatura.elektrikTutar == 0) {					//Elektrik faturasý borcu yoksa ucretOdeme fonksiyonuna girilmez.
					cout << "Elektrik faturasý borcunuz yoktur..." << endl;
					cout << "Hesabýnýzýnýn mevcut bakiyesi : " << ATM[i].bakiye << " TL" << endl;
					cout << "-------------------------------------------------------------" << endl << endl;
				}

				else if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriFatura.elektrikTutar) == true) 	//Ücret doðru ödenirse elektrik faturasý borcu sýfýrlanýr.
					ATM[i].musteriFatura.elektrikTutar = 0;
			}

			else {
				cout << "Yanlýþ abone numarasý tuþladýnýz..." << endl;
				cout << "-------------------------------------------------------------" << endl << endl;
			}
		}

		else if (ATM[i].musteriFatura.secim == "2") {						//Su faturasý görüntüleme ekraný.		
			if (ATM[i].musteriFatura.suFaturasi() == true) {				//Her þey doðruysa ödeme alanýna gidilir.
				if (ATM[i].musteriFatura.suTutar == 0) {					//Su faturasý borcu yoksa ucretOdeme fonksiyonuna girilmez.				
					cout << "Su faturasý borcunuz yoktur..." << endl;
					cout << "Hesabýnýzýnýn mevcut bakiyesi : " << ATM[i].bakiye << " TL" << endl;
					cout << "-------------------------------------------------------------" << endl << endl;
				}

				else if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriFatura.suTutar) == true) 	//Ücret doðru ödenirse su faturasý borcu sýfýrlanýr.
					ATM[i].musteriFatura.suTutar = 0;
			}

			else {
				cout << "Yanlýþ abone numarasý tuþladýnýz..." << endl;
				cout << "-------------------------------------------------------------" << endl << endl;
			}
		}

		else if (ATM[i].musteriFatura.secim == "3") {						//Doðalgaz faturasý görüntüleme ekraný.
			if (ATM[i].musteriFatura.dogalgazFaturasi() == true) {			//Her þey doðruysa ödeme alanýna gidilir.
				if (ATM[i].musteriFatura.dogalgazTutar == 0) {				//Doðalgaz faturasý borcu yoksa ucretOdeme fonksiyonuna girilmez.				
					cout << "Doðalgaz faturasý borcunuz yoktur..." << endl;
					cout << "Hesabýnýzýnýn mevcut bakiyesi : " << ATM[i].bakiye << " TL" << endl;
					cout << "-------------------------------------------------------------" << endl << endl;
				}

				else if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriFatura.dogalgazTutar) == true) 	//Ücret doðru ödenirse elektrik faturasý borcu sýfýrlanýr.
					ATM[i].musteriFatura.dogalgazTutar = 0;
			}

			else {
				cout << "Yanlýþ abone numarasý tuþladýnýz..." << endl;
				cout << "-------------------------------------------------------------" << endl << endl;
			}
		}

		else if (ATM[i].musteriFatura.secim == "4") {
			cout << "Geri dönülüyor..." << endl << endl;
			ekranTemizleme();
			break;
		}

		else {
			cout << "Tanýmsýz tuþlama..." << endl << endl;
			ekranTemizleme();
		}
	}
}

void kriptoParaIslemleri(void) {
	int miktar;

	while (1) {
		ATM[i].musteriKriptoPara.menu();

		if (ATM[i].musteriKriptoPara.menuSecim == "1") {				//Kripto para satýn alma iþlemi
			while (1) {
				ATM[i].musteriKriptoPara.kriptoSatinAlma();

				if (ATM[i].musteriKriptoPara.kriptoSatinAlmaSecim == "1") {			//Bitcoin satýn alma.
					cout << "Kaç tane bitcoin alacaðýnýzý tuþlayýnýz : ";
					cin >> miktar;

					cout << "Ödenecek ücret : " << ATM[i].musteriKriptoPara.btcFiyat * miktar << " TL" << endl;

					if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriKriptoPara.btcFiyat * miktar) == true)
						ATM[i].musteriKriptoPara.btcMiktar += miktar;
				}

				else if (ATM[i].musteriKriptoPara.kriptoSatinAlmaSecim == "2") {			//Ethereum satýn alma.
					cout << "Kaç tane ethereum alacaðýnýzý tuþlayýnýz : ";
					cin >> miktar;

					cout << "Ödenecek ücret : " << ATM[i].musteriKriptoPara.ethFiyat * miktar << " TL" << endl;

					if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriKriptoPara.ethFiyat * miktar) == true)
						ATM[i].musteriKriptoPara.ethMiktar += miktar;
				}

				else if (ATM[i].musteriKriptoPara.kriptoSatinAlmaSecim == "3") {			//Ripple satýn alma.
					cout << "Kaç tane ripple (XRP) alacaðýnýzý tuþlayýnýz : ";
					cin >> miktar;

					cout << "Ödenecek ücret : " << ATM[i].musteriKriptoPara.xrpFiyat * miktar << " TL" << endl;

					if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriKriptoPara.xrpFiyat * miktar) == true)
						ATM[i].musteriKriptoPara.xrpMiktar += miktar;
				}

				else if (ATM[i].musteriKriptoPara.kriptoSatinAlmaSecim == "4") {
					cout << "Ýptal ediliyor..." << endl << endl;
					ekranTemizleme();
					break;
				}

				else
					cout << "Tanýmsýz tuþlama..." << endl << endl;
			}
		}

		else if (ATM[i].musteriKriptoPara.menuSecim == "2") {			//Kripto cüzdan görüntüleme.			
			ATM[i].musteriKriptoPara.kriptoCuzdanGoruntuleme();
		}

		else if (ATM[i].musteriKriptoPara.menuSecim == "3") {
			cout << "Geri dönülüyor..." << endl << endl;
			ekranTemizleme();
			break;
		}

		else {
			cout << "Tanýmsýz tuþlama..." << endl << endl;
			ekranTemizleme();
		}
	}
}

void istanbulkartIslemleri(void) {
	while (1) {
		ATM[i].musteriIstanbulkart.menu();

		if (ATM[i].musteriIstanbulkart.secim == "1") {					//Ýstanbulkart bakiye yükleme ekraný.
			if (ATM[i].musteriIstanbulkart.paraYukleme() == true) {	//Eðer kart numarasý doðruysa para yükleme sistemine giriþ yapýlýr.	
				if (ucretOdeme(&ATM[i].bakiye, ATM[i].musteriIstanbulkart.tutar) == true)			//Eðer bakiyeniz yeterliyse kartýnýza ücret ödenir.
					ATM[i].musteriIstanbulkart.kartBakiye += ATM[i].musteriIstanbulkart.tutar;
			}
		}

		else if (ATM[i].musteriIstanbulkart.secim == "2")		//Ýstanbulkart bakiye sorgulama ekraný.
			ATM[i].musteriIstanbulkart.bakiyeSorgulama();

		else if (ATM[i].musteriIstanbulkart.secim == "3") {
			cout << "Geri dönülüyor..." << endl << endl;
			ekranTemizleme();
			break;
		}

		else {
			cout << "Tanýmsýz tuþlama..." << endl << endl;
			ekranTemizleme();
		}
	}
}

void hayirKurumlariIslemleri(void) {
	while (1) {
		ATM[i].musteriHayirKurumuYardim.menu();

		if (ATM[i].musteriHayirKurumuYardim.secim == "1") {					//TEMA baðýþ ekraný.
			ATM[i].musteriHayirKurumuYardim.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriHayirKurumuYardim.tutar);
		}

		else if (ATM[i].musteriHayirKurumuYardim.secim == "2") {				//LÖSEV baðýþ ekraný.
			ATM[i].musteriHayirKurumuYardim.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriHayirKurumuYardim.tutar);
		}

		else if (ATM[i].musteriHayirKurumuYardim.secim == "3") {				//AKUT baðýþ ekraný.
			ATM[i].musteriHayirKurumuYardim.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriHayirKurumuYardim.tutar);
		}

		else if (ATM[i].musteriHayirKurumuYardim.secim == "4") {				//Kýzýlay baðýþ ekraný.
			ATM[i].musteriHayirKurumuYardim.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriHayirKurumuYardim.tutar);
		}

		else if (ATM[i].musteriHayirKurumuYardim.secim == "5") {
			cout << "Geri dönülüyor..." << endl << endl;
			ekranTemizleme();
			break;
		}

		else {
			cout << "Tanýmsýz tuþlama..." << endl << endl;
			ekranTemizleme();
		}
	}
}

void sporTakimlariIslemleri(void) {
	while (1) {
		ATM[i].musteriTakimi.menu();

		if (ATM[i].musteriTakimi.secim == "1") {								//Beþiktaþ baðýþ ekraný.
			ATM[i].musteriTakimi.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriTakimi.tutar);
		}

		else if (ATM[i].musteriTakimi.secim == "2") {						//Fenerbahçe baðýþ ekraný.
			ATM[i].musteriTakimi.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriTakimi.tutar);
		}

		else if (ATM[i].musteriTakimi.secim == "3") {						//Galatasaray baðýþ ekraný.
			ATM[i].musteriTakimi.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriTakimi.tutar);
		}

		else if (ATM[i].musteriTakimi.secim == "4") {						//Trabzonspor baðýþ ekraný.
			ATM[i].musteriTakimi.bagisMenusu();
			ucretOdeme(&ATM[i].bakiye, ATM[i].musteriTakimi.tutar);
		}

		else if (ATM[i].musteriTakimi.secim == "5") {
			cout << "Geri dönülüyor..." << endl << endl;
			ekranTemizleme();
			break;
		}

		else {
			cout << "Tanýmsýz tuþlama..." << endl << endl;
			ekranTemizleme();
		}
	}
}