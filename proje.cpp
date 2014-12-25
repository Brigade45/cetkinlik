// siginmacilara otomatik olarak 1.2.3.
// admin tüm yetkilere sahip
// siginmaci memuru sadece siginmacilarla ilgili islemler
// kullanici sadece goruntuleme
// sifre yetki türü tutulacak
// kullanıcı ile ilgili işlemleri sadece admin
// her kullanıcı bilgilerini görüntüleyip , şifresini değiştirebilir
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
char id[20];
char pass[20];
int checkadmin = 0, checkkullanici = 0, checkmemur = 0;
int secim;
int login();
void loginmenu();
int admin();
int memur();
int kullanici();;
void help();
void adminmenu();
void memurmenu();
void kullanicimenu();
void kullanici_ekle();
void kullanici_sil();
void kullanici_guncelle();
void kullanici_ara();
void siginmaci_ekle();
void siginmaci_sil();
void siginmaci_guncelle();
void siginmaci_ara();
void siginmaci_listele();
void siginmaci_goruntule();
void bilgilerimi_goruntule();
void sifre_degistir();
int dosya_olusturma();
int default_check();
int admin_check();
int kullanici_check();
int memur_check();
int first_memur();
int first_kullanici();
int user_information();
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
    int siginmaci_no;
    char ad[20];
    char soyad[20];
    char dogum_tarihi;
    char dogum_yeri[20];
    char cinsiyet[1];
    char uyruk[20];
    char meslek[20];
    char egitim_durumu[20];
    char telefon[20];
    char yerlestirildigi_adres;
    char geldigi_sehir;
    char gelis_tarihi;
    char eposta;
};
int main()
{
    system("color 90");
    default_check();       // tamamlandi
    login();
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
        gets_s(pass);
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
    //loginmenu();
    //scanf_s("%d", &secim);
    _flushall();
    if (checkadmin == 1)
        admin();
    else if (checkmemur == 1)
        memur();
    else if (checkkullanici == 1)
        kullanici();
    else if (secim == 4)
        help();
    else if (secim == 0)
        exit(EXIT_SUCCESS);
    return 0;
}
void loginmenu()
{
    printf("\t\t  Siginmaci takip programina hosgeldiniz");
    for (int a = 1; a <= 5; a++)
    {
        Sleep(1000);
        printf(".");
    }
    printf("\n1 = Admin Girisi");
    printf("\n2 = Memur Girisi");
    printf("\n3 = Kullanici Girisi");
    printf("\n4 = Yardim");
    printf("\n0 = Cikis");
    printf("\nSeciminiz = ");
}
int admin()
{
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
    return 0;
}
int memur()
{
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
    return 0;
}
int kullanici()
{
    kullanicimenu();
    scanf_s("%d", &secim);
    _flushall();
    if (secim == 1)
        siginmaci_goruntule();
    else if (secim == 2)
        bilgilerimi_goruntule();
    else if (secim == 3)
        sifre_degistir();
    else if (secim == 0)
        exit(EXIT_SUCCESS);
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
}
void kullanicimenu()
{
    system("cls");
    printf("1 = Siginmaci goruntule");
    printf("\n2 = Bilgilerimi goruntule");
    printf("\n3 = Sifre degistir");
    printf("\n0 = Cikis");
}
void help()
{
    system("cls");
}
void kullanici_ekle()
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
        printf("Kullanici adini giriniz : ");
        gets_s(users.kullanici_adi);
        _flushall();
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
        fprintf(add_user, "%s\t%s\t%s\t%s\t%s\t%s\t%c\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", users.ad, users.soyad, users.tckimlik, users.telefon, users.eposta, users.kullanici_adi,
            users.yetki_turu, users.address.il, users.address.ilce, users.address.cadde, users.address.mahalle, users.address.sokak, users.address.apartman, users.address.no);
        if (users.yetki_turu == 'a')
        {
            fopen_s(&add_user, "adminsifre.dat", "a");
            fprintf(add_user, "\n%s\n%s", users.kullanici_adi, users.sifre);
        }
        else if (users.yetki_turu == 'm')
        {
            fopen_s(&add_user, "memursifre.dat", "a");
            fprintf(add_user, "\n%s\n%s", users.kullanici_adi, users.sifre);
        }
        else if (users.yetki_turu == 'k')
        {
            fopen_s(&add_user, "kullanicisifre.dat", "a");
            fprintf(add_user, "\n%s\n%s", users.kullanici_adi, users.sifre);
        }
    }
    fclose(add_user);
}
void kullanici_sil()
{
    system("cls");
}
void kullanici_guncelle()
{
    system("cls");
}
void kullanici_ara()
{
    system("cls");
}
void siginmaci_ekle()
{
    system("cls");
}
void siginmaci_sil()
{
    system("cls");
}
void siginmaci_guncelle()
{
    system("cls");
}
void siginmaci_ara()
{
    system("cls");
}
void siginmaci_listele()
{
    system("cls");
}
void siginmaci_goruntule()
{
    system("cls");
}
void bilgilerimi_goruntule()
{
    system("cls");
}
void sifre_degistir()
{
    system("cls");
}
int dosya_olusturma(){
    FILE *admin;  /* dosya göstericisi */
    fopen_s(&admin, "adminsifre.dat", "w");
    if (admin == NULL)
    {
        puts("Dosya acilamiyor...");
    }
    fclose(admin);
    FILE *kullanici;  /* dosya göstericisi */
    fopen_s(&kullanici, "kullanicisifre.dat", "w");
    if (kullanici == NULL)
    {
        puts("Dosya acilamiyor...");
    }
    fclose(kullanici);
    FILE *memur;  /* dosya göstericisi */
    fopen_s(&memur, "memursifre.dat", "w");
    if (memur == NULL)
    {
        puts("Dosya acilamiyor...");
    }
    fclose(memur);
    return 0;
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
