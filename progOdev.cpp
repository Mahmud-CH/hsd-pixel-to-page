/***********************************************
**		      SAKARYA UNIVERSITESI
**	BILGISAYAR VE BILISIM BILIMLERI FAKULTESI
**	BILGISAYAR MUHENDISLIGI BOLUMU
**	PROGRAMLAMAYA GIRISI DERSI
**	
**	ODEV NUMARASI.: 1.Odev
**	OGRENCI ADI.: Mahmud Chazli
**	OGRENCI NUMARASI.: B251210561
**  DERS GRUBU.: 1.A
***********************************************/


#include <iostream>
#include <ctime> // time(NULL) icin
#include <cmath> // standart sapma icin (sqrt() ve pow())
#include <sstream> // basNot desimal sayilari duzgun gostermek icin (str() ve stringstream)
#include <iomanip> // istedigim desimal kadar almasi icin (fixed ve setprecision)
#include <clocale> // visual studioda turkce dil icin (setlocale())
#include <cstdlib> // ne olur ne olmaz (srand ve rand icin)
using namespace std;


// int main() temiz gozuksun diye bu kadar fonksiyon kullandim
void siniflar();
void ogrenciArama(int sinif);
void ogrenciBilYaz(int sinif, int ogrSay);
void ogrenciBilgi(struct ogrenci sinif[], int ders);
void standartSap(struct ogrenci sinif[], int ders);
int stringToInt(string stringOgr);
double yilIciHesap(int odev1, int odev2, int proje, int vize);
double genelNotHesaplama(int final, double yilIci);
string ogrenciTel(string ogrenci);
string basariNotu(double basNotSayi);
string isimSoySeh(int sira, int randNum);


struct ogrenci
{
  string ad = "";
  string soyad = "";
  string telNum = "";
  string sehir = "";
  string dersAd = "";
  string basNot = "";
  int odev1 = 0;
  int odev2 = 0;
  int proje = 0;
  int vize = 0;
  int final = 0;
  double yilIci = 0;
  double genelNot = 0;
};
struct sinifNot 
{
  double ortalama;
  string stanSap;
};

// yuz ogrencilik siniflar sinif
ogrenci programlamayaGiris[100];
ogrenci matematic[100];
ogrenci fizik[100];
ogrenci bilgisayarGiris[100];
ogrenci ingilizce[100];

// siniflarin standart sapma ve ortalamalari
sinifNot progNotlar;
sinifNot matNotlar;
sinifNot fizNotlar;
sinifNot bilgNotlar;
sinifNot ingNotlar;

int main()
{
  setlocale(LC_ALL, "Turkish");

  srand(time(NULL));

  ogrenciBilgi(programlamayaGiris, 1);
  ogrenciBilgi(matematic, 2);
  ogrenciBilgi(fizik, 3);
  ogrenciBilgi(bilgisayarGiris, 4);
  ogrenciBilgi(ingilizce, 5);

  siniflar();
  
  return 0;
}


void siniflar()
{
  int sinif = 1;

  while (sinif != 0)
  {
    string stringSinif = "";
    cout << "\n----------------------------------------------------------------------\n";

    cout << "Aradiginiz Sinifi Secin.\n" << endl;
    cout << "1) Programlamaya Giris Icin Bir (1) Giriniz" << endl;
    cout << "2) Bilgisayar Muhendislige giris Icin Iki (2) Giriniz" << endl;
    cout << "3) Matematik Icin Uc (3) Giriniz" << endl;
    cout << "4) Fizik Icin Dort (4) Giriniz" << endl;
    cout << "5) Ingilizce Icin Bes (5) Giriniz" << "  |  Cikmak Icin Sifir (0) Giriniz." << endl;

    cin >> stringSinif;

    sinif = stringToInt(stringSinif);

    if(sinif < 0 || sinif > 5)
    {
      cout << "\nListede Olan Bir Sinifi Giriniz." << endl;
      continue;
    } else if (sinif == 0) 
    {
      break;
    }

    ogrenciArama(sinif);
  }

  return;
}

