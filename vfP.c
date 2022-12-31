#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
int jour;
int mois;
int annee;
}Date;
typedef struct {
char codeP[100];
char refP[100];
char descriP[100];
float prixP;
int stockP;
}Produit;

typedef struct {
char codePr[100];
Date dateEntree;
int quantiEntree;

}HistoriqueEntree;
typedef struct {
char codeCarte[100];
char nom[100];
char prenom[100];
float montant;

}Client;
typedef struct {
char codeProd[100];
Date dateAchat;
int quantiAchat;
float montantTot;
Client client;

}HistoriqueSortie;
int mode(){

   int choixMo;
   printf("\n");
     printf("  ---------------------------\n");
  printf("           || MENU ||\n");
  printf("  ---------------------------\n");
  printf("  1. Mode Manager \n"
         "  2. Mode Client \n");
  printf(" Faites votre choix : ");
   scanf("%d",&choixMo);
    system("cls");

   return choixMo;
}


 void CodeCard(char cc[20])
{
    FILE *C;
C=fopen("clients.txt","r");
Client cl;
char codeC;

for(int i=0;i<nbClients();i++){

            fscanf(C, "%s  ",&cl.nom);
            fscanf(C, "%s  ",&cl.prenom);
            fscanf(C, "%s  ",&cl.codeCarte);
            fscanf(C, "%f  ",&cl.montant);




}
strcpy(cc,cl.codeCarte);

  }


void Menu(int m) {

        char codeEnt[20];
        int nb=nbFinalProd();

        char codeSort[20];
        int quantitySort;
        int quantity;
        FILE *f3;
        int Hist=0;
        Client nvClient;
        int choixOb=0;

int choice;
if(m==1){




    while(choixOb != 10)
{
/********** Affichage du menu **********/
do
{
     printf("\n");
     printf("  ---------------------------\n");
  printf("           || MENU ||\n");
  printf("  ---------------------------\n");
  printf(" 1. Ajout d'un nouveau produit dans la liste des produits existante \n"
         " 2. Ajout d'une quantite dans les entrees \n"
         " 3. Affichage des produits \n"
	 " 4. Suppression d'un produit \n"
	 " 5. Modification d'un produit \n"
	 " 6. Recherche d'un produit \n"
	 " 7. Affichage de l'historique d'entree \n"
	 " 8. Affichage de l'historique sortie   \n"
	 " 9. Afficher la liste des clients   \n"
	 " 10. Quitter le mode manager \n");
  printf(" Faites votre choix : ");

 scanf("%d",&choixOb);
 } while( (choixOb<1)||(choixOb>10) );

    switch(choixOb){
      case 1:
          system("cls");
	      ajoutNouveauP();

	      break;
      case 2:
          system("cls");
          AjoutHisEntree(codeEnt,&quantity);

 	      break;
      case 3:
            system("cls");
            AfficheProduitManager();
	      break;
     case 4:
        system("cls");
        Suppression();
	   break;
     case 5:
         system("cls");

         Modification();
        break;

      case 6:
          system("cls");
	      RechercheProduit();
	     // return 0;
	     break;

      case 7:
         system("cls");

        AffichageHis();

        break;
        case 8:
            system("cls");
            AffichageHisSortie();
            break;

        case 9:
            system("cls");
            AffichageClient();
            break;
	  case 10:
	      system("cls");
	      main();

      default:
	      printf("/!\\ Option inexistante /!\\\n");
	      break;
    }
	      }

    }
else {
            if(NULL == (f3 = fopen("clients.txt","a"))){
    printf("echec %d\n");

  }else{

     printf("------------------------------------------\n");
  printf("   | Saisie de coordonnes du client |\n");
  printf("------------------------------------------\n");
    printf(" Entrer votre nom: ");
    fflush(stdin);
    gets(nvClient.nom);
    fputs(nvClient.nom,f3);
    fputs("  ",f3);
    printf(" Entrer votre prenom: ");
    fflush(stdin);
    gets(nvClient.prenom);
    fputs(nvClient.prenom,f3);
    fputs("  ",f3);
    do{
    printf(" Entrer votre numero de carte: ");
    fflush(stdin);
    gets(nvClient.codeCarte);}while(strlen(nvClient.codeCarte)!=8);
    fputs(nvClient.codeCarte,f3);
    fputs("  ",f3);
    nvClient.montant=rand()%(500 - 2000) + 2000;
    fprintf(f3,"%f",nvClient.montant);
    fputs("  ",f3);
    fputs("\n",f3);

 system("cls");


  }
  fclose(f3);

     while(choixOb != 6)
{
/********** Affichage du menu **********/
do
{

   printf("\n");
     printf("  ---------------------------\n");
  printf("           || MENU ||\n");
  printf("  ---------------------------\n");
  printf("1. Consultation de la liste des produits \n"
         "2. Recherche d'un produit \n"
         "3. Effectuer une operation d'achat \n"
	 "4. Quitter le mode client \n");

 scanf("%d",&choixOb);
 } while( (choixOb<1)||(choixOb>4) );

    switch(choixOb){
      case 1:
           system("cls");

	      AfficheProdClient();

	      break;
      case 2:
           system("cls");

          RechercheProduitClient();

 	      break;
      case 3:
           system("cls");

         AjoutHisSortie(codeSort,&quantitySort);

	      break;
     case 4:
          system("cls");

         main();

 	   break;
      default:
	      printf("/!\\ Option inexistante /!\\\n");
	      break;
    }

	      }

    }

}



///***************************
  int nbProduits(){
  FILE *f;
  Produit elem;
  int nb = 0;
  int c ;
  if(NULL == (f = fopen("produits.txt","r"))){
  }else{
 do
{
c = getc(f); // On lit le caractère
if ((char)c=='\n'){
    nb++;
    }
} while (c!= EOF); // On continue tant quefgetc n'a pas retourné EOF (fin de fichier)
fclose(f);
}
return nb;

}



  int nbHistoriques(){
  FILE *f1;
  HistoriqueEntree h;
  int nb = 0;
  int c ;
  if(NULL == (f1 = fopen("hisEntree.txt","r"))){
  }else{
 do
{
c = getc(f1); // On lit le caractère
if ((char)c=='\n'){
    nb++;
    }
} while (c!= EOF); // On continue tant quefgetc n'a pas retourné EOF (fin de fichier)
fclose(f1);
}
return nb;

}
///***************
int testCode(char code[100]){

    char ch[200];

    FILE *f;
    int i=-1;
    int trouve=0;
    Produit elem;
    int nbProd;
    nbProd=nbProduits();
    if(NULL == (f = fopen("produits.txt","r"))){
  }
  else{


    while(i<nbProd && trouve==0){i++;
            fscanf(f, "%s  ",&elem.codeP);
            fscanf(f, "%s  ",&elem.refP);
            fscanf(f, "%s  ",&elem.descriP);
            fscanf(f, "%f  ",&elem.prixP);
            fscanf(f, "%d\n",&elem.stockP);

           // printf("%s \n",elem.codeP);
            if(strcmp(code,elem.codeP)==0){
                trouve=1;
            }

    }}
    return trouve;




}
///**********

void ajoutNouveauP(){

FILE *f;
  Produit nouveau;
  if(NULL == (f = fopen("produits.txt","a"))){
    printf("echec %d\n");

  }else{
  printf("--------------------------------\n");
  printf("      | Nouveau produit |\n");
  printf("--------------------------------\n");
   do{
    printf(" Entrez le code : ");
    fflush(stdin);
    gets(nouveau.codeP);
   }while(testCode(nouveau.codeP)==1);
   // scanf("%s",&nouveau.codeP);
    fputs(nouveau.codeP,f);
    fputs("  ",f);
    printf(" Entrez la reference: ");
    fflush(stdin);
    gets(nouveau.refP);
    //scanf("%s",&nouveau.refP);
    fputs(nouveau.refP,f);
    fputs("  ",f);
    printf(" Entrez la description: ");
    fflush(stdin);
    gets(nouveau.descriP);
    //scanf("%s",&nouveau.descriP);
    fputs(nouveau.descriP,f);
    fputs("  ",f);
    printf(" Entrez le prix: ");
    scanf("%f",&nouveau.prixP);
    fprintf(f,"%f",nouveau.prixP);
    fputs("  ",f);
    nouveau.stockP=0;
    fprintf(f,"%d",nouveau.stockP);
    //fputs("  ",f);
    fputs("\n",f);


  }
  fclose(f);
  }


