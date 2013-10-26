#include <stdio.h>
#include <stdlib.h>

#ifndef _HELPER_H_
#define _HELPER_H_

const char *DEV_BRANCH;

void buildBranchName(char *into, const char *type, const char *name);
void buildVersionBumpMessage(char *into, const char *version);

void createFeatureBranch(const char *name);
void mergeFeatureBranch(const char *name);

void createReleaseBranch(const char *version, const char *bumpScript);
void mergeReleaseBranch(const char *version);

void createHotfixBranch(const char *version, const char *bumpScript);
void mergeHotfixBranch(const char *version, const char *releaseVersion);

#endif
