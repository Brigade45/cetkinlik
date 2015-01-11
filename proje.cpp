/*
1353056
Tugay ŞENGEL
Dönem Proje
---------------
Sifre degistirme eksik
Guncelle eksik
Sil eksik
listele eksik(tek koşul)
*/
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
char id[20];
char pass[20];
char kontrol[50];
int checkadmin = 0, checkkullanici = 0, checkmemur = 0,kontrolno=0;
int admin_id_check = 0, kullanici_id_check = 0, memur_id_check = 0;
int secim;
int login();
int admin();
int memur();
int kullanici();;
void adminmenu();
void memurmenu();
void kullanicimenu();
int kullanici_ekle();
void kullanici_sil();
void kullanici_guncelle();
int kullanici_ara();
int siginmaci_ekle();
void siginmaci_sil();
void siginmaci_guncelle();
int siginmaci_ara();
int siginmaci_listele();        
void bilgilerimi_goruntule();
void sifre_degistir();
int default_check();
int admin_check();
int kullanici_check();
int memur_check();
int first_memur();
int first_kullanici();
int user_information();
int id_check_admin();
int id_check_memur();
int id_check_kullanici();
int first_siginmaci();
int kontrol_siginmacino();
struct adres
{
    char il[15];
    char ilce[15];
    char cadde[15];
    char mahalle[15];
    char sokak[15];
    char no[6];
    char apartman[15];
};
struct kullanici{
    char ad[20];
    char soyad[20];
    char telefon[20];
    char tckimlik[20];
    char kullanici_adi[20];
    char sifre[20];
    char eposta[20];
    char yetki_turu;
    struct adres address;
};
struct siginmaci{
    //int siginmaci_no;
    char ad[20];
    char soyad[20];
    char dogum_tarihi[5];
    char dogum_yeri[20];
    char cinsiyet;
    char uyruk[20];
    char meslek[20];
    char egitim_durumu[20];
    char telefon[20];
    struct adres address;
    char geldigi_sehir[20];
    char gelis_tarihi[11];
    char eposta[20];
}yedek[50];
int main()
{
    system("color 90");
    default_check();       // tamamlandi
    login(); // tamamlandı
    _getch();
    return 0;
}
int login()
{
    system("cls");
    do{
        system("cls");
        printf("Kullanici adi=");
        gets_s(id);
        _flushall();
        printf("\nSifre =");
        //gets_s(pass);
        int i = 0;
        int p;
        while ((p = _getch()) != 13)
        {
            pass[i] = p;
            if (p != 8)
                printf("*");
            if (p == 8)
            {
                int a = i - 2;
                i = i - 2;
                printf("\b");
                for (int z = a; z <= a;z++)
                    printf(" ");
                printf("\b");
            }
            i++;
        }
        printf("\n");
        pass[i] = '\0'; 
        _flushall();
        admin_check();
        if (checkadmin == 1)
            break;
        kullanici_check();
        if (checkkullanici == 1)
            break;
        memur_check();
        if (checkmemur == 1)
            break;
        printf("Hatali uyelik\n");
        printf("3 saniye sonra tekrar kullanici adi ve sifre istenecektir.\n");
        Sleep(3000);
    } while (checkadmin != 1 && checkkullanici != 1 && checkmemur != 1);
    _flushall();
    if (checkadmin == 1)
        admin();
    else if (checkmemur == 1)
        memur();
    else if (checkkullanici == 1)
        kullanici();
    else if (secim == 0)
        exit(EXIT_SUCCESS);
    return 0;
}
int admin()
{
    do{
        secim = 10;
        adminmenu();
        scanf_s("%d", &secim);
        _flushall();
        if (secim == 1)
            kullanici_ekle();
        else if (secim == 2)
            kullanici_sil();
        else if (secim == 3)
            kullanici_guncelle();
        else if (secim == 4)
            kullanici_ara();
        else if (secim == 5)
            siginmaci_ekle();
        else if (secim == 6)
            siginmaci_sil();
        else if (secim == 7)
            siginmaci_guncelle();                                                       
        else if (secim == 8)
            siginmaci_ara();
        else if (secim == 9)
            siginmaci_listele();
        else if (secim == 0)
            exit(EXIT_SUCCESS);
    } while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9 && secim != 0);
    return 0;
}
int memur()
{
    do{
    secim = 10;
    memurmenu();
    scanf_s("%d", &secim);
    _flushall();
    if (secim == 1)
        siginmaci_ekle();
    else if (secim == 2)
        siginmaci_sil();
    else if (secim == 3)
        siginmaci_guncelle();
    else if (secim == 4)
        siginmaci_ara();
    else if (secim == 5)
        siginmaci_listele();
    else if (secim == 0)
        exit(EXIT_SUCCESS);
    } while (secim !=1 && secim !=2 && secim !=3 && secim !=4 && secim !=5 && secim !=0);
    return 0;
}
int kullanici()
{
    do{
    secim = 10;
    kullanicimenu();
    scanf_s("%d", &secim);
    _flushall();
    if (secim == 1)
        siginmaci_ara();
    else if (secim == 2)
        bilgilerimi_goruntule();
    else if (secim == 3)
        sifre_degistir();
    else if (secim == 0)
        exit(EXIT_SUCCESS);
    } while (secim != 1 && secim != 2 && secim != 3 && secim != 0);
    return 0;
}
void adminmenu()
{
    system("cls");
    printf("1 = Kullanici ekle");
    printf("\n2 = Kullanici sil");
    printf("\n3 = Kullanici guncelle");
    printf("\n4 = Kullanici ara");
    printf("\n5 = Siginmaci ekle");
    printf("\n6 = Siginmaci sil");
    printf("\n7 = Siginmaci guncelle");
    printf("\n8 = Siginmaci ara");
    printf("\n9 = Siginmacilari listele");
    printf("\n0 = Cikis");
    printf("\nSeciminiz : ");
}
void memurmenu()
{
    system("cls");
    printf("1 = Siginmaci ekle");
    printf("\n2 = Siginmaci sil");
    printf("\n3 = Siginmaci guncelle");
    printf("\n4 = Siginmaci ara");
    printf("\n5 = Siginmacilari listele");
    printf("\n0 = Cikis");
    printf("\nSeciminiz : ");
}
void kullanicimenu()
{
    system("cls");
    printf("1 = Siginmaci goruntule");
    printf("\n2 = Bilgilerimi goruntule");
    printf("\n3 = Sifre degistir");
    printf("\n0 = Cikis");
    printf("\nSeciminiz : ");
}
int kullanici_ekle()
{
    system("cls");
    first_memur();
    first_kullanici();
    user_information();
    Sleep(3000);
    system("cls");
    struct kullanici users;
    FILE *add_user;
    fopen_s(&add_user, "user_information.dat", "a");
    if (add_user == NULL)
        printf("user_information.dat acilamadi.");
    else
    {
        printf("Isim giriniz : ");
        gets_s(users.ad);
        _flushall();
        printf("Soyisim giriniz : ");
        gets_s(users.soyad);
        _flushall();
        printf("TC-Kimlik giriniz : ");
        gets_s(users.tckimlik);
        _flushall();
        printf("Telefon giriniz : ");
        gets_s(users.telefon);
        _flushall();
        printf("E-Posta giriniz : ");
        gets_s(users.eposta);
        _flushall();
        do{
        printf("\nKullanici adini giriniz : ");
        gets_s(id);
        _flushall();
        id_check_admin();
        id_check_memur();
        id_check_kullanici();
        } while (admin_id_check == 1 || kullanici_id_check ==1 || memur_id_check ==1);
        printf("Sifrenizi giriniz : ");
        gets_s(users.sifre);
        _flushall();
        do{
            printf("Yetki turunu giriniz(Admin = a,Memur = m, Kullanici = k) : ");
            users.yetki_turu = getchar();
            _flushall();
        } while (users.yetki_turu != 97 && users.yetki_turu != 107 && users.yetki_turu != 109);
        printf("Il : ");
        gets_s(users.address.il);
        _flushall();
        printf("Ilce : ");
        gets_s(users.address.ilce);
        _flushall();
        printf("Cadde : ");
        gets_s(users.address.cadde);
        _flushall();
        printf("Mahalle : ");
        gets_s(users.address.mahalle);
        _flushall();
        printf("Sokak : ");
        gets_s(users.address.sokak);
        _flushall();
        printf("Apartman : ");
        gets_s(users.address.apartman);
        _flushall();
        printf("Kapı no : ");
        gets_s(users.address.no);
        _flushall();
        fprintf(add_user, "Ad=%s Soyad=%s TC.No=%s Telefon=%s E-Posta=%s Kullanici adi=%s Yetki Turu=%c Il=%s Ilce=%s Cadde=%s Mahalle=%s Sokak=%s Apartman=%s Kap, No=%s\n", users.ad, users.soyad, users.tckimlik, users.telefon, users.eposta, id,
            users.yetki_turu, users.address.il, users.address.ilce, users.address.cadde, users.address.mahalle, users.address.sokak, users.address.apartman, users.address.no);
        if (users.yetki_turu == 'a')
        {
            fopen_s(&add_user, "adminsifre.dat", "a");
            fprintf(add_user, "\n%s\n%s", id, users.sifre);
        }
        else if (users.yetki_turu == 'm')
        {
            fopen_s(&add_user, "memursifre.dat", "a");
            fprintf(add_user, "\n%s\n%s", id, users.sifre);
        }
        else if (users.yetki_turu == 'k')
        {
            fopen_s(&add_user, "kullanicisifre.dat", "a");
            fprintf(add_user, "\n%s\n%s", id, users.sifre);
        }
    }
    fclose(add_user);
    return 0;
}
void kullanici_sil()
{
    system("cls");
}
void kullanici_guncelle()
{
    system("cls");
}
int kullanici_ara()
{
    system("cls");
    char ara[20];
    printf("Arayacaginiz kelimeyi giriniz : ");
    gets_s(ara);
    static const char filename[] = "user_information.dat";
    FILE *file;
    fopen_s(&file, filename, "r");
    if (file != NULL)
    {
        char line[256]; 
        while (fgets(line, sizeof line, file) != NULL) 
        {
            if (strstr(line, ara))
            {
                fputs(line, stdout); 
            }
        }

        fclose(file);
    }

    else
    {
        perror(filename); 
    }
    return 0;
}
int siginmaci_ekle()
{
    system("cls");
    first_siginmaci();;
    Sleep(3000);
    system("cls");
    struct siginmaci users;
    FILE *add_siginmaci;
    fopen_s(&add_siginmaci, "siginmaci.dat", "ab");
    if (add_siginmaci == NULL)
        printf("siginmaci.dat acilamadi.");
    else
    {
        printf("Isim giriniz : ");
        gets_s(users.ad);
        _flushall();
        printf("Soyisim giriniz : ");
        gets_s(users.soyad);
        _flushall();
        printf("Uyruk giriniz : ");
        gets_s(users.uyruk);
        _flushall();
        printf("Telefon giriniz : ");
        gets_s(users.telefon);
        _flushall();
        printf("E-Posta giriniz : ");
        gets_s(users.eposta);
        _flushall();
        printf("Meslek giriniz : ");
        gets_s(users.meslek);
        _flushall();
        printf("Dogum yeri giriniz : ");
        gets_s(users.dogum_yeri);
        _flushall();
        printf("Dogum tarihi(Sadece yil) giriniz : ");
        gets_s(users.dogum_tarihi);
        _flushall(); 
        printf("Egitim durumu giriniz : ");
        gets_s(users.egitim_durumu);
        _flushall();
        printf("Geldigi sehri giriniz : ");
        gets_s(users.geldigi_sehir);
        _flushall();
        printf("Gelis tarihini(01.01.2000 formatında) giriniz : ");
        gets_s(users.gelis_tarihi);
        _flushall();
        do{
            printf("Cinsiyet giriniz(Erkek = e, Kadin = k) : ");
            users.cinsiyet = getchar();
            _flushall();
        } while (users.cinsiyet != 101 && users.cinsiyet != 107);
        printf("Il : ");
        gets_s(users.address.il);
        _flushall();
        printf("İlce : ");
        gets_s(users.address.ilce);
        _flushall();
        printf("Cadde : ");
        gets_s(users.address.cadde);
        _flushall();
        printf("Mahalle : ");
        gets_s(users.address.mahalle);
        _flushall();
        printf("Sokak : ");
        gets_s(users.address.sokak);
        _flushall();
        printf("Apartman : ");
        gets_s(users.address.apartman);
        _flushall();
        printf("No : ");
        gets_s(users.address.no);
        _flushall();
        int a=0;
        char kontrol[50];
        char kontrol2[50];
        int i = 0;
        int z = 0; 
        int c = 48;
        FILE *siginmacisayi;

        //fopen_s(&siginmacisayi, "siginmacisayi.dat", "w+");
        fopen_s(&siginmacisayi, "siginmacisayi.dat", "r");
        if (siginmacisayi == NULL)
        {
            printf("Programda tanimli siginmacisayi.dat dosyasi bulunamadi.");
            printf("\nDosya olusturuldu.");
            fopen_s(&siginmacisayi, "siginmacisayi.dat", "wb+");
            fprintf(siginmacisayi, "%d", c+1);
            fclose(siginmacisayi);
        }        
        else    {

        fscanf_s(siginmacisayi, "%d",&c);
        fclose(siginmacisayi);
        c=c+1;
        fopen_s(&siginmacisayi, "siginmacisayi.dat", "wb+");
        fseek(siginmacisayi, 0, SEEK_SET);
        fprintf(siginmacisayi, "%d", c);
        fclose(siginmacisayi);
        }
        for (int a = c; a <= 99; a++)
        {
            if (a >= 49 && a <= 57)
            {
                kontrol[i] = a;                                                                                                                              
                fprintf(add_siginmaci, "\n%c-Ad=%s\tSoyad=%s\tUyruk=%s\tTelefon=%s\tE-Posta=%s\tMeslek=%s\tDogum.yeri=%s\tDogum.tarihi=%s\tEgitim.durumu=%s\tGeldigi.sehir=%s\tGelis.tarihi%s\tCinsiyet=%c\tIl=%s\tIlce=%s\tCadde=%s\tMahalle=%s\tSokak=%s\tApartman=%s\tApt.No=%s\n", kontrol[i], users.ad, users.soyad, users.uyruk, users.telefon, users.eposta, users.meslek,
                    users.dogum_yeri, users.dogum_tarihi, users.egitim_durumu, users.geldigi_sehir, users.gelis_tarihi, users.cinsiyet, users.address.il, users.address.ilce, users.address.cadde, users.address.mahalle, users.address.sokak, users.address.apartman, users.address.no);                break;
            }
            else if (a >= 58 && a <= 67)
            {
                kontrol[i] = 49;
                kontrol2[z] = a - 10;
                fprintf(add_siginmaci, "\n%c%c-Ad=%s\tSoyad=%s\tUyruk=%s\tTelefon=%s\tE-Posta=%s\tMeslek=%s\tDogum.yeri=%s\tDogum.tarihi=%s\tEgitim.durumu=%s\tGeldigi.sehir=%s\tGelis.tarihi%s\tCinsiyet=%c\tIl=%s\tIlce=%s\tCadde=%s\tMahalle=%s\tSokak=%s\tApartman=%s\tApt.No=%s\n", kontrol[i], kontrol2[z], users.ad, users.soyad, users.uyruk, users.telefon, users.eposta, users.meslek,
                    users.dogum_yeri, users.dogum_tarihi, users.egitim_durumu, users.geldigi_sehir, users.gelis_tarihi, users.cinsiyet, users.address.il, users.address.ilce, users.address.cadde, users.address.mahalle, users.address.sokak, users.address.apartman, users.address.no);                break;
            }
            else if (a >= 68 && a <= 77)
            {
                kontrol[i] = 50;
                kontrol2[z] = a - 20;
                fprintf(add_siginmaci, "\n%c%c-Ad=%s\tSoyad=%s\tUyruk=%s\tTelefon=%s\tE-Posta=%s\tMeslek=%s\tDogum.yeri=%s\tDogum.tarihi=%s\tEgitim.durumu=%s\tGeldigi.sehir=%s\tGelis.tarihi%s\tCinsiyet=%c\tIl=%s\tIlce=%s\tCadde=%s\tMahalle=%s\tSokak=%s\tApartman=%s\tApt.No=%s\n", kontrol[i], kontrol2[z], users.ad, users.soyad, users.uyruk, users.telefon, users.eposta, users.meslek,
                    users.dogum_yeri, users.dogum_tarihi, users.egitim_durumu, users.geldigi_sehir, users.gelis_tarihi, users.cinsiyet, users.address.il, users.address.ilce, users.address.cadde, users.address.mahalle, users.address.sokak, users.address.apartman, users.address.no);                break;
            }
            else if (a >= 78 && a <= 87)
            {
                kontrol[i] = 51;
                kontrol2[z] = a - 30;
                fprintf(add_siginmaci, "\n%c%c-Ad=%s\tSoyad=%s\tUyruk=%s\tTelefon=%s\tE-Posta=%s\tMeslek=%s\tDogum.yeri=%s\tDogum.tarihi=%s\tEgitim.durumu=%s\tGeldigi.sehir=%s\tGelis.tarihi%s\tCinsiyet=%c\tIl=%s\tIlce=%s\tCadde=%s\tMahalle=%s\tSokak=%s\tApartman=%s\tApt.No=%s\n", kontrol[i], kontrol2[z], users.ad, users.soyad, users.uyruk, users.telefon, users.eposta, users.meslek,
                    users.dogum_yeri, users.dogum_tarihi, users.egitim_durumu, users.geldigi_sehir, users.gelis_tarihi, users.cinsiyet, users.address.il, users.address.ilce, users.address.cadde, users.address.mahalle, users.address.sokak, users.address.apartman, users.address.no);                break;
            }
            else if (a >= 88 && a <= 97)
            {
                kontrol[i] = 52;
                kontrol2[z] = a - 40;
                fprintf(add_siginmaci, "\%c%c-Ad=%s\tSoyad=%s\tUyruk=%s\tTelefon=%s\tE-Posta=%s\tMeslek=%s\tDogum.yeri=%s\tDogum.tarihi=%s\tEgitim.durumu=%s\tGeldigi.sehir=%s\tGelis.tarihi%s\tCinsiyet=%c\tIl=%s\tIlce=%s\tCadde=%s\tMahalle=%s\tSokak=%s\tApartman=%s\tApt.No=%s\n", kontrol[i], kontrol2[z], users.ad, users.soyad, users.uyruk, users.telefon, users.eposta, users.meslek,
                    users.dogum_yeri, users.dogum_tarihi, users.egitim_durumu, users.geldigi_sehir, users.gelis_tarihi, users.cinsiyet, users.address.il, users.address.ilce, users.address.cadde, users.address.mahalle, users.address.sokak, users.address.apartman, users.address.no);
                break;
            }
            else if (a >= 98 && a <= 99)
            {
                kontrol[i] = 53;
                kontrol2[z] = a - 40;
                fprintf(add_siginmaci, "\n%c%c-Ad=%s\tSoyad=%s\tUyruk=%s\tTelefon=%s\tE-Posta=%s\tMeslek=%s\tDogum.yeri=%s\tDogum.tarihi=%s\tEgitim.durumu=%s\tGeldigi.sehir=%s\tGelis.tarihi%s\tCinsiyet=%c\tIl=%s\tIlce=%s\tCadde=%s\tMahalle=%s\tSokak=%s\tApartman=%s\tApt.No=%s\n", kontrol[i], kontrol2[z], users.ad, users.soyad, users.uyruk, users.telefon, users.eposta, users.meslek,
                    users.dogum_yeri, users.dogum_tarihi, users.egitim_durumu, users.geldigi_sehir, users.gelis_tarihi, users.cinsiyet, users.address.il, users.address.ilce, users.address.cadde, users.address.mahalle, users.address.sokak, users.address.apartman, users.address.no);
                break;
            }
            i++;
            z++;  
        }
        //fprintf(add_siginmaci, "Ad=%s Soyad=%s Uyruk=%s Telefon=%s E-Posta=%s Meslek=%s Dogum.yeri=%s Dogum.tarihi=%s Egitim.durumu=%s Geldigi.sehir=%s Gelis.tarihi=%s Cinsiyet=%c Il=%s Ilce=%s Cadde=%s Mahalle=%s Sokak=%s Apartman=%s Adres.no=%s\n",users.ad, users.soyad, users.uyruk, users.telefon, users.eposta, users.meslek,
        //users.dogum_yeri ,users.dogum_tarihi,users.egitim_durumu,users.geldigi_sehir,users.geliadmins_tarihi,users.cinsiyet,users.address.il, users.address.ilce, users.address.cadde, users.address.mahalle, users.address.sokak, users.address.apartman, users.address.no);
    }
    fclose(add_siginmaci);
    return 0;
}
void siginmaci_sil()
{
    system("cls");
}
void siginmaci_guncelle()
{
    system("cls");
}
int siginmaci_ara()
{
    system("cls");
    char ara[20];
    printf("Arayacaginiz kelimeyi giriniz : ");
    gets_s(ara);
    static const char filename[] = "siginmaci.dat";
    FILE *file;
    fopen_s(&file, filename, "r");
    if (file != NULL)
    {
        char line[256]; 
        while (fgets(line, sizeof line, file) != NULL) 
        {
            if (strstr(line, ara))
            {
                fputs(line, stdout); 
            }
        }

        fclose(file);
    }

    else
    {
        perror(filename); 
    }
    return 0;
}
int siginmaci_listele()
{
    system("cls");
    static const char filename[] = "siginmaci.dat";
    FILE *file;
    fopen_s(&file, filename, "r");
    if (file != NULL)
    {
        char line[256]; 
        while (fgets(line, sizeof line, file) != NULL) 
        {
            if (strstr(line, "Ad="))
            {
                fputs(line, stdout); 
            }
        }

        fclose(file);
    }

    else
    {
        perror(filename); 
    }
    return 0;
}
void bilgilerimi_goruntule(){
    system("cls");
    static const char filename[] = "user_information.dat";
    FILE *file;
    fopen_s(&file,filename, "r");
    if (file != NULL)
    {
        char line[256]; 
        while (fgets(line, sizeof line, file) != NULL) 
        {
            if (strstr(line, id))
            {
                fputs(line, stdout);
            }
        }

        fclose(file);
    }

    else
    {
        perror(filename); 
    }
}
void sifre_degistir()
{
    system("cls");
}
int default_check()      // default_check tamamlandi.
{
    FILE *firstadmin;  /* dosya göstericisi */
    fopen_s(&firstadmin, "adminsifre.dat", "r");
    if (firstadmin == NULL)
    {
        printf("Programda tanimli admin hesabi bulunmamaktadir.");
        printf("\nLutfen bir kullanici adi ve sifre olusturunuz.");
        printf("\nKullanici adi =");
        gets_s(id);
        _flushall();
        printf("\nSifre =");
        gets_s(pass);
        _flushall();
        fopen_s(&firstadmin, "adminsifre.dat", "w");
        fprintf(firstadmin, "%s\n%s", id, pass);
    }
    fclose(firstadmin);
    return 0;
}
int admin_check(){
    int lines_allocated = 1000;
    int max_line_len = 150;
    FILE *admin_check;
    fopen_s(&admin_check, "adminsifre.dat", "r");
    char **words = (char **)malloc(sizeof(char*)*lines_allocated);
    int i;
    for (i = 0; 1; i++)
    {
        int j;
        if (i >= lines_allocated)
        {
            int new_size;
            new_size = lines_allocated * 2;
            words = (char **)realloc(words, sizeof(char*)*new_size);
            if (words == NULL)
            {
                fprintf(stderr, "Out of memory.\n");
                exit(3);
            }
            lines_allocated = new_size;
        }
        words[i] = (char*)malloc(max_line_len);
        if (words[i] == NULL)
        {
            fprintf(stderr, "Out of memory (3).\n");
            exit(4);
        }
        if (fgets(words[i], max_line_len - 1, admin_check) == NULL)
            break;
        for (j = strlen(words[i]) - 1; j >= 0 && (words[i][j] == '\n' || words[i][j] == '\r'); j--)
            words[i][j] = '\0';
    }
    for (int c = 0; c <= i; c++)  {
    if ((strcmp(id, words[c]) == 0 && strcmp(pass, words[c+1]) == 0))
    {
        printf("\t Basariyla giris yapildi");
        for (int a = 1; a <= 5; a++)
        {
            Sleep(1000);
            printf(".");
        }
        checkadmin = 1;
    }
    }
    fclose(admin_check);
    return 0;
}
int kullanici_check(){
    int lines_allocated = 1000;
    int max_line_len = 150;
    FILE *kullanici_check;
    fopen_s(&kullanici_check, "kullanicisifre.dat", "r");
    char **words = (char **)malloc(sizeof(char*)*lines_allocated);
    int i;
    for (i = 0; 1; i++)
    {
        int j;
        if (i >= lines_allocated)
        {
            int new_size;
            new_size = lines_allocated * 2;
            words = (char **)realloc(words, sizeof(char*)*new_size);
            if (words == NULL)
            {
                fprintf(stderr, "Out of memory.\n");
                exit(3);
            }
            lines_allocated = new_size;
        }
        words[i] = (char*)malloc(max_line_len);
        if (words[i] == NULL)
        {
            fprintf(stderr, "Out of memory (3).\n");
            exit(4);
        }
        if (fgets(words[i], max_line_len - 1, kullanici_check) == NULL)
            break;
        for (j = strlen(words[i]) - 1; j >= 0 && (words[i][j] == '\n' || words[i][j] == '\r'); j--)
            words[i][j] = '\0';
    }
    for (int c = 0; c <= i; c++)  {
        if ((strcmp(id, words[c]) == 0 && strcmp(pass, words[c + 1]) == 0) && ((strcmp(id, words[c]) != EOF) && strcmp(pass, words[c + 1]) != EOF))
        {
            printf("\t Basariyla giris yapildi");
            for (int a = 1; a <= 5; a++)
            {
                Sleep(1000);
                printf(".");
            }
            checkkullanici = 1;
        }
    }
    fclose(kullanici_check);
    return 0;
}
int memur_check(){
    int lines_allocated = 1000;
    int max_line_len = 150;
    FILE *memur_check;
    fopen_s(&memur_check, "memursifre.dat", "r");
    char **words = (char **)malloc(sizeof(char*)*lines_allocated);
    int i;
    for (i = 0; 1; i++)
    {
        int j;
        if (i >= lines_allocated)
        {
            int new_size;
            new_size = lines_allocated * 2;
            words = (char **)realloc(words, sizeof(char*)*new_size);
            if (words == NULL)
            {
                fprintf(stderr, "Out of memory.\n");
                exit(3);
            }
            lines_allocated = new_size;
        }
        words[i] = (char*)malloc(max_line_len);
        if (words[i] == NULL)
        {
            fprintf(stderr, "Out of memory (3).\n");
            exit(4);
        }
        if (fgets(words[i], max_line_len - 1, memur_check) == NULL)
            break;
        for (j = strlen(words[i]) - 1; j >= 0 && (words[i][j] == '\n' || words[i][j] == '\r'); j--)
            words[i][j] = '\0';
    }
    for (int c = 0; c <= i; c++)  {
        if ((strcmp(id, words[c]) == 0 && strcmp(pass, words[c + 1]) == 0) && ((strcmp(id, words[c]) != EOF) && strcmp(pass, words[c + 1]) != EOF))
        {
            printf("\t Basariyla giris yapildi");
            for (int a = 1; a <= 5; a++)
            {
                Sleep(1000);
                printf(".");
            }
            checkmemur = 1;
        }
    }
    fclose(memur_check);
    return 0;
}
int first_memur()
{
    FILE *firstmemur;  /* dosya göstericisi */
    fopen_s(&firstmemur, "memursifre.dat", "r");
    if (firstmemur == NULL)
    {
        printf("Programda tanimli memursifre.dat dosyasi bulunamadi.");
        printf("\nDosya olusturuldu.");
        fopen_s(&firstmemur, "memursifre.dat", "w");
    }
    fclose(firstmemur);
    return 0;
}
int first_kullanici()
{
    FILE *firstkullanici;  /* dosya göstericisi */
    fopen_s(&firstkullanici, "kullanicisifre.dat", "r");
    if (firstkullanici == NULL)
    {
        printf("\nProgramda tanimli kullanicisifre.dat dosyasi bulunamadi.");
        printf("\nDosya olusturuldu.");
        fopen_s(&firstkullanici, "kullanicisifre.dat", "w");
    }
    fclose(firstkullanici);
    return 0;
}
int user_information()
{
    FILE *userinformation;  /* dosya göstericisi */
    fopen_s(&userinformation, "user_information.dat", "r");
    if (userinformation == NULL)
    {
        printf("\nProgramda tanimli user_information.dat dosyasi bulunamadi.");
        printf("\nDosya olusturuldu.");
        fopen_s(&userinformation, "user_information.dat", "w");
    }
    fclose(userinformation);
    return 0;
}
int id_check_admin(){
    int lines_allocated = 1000;
    int max_line_len = 150;
    FILE *admin_check;
    fopen_s(&admin_check, "adminsifre.dat", "r");
    char **words = (char **)malloc(sizeof(char*)*lines_allocated);
    int i;
    for (i = 0; 1; i++)
    {
        int j;
        if (i >= lines_allocated)
        {
            int new_size;
            new_size = lines_allocated * 2;
            words = (char **)realloc(words, sizeof(char*)*new_size);
            if (words == NULL)
            {
                fprintf(stderr, "Out of memory.\n");
                exit(3);
            }
            lines_allocated = new_size;
        }
        words[i] = (char*)malloc(max_line_len);
        if (words[i] == NULL)
        {
            fprintf(stderr, "Out of memory (3).\n");
            exit(4);
        }
        if (fgets(words[i], max_line_len - 1, admin_check) == NULL)
            break;
        for (j = strlen(words[i]) - 1; j >= 0 && (words[i][j] == '\n' || words[i][j] == '\r'); j--)
            words[i][j] = '\0';
    }
    for (int c = 0; c <= i; c=c+2)  {
        if ((strcmp(id, words[c]) == 0))
        {
            printf("\t Kullanici adi daha once alinmis");
            for (int a = 1; a <= 5; a++)
            {
                Sleep(1000);
                printf(".");
            }
            admin_id_check = 1;
        }
    }
    fclose(admin_check);
    return 0;
}
int id_check_kullanici(){
    int lines_allocated = 1000;
    int max_line_len = 150;
    FILE *kullanici_check;
    fopen_s(&kullanici_check, "kullanicisifre.dat", "r");
    char **words = (char **)malloc(sizeof(char*)*lines_allocated);
    int i;
    for (i = 0; 1; i++)
    {
        int j;
        if (i >= lines_allocated)
        {
            int new_size;
            new_size = lines_allocated * 2;
            words = (char **)realloc(words, sizeof(char*)*new_size);
            if (words == NULL)
            {
                fprintf(stderr, "Out of memory.\n");
                exit(3);
            }
            lines_allocated = new_size;
        }
        words[i] = (char*)malloc(max_line_len);
        if (words[i] == NULL)
        {
            fprintf(stderr, "Out of memory (3).\n");
            exit(4);
        }
        if (fgets(words[i], max_line_len - 1, kullanici_check) == NULL)
            break;
        for (j = strlen(words[i]) - 1; j >= 0 && (words[i][j] == '\n' || words[i][j] == '\r'); j--)
            words[i][j] = '\0';
    }
    for (int c = 0; c <= i; c = c + 2)  {
        if ((strcmp(id, words[c]) == 0))
        {
            printf("\t Kullanici adi daha once alinmis");
            for (int a = 1; a <= 5; a++)
            {
                Sleep(1000);
                printf(".");
            }
            kullanici_id_check = 1;
        }
    }
    fclose(kullanici_check);
    return 0;
}
int id_check_memur(){
    int lines_allocated = 1000;
    int max_line_len = 150;
    FILE *memur_check;
    fopen_s(&memur_check, "memursifre.dat", "r");
    char **words = (char **)malloc(sizeof(char*)*lines_allocated);
    int i;
    for (i = 0; 1; i++)
    {
        int j;
        if (i >= lines_allocated)
        {
            int new_size;
            new_size = lines_allocated * 2;
            words = (char **)realloc(words, sizeof(char*)*new_size);
            if (words == NULL)
            {
                fprintf(stderr, "Out of memory.\n");
                exit(3);
            }
            lines_allocated = new_size;
        }
        words[i] = (char*)malloc(max_line_len);
        if (words[i] == NULL)
        {
            fprintf(stderr, "Out of memory (3).\n");
            exit(4);
        }
        if (fgets(words[i], max_line_len - 1, memur_check) == NULL)
            break;
        for (j = strlen(words[i]) - 1; j >= 0 && (words[i][j] == '\n' || words[i][j] == '\r'); j--)
            words[i][j] = '\0';
    }
    for (int c = 0; c <= i; c = c + 2)  {
        if ((strcmp(id, words[c]) == 0))
        {
            printf("\t Kullanici adi daha once alinmis");
            for (int a = 1; a <= 5; a++)
            {
                Sleep(1000);
                printf(".");
            }
            memur_id_check = 1;
        }
    }
    fclose(memur_check);
    return 0;
}
int first_siginmaci()   
{
    FILE *firstsiginmaci;  /* dosya göstericisi */
    fopen_s(&firstsiginmaci, "siginmaci.dat", "rb");
    if (firstsiginmaci == NULL)
    {
        printf("Programda tanimli siginmaci.dat dosyasi bulunamadi.");
        printf("\nDosya olusturuldu.");
        fopen_s(&firstsiginmaci, "siginmaci.dat", "wb");
    }
    fclose(firstsiginmaci);
    return 0;
}
int kontrol_siginmacino(){
    int lines_allocated = 1000;
    int max_line_len = 150;
    FILE *siginmaci_no;
    fopen_s(&siginmaci_no, "siginmacisayi.dat", "r");
    char **words = (char **)malloc(sizeof(char*)*lines_allocated);
    int i;
    for (i = 0; 1; i++)
    {
        int j;
        if (i >= lines_allocated)
        {
            int new_size;
            new_size = lines_allocated * 2;
            words = (char **)realloc(words, sizeof(char*)*new_size);
            if (words == NULL)
            {
                fprintf(stderr, "Out of memory.\n");
                exit(3);
            }
            lines_allocated = new_size;
        }
        words[i] = (char*)malloc(max_line_len);
        if (words[i] == NULL)
        {
            fprintf(stderr, "Out of memory (3).\n");
            exit(4);
        }
        if (fgets(words[i], max_line_len - 1, siginmaci_no) == NULL)
            break;
        for (j = strlen(words[i]) - 1; j >= 0 && (words[i][j] == '\n' || words[i][j] == '\r'); j--)
            words[i][j] = '\0';
    }
    for (int c = 0; c <= i; c = c + 1)  {
        if ((strcmp(kontrol, words[c]) == 0))
        {
            printf("\t Kullanici adi daha once alinmis");
            for (int a = 1; a <= 5; a++)
            {
                Sleep(1000);
                printf(".");
            }
            kontrolno = 1;
        }
    }
    fclose(siginmaci_no);
    return 0;
}                       
