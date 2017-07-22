#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
char jugador[12][12],pc[12][12], dispj[12][12],disppc[12][12],opc[100];
int x,y,pcx,pcy, barcos[5][9],contador=9, bandera=1;


void aleatorio(int &x,int &y , int &pcx,int &pcy,int ancho){
	int num=rand()%2;
	if(num==0){
		x=1+rand()%(10);
		pcx=x;
		y=(1+ancho+rand()%(9-ancho))-ancho;
		pcy=y+ancho;			
	}else{
		y=1+rand()%(10);
		pcy=y;
		x=(1+ancho+rand()%(9-ancho))-ancho;
		pcx=x+ancho;		
	}	
}
void pausarBorrar(){
	system("pause");
	system("cls");
}

void imprimirMatriz(char matriz[12][12]){
	for(int c=0;c<12;c++){
		for(int b=0;b<12;b++){
		printf("%c",matriz[b][c]);	
		}
		printf("\n");
		
	}
}
void pedirDatos(int &c,int &d, int &e, int &f){
    	do{
		    printf("Ingrese la coordenada X donde comienza el barco");
			scanf("%d",&c);
			if(c<1||c>10){
				system("cls");
				printf("Coordenada supera el ancho de la matriz.\nPor favor ingrese coordenada de 1 a 10.\n");
				pausarBorrar();
			}
	    }while(c<1||c>10);
	    do{
			printf("Ingrese la coordenada Y donde comienza el barco");
			scanf("%d",&d);
			if(d<1||d>10){
				system("cls");
				printf("Coordenada supera el ancho de la matriz.\nPor favor ingrese coordenada de 1 a 10.\n");
				pausarBorrar();
			}
	    }while(d<1||d>10);
	    do{
			printf("Ingrese la coordenada X donde termina el barco");
			scanf("%d",&e);
			if(e<1||e>10){
				system("cls");
				printf("Coordenada supera el ancho de la matriz.\nPor favor ingrese coordenada de 1 a 10.\n");
				pausarBorrar();
			}
	    }while(e<1||e>10);
		do{
		printf("Ingrese la coordenada Y donde comienza el barco");
		scanf("%d",&f);
			if(f<1||f>10){
				system("cls");
				printf("Coordenada supera el ancho de la matriz.\nPor favor ingrese coordenada de 1 a 10.\n");
				pausarBorrar();
			}
	    }while(f<1||f>10);		
}
void bordeCampo(char matriz[12][12]){
	for(int c=0;c<12;c++){
		matriz[c][0]=196;
		matriz[c][11]=196;
	    matriz[0][c]=179;
		matriz[11][c]=179;                  
	}
	matriz[0][0]=218;
	matriz[0][11]=192;
	matriz[11][0]=191;
	matriz[11][11]=217;	
}

