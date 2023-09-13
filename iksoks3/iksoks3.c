//Tomislav Krstic RT 12/17

																//IKS OKS IGRICA
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct igraci 
{
	char prvi[10],drugi[10];
} igraci;
	char polje[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
void uputstvo();
void datoteka(int i,int igrac);				// funkcija koja upisuje ko je pobednik u datoteku
int pobednik();			// ispituje kakav je ishod
void tabela();			// crta tabelu za igricu
igraci *pobeda;
int main()
{	
	int igrac = 1, i,j, izbor;
    char znak,novaigra[3],pom[10]= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	uputstvo();
	Pocetak:
		igrac=1;// uvek prvi igrac ima prvi potez

		pobeda=(igraci*)malloc(sizeof(igraci));			//dinamicka dodela memorije za strukturu
			if(pobeda==NULL){fprintf(stderr, "Greska!"); exit(1);}
	do{
		system("cls");
		if(strcmp(pobeda->prvi,pobeda->drugi)==0)
			puts("\n\n\t\t\t\t   Imena moraju biti razlicita\n");

		printf("\n\n\n\t\t\t\t   Unesite ime prvog igraca: ");
			scanf("%s", pobeda->prvi);
					fflush(stdin);
		printf("\n\n\n\n\t\t\t\t   Unesite ime drugog igraca: ");
			scanf("%s", pobeda->drugi);
	}while(strcmp(pobeda->prvi,pobeda->drugi)==0);				//proverava da li su imena oba igraca ista


    do
    {
        tabela();
        igrac = (igrac % 2) ? 1 : 2;					 //ispituje koji je igrac na potezu
		do{   
        printf("Igrac %d, unesi broj:  ", igrac);
		fflush(stdin);
        scanf("%d", &izbor);										//unosi broj polja gde se ispisuje X ili O 
		if(izbor<1||izbor>9 )						//proverava da li je polje popunjeno
			{
				puts("Morate uneti jedan od ponudjenih brojeva u tabeli (1-9)");
			}
				else if(polje[izbor]=='X' || polje[izbor]=='O')			//proverava da li je polje u opsegu od 1 do 9
					puts("Morate izabrati polje koje nije popunjeno");

		}while(izbor<1||izbor>9 || polje[izbor]=='X' || polje[izbor]=='O');						//ponavlja sve dok se ne odigra dozvoljen potez
		
		znak = (igrac == 1) ? 'X' : 'O';				// ispituje koji je igrac na potezu , i odredjuje koji znak se upisuje

       for(i=1;i<10;i++)		//prolazi kroz sva polja 
			if (izbor == i)			//proverava da li je to  polje koje je uneo igrac,ako jeste na to polje unosi znak X ili O
			  polje[i] = znak;		
		
       i = pobednik();				//proverava da li imamo pobednika ili je nereseno
       igrac++;
    }while (i==-1);		//sledeci igrac je na potezu, vraca se na pocetak


	datoteka(i,--igrac);

    tabela();
    
    if (i == 1)
        printf("==>\t\a%d. igrac  je pobedio! \n", igrac);
    else
	printf("==>\t\aNereseno!\n");

	do{																		//Izvrsava se sve dok se ne unese Da(da) ili Ne(ne)
		printf("\n\n\t\tZelite da igrate opet ?\t Da/Ne\n");
		printf("\t\t\t\t");
		scanf("%s",novaigra);
	}while(strcmp(novaigra,"Da")!=0 && strcmp(novaigra,"Ne")!=0 && strcmp(novaigra,"da")!=0 && strcmp(novaigra,"ne")!=0); 
	
	if(!strcmp(novaigra,"Da")||!strcmp(novaigra,"da")) //Ako je uneto "Da" niz polje se obnavlja i vraca se na pocetak igre
	{
		for(j=1;j<10;j++)
		polje[j]=pom[j]; //Osvezavaju se polja u tabeli
		goto Pocetak;
	}
	 else
		printf("\n\t\t\t\tPOZDRAV!!\n\n");
		exit(1);

free(pobeda);
}



int pobednik()				// vraca 1 ako imamo pobednika,0 ako je nereseno, -1 ako igra nije zavrsena
{	
    if (polje[1] == polje[2] && polje[2] == polje[3])
        return 1;
        
    else if (polje[4] == polje[5] && polje[5] == polje[6])
        return 1;
        
    else if (polje[7] == polje[8] && polje[8] == polje[9])
        return 1;
        
    else if (polje[1] == polje[4] && polje[4] == polje[7])
        return 1;
        
    else if (polje[2] == polje[5] && polje[5] == polje[8])
        return 1;
        
    else if (polje[3] == polje[6] && polje[6] == polje[9])
        return 1;
        
    else if (polje[1] == polje[5] && polje[5] == polje[9])
        return 1;
        
    else if (polje[3] == polje[5] && polje[5] == polje[7])
        return 1;
        
    else if (polje[1] != '1' && polje[2] != '2' && polje[3] != '3' &&
        polje[4] != '4' && polje[5] != '5' && polje[6] != '6' && polje[7] 
        != '7' && polje[8] != '8' && polje[9] != '9')

        return 0;
    else
        return  - 1;
}

void tabela()						//crta tabelu za igru
{
    system("cls");
    printf("\n\n\t\t\t\t     Iks Oks\n\n");


    printf("Igrac 1 (X):%s \n\n\t      vs \n\nIgrac 2 (O):%s\n\n",pobeda->prvi,pobeda->drugi);


    printf("\t\t\t\t       |     |     \n");
    printf("\t\t\t\t    %c  |  %c  |  %c \n", polje[1], polje[2], polje[3]);

    printf("\t\t\t\t  _____|_____|_____\n");
    printf("\t\t\t\t       |     |     \n");

    printf("\t\t\t\t    %c  |  %c  |  %c \n", polje[4], polje[5], polje[6]);

    printf("\t\t\t\t  _____|_____|_____\n");
    printf("\t\t\t\t       |     |     \n");

    printf("\t\t\t\t    %c  |  %c  |  %c \n", polje[7], polje[8], polje[9]);

    printf("\t\t\t\t       |     |     \n\n");
}

void datoteka(int i,int igrac)		//otvara datoteku u koju se upisuje pobednik posle svake svake partije
{

FILE *f = fopen("rezultati.txt", "a");		//otvara datoteku rezultati
if (f == NULL)						//proverava da li je doslo do greske
{
    printf("Greska!\n");
    exit(1);
}
if (i == 1)			//proverava da li imamo pobednika
{	
		if(igrac%2)				
			fprintf(f,"==>\t%s je pobedio! \n",pobeda->prvi);	//u slucaju da je prvi igrac pobedio	

		else
			fprintf(f,"==>\t%s je pobedio! \n",pobeda->drugi);	//u slucaju da je drugi igrac pobedio
}else
	fprintf(f,"==>\tNereseno!\n");								//u slucaju da je nereseno

fclose(f);												//zatvara datoteku
}

void uputstvo()
{	
	printf("\n\n\n\n\t\t\t\t#   #   #   ####      #####     #   #   ####\n");
	printf("\t\t\t\t#   #  #    #         #   #	#  #    #    \n");
	printf("\t\t\t\t#   # #     ####  === #   #	# #     ####\n");
	printf("\t\t\t\t#   #  #       #      #   #	#  #       #\n");
	printf("\t\t\t\t#   #   #   ####      #####	#   #   ####\n");
	printf("\n\n       +--------------------------------------------------------------------------------------------------------+");
	printf("\t       |\t\tIks-oks je igra za dva igraca koja se igra na polju 3x3 kvadrata.\t\t\t\t|\n");
	printf("       |Igraci naizmenicno postavljaju svoje znakove (jedan koristi ikseve, drugi kruzice) u slobodna polja.\t|\n");
	printf("       |\t\tCilj igre je spojiti tri znaka vodoravno, uspravno ili dijagonalno.\t\t\t\t|\n");
	printf("       +--------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t Ako ste spremni pritisinite \"Enter\" ");

	getchar(); 
	fflush(stdin);
}
