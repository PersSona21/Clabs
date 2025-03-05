#include <stdio.h>
#include "Entrant.h"

void usage() {
	printf("Usage: <program name> <database name>\n");
}


int readEntrant(Entrant * ent) {
	int res = scanf("%9s %2s %d %4u %d %3d %3d %3d %3d %d\n"
			, ent->secondName
			, ent->initials
			, (int *)&ent->sex
			, &ent->schoolNumber
			, (int *)&ent->hasMedal
            , (int *)&ent->essayResult
            , &ent->examScores[0]
			, &ent->examScores[1]
            , &ent->examScores[2]
			, &ent->examScores[3]);
	return res == 10;
}

int main(int argc, char * argw[]) {
	if (argc < 2) {
		usage();
		return 1;
	}

	FILE * fileOut = fopen(argw[1], "wb");
	if (!fileOut) {
		printf("Error: can't open file %s\n", argw[1]);
		return 1;
	}

	Entrant ent;
	while (readEntrant(&ent)) {
		fwrite(&ent, sizeof(Entrant), 1, fileOut);
	}

	fclose(fileOut);
	return 0;
}