///*****
  void ModifStock(char CodeEn[20],int quanti){
      FILE *NV;
      FILE *P;
      Produit p;
      int i;
      NV=fopen("fichiersAux//nv.txt","w");
      P=fopen("produits.txt","r");
        for(i=0;i<nbProduits();i++){

            fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

            if(strcmp(CodeEn,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);

                p.stockP=p.stockP+quanti;
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);




            }
            else {
                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

            }



        }

fclose(P);

fclose(NV);




  }






///******
void AjoutHisEntree(char codeEnt[20], int *quantity){
FILE *f2;
FILE *f3;
FILE *FINAL;
FILE *nv;

FINAL=fopen("fichiersAux//produitsFinal.txt","a");
  HistoriqueEntree hi;
  Produit nvP;
  Produit p;
  int sommeQ=0;
  int trouve=0;
  int i=-1;
  int nbProd;
  HistoriqueEntree nouveauE;
  nbProd=nbProduits();

  f2 = fopen("hisEntree.txt","a");


    printf("--------------------------------\n");
  printf("      | Nouvelle entree |\n");
  printf("--------------------------------\n");
    do{
    printf(" Entrez le code : ");
    fflush(stdin);
    gets(nouveauE.codePr);
    }while(testCode(nouveauE.codePr)==0);
    fputs(nouveauE.codePr,f2);
    fputs("  ",f2);
    printf(" Entrez la date de l'entree: ");
    scanf("%d-%d-%d",&nouveauE.dateEntree.jour,&nouveauE.dateEntree.mois,&nouveauE.dateEntree.annee);
    strcpy(codeEnt,nouveauE.codePr);
    fprintf(f2,"%d",nouveauE.dateEntree.jour);
    fputs("-",f2);
    fprintf(f2,"%d",nouveauE.dateEntree.mois);
    fputs("-",f2);
    fprintf(f2,"%d",nouveauE.dateEntree.annee);
    fputs("  ",f2);
    printf(" Entrez la quantite: ");
    scanf("%d",&nouveauE.quantiEntree);
    fprintf(f2,"%d",nouveauE.quantiEntree);
    *quantity=nouveauE.quantiEntree;

    fputs("  ",f2);
    fputs("\n",f2);


fclose(f2);

f3=fopen("hisEntree.txt","r");
for(int k=0;k<nbHistoriques();k++){

            fscanf(f3,"%s  ",&hi.codePr);
            fscanf(f3, "%d-",&hi.dateEntree.jour);
            fscanf(f3, "%d-",&hi.dateEntree.mois);
            fscanf(f3, "%d  ",&hi.dateEntree.annee);
            fscanf(f3, "%d\n",&hi.quantiEntree);


    if(strcmp(hi.codePr,codeEnt)==0){




        sommeQ=sommeQ+hi.quantiEntree;


    }


}
fclose(f3);

int k;


FILE *HS;
HS=fopen("hisSortie.txt","r");
HistoriqueSortie hs;
int sommeS=0;
for(int i=0;i<nbHistoriquesSortie();i++){

    fscanf(HS,"%s  ",&hs.codeProd);
    fscanf(HS,"%d-",&hs.dateAchat.jour);
    fscanf(HS,"%d-",&hs.dateAchat.mois);
    fscanf(HS,"%d  ",&hs.dateAchat.annee);
    fscanf(HS,"%d  ",&hs.quantiAchat);
    fscanf(HS, "%s  ",&hs.client.codeCarte);
    fscanf(HS, "%f\n",&hs.montantTot);


    if(strcmp(hs.codeProd,codeEnt)==0){

            sommeS=sommeS+hs.quantiAchat;


    }

}
fclose(HS);

sommeQ=sommeQ-sommeS;
*quantity=sommeQ;

ModifStock(codeEnt,sommeQ);
nv=fopen("fichiersAux//nv.txt","r");

for(int j=0;j<nbProduits();j++){




            fscanf(nv, "%s  ",&nvP.codeP);
            fscanf(nv, "%s  ",&nvP.refP);
            fscanf(nv, "%s  ",&nvP.descriP);
            fscanf(nv, "%f  ",&nvP.prixP);
            fscanf(nv, "%d\n",&nvP.stockP);

            if(strcmp(nouveauE.codePr,nvP.codeP)==0){

                fprintf(FINAL,"%s",nvP.codeP);
                fputs("  ",FINAL);
                fprintf(FINAL,"%s",nvP.refP);
                fputs("  ",FINAL);
                fprintf(FINAL,"%s",nvP.descriP);
                fputs("  ",FINAL);
                fprintf(FINAL,"%f",nvP.prixP);
                fputs("  ",FINAL);
                fprintf(FINAL,"%d",*quantity);
                fputs("\n",FINAL);


            }

}
fclose(FINAL);
FinalP();

      }

///*****

   int nbFinalProd(){
  FILE *f1;
  Produit h;
  int nb = 0;
  int c ;
  if(NULL == (f1 = fopen("fichiersAux//produitsFinal.txt","r"))){

  }else{
 do
{
c = getc(f1); // On lit le caractère
if ((char)c=='\n'){
    nb++;
    }
} while (c!= EOF); // On continue tant quefgetc n'a pas retourné EOF (fin de fichier)
fclose(f1);
}
return nb;
   }



///****

void FinalP(){
FILE *PF2;
FILE *P;
FILE *NV;
PF2=fopen("fichiersAux//produitsFinal.txt","r");
NV=fopen("produitFINAL.txt","w");
Produit pf;
int max=0;
int test;
int y;
Produit pf2;
P=fopen("produits.txt","r");

for(int i=0;i<nbProduits();i++){

        fclose(PF2);
        PF2=fopen("fichiersAux//produitsFinal.txt","r");




            fscanf(P, "%s  ",&pf.codeP);
//
            fscanf(P, "%s  ",&pf.refP);
            fscanf(P, "%s  ",&pf.descriP);
            fscanf(P, "%f  ",&pf.prixP);
            fscanf(P, "%d\n",&pf.stockP);
            y=pf.stockP;
            fprintf(NV,"%s",pf.codeP);
            fputs("  ",NV);
            fprintf(NV,"%s",pf.refP);
            fputs("  ",NV);
            fprintf(NV,"%s",pf.descriP);
            fputs("  ",NV);
            fprintf(NV,"%f",pf.prixP);
            fputs("  ",NV);

        for(int j=0;j<nbFinalProd();j++){

            fscanf(PF2, "%s  ",&pf2.codeP);
            fscanf(PF2, "%s  ",&pf2.refP);
            fscanf(PF2, "%s  ",&pf2.descriP);
            fscanf(PF2, "%f  ",&pf2.prixP);
            fscanf(PF2, "%d\n",&pf2.stockP);

            if(strcmp(pf.codeP,pf2.codeP)==0){


                y=pf2.stockP;


            }
}

fprintf(NV,"%d",y);
fputs("\n",NV);}
fclose(PF2);
fclose(NV);
fclose(P);



}



///******

