#ifndef _NAMESLIST_H
# define _NAMESLIST_H

/* This file was generated using the program 'buildnameslist.c' */

#ifdef __cplusplus
extern "C" {
#endif

struct unicode_block {
	int start, end;
	const char *name;
};

struct unicode_nameannot {
	const char *name, *annot;
};

/* NOTE: Build your program to access UnicodeBlock[], not UnicodeBlock[287] */
/* because newer version of NamesList.txt can have more blocks than before. */
/* To allow for future use of libuninameslist without changing your program */
/* you can test for (UnicodeBlock[i].end>=0x10ffff) to find the last block. */
#define UNICODE_BLOCK_MAX	287
extern const struct unicode_block UnicodeBlock[287];

/* NOTE: These 4 constants are correct for this version of libuninameslist, */
/* but can change for later versions of NamesList (use as an example guide) */
#define UNICODE_NAME_MAX	105
#define UNICODE_ANNOT_MAX	513
#define UNICODE_EN_NAME_MAX	83
#define UNICODE_EN_ANNOT_MAX	513
extern const struct unicode_nameannot * const *const UnicodeNameAnnot[];

/* Index by: UnicodeNameAnnot[(uni>>16)&0x1f][(uni>>8)&0xff][uni&0xff] */

/* At the beginning of lines (after a tab) within the annotation string, a: */
/*  * should be replaced by a bullet U+2022 */
/*  x should be replaced by a right arrow U+2192 */
/*  : should be replaced by an equivalent U+224D */
/*  # should be replaced by an approximate U+2245 */
/*  = should remain itself */

/* Return a pointer to the name for this unicode value */
/* This value points to a constant string inside the library */
const char *uniNamesList_name(unsigned long uni);

/* Return a pointer to the annotations for this unicode value */
/* This value points to a constant string inside the library */
const char *uniNamesList_annot(unsigned long uni);

/* Return a pointer to the Nameslist.txt version number. */
/* This value points to a constant string inside the library */
const char *uniNamesList_NamesListVersion(void);


/* These functions are available in libuninameslist-0.4.20140731 and higher */

/* Version information for this <uninameslist.h> include file */
#define LIBUNINAMESLIST_MAJOR	1
#define LIBUNINAMESLIST_MINOR	0

/* Return number of blocks in this NamesList (Version 9.0). */
int uniNamesList_blockCount(void);

/* Return block number for this unicode value (-1 if bad unicode value) */
int uniNamesList_blockNumber(unsigned long uni);

/* Return unicode value starting this Unicode block (-1 if bad uniBlock). */
long uniNamesList_blockStart(int uniBlock);

/* Return unicode value ending this Unicode block (-1 if bad uniBlock). */
long uniNamesList_blockEnd(int uniBlock);

/* Return a pointer to the blockname for this unicode block. */
/* This value points to a constant string inside the library */
const char *uniNamesList_blockName(int uniBlock);

#ifdef __cplusplus
}
#endif
#endif