bool validaBarcos(char jugador[][12],int tam,int x,int y,int pcx,int pcy){
	bool comprueba=true;
	if(x==pcx){
		for(int a=y;a<pcy;a++){
			if((jugador[x][a]!=NULL)){
				return comprueba==false;
				
			}
		}		
	}else if(y==pcy){
		for(int a=x;a<pcx;a++){
			if(jugador[a][y]!=NULL){
				return comprueba==false;
				
			}
		}	
	}else{
		return comprueba=true;
	}	
	
}
void colocarBarcos(int ancho,int &barco,char jugador[][12],int tam){
	system("cls");
	if(validaBarcos(jugador,12,x,y,pcx,pcy)==true){
		if((((pcy-y)==ancho)||((pcx-x)==ancho))&&((x<12)&&(y<12)&&(pcx<12)&&(pcy<12))){	
			barco--;
			if(x==pcx){
				for(int a=y;a<pcy;a++){
					jugador[x][a]='o';
				}
			}else if(y==pcy){
				for(int a=x;a<pcx;a++){
	    			jugador[a][y]='o';
				}		
		    }
		}else{
			printf("Coordenadas erroneas. Por favor seleccione coordenadas que no\nsuperen ni sean menores al ancho del barco elegido.\n");
			pausarBorrar();
		}
	}else{
		printf("No puedes encimar barcos\n");
		pausarBorrar();
	}
}
bool colocarBarcosPc(int ancho,int &barco,char jugador[][12],int tam,char simbolo){
	bool n=true;
	if(validaBarcos(jugador,12,x,y,pcx,pcy)==true){
		if(x==pcx){
			for(int a=y;a<pcy;a++){
				jugador[x][a]=simbolo;
			}
		}else if(y==pcy){
			for(int a=x;a<pcx;a++){
    			jugador[a][y]=simbolo;
			}		
	    }
	}else{
	    n= false;
	}

	return n;
	
}
int main(int argc, char** argv) {

	printf("Bienvenido al juego de batalla naval.\n");
	printf("Procedera a elegir la posicion de sus barcos\n");
	pausarBorrar();
	int portaaviones, submarinos, destructores, fragatas, total;
	portaaviones=1;
	submarinos=3;
	destructores=3;
	fragatas=2;
	total=portaaviones+submarinos+destructores+fragatas;
	bordeCampo(jugador);
	bordeCampo(pc);
	//bordeCampo(dispj);
	
    //bordeCampo(disppc);	
    while(total>0){
		imprimirMatriz(jugador);
		fflush(stdin);
		total=portaaviones+submarinos+destructores+fragatas;
		printf("Usted tiene:\n1)%d Portaaviones(Ocupa 4 casillas).\n2)%d Submarinos(Ocupa 3 casillas).\n3)%d Destructores(Ocupa 2 casillas).\n4)%d fragatas(Ocupa una casilla).\n",portaaviones,submarinos, destructores,fragatas);
		printf("Ingrese el numero que corresponde al elemento que desea colocar en el tablero:");
		scanf("%s",&opc);
		system("cls");
		
		if(opc[1]!='\0')opc[0]='a';
		fflush(stdin);
		if(opc[0]=='1'){
			if(portaaviones>0){
				pedirDatos(x,y,pcx,pcy);
				colocarBarcos(4,portaaviones,jugador,12);

	 		}else{
	 			system("cls");
	 			printf("No posee mas portaaviones");
	 			pausarBorrar();
			}
		}else if(opc[0]=='2'){
			if(submarinos>0){
				pedirDatos(x,y,pcx,pcy);
				colocarBarcos(3,submarinos,jugador,12);

	 		}else{
	 			system("cls");
	 			printf("No posee mas submarinos");
	 			pausarBorrar();
			}
		}else if(opc[0]=='3'){
			if(destructores>0){
				pedirDatos(x,y,pcx,pcy);
				colocarBarcos(2,destructores,jugador,12);

	 		}else{
	 			system("cls");
	 			printf("No posee mas destructores");
	 			pausarBorrar();
			}
		
		}else if(opc[0]=='4'){
			if(fragatas>0){
				pedirDatos(x,y,pcx,pcy);
				colocarBarcos(1,fragatas,jugador,12);

	 		}else{
	 			system("cls");
	 			printf("No posee mas fragatas");
	 			pausarBorrar();
			}
		}else{
			system("cls");
			printf("Opcion no valida.\n");
			pausarBorrar();
		}
		
    };
    system("cls");
    printf("Ha colocado todos los barcos");
    pausarBorrar();
    srand (time(NULL));
    aleatorio(x,y,pcx,pcy,4);
    colocarBarcosPc(4,destructores,pc,12,'V');
    barcos[0][0]=x;
    barcos[1][0]=y;
    barcos[2][0]=pcx;
    barcos[3][0]=pcy;
    barcos[4][0]=4;
    bool n;
	do{
	 	aleatorio(x,y,pcx,pcy,3);
	 	n=colocarBarcosPc(3,submarinos,pc,12,'U');
	 	barcos[0][1]=x;
        barcos[1][1]=y;
	    barcos[2][1]=pcx;
	    barcos[3][1]=pcy;
	    barcos[4][1]=3;
		colocarBarcosPc(3,submarinos,pc,12,'U');
	}while(n==false);
	do{
	 	aleatorio(x,y,pcx,pcy,3);
	 	n=colocarBarcosPc(3,submarinos,pc,12,'U');
	 	barcos[0][2]=x;
		barcos[1][2]=y;
		barcos[2][2]=pcx;
		barcos[3][2]=pcy;
		barcos[4][2]=3;
		colocarBarcosPc(3,submarinos,pc,12,'U');
	}while(n==false);	
    do{

	 	aleatorio(x,y,pcx,pcy,3);
	 	n=colocarBarcosPc(3,submarinos,pc,12,'U');
	 	barcos[0][3]=x;
		barcos[1][3]=y;
		barcos[2][3]=pcx;
		barcos[3][3]=pcy;
		barcos[4][3]=3;
		colocarBarcosPc(3,submarinos,pc,12,'U');
	}while(n==false);
	
	do{
     	aleatorio(x,y,pcx,pcy,2);
     	n=colocarBarcosPc(2,submarinos,pc,12,'Z');
     	barcos[0][4]=x;
		barcos[1][4]=y;
		barcos[2][4]=pcx;
		barcos[3][4]=pcy;
		barcos[4][4]=2;
		colocarBarcosPc(2,submarinos,pc,12,'Z');
	}while(n==false);
	do{
     	aleatorio(x,y,pcx,pcy,2);
     	n=colocarBarcosPc(2,submarinos,pc,12,'Z');
     	barcos[0][5]=x;
		barcos[1][5]=y;
		barcos[2][5]=pcx;
		barcos[3][5]=pcy;
		barcos[4][5]=2;
		colocarBarcosPc(2,submarinos,pc,12,'Z');
	}while(n==false);
	do{
     	aleatorio(x,y,pcx,pcy,2);
     	n=colocarBarcosPc(2,submarinos,pc,12,'Z');
     	barcos[0][6]=x;
		barcos[1][6]=y;
		barcos[2][6]=pcx;
		barcos[3][6]=pcy;
		barcos[4][6]=2;
		colocarBarcosPc(2,submarinos,pc,12,'Z');
	}while(n==false);
	do{
     	aleatorio(x,y,pcx,pcy,1);
     	n=colocarBarcosPc(1,submarinos,pc,12,'X');
     	barcos[0][7]=x;
		barcos[1][7]=y;
		barcos[2][7]=pcx;
		barcos[3][7]=pcy;
		barcos[4][7]=1;
		colocarBarcosPc(1,submarinos,pc,12,'X');
	}while(n==false);
		do{
     	aleatorio(x,y,pcx,pcy,1);
     	n=colocarBarcosPc(1,submarinos,pc,12,'X');
     	barcos[0][8]=x;
		barcos[1][8]=y;
		barcos[2][8]=pcx;
		barcos[3][8]=pcy;
		barcos[4][8]=1;
		colocarBarcosPc(1,submarinos,pc,12,'X');
	}while(n==false);
	imprimirMatriz(pc);
	printf("Comencemos a jugar.");

	
	
	

    
    
    
    
		
		
		
		
	return 0;
}