void AfficheProdClient(){

Produit p;
FILE *P;
P=fopen("produits.txt","r");
 printf("--------------------------------\n");
  printf("      | Liste des produits |\n");
  printf("--------------------------------\n");

for(int i=0;i<nbProduits();i++){

            fscanf(P, "%s  ",&p.codeP);
            fscanf(P, "%s  ",&p.refP);
            fscanf(P, "%s  ",&p.descriP);
            fscanf(P, "%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

            printf("%d.  ",i+1);
            printf("%s  ",p.codeP);
            printf("%s  ",p.refP);
            printf("%s  ",p.descriP);
            printf("%f \n",p.prixP);




}
fclose(P);


}

///***



void AfficheProduitManager(){

Produit p;
FILE *P;
P=fopen("produitFINAL.txt","r");

 printf("--------------------------------\n");
  printf("      | Liste de produits |\n");
  printf("--------------------------------\n");


for(int i=0;i<nbProduits();i++){

            fscanf(P, "%s  ",&p.codeP);
            fscanf(P, "%s  ",&p.refP);
            fscanf(P, "%s  ",&p.descriP);
            fscanf(P, "%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

            printf("%d.  ",i+1);
            printf("%s  ",p.codeP);
            printf("%s  ",p.refP);
            printf("%s  ",p.descriP);
            printf("%f  ",p.prixP);
            printf("%d\n",p.stockP);



}
fclose(P);


}


 ///***

 void ModifStockSortie(char CodeEn[20],int quantiAch){
      FILE *NV;
      FILE *P;
      Produit p;
      int i;
      NV=fopen("fichiersAux//new.txt","w");
      P=fopen("produitFINAL.txt","r");
        for(i=0;i<nbProduits();i++){

            fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

            if(strcmp(CodeEn,p.codeP)==0){
                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);

                p.stockP=p.stockP-quantiAch;
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);




            }
            else {
                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

            }



        }

fclose(P);
//P=NV;
//free(P);
fclose(NV);




  }



 ///***


 int nbHistoriquesSortie(){
  FILE *f1;
  Produit h;
  int nb = 0;
  int c ;
  if(NULL == (f1 = fopen("hisSortie.txt","r"))){
  }else{
 do
{
c = getc(f1); // On lit le caractère
if ((char)c=='\n'){
    nb++;
    }
} while (c!= EOF); // On continue tant quefgetc n'a pas retourné EOF (fin de fichier)
fclose(f1);
}
return nb;
   }

///****


int nbClients(){
  FILE *f1;
  Produit h;
  int nb = 0;
  int c ;
  if(NULL == (f1 = fopen("clients.txt","r"))){
  }else{
 do
{
c = getc(f1); // On lit le caractère
if ((char)c=='\n'){
    nb++;
    }
} while (c!= EOF); // On continue tant quefgetc n'a pas retourné EOF (fin de fichier)
fclose(f1);
}
return nb;
   }


///****



float verifMontant(){

FILE *C;
C=fopen("clients.txt","r");
Client cl;

for(int i=0;i<nbClients();i++){

            fscanf(C, "%s  ",&cl.nom);
            fscanf(C, "%s  ",&cl.prenom);
            fscanf(C, "%s  ",&cl.codeCarte);
            fscanf(C, "%f  ",&cl.montant);



}

return cl.montant;


}

