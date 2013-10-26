#include "helper.h"
#include "git.h"

void createFeatureBranch(const char *name) {
    char featName[1000];
    buildBranchName(featName, "feat", name);
    
    printf("Create branch %s for feature %s\n", featName, name);
    
    createBranchAndSwitch(featName, DEV_BRANCH);
    pushToOrigin(featName);
}

void mergeFeatureBranch(const char *name) {
    char featName[1000];
    buildBranchName(featName, "feat", name);
    
    printf("Merge branch %s for feature %s\n", featName, name);
    
    mergeIntoAndPush(featName, DEV_BRANCH, "feature");
    deleteBranch(featName);
}
