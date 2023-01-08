//Berkay Ozturk 17010011067
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct kargolar
{
    int kargo_id;
    int kargo_agirlik;
    char kargo_durum[20];
    char varis_il[20];
    char varis_ilce[20];
    char varis_mah[20];
    char varis_sokak[20];
    int varis_no;
    char bireysel[10];
    char paketleme[10];
    float ucret;
} kargo;
typedef struct alicilar
{
    char isim[20];
    char soyisim[20];
    int alici_id;
    int kargo_sayi;
    struct kargolar *ptr2;
} alici;

struct alicilar *ptr;
char id2[20]="kargo", id[20];
char sifre2[20]="sifre2", sifre[20];
void kargo_nerede(int sayac)
{
    system("cls");
    int aranan, bulunan, i;
    printf("aranan kargo id girin:");
    scanf("%d", &aranan);
    bulunan=aranan_bul(aranan, sayac);
    if(bulunan==-1)
    {
        return -1;
    }
    for(i=0; i<(ptr+bulunan)->kargo_sayi; i++)
    {
        if(((ptr+bulunan)->ptr2+i)->kargo_id==aranan)
        {
            printf("isim:%s soyisim:%s kimlik no:%d\n", (ptr+bulunan)->isim,(ptr+bulunan)->soyisim,(ptr+bulunan)->alici_id);
            printf("kargo id:%d \nadres:%s %s %s mahallesi %s sokak no:%d  \nkargo durum:%s \ngonderim turu:%s \npaketleme:%s \nucret:%5f\n", ((ptr+bulunan)->ptr2+i)->kargo_id, ((ptr+bulunan)->ptr2+i)->varis_il, ((ptr+bulunan)->ptr2+i)->varis_ilce, ((ptr+bulunan)->ptr2+i)->varis_mah, ((ptr+bulunan)->ptr2+i)->varis_sokak, ((ptr+bulunan)->ptr2+i)->varis_no, ((ptr+bulunan)->ptr2+i)->kargo_durum, ((ptr+bulunan)->ptr2+i)->bireysel, ((ptr+bulunan)->ptr2+i)->paketleme, ((ptr+bulunan)->ptr2+i)->ucret);

        }
    }
    getch();
}
int kaldir(int sayac)
{
    int aranan, bulunan, i, kargosayi;
    system("cls");
    listele(sayac);
    printf("kaldirilacak kargo id girin:");
    scanf("%d", &aranan);
    bulunan=aranan_bul(aranan, sayac);
    if(bulunan==-1)
    {
        return sayac;
    }
    if((ptr+bulunan)->kargo_sayi==1)
    {
        strcpy((ptr+bulunan)->isim,(ptr+sayac-1)->isim);
        strcpy((ptr+bulunan)->soyisim,(ptr+sayac-1)->soyisim);
        (ptr+bulunan)->alici_id=(ptr+sayac-1)->alici_id;
        (ptr+bulunan)->ptr2=realloc((ptr+bulunan)->ptr2,sizeof(struct kargolar)*(ptr+sayac-1)->kargo_sayi);
        for(i=0; i<(ptr+sayac-1)->kargo_sayi; i++)
        {
            ((ptr+bulunan)->ptr2+i)->kargo_id=((ptr+sayac-1)->ptr2+i)->kargo_id;
            ((ptr+bulunan)->ptr2+i)->kargo_agirlik=((ptr+sayac-1)->ptr2+i)->kargo_agirlik;
            ((ptr+bulunan)->ptr2+i)->varis_no=((ptr+sayac-1)->ptr2+i)->varis_no;
            ((ptr+bulunan)->ptr2+i)->ucret=((ptr+sayac-1)->ptr2+i)->ucret;
            strcpy(((ptr+bulunan)->ptr2+i)->kargo_durum,((ptr+sayac-1)->ptr2+i)->kargo_durum);
            strcpy(((ptr+bulunan)->ptr2+i)->varis_il,((ptr+sayac-1)->ptr2+i)->varis_il);
            strcpy(((ptr+bulunan)->ptr2+i)->varis_ilce,((ptr+sayac-1)->ptr2+i)->varis_ilce);
            strcpy(((ptr+bulunan)->ptr2+i)->varis_mah,((ptr+sayac-1)->ptr2+i)->varis_mah);
            strcpy(((ptr+bulunan)->ptr2+i)->varis_sokak,((ptr+sayac-1)->ptr2+i)->varis_sokak);
            strcpy(((ptr+bulunan)->ptr2+i)->bireysel,((ptr+sayac-1)->ptr2+i)->bireysel);
            strcpy(((ptr+bulunan)->ptr2+i)->paketleme,((ptr+sayac-1)->ptr2+i)->paketleme);
        }
        (ptr+bulunan)->kargo_sayi=(ptr+sayac-1)->kargo_sayi;
        sayac--;
        ptr=realloc(ptr,sizeof(struct alicilar)*sayac);
        return sayac;
    }
    else
    {
        kargosayi=(ptr+bulunan)->kargo_sayi;
        for(i=0; i<(ptr+bulunan)->kargo_sayi; i++)
        {
            if( ((ptr+bulunan)->ptr2+i)->kargo_id==aranan)
            {
                ((ptr+bulunan)->ptr2+i)->kargo_id=((ptr+bulunan)->ptr2+kargosayi-1)->kargo_id;
                ((ptr+bulunan)->ptr2+i)->kargo_agirlik=((ptr+bulunan)->ptr2+kargosayi-1)->kargo_agirlik;
                ((ptr+bulunan)->ptr2+i)->varis_no=((ptr+bulunan)->ptr2+kargosayi-1)->varis_no;
                ((ptr+bulunan)->ptr2+i)->ucret=((ptr+bulunan)->ptr2+kargosayi-1)->ucret;
                strcpy(((ptr+bulunan)->ptr2+i)->kargo_durum,((ptr+bulunan)->ptr2+kargosayi-1)->kargo_durum);
                strcpy(((ptr+bulunan)->ptr2+i)->varis_il,((ptr+bulunan)->ptr2+kargosayi-1)->varis_il);
                strcpy(((ptr+bulunan)->ptr2+i)->varis_ilce,((ptr+bulunan)->ptr2+kargosayi-1)->varis_ilce);
                strcpy(((ptr+bulunan)->ptr2+i)->varis_mah,((ptr+bulunan)->ptr2+kargosayi-1)->varis_mah);
                strcpy(((ptr+bulunan)->ptr2+i)->varis_sokak,((ptr+bulunan)->ptr2+kargosayi-1)->varis_sokak);
                strcpy(((ptr+bulunan)->ptr2+i)->bireysel,((ptr+bulunan)->ptr2+kargosayi-1)->bireysel);
                strcpy(((ptr+bulunan)->ptr2+i)->paketleme,((ptr+bulunan)->ptr2+kargosayi-1)->paketleme);
                (ptr+bulunan)->kargo_sayi--;
                (ptr+bulunan)->ptr2=realloc((ptr+bulunan)->ptr2,sizeof(struct kargolar)*(ptr+bulunan)->kargo_sayi);
                return sayac;
            }
        }

    }
}
void durum_guncelle(int sayac)
{
    int aranan, bulunan, i;
    system("cls");
    listele(sayac);
    printf("lutfen aranan kargo id girin:");
    scanf("%d", &aranan);
    bulunan=aranan_bul(aranan, sayac);
    if(bulunan==-1)
    {
        return -1;
    }
    for(i=0; i<(ptr+bulunan)->kargo_sayi; i++)
    {
        if(((ptr+bulunan)->ptr2+i)->kargo_id==aranan)
        {
            printf("yeni kargo durumunu girin:");
            scanf("%s", ((ptr+bulunan)->ptr2+i)->kargo_durum);

        }
    }
}
int aranan_bul(int aranan, int sayac)
{
    system("cls");
    int i, j;
    for(i=0; i<sayac; i++)
    {
        for(j=0; j<(ptr+i)->kargo_sayi; j++)
        {
            if(((ptr+i)->ptr2+j)->kargo_id==aranan)
            {
                return i;
            }
        }
    }
    printf("girilen id kayitli degil");
    getch();
    return -1;
}
float tahmini_ucret()
{
    int secim, secim2, cik=2, agirlik;
    float ucret=0;

    while(5)
    {
        system("cls");
        printf("kargo agirligini girin (ust limit 2000 kg):");
        scanf("%d", &agirlik);
        system("cls");
        if(agirlik>2000||agirlik<0)
        {
            printf("lutfen gecerli bir agirlik girin");
            getch();
            continue;
        }
        else
        {
            break;
        }
    }
    while(cik!=1)
    {
        printf("Gonderim turu nedir?\n[1]-Bireysel\n[2]-Kurumsal\n seciminiz:");
        scanf("%d", &secim);
        switch(secim)
        {
        case 1:
        {
            ucret+=agirlik*2;
            cik=1;
            break;
        }
        case 2:
        {
            ucret+=agirlik;
            cik=1;
            break;
        }
        default:
        {
            printf("\ntekrar deneyin");
            getch();
            continue;
        }
        }

    }
    cik=0;
    while(cik!=1)
    {
        system("cls");
        printf("ozel paket ister misiniz?\n[1]-Evet\n[2]-Hayir\nseciminiz:");
        scanf("%d", &secim2);
        switch(secim2)
        {
        case 1:
        {

            ucret+=ucret*0.1;
            cik=1;
            break;
        }
        case 2:
        {
            cik=1;
            break;
        }
        default:
        {
            printf("\ntekrar deneyin");
            getch();
            continue;
        }
        }
    }
    system("cls");
    printf("tahmini ucret %f", ucret);
    getch();
    system("cls");
    return ucret;
}
float ucret_hesapla(int sayac, int i)
{
    int secim, secim2, cik=2;
    float ucret=0;

    while(5)
    {
        system("cls");
        printf("kargo agirligini girin (ust limit 2000 kg):");
        scanf("%d", &((ptr+sayac-1)->ptr2+i)->kargo_agirlik);
        system("cls");
        if(((ptr+sayac-1)->ptr2+i)->kargo_agirlik>2000||((ptr+sayac-1)->ptr2+i)->kargo_agirlik<0)
        {
            printf("lutfen gecerli bir agirlik girin");
            getch();
            continue;
        }
        else
        {
            break;
        }
    }
    while(cik!=1)
    {
        printf("Gonderim turu nedir?\n[1]-Bireysel\n[2]-Kurumsal\n seciminiz:");
        scanf("%d", &secim);
        switch(secim)
        {
        case 1:
        {
            ucret+=((ptr+sayac-1)->ptr2+i)->kargo_agirlik*2;
            cik=1;
            strcpy(((ptr+sayac-1)->ptr2+i)->bireysel,"bireysel");
            break;
        }
        case 2:
        {
            ucret+=((ptr+sayac-1)->ptr2+i)->kargo_agirlik;
            cik=1;
            strcpy(((ptr+sayac-1)->ptr2+i)->bireysel,"kurumsal");
            break;
        }
        default:
        {
            printf("\ntekrar deneyin");
            getch();
            continue;
        }
        }

    }
    cik=0;
    while(cik!=1)
    {
        system("cls");
        printf("ozel paket ister misiniz?\n[1]-Evet\n[2]-Hayir\nseciminiz:");
        scanf("%d", &secim2);
        switch(secim2)
        {
        case 1:
        {

            ucret+=ucret*0.1;
            strcpy(((ptr+sayac-1)->ptr2+i)->paketleme,"ozel");
            cik=1;
            break;
        }
        case 2:
        {
            strcpy(((ptr+sayac-1)->ptr2+i)->paketleme,"normal");
            cik=1;
            break;
        }
        default:
        {
            printf("\ntekrar deneyin");
            getch();
            continue;
        }
        }

    }
    system("cls");
    return ucret;
}
int kargo_ekle(int sayac)
{
    int i, krgoid=0, j, k;
    srand(time(NULL));
    system("cls");
    sayac++;
    ptr=realloc(ptr, sizeof(struct alicilar)*sayac);
    printf("alici ismini girin:");
    scanf("%s", (ptr+sayac-1)->isim);
    printf("alici soyismini girin:");
    scanf("%s", (ptr+sayac-1)->soyisim);
    printf("alici kimlik no girin:");
    scanf("%d", &(ptr+sayac-1)->alici_id);
    printf("gonderilecek kargo sayisi:");
    scanf("%d", &(ptr+sayac-1)->kargo_sayi);
    (ptr+sayac-1)->ptr2=malloc(sizeof(struct kargolar)*(ptr+sayac-1)->kargo_sayi);
    for(i=0; i<(ptr+sayac-1)->kargo_sayi; i++)
    {
        system("cls");
        ((ptr+sayac-1)->ptr2+i)->ucret=ucret_hesapla(sayac, i);
        while(5)
        {
            for(k=1; k<=9; k++)
            {
                krgoid*=10;
                krgoid+=rand()%9;
            }
            for(k=0; k<sayac-1; k++)
            {
                for(j=0; j<(ptr+k)->kargo_sayi; j++)
                {
                    if(((ptr+k)->ptr2+j)->kargo_id==krgoid)
                    {
                        krgoid=0;
                        break;
                    }
                }
            }
            if(krgoid!=0)
            {
                ((ptr+sayac-1)->ptr2+i)->kargo_id=krgoid;
                break;
            }
        }
        krgoid=0;
        printf("%d.kargo varis ilini girin:", i+1);
        scanf("%s", ((ptr+sayac-1)->ptr2+i)->varis_il);
        printf("%d.kargo varis ilce girin:", i+1);
        scanf("%s", ((ptr+sayac-1)->ptr2+i)->varis_ilce);
        printf("%d.kargo varis mahalle girin:", i+1);
        scanf("%s", ((ptr+sayac-1)->ptr2+i)->varis_mah);
        printf("%d.kargo varis sokak girin:", i+1);
        scanf("%s", ((ptr+sayac-1)->ptr2+i)->varis_sokak);
        printf("%d.kargo varis apartman no girin:", i+1);
        scanf("%d", &((ptr+sayac-1)->ptr2+i)->varis_no);
        strcpy(((ptr+sayac-1)->ptr2+i)->kargo_durum,"subede");

    }
    system("cls");
    printf("kargo id:%d", ((ptr+sayac-1)->ptr2+i)->kargo_id);
    getch();
    return sayac;
}
int dosyadan_oku()
{
    int cikis, sayac=0, i;
    FILE *kayitlar;
    kayitlar=fopen("kayitlar1767.txt","r");
    if(kayitlar==NULL)
    {
        printf("kayitli veriler alinamadi");
        cikis=0;
        return cikis;
    }
    ptr = malloc(sizeof(struct alicilar)*0);
    while(!feof(kayitlar))
    {
        sayac++;
        ptr=realloc(ptr,sizeof(struct alicilar)*sayac);
        fscanf(kayitlar,"%s %s %d %d\n", (ptr+sayac-1)->isim, (ptr+sayac-1)->soyisim, &(ptr+sayac-1)->alici_id, &(ptr+sayac-1)->kargo_sayi);
        (ptr+sayac-1)->ptr2=malloc(sizeof(struct kargolar)*(ptr+sayac-1)->kargo_sayi);
        for(i=0; i<(ptr+sayac-1)->kargo_sayi; i++)
        {
            fscanf(kayitlar,"%d %d %s %s %s %s %s %d %f %s %s\n", &((ptr+sayac-1)->ptr2+i)->kargo_id, &((ptr+sayac-1)->ptr2+i)->kargo_agirlik, ((ptr+sayac-1)->ptr2+i)->kargo_durum, ((ptr+sayac-1)->ptr2+i)->varis_il, ((ptr+sayac-1)->ptr2+i)->varis_ilce, ((ptr+sayac-1)->ptr2+i)->varis_mah, ((ptr+sayac-1)->ptr2+i)->varis_sokak, &((ptr+sayac-1)->ptr2+i)->varis_no, &((ptr+sayac-1)->ptr2+i)->ucret, ((ptr+sayac-1)->ptr2+i)->bireysel, ((ptr+sayac-1)->ptr2+i)->paketleme);
        }

    }
    fclose(kayitlar);
    return sayac;
}
void dosya_kaydet(int sayac)
{
    int i, j;
    FILE *veriler;
    veriler=fopen("kayitlar1767.txt","w");
    for(i=0; i<sayac; i++)
    {
        fprintf(veriler,"%s %s %d %d\n", (ptr+i)->isim, (ptr+i)->soyisim, (ptr+i)->alici_id, (ptr+i)->kargo_sayi);
        for(j=0; j<(ptr+i)->kargo_sayi; j++)
        {
            fprintf(veriler,"%d %d %s %s %s %s %s %d %f %s %s\n", ((ptr+i)->ptr2+j)->kargo_id, ((ptr+i)->ptr2+j)->kargo_agirlik, ((ptr+i)->ptr2+j)->kargo_durum, ((ptr+i)->ptr2+j)->varis_il, ((ptr+i)->ptr2+j)->varis_ilce, ((ptr+i)->ptr2+j)->varis_mah, ((ptr+i)->ptr2+j)->varis_sokak, ((ptr+i)->ptr2+j)->varis_no, ((ptr+i)->ptr2+j)->ucret, ((ptr+i)->ptr2+j)->bireysel, ((ptr+i)->ptr2+j)->paketleme);
        }
    }
    free(ptr);
    fclose(veriler);
}
void listele(int sayac)
{
    system("cls");
    int i, j;
    for(i=0; i<sayac; i++)
    {
        printf("isim:%s soyisim:%s kimlik no:%d\n", (ptr+i)->isim,(ptr+i)->soyisim,(ptr+i)->alici_id);
        for(j=0; j<(ptr+i)->kargo_sayi; j++)
        {
            printf("**************************************************************************************************************************************************\n");
            printf("kargo id:%d \nadres:%s %s %s mahallesi %s sokak no:%d  \nkargo durum:%s \ngonderim turu:%s \npaketleme:%s \nucret:%5f\n", ((ptr+i)->ptr2+j)->kargo_id, ((ptr+i)->ptr2+j)->varis_il, ((ptr+i)->ptr2+j)->varis_ilce, ((ptr+i)->ptr2+j)->varis_mah, ((ptr+i)->ptr2+j)->varis_sokak, ((ptr+i)->ptr2+j)->varis_no, ((ptr+i)->ptr2+j)->kargo_durum, ((ptr+i)->ptr2+j)->bireysel, ((ptr+i)->ptr2+j)->paketleme, ((ptr+i)->ptr2+j)->ucret);
        }
            printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    return 1;
}
int yntc_kntrl()
{
    int boyut=0, boyut2=0, i, sonuc=0;
    boyut=strlen(id);
    boyut2=strlen(sifre);
    if(boyut!=strlen(id2)||boyut2!=strlen(sifre2))
    {
        return 0;
    }
    for(i=0; i<boyut; i++)
    {
        if(id2[i]==id[i])
        {
            if(i==boyut-1)
            {
                sonuc=1;
            }
            else
            {
                continue;
            }
        }
        else
        {
            return 0;
        }
    }
    for(i=0; i<boyut2; i++)
    {
        if(sifre2[i]==sifre2[i])
        {
            if(i==boyut-1)
            {
                sonuc=1;
            }
            else
            {
                continue;
            }
        }
        else
        {
            return 0;
        }
    }
    if(sonuc==1)
    {
        return sonuc;
    }

}
int main()
{
    int secim, secim2, cikis, kontrol=0, sayac=0;
    cikis=dosyadan_oku();
    sayac=cikis;
    while(cikis!=0)
    {
        cikis=2;
        system("cls");
        printf("[1]-YETKILI GIRISI\n[2]-ZIYARETCI GIRISI\nseciminiz:");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
        {
            system("cls");
            printf("//kullanici adi:%s, sifre:%s\n", id2, sifre2);
            printf("KULLANICI ADI:");
            scanf("%s", &id);
            printf("SIFRE:");
            scanf("%s", &sifre);
            kontrol=yntc_kntrl();
            if(kontrol==0)
            {
                system("cls");
                printf("yanlis kullanici adi yada sifre!\nlutfen tekrar deneyin.");
                getch();
                continue;
            }
            while(cikis>1)
            {
                system("cls");
                printf("[1]-KARGO EKLEME\n[2]-KARGO DURUMU GUNCELLE\n[3]-GONDERIMDEN KALDIRMA\n[4]-LISTELEME\n[5]-GERI\n[6]-KAYDET VE CIK\nseciminiz:");
                scanf("%d", &secim2);
                switch(secim2)
                {
                case 1:
                {
                    sayac=kargo_ekle(sayac);
                    break;
                }
                case 2:
                {
                    durum_guncelle(sayac);
                    break;
                }
                case 3:
                {
                    sayac=kaldir(sayac);
                    break;
                }
                case 4:
                {
                    listele(sayac);
                    getch();
                    break;
                }
                case 5:
                {
                    cikis=1;
                    break;
                }
                case 6:
                {
                    cikis=0;
                    dosya_kaydet(sayac);
                    break;
                }
                default: system("cls");printf("yanlis giris tekrar girin!");getch();
                }
            }
            break;
        }
        case 2:
        {
            while(cikis>1)
            {
                system("cls");
                printf("HOS GELDINIZ\n[1]-KARGOM NEREDE\n[2]-FIYAT HESAPLA\n[3]-GERI\n[4]-CIKIS\nSECIMINIZ:");
                scanf("%d", &secim2);
                switch(secim2)
                {
                case 1:
                {
                    kargo_nerede(sayac);
                    break;
                }
                case 2:
                {
                    tahmini_ucret();
                    break;
                }
                case 3:
                {
                    cikis=1;
                    break;
                }
                case 4:
                {
                    cikis=0;
                    break;
                }
                default: system("cls");printf("yanlis giris tekrar deneyin:");getch();break;
                }
            }
            break;
        }
        default: system("cls");printf("yanlis giris tekrar deneyin:");getch();break;
        }
    }
}
