#include <stdbool.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)

typedef struct{
	uint16_t e_magic;
	uint16_t e_cblp;
	uint16_t e_cp;
	uint16_t e_crlc;
	uint16_t e_cparhdr;
	uint16_t e_minalloc;
	uint16_t e_maxalloc;
	uint16_t e_ss;
	uint16_t e_sp;
	uint16_t e_csum;
	uint16_t e_ip;
	uint16_t e_cs;
	uint16_t e_lfarlc;
	uint16_t e_ovno;
	uint16_t e_res[4];
	uint16_t e_oemid;
	uint16_t e_oeminfo;
	uint16_t e_res2[10];
	uint16_t e_lfanew; // sizeof(IMAGE_DOS_HEADER) + sizeof MS-DOS stub
} IMAGE_DOS_HEADER;

#pragma pack(pop)

bool petest_ispe(const unsigned char *b);

typedef struct{
        char* filepath;
        IMAGE_DOS_HEADER* hdr_dos;
} PE_FILE;

bool petest_init(PE_FILE *pe);
