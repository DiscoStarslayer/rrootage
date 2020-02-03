/*
 * $Id: barragemanager.cc,v 1.4 2003/04/26 03:24:15 kenta Exp $
 *
 * Copyright 2002 Kenta Cho. All rights reserved.
 */

/**
 * Handle barrages.
 *
 * @version $Revision: 1.4 $
 */
extern "C" {
#include "SDL.h"
#include "genmcr.h"
#include "brgmng_mtd.h"
}

#include <windows.h>
#include <fileapi.h>
#include "barragemanager.h"

Barrage barragePattern[BARRAGE_TYPE_NUM][BARRAGE_PATTERN_MAX];
int barragePatternNum[BARRAGE_TYPE_NUM];

static const char *BARRAGE_DIR_NAME[BARRAGE_TYPE_NUM] = {
  "normal", "reversible", "morph", "simple", "morph_heavy", "psy",
};

static int readBulletMLFiles(const char *directoryPath, Barrage barrage[]) {
  int barrageIndex = 0;
  WIN32_FIND_DATAA findData;
  HANDLE searchHandle;
  BOOL fileFound = true;

  char directorySearch[strlen(directoryPath) + 2];
  strcpy(directorySearch, directoryPath);
  strcat(directorySearch, "\\*");

  searchHandle = FindFirstFileA(directorySearch, &findData);

  if (searchHandle == INVALID_HANDLE_VALUE) {
    fprintf(stderr, "Could not open directory: %s\n", directoryPath);
    exit(1);
  }

  while (fileFound) {
    if (strcmp(strrchr(findData.cFileName, '.'), ".xml") != 0) {
      fileFound = FindNextFileA(searchHandle, &findData);
      continue;
    }

    char fileName[256];

    strcpy(fileName, directoryPath);
    strcat(fileName, "\\");
    strncat(fileName, findData.cFileName, sizeof(fileName) - strlen(fileName) - 1);

    barrage[barrageIndex].bulletml = new BulletMLParserTinyXML(fileName);
    barrage[barrageIndex].bulletml->build();
    barrageIndex++;

    printf("Loaded: %s\n", fileName);

    fileFound = FindNextFileA(searchHandle, &findData);
  }

  FindClose(searchHandle);

  return barrageIndex;
}

void initBarragemanager() {
  for ( int i=0 ; i<BARRAGE_TYPE_NUM ; i++ ) {
    barragePatternNum[i] = readBulletMLFiles(BARRAGE_DIR_NAME[i], barragePattern[i]);
    printf("--------\n");
  }
}

void closeBarragemanager() {
  for ( int i=0 ; i<BARRAGE_TYPE_NUM ; i++ ) {
    for ( int j=0 ; j<barragePatternNum[i] ; j++ ) {
      delete barragePattern[i][j].bulletml;
    }
  }
}
