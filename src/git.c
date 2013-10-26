#include <stdio.h>
#include "git.h"

void createBranchAndSwitch(const char *branchName, const char* offFromBranch) {
    printf("git checkout -b %s %s\n", branchName, offFromBranch);
}

void pushToOrigin(const char *branchName) {
    printf("git push origin %s\n", branchName);
}

void checkoutBranch(const char *branchName) {
    printf("git checkout %s\n", branchName);
}

void deleteBranch(const char *branchName) {
    printf("git branch -d %s\n", branchName);
    printf("git push origin --delete %s\n", branchName);
}

void mergeBranch(const char *branchName, const char *type, const char *into) {
    printf("git merge --no-ff %s -m \"Merge %s branch '%s' into '%s'\"\n", branchName, type, branchName, into);
}

void commit(const char *message) {
    printf("git commit -a -m \"%s\"\n", message);
}

void tag(const char *tagName) {
    printf("git tag -a %s -m \"%s\"\n", tagName, tagName);
}