void ogrenciArama(int sinif)
{
  int ogr = 0;

  while (ogr != -1)
  {
    string stringOgr = "";
    cout << "\n----------------------------------------------------------------------\n";

    switch(sinif)
    {
      case 1:
        cout << "Sinif Ortalamasi: "<<  progNotlar.ortalama << ", " << "Sinifin Standart Sapmasi: " << progNotlar.stanSap << endl;
        break;

      case 2:
        cout << "Sinif Ortalamasi: "<<  matNotlar.ortalama << ", " << "Sinifin Standart Sapmasi: " << matNotlar.stanSap << endl;
        break;

      case 3:
        cout << "Sinif Ortalamasi: "<<  fizNotlar.ortalama << ", " << "Sinifin Standart Sapmasi: " << fizNotlar.stanSap << endl;
        break;

      case 4:
        cout << "Sinif Ortalamasi: "<<  bilgNotlar.ortalama << ", " << "Sinifin Standart Sapmasi: " << bilgNotlar.stanSap << endl;
        break;

      case 5:
        cout << "Sinif Ortalamasi: "<<  ingNotlar.ortalama << ", " << "Sinifin Standart Sapmasi: " << ingNotlar.stanSap << endl;
        break;
    }

    cout << "\nBakmak Istediginiz Orencinin Numarasini Giriniz (1-100)" << endl;
    cout << "          Geri Gitmek Icin Sifir (0) Giriniz" << endl;
    cin >> stringOgr;

    ogr = stringToInt(stringOgr) - 1; // dizi icin bir azaltiyor

    // ogrenci numarasi yanlis girilidigise
    if(ogr < -1 || ogr > 99) 
    {
      cout << endl << "Olmayan Ogrenci Numarasi Girdiniz." <<endl;
      cout << "Bir Daha Girin." << endl;
      continue;
    } else if (ogr == -1) 
    {
      break;
    }

    ogrenciBilYaz(sinif, ogr);
  }

  return;
}

void ogrenciBilYaz(int sinif, int ogrSay)
{
  ogrenci &ogr = programlamayaGiris[ogrSay];
  string bos;

  switch(sinif)
  {
    case 1:
      ogr = programlamayaGiris[ogrSay];
      break;
    case 2:
      ogr = matematic[ogrSay];
      break;
    case 3:
      ogr = fizik[ogrSay];
      break;
    case 4:
      ogr = bilgisayarGiris[ogrSay];
      break;
    case 5:
      ogr = ingilizce[ogrSay];
      break;
  }
  cout << "\n----------------------------------------------------------------------\n";
  cout << "Isim: " << ogr.ad << ", " << "Soyisim: " << ogr.soyad << endl;
  cout << "Sehir: " << ogr.sehir << endl;
  cout << "Telefon: " << ogr.telNum << endl;
  cout << "Sinif: " << ogr.dersAd << endl;
  cout << "\n1.Odev: %" << ogr.odev1 << ", " << "2.Odev: %" << ogr.odev2 << endl;
  cout << "Proje: %" << ogr.proje << ", " << "Vize: %" << ogr.vize << endl;
  cout << "Final: %" << ogr.final << ", " << "Yil Ici: %" << ogr.yilIci << endl;
  cout << "Genel Not Ortalama: %" << ogr.genelNot << endl;
  cout << "Basari Notu: " << ogr.basNot << endl;

  cout << "\nGeri Gitmek Icin Herhangi Bir Sayi Giriniz" << endl;
  cin >> bos;

  return;
}


double yilIciHesap(int odev1, int odev2, int proje, int vize)
{
  double yilIci = (odev1 * 5 + odev2 * 5 + proje * 10 + vize * 30) / 50;

  if (yilIci > 100)
  { 
    yilIci = 100;
  }

  return yilIci;
}

double genelNotHesaplama(int final, double yilIci)
{
  int basNot = (yilIci * 0.5) +(final * 0.5); // prog giris icin boyle

  if (basNot > 100)
  {
    basNot = 100;
  }

  return basNot;
}

