#include <stdlib.h>
#include <stdio.h>
#include <time.h> // для рандомной генерации
#include "Entrant.h"

void usage() {
	printf("Usage: <program name> <number of entrant to generate> <output file>\n");
}

void generateEntrant(Entrant * ent) {
	ent->secondName[0] = 'A' + rand() % 26;
	int secondNameLen = 5 + rand() % 5;
	for (int i = 1; i < secondNameLen; ++i) {
		ent->secondName[i] = 'a' + rand() % 26;
	}

	ent->secondName[secondNameLen] = '\0';

	ent->initials[0] = 'A' + rand() % 26;
	ent->initials[1] = 'A' + rand() % 26;
	ent->initials[2] = '\0';

	ent->sex = rand() % 2;

	ent->schoolNumber = 1 + rand() % 2000;

	ent->hasMedal = rand() % 2;

	ent->essayResult = rand() % 2;

    for (int i = 0; i < 4; i++)
    {
        ent->examScores[i] = rand() % 100;
    }
}

int main(int argc, char * argw[]) {
	if (argc < 3) {
		usage();
		return 1;
	}

	srand(time(NULL)); // для рандомной генерации

	int nEntrant = atoi(argw[1]);
	FILE * fileOut = fopen(argw[2], "w");
	if (!fileOut) {
		printf("Error: can't open file %s\n", argw[1]);
		return 1;
	}

	Entrant ent;
	for (int i = 0; i < nEntrant; ++i) {
		generateEntrant(&ent);
		fprintf(fileOut, "%9s %2s %d %4u %d %3d %3d %3d %3d %3d\n"
				, ent.secondName
				, ent.initials
				, ent.sex
				, ent.schoolNumber
                , ent.hasMedal
				, ent.essayResult
                , ent.examScores[0]
                , ent.examScores[1]
                , ent.examScores[2]
                , ent.examScores[3]);
	}

	fclose(fileOut);
	return 0;
}
