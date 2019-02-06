#ifndef BUCKET_H
#define BUCKET_H

#include <time.h>
#include "misc.h"

/*Type 1 bucket*/
struct NumberBucket
{
	char* hash_key; /*Caller or Callee*/
	struct List* CDRList; /*CDR List for the hash_key above*/
};

/*Type 2 bucket*/
struct CDRBucket
{
	char* cdr_uniq_id; 
	char* other_number;/*Caller or Callee*/
	struct tm date;
	int duration;
	int type;
	int tarrif;
	int fault_condition;
};

/*Creates a new bucket*/
void CreateBucket(void **,int,int);

/*Destroys a bucket [free memory]*/
void DestroyBucket(void*,int,int);

/*Prints all CDRs*/
void PrintCDRBucket(struct CDRBucket*,char*,int,int);

/*Prints CDRs in a specific time range*/
int PrintCDR(struct CDRBucket*,char*,struct tm,struct tm,int,int,int);

/*Dumps all CDRs in a file*/
void DumpCDRBucket(void*,int,int,FILE*,char*);

/*Copies a number to a NumberBucket slot*/
void number_copy(struct NumberBucket*,char*);

/*Copies a cdr to a CDRBucket  slot*/
void cdr_copy(struct CDRBucket*,struct CDR*);

/*Returns true if CDRBucket is empty*/
int IsEmptyBucket(struct CDRBucket*,int);

#endif