string basariNotu(double genelNot)
{
  string basNot = "";

  double basNotSayi = (genelNot * 4)  / 100;

  // bellekte yer veriyoruz 32 ile 48 byte arasi
  stringstream basNotStream;

  // format oldu ilk desemale kadar gosetrir
  basNotStream << fixed << setprecision(1) << basNotSayi; 


  if(basNotSayi == 4)
  {

    basNot += basNotStream.str() + " AA";

    // diger else if leri bakmasin diye return basNot koydum
    return basNot;

  }else if(basNotSayi < 4 && basNotSayi >= 3.5)
  {
    basNot += basNotStream.str() + " BA";
    return basNot;

  }else if(basNotSayi < 3.5 && basNotSayi >= 3)
  {
    basNot += basNotStream.str() + " BB";
    return basNot;

  }else if(basNotSayi < 3 && basNotSayi >= 2.5)
  {
    basNot += basNotStream.str()  + " CB";
    return basNot;

  }else if(basNotSayi < 2.5 && basNotSayi >= 2)
  {
    basNot += basNotStream.str() + " CC";
    return basNot;

  }else if(basNotSayi < 2 && basNotSayi >= 1.5)
  {
    basNot += basNotStream.str() + " DC";
    return basNot;

  }else if(basNotSayi < 1.5 && basNotSayi >= 1)
  {
    basNot += basNotStream.str() + " DD";
    return basNot;

  }else
  {
    basNot += basNotStream.str() + " FF";
  }

  return basNot;
}

void standartSap(struct ogrenci sinif[], int ders)
{
  double ortalama = 0;
  double toplamGenel = 0;
  double doubleStanSap = 0; // ciktisi 3 decimal gosteriyor; 
  stringstream stanSap;

  for(int i = 0; i < 100; i++)
  {
    ogrenci &ogr = sinif[i];

    ortalama += (ogr.genelNot); 
  }
  ortalama = ortalama / 100;


  for(int i = 0; i < 100; i++)
  {
    ogrenci &ogr = sinif[i];

    toplamGenel += pow(ogr.genelNot - ortalama, 2);
  }
  doubleStanSap = sqrt(toplamGenel / 100);
  stanSap << fixed << setprecision(2) << doubleStanSap;


  switch(ders)
  {
    case 1:
      progNotlar.ortalama = ortalama;
      progNotlar.stanSap = stanSap.str();
      break;
    case 2:
      matNotlar.ortalama = ortalama;
      matNotlar.stanSap = stanSap.str();
      break;
    case 3:
      fizNotlar.ortalama = ortalama;
      fizNotlar.stanSap = stanSap.str();
      break;
    case 4:
      bilgNotlar.ortalama = ortalama;
      bilgNotlar.stanSap = stanSap.str();
      break;
    case 5:
      ingNotlar.ortalama = ortalama;
      ingNotlar.stanSap = stanSap.str();
      break;
  }
  return;
}


void ogrenciBilgi(struct ogrenci sinif[], int ders)
{
  //  ad, soyad, telefon numarasi, sehir, ders adi ve 
  //  odev1, odev2, proje, vize, final notlari belirliyor
  for(int i = 0; i < 100; i++)
  {
    ogrenci &ogr = sinif[i];

    //telefon numaralari belirliyor
    ogr.telNum = ogrenciTel(ogr.telNum);


    int randNum = rand() % 50;
    ogr.ad = isimSoySeh(1, randNum);
    ogr.soyad = isimSoySeh(2, randNum);
    ogr.sehir = isimSoySeh(3, randNum);

    switch(ders)
    {
      case 1:
        ogr.dersAd = "Programlamaya giris";
        break;    
      case 2:
        ogr.dersAd = "Matematik";
        break;
      case 3:
        ogr.dersAd = "Fizik";
        break;
      case 4:
        ogr.dersAd = "Bilgisayar Muhendisligine giris";
        break;
      case 5:
        ogr.dersAd = "Ingilizce";
        break;
    }

    // Ortalama cok kotu cikiyordu
    // bundan diye + 20 ekledim
    // sinav kagidinda adini soyadini yazan +20
    int randOdev1 = rand() % 100 + 20;
      if(randOdev1 >= 100)
      {
        randOdev1 = 100;
      }
    int randOdev2 = rand() % 100 + 20;
      if(randOdev2 >= 100) 
      {
        randOdev2 = 100;
      }
    int randProje = rand() % 100 + 20;
      if(randProje >= 100) 
      {
        randProje = 100;
      }
    int randVize = rand() %  100 + 20;
      if(randVize >= 100) 
      {
        randVize = 100;
      }
    int randFinal = rand() % 100 + 20;
      if(randFinal >= 100)
      {
        randFinal = 100;
      }



    ogr.odev1 = randOdev1;
    ogr.odev2 = randOdev2;
    ogr.proje = randProje;
    ogr.vize = randVize;
    ogr.final = randFinal;
    
    ogr.yilIci = yilIciHesap(ogr.odev1, ogr.odev2, ogr.proje, ogr.vize);
    ogr.genelNot = genelNotHesaplama(ogr.final, ogr.yilIci);
    ogr.basNot += basariNotu(ogr.genelNot);
  }
  standartSap(sinif, ders);

  return;
}