float CalculMontant(char code[20],int quantity){

FILE *P;
P=fopen("produitFINAL.txt","r");
Produit p;
int i=-1;
int trouve=0;
float montantTotal;
  while(i<nbProduits() && trouve==0){
                i++;
            fscanf(P, "%s  ",&p.codeP);
            fscanf(P, "%s  ",&p.refP);
            fscanf(P, "%s  ",&p.descriP);
            fscanf(P, "%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

            if(strcmp(p.codeP,code)==0){

                trouve=1;
                montantTotal=quantity*p.prixP;



            }
            }

 fclose(P);
        return montantTotal;
}



///***
int verifStockNull(char code[20]){

Produit p;
int trouve=0;
FILE *P;
P=fopen("produitFINAL.txt","r");
int test=1;
int i=-1;
while(i<nbProduits() && trouve==0){
            i++ ;

            fscanf(P, "%s  ",&p.codeP);
            fscanf(P, "%s  ",&p.refP);
            fscanf(P, "%s  ",&p.descriP);
            fscanf(P, "%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

            if(strcmp(p.codeP,code)==0){
                    trouve=1;

                if(p.stockP==0){

                    test=0;
                }
            }
}

fclose(P);
return test;


}





///****
int verifStock(char code[20],int stock){
Produit p;
int trouve=0;
FILE *P;
P=fopen("produitFINAL.txt","r");
int test=1;
int i=-1;
while(i<nbProduits() && trouve==0){
            i++ ;

            fscanf(P, "%s  ",&p.codeP);
            fscanf(P, "%s  ",&p.refP);
            fscanf(P, "%s  ",&p.descriP);
            fscanf(P, "%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

            if(strcmp(p.codeP,code)==0){
                    trouve=1;

                if(stock>p.stockP){

                    test=0;
                }
            }
}

fclose(P);
return test;


}


///****


///***




void AjoutHisSortie(char codeSort[20], int *quantityAch){
FILE *f2;
FILE *f3;
FILE *FINAL;
FILE *nv;



FINAL=fopen("fichiersAux//produitsFinalClient.txt","a");
  HistoriqueSortie hi;
  Produit nvP;
  Produit p;
  char ON[10];
  int sommeQ=0;
  int trouve=0;
  int i=-1;
  int nbProd;
  HistoriqueSortie nouveauS;
  nbProd=nbProduits();

  f2 = fopen("hisSortie.txt","a");


    printf("--------------------------------------\n");
  printf("      | Acheter un produit |\n");
  printf("--------------------------------------\n");
    do{
    printf(" Entrez le code : ");
    fflush(stdin);
    gets(nouveauS.codeProd);
    }while(testCode(nouveauS.codeProd)==0 || verifStockNull(nouveauS.codeProd)==0);

    printf(" Entrez la date de l'entree: ");
    scanf("%d-%d-%d",&nouveauS.dateAchat.jour,&nouveauS.dateAchat.mois,&nouveauS.dateAchat.annee);
    strcpy(codeSort,nouveauS.codeProd);
    //scanf("%s",&nouveau.refP);

        char cc[30];

     printf(" Entrez la quantite: ");
     scanf("%d",&nouveauS.quantiAchat);
        while(verifStock(nouveauS.codeProd,nouveauS.quantiAchat)==0){

            printf(" la quantite desiree n'est pas disponible \n");
            printf(" Entrer la quantite :");
            scanf("%d",&nouveauS.quantiAchat);
        }
        CodeCard(cc);


        strcpy(nouveauS.client.codeCarte,cc);



        printf("\n Votre montant total est : %f",CalculMontant(nouveauS.codeProd,nouveauS.quantiAchat));
        printf(" Voulez vous confirmer l'operation de l'achat OUI/NON ? \n");
        scanf(" %s",&ON);
        while(strcmp(ON,"OUI")!=0 && strcmp(ON,"NON")!=0){

        printf(" Voulez vous confirmer l'operation de l'achat O/N ? \n");
        scanf("%s",&ON);


        }
        if(strcmp(ON,"OUI")==0){
        if(CalculMontant(nouveauS.codeProd,nouveauS.quantiAchat)>verifMontant()){

            printf("\n votre solde est insuffisant ! ");

        }
        else{
        nouveauS.montantTot=CalculMontant(nouveauS.codeProd,nouveauS.quantiAchat);

        fputs(nouveauS.codeProd,f2);
        fputs("  ",f2);
        fprintf(f2,"%d",nouveauS.dateAchat.jour);
        fputs("-",f2);
        fprintf(f2,"%d",nouveauS.dateAchat.mois);
        fputs("-",f2);
        fprintf(f2,"%d",nouveauS.dateAchat.annee);
        fputs("  ",f2);
        fprintf(f2,"%d",nouveauS.quantiAchat);
        fputs("  ",f2);
        fputs(nouveauS.client.codeCarte,f2);
        fputs("  ",f2);
        fprintf(f2,"%f",nouveauS.montantTot);
        fputs("  ",f2);
        fputs("\n",f2);






    *quantityAch=nouveauS.quantiAchat;



fclose(f2);

f3=fopen("hisSortie.txt","r");
for(int k=0;k<nbHistoriquesSortie();k++){

            fscanf(f3,"%s  ",&hi.codeProd);
            fscanf(f3, "%d-",&hi.dateAchat.jour);
            fscanf(f3, "%d-",&hi.dateAchat.mois);
            fscanf(f3, "%d  ",&hi.dateAchat.annee);
            fscanf(f3, "%d  ",&hi.quantiAchat);
            fscanf(f3, "%s  ",&hi.client.codeCarte);
            fscanf(f3, "%f\n",&hi.montantTot);

            //printf("%s",hi.codeProd);
            //printf("%f",hi.montantTot);


    if(strcmp(hi.codeProd,codeSort)==0){






    }


}
fclose(f3);

int k;

*quantityAch=nouveauS.quantiAchat;
sommeQ=*quantityAch;
ModifStockSortie(codeSort,sommeQ);
nv=fopen("fichiersAux//new.txt","r");

for(int j=0;j<nbProduits();j++){



            fscanf(nv, "%s  ",&nvP.codeP);
            fscanf(nv, "%s  ",&nvP.refP);
            fscanf(nv, "%s  ",&nvP.descriP);
            fscanf(nv, "%f  ",&nvP.prixP);
            fscanf(nv, "%d\n",&nvP.stockP);

            if(strcmp(nouveauS.codeProd,nvP.codeP)==0){

                fprintf(FINAL,"%s",nvP.codeP);
                fputs("  ",FINAL);
                fprintf(FINAL,"%s",nvP.refP);
                fputs("  ",FINAL);
                fprintf(FINAL,"%s",nvP.descriP);
                fputs("  ",FINAL);
                fprintf(FINAL,"%f",nvP.prixP);
                fputs("  ",FINAL);
                fprintf(FINAL,"%d",nvP.stockP);
                fputs("\n",FINAL);


            }

}
fclose(FINAL);
FinalPClient();

MiseAjour();

      }}

}


///****



void FinalPClient(){
FILE *PF2;
FILE *P;
FILE *NV;
PF2=fopen("fichiersAux//produitsFinalClient.txt","r");
NV=fopen("fichiersAux//produitFINALClient.txt","w");
//code char[20];
Produit pf;
int min=100000000;
int test;
Produit pf2;
P=fopen("produitFINAL.txt","r");

for(int i=0;i<nbProduits();i++){

        fclose(PF2);
        PF2=fopen("fichiersAux//produitsFinalClient.txt","r");


        min=100000000;

            fscanf(P, "%s  ",&pf.codeP);

            fscanf(P, "%s  ",&pf.refP);
            fscanf(P, "%s  ",&pf.descriP);
            fscanf(P, "%f  ",&pf.prixP);
            fscanf(P, "%d\n",&pf.stockP);

            fprintf(NV,"%s",pf.codeP);
            fputs("  ",NV);
            fprintf(NV,"%s",pf.refP);
            fputs("  ",NV);
            fprintf(NV,"%s",pf.descriP);
            fputs("  ",NV);
            fprintf(NV,"%f",pf.prixP);
            fputs("  ",NV);

        for(int j=0;j<nbFinalProd();j++){

            fscanf(PF2, "%s  ",&pf2.codeP);

            fscanf(PF2, "%s  ",&pf2.refP);
            fscanf(PF2, "%s  ",&pf2.descriP);
            fscanf(PF2, "%f  ",&pf2.prixP);
            fscanf(PF2, "%d\n",&pf2.stockP);

            if(strcmp(pf.codeP,pf2.codeP)==0){


                if(min>pf2.stockP){

                    min=pf2.stockP;


                }

            }
            else{

                min=pf.stockP;
            }
}

fprintf(NV,"%d",min);
fputs("\n",NV);}
//}
fclose(PF2);
fclose(NV);
fclose(P);



}
///****


void MiseAjour(){


    FILE *fp1, *fp2;
    char ch;

    // ouvrir le fichier en lecture
    fp1 = fopen("fichiersAux//produitFINALClient.txt", "r");
    // ouvrir le fichier en écriture
    fp2 = fopen("produitFINAL.txt", "w");

    // Lire le contenu du fichier
    while((ch = getc(fp1)) != EOF)
        putc(ch, fp2);

    fclose(fp1);
    fclose(fp2);



}

//void Remplacer(FILE f){












///****

























 void RechercheProduit(){

    FILE *P;
    P=fopen("produitFINAL.txt","r");
    char code[20];
    char ref[20];
    int i,choix;
    Produit p;



        if(nbProduits()==0)
	  printf("Pas de produits");



     else{


             while(choix != 6)
{
/********** Affichage du menu **********/
do
{
 //system("cls");
 printf("--------------------------------------\n");
  printf("      | Rechercher un produit |\n");
  printf("--------------------------------------\n");
  printf("   1. Recherche par code\n   2. Recherche par reference\n");
  printf("   3. Annuler \n Faites votre choix :");
  scanf("%d",&choix);
 } while( (choix<1)||(choix>4) );
    switch(choix){
      case 1:
         printf("--------------------------------------\n");
  printf("      | Recherche par code |\n");
  printf("--------------------------------------\n");
	    printf(" Entrez le code : ");
	    scanf("%s",&code);

	    while(testCode(code)==0){
        printf(" Entrez un code valide : ");
	    scanf("%s",&code);

	    }
	    for(int i=0;i<nbProduits();++i){

            fscanf(P, "%s  ",&p.codeP);
          //  printf(" CodeP final = %s \n ",p.codeP);
            fscanf(P, "%s  ",&p.refP);
            fscanf(P, "%s  ",&p.descriP);
            fscanf(P, "%f  ",&p.prixP);

            fscanf(P, "%d\n",&p.stockP);
	      if( strcmp(code,p.codeP)==0){
                printf(" Code Produit : %s  Reference : %s  Description : %s  Prix : %f  Stock: %d  \n",p.codeP,p.refP,p.descriP,p.prixP,p.stockP);}
           }
	     break ;
         case 2:
              printf("--------------------------------------\n");
  printf("      | Recherche par reference |\n");
  printf("--------------------------------------\n");
               printf(" Entrez la reference: ");
	    scanf("%s",&ref);
	    for(int j=0;i<nbProduits();j++){
            fscanf(P, "%s  ",&p.codeP);
            fscanf(P, "%s  ",&p.refP);
            fscanf(P, "%s  ",&p.descriP);
            fscanf(P, "%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);
	      if( strcmp(ref,p.refP)==0){
                printf(" Code Produit : %s  Reference : %s  Descrittion : %s  Prix : %f  Stock: %d  \n",p.codeP,p.refP,p.descriP,p.prixP,p.stockP);

         }}
        break;
         case 3:
            return 0 ;
         default:
            printf("choix incorrect !");
	    }
     }

 }}


 ///****

  void RechercheProduitClient(){

    FILE *P;
    P=fopen("produitFINAL.txt","r");
    char code[20];
    char ref[20];
    int i,choix;
    Produit p;



        if(nbProduits()==0)
	  printf("Pas de produits");



     else{


             while(choix != 6)
{
/********** Affichage du menu **********/
do
{
 //system("cls");
 printf("--------------------------------------\n");
  printf("      | Rechercher un produit |\n");
  printf("--------------------------------------\n");
  printf("   1. Recherche par code\n   2. Recherche par reference\n");
  printf("   3. Annuler \n Faites votre choix :");
  scanf("%d",&choix);
 } while( (choix<1)||(choix>4) );
    switch(choix){
      case 1:
  printf("--------------------------------------\n");
  printf("      | Recherche par code |\n");
  printf("--------------------------------------\n");

	    printf(" Entrez le code : ");

	    scanf("%s",&code);

	    while(testCode(code)==0){
        printf(" Entrez un code valide : ");
	    scanf("%s",&code);

	    }
	    for(int i=0;i<nbProduits();++i){

            fscanf(P, "%s  ",&p.codeP);
            fscanf(P, "%s  ",&p.refP);
            fscanf(P, "%s  ",&p.descriP);
            fscanf(P, "%f  ",&p.prixP);

            fscanf(P, "%d\n",&p.stockP);
	      if( strcmp(code,p.codeP)==0){
                printf(" Code Produit : %s, Reference : %s, Descrittion : %s, Prix : %f  \n",p.codeP,p.refP,p.descriP,p.prixP);}
           }
	     break ;
         case 2:
             printf("--------------------------------------\n");
  printf("      | Recherche par reference |\n");
  printf("--------------------------------------\n");
               printf(" Entrez la reference: ");
	    scanf("%s",&ref);
	    for(int j=0;i<nbProduits();j++){
            fscanf(P, "%s  ",&p.codeP);
            fscanf(P, "%s  ",&p.refP);
            fscanf(P, "%s  ",&p.descriP);
            fscanf(P, "%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);
	      if( strcmp(ref,p.refP)==0){
                printf(" Code Produit : %s, Reference : %s, Description : %s, Prix : %f  \n",p.codeP,p.refP,p.descriP,p.prixP);

         }}
        break;
         case 3:
            return 0 ;
         default:
            printf("choix incorrect !");
	    }
     }

 }}

 ///***
void SuppressionProduits(char code[20]){

    FILE *NV;
    FILE *P;
    Produit p;
    char ch;

    NV=fopen("fichiersAux//au.txt","w+");
    P=fopen("produits.txt","r");
     for(int i=0;i<nbProduits();i++){


            fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)!=0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }




    }
    fclose(P);
    fclose(NV);
    NV = fopen("fichiersAux//au.txt", "r");
    // ouvrir le fichier en écriture
    P = fopen("produits.txt", "w");

    while((ch = getc(NV)) != EOF)
        putc(ch, P);

    fclose(P);
    fclose(NV);
}



void SuppressionHis(char code[20]){

    FILE *f3;
    char ch;
    FILE *f2;
    FILE *NV;
    FILE *P;
    HistoriqueEntree hi;

    f2=fopen("fichiersAux//au1.txt","w");
    f3=fopen("hisEntree.txt","r");

     for(int i=0;i<nbHistoriques();i++){




           fscanf(f3,"%s  ",&hi.codePr);
            fscanf(f3, "%d-",&hi.dateEntree.jour);
            fscanf(f3, "%d-",&hi.dateEntree.mois);
            fscanf(f3, "%d  ",&hi.dateEntree.annee);
            fscanf(f3, "%d\n",&hi.quantiEntree);

             if(strcmp(code,hi.codePr)!=0){

                fputs(hi.codePr,f2);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.dateEntree.jour);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateEntree.mois);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateEntree.annee);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.quantiEntree);
                fputs("  ",f2);
                fputs("\n",f2);

             }




    }
    fclose(f2);
    fclose(f3);
    NV = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P = fopen("hisEntree.txt", "w");

    while((ch = getc(NV)) != EOF)
        putc(ch, P);

    fclose(P);
    fclose(NV);
}
///***

