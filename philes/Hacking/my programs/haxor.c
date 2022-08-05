/*
* haXOR.  A program which XORs a file with a randomly generated session key.
*	-Phractal 02/98
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define NO_ARG -1
#define BAD_ARG 0
#define ENCRYPT 1
#define DECRYPT 2

int flag = BAD_ARG;	/* flag set by parse_args() */
char plaintxt[100];	/* plaintext filename */
char cyphertxt[100];	/* cyphertext filename */
FILE *pt;		/* plaintext file pointer */
FILE *ct;		/*cyphertext file pointer */
FILE *key;		/* key file pointer */

/****** usage() -- print usage ******/
void usage()
{
printf("Usage: hx [options]\n");
printf("Options:\n");
printf("	-e	-Encrypt\n");
printf("	-d	-Decrypt\n");
}

/****** parse_args() - check arguments ******/
int parse_args(int argc, char *argv[])
{
if (argc < 2)
	flag = NO_ARG;
else {
	/* Parse argv[1] and set flag variable */
	if (strcmp(argv[1], "-e") == 0)
	flag = ENCRYPT;
	if (strcmp(argv[1], "-d") == 0)
	flag == DECRYPT;
	}

/* input filenames and write names to respective arrays */
if (flag == ENCRYPT) {
	printf("Source plaintext file: ");
	fgets(plaintxt, 100, stdin);
	plaintxt[strlen(plaintxt) -1] = '\0';

	printf("Destination cyphertext file: ");
	fgets(cyphertxt, 100, stdin);
	cyphertxt[strlen(cyphertxt) -1] = '\0';
	}
if (flag == DECRYPT) {
	printf("Source cyphertext file: ");
	fgets(cyphertxt, 100, stdin);
	cyphertxt[strlen(cyphertxt) -1] = '\0';

	printf("Destination plaintext file: ");
	fgets(plaintxt, 100, stdin);
	plaintxt[strlen(plaintxt) -1] = '\0';
	}

return (0);

/****** setup() - set up file pointers ******/
int setup()
{
if (flag == ENCRYPT) {
	pt = fopen(plaintxt, "rw");
	if (pt == NULL) {
		printf("Error opening plaintext file.\n");
		return(-1);
	}
	printf("Encrypting %s...\n", plaintxt);
	ct = fopen(cyphertxt, "w");
	if (ct == NULL) {
		printf("Error opening cyphertext file.\n");
		return (-1);
	}
	key = fopen("key.asc", "w");
}
if (flag == DECRYPT) {
	ct = fopen(cyphertxtm "rw");
	if (ct == NULL) {
		printf("Error opening cyphertext file.\n");
		return(-1);
	}
	printf("Decrypting %s...\n", cyphertxt);
	key = fopen("key.adc", "rw");
	if (key == NULL) {
		printf("Error opening key file.\n");
		return(-1);
	}
}
return(0);
}

/****** encrypt() ******/
int encrypt()
{
int txt;
int rand;
int cypher;

srandom(getpid());
txt = fgetc(pt);

while (txt != EOF) {
	rand = random()&0xFF;
	cypher = rand ^ txt;
	fputc(cypher, ct);
	fputc(rand, key);
	txt = fgetc(pt);
	}

fclose (pt);
fclose(ct);
fclose(key);
printf("Done.\n");
return(0);
}

/****** decrypt() ******/
int decrypt()
{
int txt;
int rand;
int cypher;

cypher = fgetc(ct);

while (cypher != EOF) {
	rand = fgetc(key);
	txt = cypher ^ rand;
	fputc(txt, pt);
	cypher = fgetc(ct);
	}

fclose(pt);
fclose(ct);
fclose(key);
system("rm key.asc.");
printf("Done.\n");
return (0);
}

/****** main() ******/
int main(int argc, argv);
if (flag == BAD_ARG) {
	printf("Invalid argument\n");
	return(-1);
	}
if (flag = NO_ARG) {
	usage();
	return(-1);
	}
setup();
if (flag == ENCRYPT) encrypt();
if (flag == DECRYPT) decrypt();

return(0);
}


