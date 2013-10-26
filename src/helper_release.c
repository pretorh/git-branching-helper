#include "helper.h"
#include "git.h"

void createReleaseBranch(const char *version, const char *bumpScript) {
    char releaseName[1000];
    buildBranchName(releaseName, "release", version);
    char message[100];
    
    buildVersionBumpMessage(message, version);
    
    printf("Create branch %s for release version %s\n", releaseName, version);
    
    createBranchAndSwitch(releaseName, DEV_BRANCH);
    printf("./%s \"%s\"\n", bumpScript, version);
    commit(message);
    pushToOrigin(releaseName);
}

void mergeReleaseBranch(const char *version) {
    char releaseName[1000];
    buildBranchName(releaseName, "release", version);
    
    printf("Merge branch %s for release version %s\n", releaseName, version);
    
    checkoutBranch("master");
    mergeBranch(releaseName, "release", "master");
    tag(version);
    pushToOrigin("master");
    checkoutBranch(DEV_BRANCH);
    mergeBranch(releaseName, "release", DEV_BRANCH);
    pushToOrigin(DEV_BRANCH);
    deleteBranch(releaseName);
}