void SuppressionProduitFinal(char code[20]){


    FILE *f3;
    char ch;
    FILE *f2;
    FILE *NV;
    FILE *P;
    Produit p;

    NV=fopen("fichiersAux//au.txt","w");
    P=fopen("fichiersAux//produitsFinal.txt","r");

     for(int i=0;i<nbFinalProd();i++){




               fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)!=0){

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }




    }
    fclose(P);
    fclose(NV);
    NV = fopen("fichiersAux//au.txt", "r");
    // ouvrir le fichier en écriture
    P = fopen("fichiersAux//produitsFinal.txt", "w");

    while((ch = getc(NV)) != EOF)
        putc(ch, P);

    fclose(P);
    fclose(NV);

}



///**
void SuppressionNV(char code[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
   // FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;;

    NV=fopen("fichiersAux//au.txt","w");
    P=fopen("fichiersAux//nv.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)!=0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//nv.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}

///***

void SuppressionProduitFINAL(char code[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
   // FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au.txt","w");
    P=fopen("produitFINAL.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)!=0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("produitFINAL.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}

/// ****



///***


void SuppressionHisS(char code[20]){


FILE *f3;
    char ch;
    FILE *f2;
    FILE *NV;
    FILE *P;
    HistoriqueSortie hi;

    f2=fopen("fichiersAux//au.txt","w");
    f3=fopen("hisSortie.txt","r");

     for(int i=0;i<nbHistoriquesSortie();i++){




            fscanf(f3,"%s  ",&hi.codeProd);
            fscanf(f3, "%d-",&hi.dateAchat.jour);
            fscanf(f3, "%d-",&hi.dateAchat.mois);
            fscanf(f3, "%d  ",&hi.dateAchat.annee);
            fscanf(f3, "%d  ",&hi.quantiAchat);
            fscanf(f3, "%s  ",&hi.client.codeCarte);
            fscanf(f3, "%f\n",&hi.montantTot);

             if(strcmp(code,hi.codeProd)!=0){

                fputs(hi.codeProd,f2);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.dateAchat.jour);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateAchat.mois);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateAchat.annee);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.quantiAchat);
                fputs("  ",f2);
                fprintf(f2,"%s",hi.client.codeCarte);
                fputs("  ",f2);
                fprintf(f2,"%f",hi.montantTot);
                fputs("  ",f2);
                fputs("\n",f2);

             }




    }
    fclose(f2);
    fclose(f3);
    NV = fopen("fichiersAux//au.txt", "r");
    // ouvrir le fichier en écriture
    P = fopen("hisSortie.txt", "w");

    while((ch = getc(NV)) != EOF)
        putc(ch, P);

    fclose(P);
    fclose(NV);

}

///***

  void Suppression(){

    char code[20];
    char ch;
    int nb;
    nb=nbFinalProd();

  printf("--------------------------------\n");
  printf("  | Suppression d'un produit |\n");
  printf("--------------------------------\n");

    printf(" Entrer le code: ");
    scanf("%s",&code);
    while(testCode(code)==0){
        printf(" Entrer un code valide: ");
        scanf("%s",&code);

    }
    if (nb>0){
    SuppressionHis(code);
    SuppressionHisS(code);
    SuppressionNV(code);
    SuppressionProduitFinal(code);
    SuppressionProduitFINAL(code);}
    SuppressionProduits(code);
   // FinalP();





  }


  void Modification(){

    FILE *P;
    P=fopen("produitFINAL.txt","r");
    char code[20];
    char ref[20];
    char des[20];
    float newPr;
    char nvCode[20];
    int i,choix;
    Produit p;
    int nb=nbFinalProd();


        if(nbProduits()==0)
	  printf("Pas de produits");



     else{


             while(choix != 6)
{
/********** Affichage du menu **********/
do
{
 //system("cls");
  printf("-------------------------------------\n");
  printf("       | Modifer un produit |\n");
  printf("-------------------------------------\n");
   printf("   1. Modifier le code\n   2. Modifer la reference\n   3. Modifer la description\n   4. Modifer le prix\n");
  printf("   5. Annuler \n Faites votre choix :");
  scanf("%d",&choix);
 } while( (choix<1)||(choix>5) );
    switch(choix){
      case 1:
        system("cls");
         printf("-------------------------------------\n");
  printf("       | Modifer le code |\n");
  printf("-------------------------------------\n");
	    printf(" Entrez le code : ");
	    scanf("%s",&code);

	    while(testCode(code)==0){
        printf(" Entrez un code valide : ");
	    scanf("%s",&code);

	    }
        do{
        printf(" Entrer le nouveau code : ");
        scanf("%s",&nvCode);
        }while(testCode(nvCode)==1);
        if(nb>0){
        ModificationHis(code,nvCode);
        ModificationHisS(code,nvCode);
        ModificationNV(code,nvCode);
        ModificationNew(code,nvCode);
        ModificationProduitFinal(code,nvCode);
        ModificationFinalCLient(code,nvCode);
        ModificationFINALCLient(code,nvCode);
        ModificationProduitFINAL(code,nvCode);}
        ModificationProduits(code,nvCode);

	     break ;
         case 2:
        system("cls");
         printf("-------------------------------------\n");
  printf("      | Modifer la reference |\n");
  printf("-------------------------------------\n");
          printf(" Entrez le code : ");
	    scanf("%s",&code);

	    while(testCode(code)==0){
        printf(" Entrez un code valide : ");
	    scanf("%s",&code);

	    }
        printf(" Entrez la nouvelle reference: ");
	    scanf("%s",&ref);
        if(nb>0){
	    ModificationNV2(code,ref);
	    ModificationNew2(code,ref);
	    ModificationProduitFinal2(code,ref);
	    ModificationFinalCLient2(code,ref);
	    ModificationFINALCLient2(code,ref);
	    ModificationProduitFINAL2(code,ref);}
	    ModificationProduits2(code,ref);



        break;

         case 3:
        system("cls");
         printf("-------------------------------------\n");
  printf("      | Modifer la description |\n");
  printf("-------------------------------------\n");
        printf(" Entrez le code : ");
	    scanf("%s",&code);

	    while(testCode(code)==0){
        printf(" Entrez un code valide : ");
	    scanf("%s",&code);

	    }
        printf(" Entrez la nouvelle description: ");
	    scanf("%s",&des);
	    if(nb>0){
        ModificationNV3(code,des);
	    ModificationNew3(code,des);
	    ModificationProduitFinal3(code,des);
	    ModificationFinalCLient3(code,des);
	    ModificationFINALCLient3(code,des);
	    ModificationProduitFINAL3(code,des);}
	    ModificationProduits3(code,des);


            break;

         case 4:
        system("cls");
        printf("-------------------------------------\n");
  printf("       | Modifer le prix |\n");
  printf("-------------------------------------\n");
        printf(" Entrez le code : ");
	    scanf("%s",&code);

	    while(testCode(code)==0){
        printf(" Entrer un code valide : ");
	    scanf("%s",&code);

	    }
        printf(" Entrer le nouveau prix : ");
	    scanf("%f",&newPr);
	    float *price;
	    price=&newPr;


       ModificationProduits4(code,price);


        if(nb>0){
        ModificationNV4(code,price);
	    ModificationNew4(code,price);
	    ModificationProduitFinal4(code,price);
	    ModificationFinalCLient4(code,price);
	    ModificationFINALCLient4(code,price);}
	    ModificationProduitFINAL4(code,price);



            break;

         case 5:
             system("cls");
            return 0 ;
         default:
            printf("choix incorrect !");
	    }
     }

 }}


 ///***

 void ModificationHis(char code[20],char nvCode[20]){

    FILE *f3;
    char ch;
    FILE *f2;
    FILE *NV;
    FILE *P;
    HistoriqueEntree hi;

    f2=fopen("fichiersAux//au1.txt","w");
    f3=fopen("hisEntree.txt","r");
        if (P == NULL)
{


}
else{
     for(int i=0;i<nbHistoriques();i++){




           fscanf(f3,"%s  ",&hi.codePr);
            fscanf(f3, "%d-",&hi.dateEntree.jour);
            fscanf(f3, "%d-",&hi.dateEntree.mois);
            fscanf(f3, "%d  ",&hi.dateEntree.annee);
            fscanf(f3, "%d\n",&hi.quantiEntree);

             if(strcmp(code,hi.codePr)==0){

                fputs(nvCode,f2);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.dateEntree.jour);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateEntree.mois);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateEntree.annee);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.quantiEntree);
                fputs("  ",f2);
                fputs("\n",f2);

             }
             else{

                fputs(hi.codePr,f2);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.dateEntree.jour);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateEntree.mois);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateEntree.annee);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.quantiEntree);
                fputs("  ",f2);
                fputs("\n",f2);


             }




    }
    fclose(f2);
    fclose(f3);
    NV = fopen("fichiersAux//au1.txt", "r");
    P = fopen("hisEntree.txt", "w");

    while((ch = getc(NV)) != EOF)
        putc(ch, P);

    fclose(P);
    fclose(NV);
}}



