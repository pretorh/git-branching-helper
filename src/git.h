#ifndef GIT_H_
#define GIT_H_

void createBranchAndSwitch(const char *branchName, const char* offFromBranch);
void pushToOrigin(const char *branchName);
void checkoutBranch(const char *branchName);
void deleteBranch(const char *branchName);
void mergeBranch(const char *branchName, const char *type, const char *into);
void commit(const char *message);
void tag(const char *tagName);

#endif