string isimSoySeh(int sira, int randNum)
{
  // isimler, soyadlar ve sehirler birer dizi 
  // her dizinin icinde 50 kelime vardir
  string isim[50] = {
    "Ahmet", "Mehmet", "Ayse", "Fatma", "Emre", "Elif", "Ali", "Zeynep", "Can", "Merve",
    "Huseyin", "Cem", "Ebru", "Selim", "Deniz", "Derya", "Baris", "Busra", "Okan", "Seda",
    "Tolga", "Irem", "Burak", "Yasemin", "Murat", "Gizem", "Onur", "Furkan", "Aylin", "Serkan",
    "Kerem", "Ozge", "Eren", "Sule", "Kaan", "Melis", "Ilker", "Ece", "Umut", "Ceren",
    "Engin", "Hande", "Suat", "Bora", "Zehra", "Oguz", "Selin", "Caglar", "Nilay", "Tuncay"
  };
  string soyad[50] = {
    "Yilmaz", "Kaya", "Demir", "Sahin", "Celik", "Koc", "Aydin", "Ozturk", "Arslan", "Polat",
    "Aksoy", "Yildiz", "Gunes", "Ozkan", "Cetin", "Erdogan", "Bulut", "Kurt", "Tas", "Gur",
    "Kilic", "Kaplan", "Ozdemir", "Bayrak", "Aslan", "Erdem", "Tekin", "Yalcin", "Karaca", "Tuna",
    "Dogan", "Demirtas", "Kara", "Cakir", "Karagoz", "Kocak", "Sonmez", "Ozer", "Mutlu", "Cakmak",
    "Acar", "Ari", "Basar", "Eren", "Gurkan", "Karaoglu", "Topal", "Altin", "Onal", "Erkut"
  };
  string sehir[50] = {
    "Istanbul", "Ankara", "Izmir", "Bursa", "Adana", "Gaziantep", "Konya", "Antalya", "Mersin", "Kayseri",
    "Samsun", "Eskisehir", "Diyarbakir", "Sakarya", "Trabzon", "Malatya", "Erzurum", "Aydin", "Balikesir", "Mugla",
    "Manisa", "Denizli", "Ordu", "Hatay", "Kocaeli", "Mardin", "Sanliurfa", "Batman", "Bolu", "Kutahya",
    "Tekirdag", "Canakkale", "Elazig", "Rize", "Sivas", "Usak", "Zonguldak", "Amasya", "Bingol", "Kirklareli",
    "Yozgat", "Nigde", "Kahramanmaras", "Isparta", "Afyonkarahisar", "Osmaniye", "Kirikkale", "Siirt", "Bartin", "Ardahan"
  };

  switch (sira)
  {
    case 1:
      return isim[randNum];
      // diger case leri okumasin diye break koydum
      break;

    case 2:
      return soyad[randNum];
      break;

    case 3:
      return sehir[randNum];
      break;
  }

  return "";
}

string ogrenciTel(string ogr)
{
  ogr += "+90 5";

  for(int j = 1; j < 3; j++) 
  {
    int telNum = rand() % 10;
    ogr +=  to_string(telNum);
  }
  ogr += " ";
  for(int j = 1; j < 4; j++) 
  {
    int telNum = rand() % 10;
    ogr +=  to_string(telNum);
  }
  ogr += " ";
  for (int j = 1; j < 3; j++) 
  {
    for (int k = 1; k < 3; k++) 
    {
      int telNum = rand() % 10;
      ogr +=  to_string(telNum);
    }
    ogr += " ";
  }

  return ogr;
}

int stringToInt(string stringOgr)
{
  for(int i = 0; i < stringOgr.size(); i++)
  {
    if(isalpha(stringOgr[i]))
    {
      return -2; // do while tekrar etmesi için
    }
  }
  
  return stoi(stringOgr);
};