///***

void ModificationHisS(char code[20],char nvCode[20]){

    FILE *f3;
    char ch;
    FILE *f2;
    FILE *NV;
    FILE *P;
    HistoriqueSortie hi;

    f2=fopen("fichiersAux//au1.txt","w");
    f3=fopen("hisSortie.txt","r");
        if (P == NULL)
{
}
else{
     for(int i=0;i<nbHistoriquesSortie();i++){




            fscanf(f3,"%s  ",&hi.codeProd);
            fscanf(f3, "%d-",&hi.dateAchat.jour);
            fscanf(f3, "%d-",&hi.dateAchat.mois);
            fscanf(f3, "%d  ",&hi.dateAchat.annee);
            fscanf(f3, "%d  ",&hi.quantiAchat);
            fscanf(f3, "%s  ",&hi.client.codeCarte);
            fscanf(f3, "%f\n",&hi.montantTot);


             if(strcmp(code,hi.codeProd)==0){

                fputs(nvCode,f2);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.dateAchat.jour);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateAchat.mois);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateAchat.annee);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.quantiAchat);
                fputs("  ",f2);
                fprintf(f2,"%s",hi.client.codeCarte);
                fputs("  ",f2);
                fprintf(f2,"%f",hi.montantTot);
                fputs("  ",f2);
                fputs("\n",f2);


             }
             else{

                fputs(hi.codeProd,f2);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.dateAchat.jour);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateAchat.mois);
                fputs("-",f2);
                fprintf(f2,"%d",hi.dateAchat.annee);
                fputs("  ",f2);
                fprintf(f2,"%d",hi.quantiAchat);
                fputs("  ",f2);
                fprintf(f2,"%s",hi.client.codeCarte);
                fputs("  ",f2);
                fprintf(f2,"%f",hi.montantTot);
                fputs("  ",f2);
                fputs("\n",f2);


             }




    }
    fclose(f2);
    fclose(f3);
    NV = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P = fopen("hisSortie.txt", "w");

    while((ch = getc(NV)) != EOF)
        putc(ch, P);

    fclose(P);
    fclose(NV);
}
}

