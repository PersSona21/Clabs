#include <stdio.h>
#include "Entrant.h"

void usage() {
	printf("Usage: <program name> <database name>\n");
}

int hasDuplicate(int arr[4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char * argw[]) {
	if (argc < 2) {
		usage();
		return 1;
	}

	FILE * fileIn = fopen(argw[1], "rb");
	if (!fileIn) {
		printf("Error: can't open file %s\n", argw[1]);
		return 1;
	}

	Entrant ent;
	while (fread(&ent, sizeof(Entrant), 1, fileIn) == 1) { 
		if (ent.sex == female && hasDuplicate(ent.examScores)){
			printf("%9s %2s %d %4u %d %d %3d %3d %3d %3d\n"
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
		
	}

	fclose(fileIn);
	return 0;
}
