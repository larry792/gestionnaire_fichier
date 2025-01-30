#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ecrireFichier(char mon_fichier[20]){


FILE *fichier;
char i[7];
char a;
printf("voulez vous ajouter des informatios ou ecraser le fichier existant?\nPour ajouter taper A\nPour ecraser taper E\n");
a=fgets(i, sizeof(i), stdin);
i[strcspn(i, "\n")] = '\0';
if(a="A")
    fichier = fopen(mon_fichier,"a"); 
if(a='E')
    fichier = fopen(mon_fichier,"w"); 
if (fichier ==NULL)
{
    printf("Erreur de creation ou d'ouverture du fichier\n");
    return 1;
}
char texte[200];
printf("Entrez le texte a ecrire: \n");
fgets(texte, sizeof(texte), stdin);
texte[strcspn(texte, "\n")] = '\0';
fprintf(fichier,"%s",texte);
fclose(fichier);
printf("Donnees enregistrer dans le fichier avec succes\n ");
   
}

void lireFichier(char mon_fichier[20]){
    FILE *fichier=fopen(mon_fichier, "r");
    if(fichier == NULL){
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    char ligne[256];
    printf("Contenu du fichier:\n");
    while (fgets(ligne,sizeof(ligne),fichier) != NULL)
    {
        printf("%s\n",ligne);
    }
    fclose(fichier);
}


void supprimerFichier(char mon_fichier[20]){
    if(remove(mon_fichier) ==0)
    printf("fichier suprimer avec succes\n");
    else
    printf("IMPOSSIBLE!\n Erreure de supression du fichier\n");
    return 1;
}
int main(){
int choix;
char chaine[30];
printf("***GESTIONNAIRE DE FICHIER***\n");
printf("Veillez entrez le nom du fichier que vous voulier traiter\n");
fgets(chaine, sizeof(chaine), stdin);
chaine[strcspn(chaine, "\n")] = '\0';

printf("QUE VOULEZ VOUS FAIRE?\n Taper:\n 1(pour ecrire dans le fichier)\n2(pour lire le fichier)\n3(pour supprimer le fichier )\n");

switch (choix)
{
case 1:
    ecrireFichier(chaine);
    break;
case 2:
    lireFichier(chaine);
    break;
case 3:
    supprimerFichier(chaine);
    break;
default:
    printf("Option de tache invalide\n");
    break;
}   
    
return 0;
}