///***
void ModificationNV(char code[20],char nvCode[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//nv.txt","r");
        if (P == NULL)
{
    /* Le fichier n'existe pas */
}
else{
     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",nvCode);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//nv.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}}


///**


void ModificationProduitFinal(char code[20],char nvCode[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitsFinal.txt","r");
        if (P == NULL)
{
    /* Le fichier n'existe pas */
}
else{
     for(int i=0;i<nbFinalProd();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",nvCode);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitsFinal.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}}



///****



void ModificationProduitFINAL(char code[20],char nvCode[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("produitFINAL.txt","r");
        if (P == NULL)
{
    /* Le fichier n'existe pas */
}
else{
     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",nvCode);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("produitFINAL.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);

}
}
///***


void ModificationNew(char code[20],char nvCode[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//new.txt","r");
    if (P == NULL)
{
    /* Le fichier n'existe pas */
}
else{
     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",nvCode);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//new.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}}

///***





///***


void ModificationProduits(char code[20],char nvCode[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("produits.txt","r");
    if (P == NULL)
{
    printf("Le fichier n'existe pas ");
}
else{
     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",nvCode);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("produits.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}}


  ///****


void ModificationFinalCLient(char code[20],char nvCode[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitsFinalClient.txt","r");
        if (P == NULL)
{
    /* Le fichier n'existe pas */
}
else{

     for(int i=0;i<nbFinalProd();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",nvCode);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitsFinalClient.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}}
 ///***


 void ModificationFINALCLient(char code[20],char nvCode[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitFINALClient.txt","r");
    if (P == NULL)
{
    /* Le fichier n'existe pas */
}
else{

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",nvCode);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitFINALClient.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}}
///**** Modification de reference
///****






void ModificationNV2(char code[20],char ref[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//nv.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",ref);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//nv.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}


///**


void ModificationProduitFinal2(char code[20],char ref[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitsFinal.txt","r");

     for(int i=0;i<nbFinalProd();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",ref);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitsFinal.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}



///****



void ModificationProduitFINAL2(char code[20],char ref[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("produitFINAL.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",ref);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("produitFINAL.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}
///***


void ModificationNew2(char code[20],char ref[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//new.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",ref);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//new.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}

///***





///***


void ModificationProduits2(char code[20],char ref[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("produits.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",ref);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("produits.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}


  ///****


void ModificationFinalCLient2(char code[20],char ref[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitsFinalClient.txt","r");

     for(int i=0;i<nbFinalProd();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",ref);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitsFinalClient.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}
 ///***


 void ModificationFINALCLient2(char code[20],char ref[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitFINALClient.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",ref);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitFINALClient.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}



///***
///**** Modification de description

void ModificationNV3(char code[20],char des[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//nv.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",des);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//nv.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}


///**


void ModificationProduitFinal3(char code[20],char des[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitsFinal.txt","r");

     for(int i=0;i<nbFinalProd();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",des);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitsFinal.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}



///****



void ModificationProduitFINAL3(char code[20],char des[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("produitFINAL.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",des);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("produitFINAL.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}
///***


void ModificationNew3(char code[20],char des[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//new.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",des);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//new.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}

///***





///***


void ModificationProduits3(char code[20],char des[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("produits.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",des);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("produits.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}


  ///****


void ModificationFinalCLient3(char code[20],char des[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitsFinalClient.txt","r");

     for(int i=0;i<nbFinalProd();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",des);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitsFinalClient.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}
 ///***


 void ModificationFINALCLient3(char code[20],char des[20]){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitFINALClient.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",des);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitFINALClient.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}
///*** Modification de prix

///***




void ModificationNV4(char code[20],float *pr){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//nv.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",*pr);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//nv.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}


///**


void ModificationProduitFinal4(char code[20],float *pr){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitsFinal.txt","r");

     for(int i=0;i<nbFinalProd();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",*pr);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitsFinal.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}



///****



void ModificationProduitFINAL4(char code[20],float *pr){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("produitFINAL.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",*pr);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("produitFINAL.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}
///***


void ModificationNew4(char code[20],float *pr){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//new.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",*pr);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//new.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}

///***





///***


void ModificationProduits4(char code[20],float *pr){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("produits.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",*pr);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("produits.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}


  ///****


void ModificationFinalCLient4(char code[20],float *pr){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitsFinalClient.txt","r");

     for(int i=0;i<nbFinalProd();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",*pr);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitsFinalClient.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}
 ///***

void ModificationFINALCLient4(char code[20],float *pr){

    FILE *f3;
    char ch;
    FILE *NV1;
    FILE *NV;
    FILE *P;
    FILE *P1;

    Produit p;

    NV=fopen("fichiersAux//au1.txt","w");
    P=fopen("fichiersAux//produitFINALClient.txt","r");

     for(int i=0;i<nbProduits();i++){




           fscanf(P,"%s  ",&p.codeP);
            fscanf(P,"%s  ",&p.refP);
            fscanf(P,"%s  ",&p.descriP);
            fscanf(P,"%f  ",&p.prixP);
            fscanf(P, "%d\n",&p.stockP);

             if(strcmp(code,p.codeP)==0){

                fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",*pr);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);

             }

             else{

                 fprintf(NV,"%s",p.codeP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.refP);
                fputs("  ",NV);
                fprintf(NV,"%s",p.descriP);
                fputs("  ",NV);
                fprintf(NV,"%f",p.prixP);
                fputs("  ",NV);
                fprintf(NV,"%d",p.stockP);
                fputs("  ",NV);
                fputs("\n",NV);
             }




    }
    fclose(P);
    fclose(NV);
    NV1 = fopen("fichiersAux//au1.txt", "r");
    // ouvrir le fichier en écriture
    P1 = fopen("fichiersAux//produitFINALClient.txt", "w");

    while((ch = getc(NV1)) != EOF)
        putc(ch, P1);

    fclose(P1);
    fclose(NV1);


}



///*** Affichage de l'historique entree


 //  mois //
  void mois ()
  {



  FILE *His;
  HistoriqueEntree HE;
  int mois=0;
  His=fopen("hisEntree.txt","r");
  printf("---------------------------------------------\n");
  printf("  | Afficher l'historique Entree par mois |\n");
  printf("---------------------------------------------\n");
  printf (" Entrer le numero du mois de 1 a 12: ");
  scanf("%d",&mois);
  while(mois>12 || mois<1){
  printf (" Entrer le numero du mois de 1 a 12: ");
  scanf("%d",&mois);}
  for (int i =0; i<nbHistoriques();i++)
     {
   fscanf(His,"%s  ",&HE.codePr);
   fscanf(His,"%d-",&HE.dateEntree.jour);
   fscanf(His,"%d-",&HE.dateEntree.mois);
   fscanf(His,"%d  ",&HE.dateEntree.annee);
   fscanf(His,"%d\n",&HE.quantiEntree);
         if (HE.dateEntree.mois==mois)
              { printf(" %s  ",HE.codePr);

                printf("%d-",HE.dateEntree.jour);

                printf("%d-",HE.dateEntree.mois);

                printf("%d  ",HE.dateEntree.annee);

                printf("%d  ",HE.quantiEntree);
                printf("\n");

                     }
     }

         fclose(His);

  }



    //  année //
    void annee ()
  {



  FILE *His;
  HistoriqueEntree HE;
  int annee=0;
  His=fopen("hisEntree.txt","r");
  printf("---------------------------------------------\n");
  printf("  | Afficher l'historique Entree par annee |\n");
  printf("---------------------------------------------\n");
  printf (" Entrer l'annee: ");
  scanf("%d",&annee);
  for (int i =0; i<nbHistoriques();i++)
     {
   fscanf(His,"%s  ",&HE.codePr);
   fscanf(His,"%d-",&HE.dateEntree.jour);
   fscanf(His,"%d-",&HE.dateEntree.mois);
   fscanf(His,"%d  ",&HE.dateEntree.annee);
   fscanf(His,"%d\n",&HE.quantiEntree);
         if (HE.dateEntree.annee==annee)
              { printf(" %s  ",HE.codePr);

                printf("%d-",HE.dateEntree.jour);

                printf("%d-",HE.dateEntree.mois);

                printf("%d ",HE.dateEntree.annee);

                printf("%d\n",HE.quantiEntree);

                     }

         }
         fclose(His);
  }








  // tout//
  void tout()
  {



  FILE *His;
  HistoriqueEntree HE;
    His=fopen("hisEntree.txt","r");

  printf("---------------------------------------------\n");
  printf("  | Afficher l'historique Entree |\n");
  printf("---------------------------------------------\n");
  for ( int i=0 ; i<nbHistoriques() ;i++){
          fscanf(His,"%s  ",&HE.codePr);
          fscanf(His,"%d-",&HE.dateEntree.jour);
          fscanf(His,"%d-",&HE.dateEntree.mois);
          fscanf(His,"%d  ",&HE.dateEntree.annee);
          fscanf(His,"%d\n",&HE.quantiEntree);


                printf(" %s  ",HE.codePr);

                printf("%d-",HE.dateEntree.jour);

                printf("%d-",HE.dateEntree.mois);

                printf("%d  ",HE.dateEntree.annee);

                printf("%d\n",HE.quantiEntree);


     }

         fclose(His); }
     // jour //

     void jour ()
  {


  FILE *His;
  HistoriqueEntree HE;
  int jour=0;
  His=fopen("hisEntree.txt","r");
  printf("---------------------------------------------\n");
  printf("  | Afficher l'historique Entree par jour |\n");
  printf("---------------------------------------------\n");
  printf (" Entrer le jour: ");
  scanf("%d",&jour);
  while(jour>31 || jour<1){
  printf (" Entrer le jour: ");
  scanf("%d",&jour);}
  for (int i =0; i<nbHistoriques();i++)
     {
   fscanf(His,"%s  ",&HE.codePr);
   fscanf(His,"%d-",&HE.dateEntree.jour);
   fscanf(His,"%d-",&HE.dateEntree.mois);
   fscanf(His,"%d  ",&HE.dateEntree.annee);
   fscanf(His,"%d\n",&HE.quantiEntree);
         if (HE.dateEntree.jour==jour)
              { printf(" %s  ",HE.codePr);

                printf("%d-",HE.dateEntree.jour);

                printf("%d-",HE.dateEntree.mois);

                printf("%d  ",HE.dateEntree.annee);

                printf("%d\n",HE.quantiEntree);

                     }

         }
       fclose(His);
  }




  ///***

  void AffichageHis(){



  int nb;
  nb=nbFinalProd();
  int Hist=0;


  if(nb<0){
                printf("\n pas d'historique d'entree \n");
            }
            else{
                  while(Hist != 6){


                    do{



  printf("----------------------------------------\n");
  printf("    | Afficher l'historique Entree |\n");
  printf("----------------------------------------\n");
  printf("   1. par mois\n   2. par an\n   3. par jour\n   4. tout\n");
  printf("   5. Annuler \n Faites votre choix :");

               scanf("%d",&Hist);

                    } while( (Hist<1)||(Hist>6) );


              switch (Hist) {
                  case 1: mois() ;
                      break ;
                  case 2: annee() ;
                     break;
                  case 3: jour() ;
                      break;
                  case 4: tout();
                      break;
                  case 5:
                      return 0;



                  default:
	      printf("/!\\ Option inexistante /!\\\n");

              }
                  }}


  }



///***



void AffichageHisSortie (){




  int nbS;
  nbS=nbHistoriquesSortie;
  int Histsortie=0;


  if(nbS<0){
                printf("\n pas d'historique d'entree \n");
            }
            else{
                  while(Histsortie != 6){


                    do{



                        printf("------------------------------------------\n");
  printf("| Afficher l'historique Sortie |\n");
  printf("------------------------------------------\n");
  printf("   1. par mois\n   2. par an\n   3. par jour\n   4. tout\n");
  printf("   5. Annuler \n Faites votre choix :");

               scanf("%d",&Histsortie);

                    } while( (Histsortie<1)||(Histsortie>6) );


              switch (Histsortie) {
                  case 1: moissortie() ;
                      break ;
                  case 2: anneesortie() ;
                     break;
                  case 3: joursortie() ;
                      break;
                  case 4: toutsortie();
                      break;
                  case 5:
                      return 0;

                  default:
	      printf("/!\\ Option inexistante /!\\\n");

              }
                  }}


  }
















void joursortie()
{

  FILE *HisSortie;
  HistoriqueSortie HS;
  int joursortie=0;
  HisSortie=fopen("hisSortie.txt","r");
    printf("---------------------------------------------\n");
  printf("  | Afficher l'historique sortie par jour |\n");
  printf("---------------------------------------------\n");
  printf (" Entrer le jour: ");
  scanf("%d",&joursortie);
  while(joursortie>31 || joursortie<1){
  printf (" Entrer le jour: ");
  scanf("%d",&joursortie);}
  for (int i =0; i<nbHistoriquesSortie();i++){

            fscanf(HisSortie,"%s  ",&HS.codeProd);
            fscanf(HisSortie, "%d-",&HS.dateAchat.jour);
            fscanf(HisSortie, "%d-",&HS.dateAchat.mois);
            fscanf(HisSortie, "%d  ",&HS.dateAchat.annee);
            fscanf(HisSortie, "%d  ",&HS.quantiAchat);
            fscanf(HisSortie, "%s  ",&HS.client.codeCarte);
            fscanf(HisSortie, "%f\n",&HS.montantTot);
             if (HS.dateAchat.jour==joursortie)
              {
                printf("%s  ",HS.codeProd);
                printf("%d-",HS.dateAchat.jour);
                printf("%d-",HS.dateAchat.mois);
                printf("%d  ",HS.dateAchat.annee);
                printf("%d  ",HS.quantiAchat);
                printf("%s  ",HS.client.codeCarte);
                printf("%f\n",HS.montantTot);

                     }

         }
       fclose(HisSortie);
  }


void anneesortie()
{

  FILE *HisSortie;
  HistoriqueSortie HS;
  int anneesortie=0;
  HisSortie=fopen("hisSortie.txt","r");
    printf("---------------------------------------------\n");
  printf("  | Afficher l'historique sortie par annee |\n");
  printf("---------------------------------------------\n");
  printf (" Entrer l'annee: ");
  scanf("%d",&anneesortie);
  for (int i =0; i<nbHistoriquesSortie();i++){

            fscanf(HisSortie,"%s  ",&HS.codeProd);
            fscanf(HisSortie, "%d-",&HS.dateAchat.jour);
            fscanf(HisSortie, "%d-",&HS.dateAchat.mois);
            fscanf(HisSortie, "%d  ",&HS.dateAchat.annee);
            fscanf(HisSortie, "%d  ",&HS.quantiAchat);
            fscanf(HisSortie, "%s  ",&HS.client.codeCarte);
            fscanf(HisSortie, "%f\n",&HS.montantTot);
             if (HS.dateAchat.annee==anneesortie)
              {
                printf(" %s  ",HS.codeProd);
                printf("%d-",HS.dateAchat.jour);
                printf("%d-",HS.dateAchat.mois);
                printf("%d  ",HS.dateAchat.annee);
                printf("%d  ",HS.quantiAchat);
                printf("%s  ",HS.client.codeCarte);
                printf("%f\n",HS.montantTot);

                     }

         }
       fclose(HisSortie);
  }




  void moissortie()
{

  FILE *HisSortie;
  HistoriqueSortie HS;
  int moissortie=0;
  HisSortie=fopen("hisSortie.txt","r");
   printf("---------------------------------------------\n");
  printf("  | Afficher l'historique sortie par mois |\n");
  printf("---------------------------------------------\n");
  printf (" Entrer le mois: ");
  scanf("%d",&moissortie);
  while(moissortie>12 || moissortie<1){

    printf (" Entrer le mois: ");
  scanf("%d",&moissortie);
  }
  for (int i =0; i<nbHistoriquesSortie();i++){

            fscanf(HisSortie, "%s  ",&HS.codeProd);
            fscanf(HisSortie, "%d-",&HS.dateAchat.jour);
            fscanf(HisSortie, "%d-",&HS.dateAchat.mois);
            fscanf(HisSortie, "%d  ",&HS.dateAchat.annee);
            fscanf(HisSortie, "%d  ",&HS.quantiAchat);
            fscanf(HisSortie, "%s  ",&HS.client.codeCarte);
            fscanf(HisSortie, "%f\n",&HS.montantTot);
             if (HS.dateAchat.mois==moissortie)
              {
                printf(" %s  ",HS.codeProd);
                printf("%d-",HS.dateAchat.jour);
                printf("%d-",HS.dateAchat.mois);
                printf("%d  ",HS.dateAchat.annee);
                printf("%d  ",HS.quantiAchat);
                printf("%s  ",HS.client.codeCarte);
                printf("%f\n",HS.montantTot);

                     }

         }
       fclose(HisSortie);
  }
void toutsortie()
{

  FILE *HisSortie;
  HistoriqueSortie HS;
  HisSortie=fopen("hisSortie.txt","r");
  printf("---------------------------------------------\n");
  printf("  | Afficher l'historique sortie |\n");
  printf("---------------------------------------------\n");
  for (int i =0; i<nbHistoriquesSortie();i++){

            fscanf(HisSortie,"%s  ",&HS.codeProd);
            fscanf(HisSortie, "%d-",&HS.dateAchat.jour);
            fscanf(HisSortie, "%d-",&HS.dateAchat.mois);
            fscanf(HisSortie, "%d  ",&HS.dateAchat.annee);
            fscanf(HisSortie, "%d  ",&HS.quantiAchat);
            fscanf(HisSortie, "%s  ",&HS.client.codeCarte);
            fscanf(HisSortie, "%f\n",&HS.montantTot);

            printf(" %s  ",HS.codeProd);
            printf("%d-",HS.dateAchat.jour);
            printf("%d-",HS.dateAchat.mois);
            printf("%d  ",HS.dateAchat.annee);
            printf("%d  ",HS.quantiAchat);
            printf("%s  ",HS.client.codeCarte);
            printf("%f\n",HS.montantTot);

                     }


       fclose(HisSortie);
  }
///***



void AffichageClient()
{

  FILE *Cli;
  Client CL;
  Cli=fopen("clients.txt","r");

  printf("--------------------------------\n");
  printf("      | Liste de clients |\n");
  printf("--------------------------------\n");

  for (int i =0; i<nbClients();i++){

            fscanf(Cli, "%s  ",&CL.nom);
            fscanf(Cli, "%s  ",&CL.prenom);
            fscanf(Cli, "%s  ",&CL.codeCarte);
            fscanf(Cli, "%f\n",&CL.montant);



            printf("%s  ",CL.nom);
            printf("%s  ",CL.prenom);
            printf("%s  ",CL.codeCarte);
            printf("\n");

                     }


       fclose(Cli);
}




///***

void main(){


int choixOb=0;
int modeChoisi;
modeChoisi=mode();

Menu(modeChoisi);







}



