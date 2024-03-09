#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void fun_HW02a_InOut (char Inloc[], char Outloc[])	{

	// char Inloc[] = "data .in"; Inloc[4] = fname;
	FILE *In_ptr;	In_ptr = fopen(Inloc, "r");
	// char Outloc[] = "data .out"; Outloc[4] = fname;
	FILE *Out_ptr;	Out_ptr = fopen(Outloc, "w");

    if (NULL == In_ptr) {
    printf("file can't be opened \n");
    exit(1);	}

    		// Definice a inicializace inputu
	int Input1;		fscanf(In_ptr, "%d", &Input1);
			// Definice a inicializace outputu
    int Input2;		fscanf(In_ptr, "%d", &Input2);
    											fclose(In_ptr);

    		// Kontrola limitů												
	if (Input1 < -10000 | Input1 > 10000 | Input2 < -10000 | Input2 > 10000) {
		fprintf(Out_ptr,"Mimo interval");
				}
	else	{
		fprintf(Out_ptr,"Desitkova soustava: %d %d\n",Input1, Input2);
		fprintf(Out_ptr,"Sestnackova soustava: %x %x\n", Input1, Input2);
		fprintf(Out_ptr,"Soucet: %d + %d = %d\n", Input1, Input2, Input1 + Input2);
		fprintf(Out_ptr,"Rozdil: %d - %d = %d\n", Input1, Input2, Input1 - Input2);
		fprintf(Out_ptr,"Soucin: %d * %d = %d\n", Input1, Input2, Input1 * Input2);
		
			// Kontrola dělení 0
		if (Input2 == 0)	{
			fprintf(Out_ptr,"Nedefinovany vysledek\n");	}
		else	{
			fprintf(Out_ptr,"Podil: %d / %d = %d\n", Input1, Input2, Input1 / Input2);	}
		double add = Input1 + Input2;
		double procento = add / 2;
		fprintf(Out_ptr,"Prumer: %.1lf", procento);


	}
		fclose(Out_ptr);

}

int main(int argc, char const *argv[])
{	
	
	char Inloc1[] = "data\\pub01.in"; char Outloc1[] = "data\\pub01.out";
	char Inloc2[] = "data\\pub02.in"; char Outloc2[] = "data\\pub02.out";
	char Inloc3[] = "data\\pub03.in"; char Outloc3[] = "data\\pub03.out";
	char Inloc4[] = "data\\pub04.in"; char Outloc4[] = "data\\pub04.out";

	fun_HW02a_InOut(Inloc1, Outloc1);
	fun_HW02a_InOut(Inloc2, Outloc2);
	fun_HW02a_InOut(Inloc3, Outloc3);
	fun_HW02a_InOut(Inloc4, Outloc4);


	return 0;
}