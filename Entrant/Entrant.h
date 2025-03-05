#ifndef ENTRANT_H_
#define ENTRANT_H_

typedef enum {
	male,
	female
} Sex;

typedef struct {
	char secondName[50];
	char initials[3];
	Sex sex;
	unsigned int schoolNumber;
	char hasMedal;
	char essayResult;
    int examScores[4];
} Entrant;

#endif