#include "helper.h"
#include "git.h"

void createHotfixBranch(const char *version, const char *bumpScript) {
    char hotfixName[1000];
    buildBranchName(hotfixName, "hotfix", version);
    char message[100];
    buildVersionBumpMessage(message, version);
    
    printf("Create branch %s for hotfix version %s\n", hotfixName, version);
    
    createBranchAndSwitch(hotfixName, "master");
    printf("./%s \"%s\"\n", bumpScript, version);
    commit(message);
    pushToOrigin(hotfixName);
}

void mergeHotfixBranch(const char *version, const char *releaseVersion) {
    char hotfixName[1000];
    buildBranchName(hotfixName, "hotfix", version);
    
    printf("Merge branch %s for hotfix version %s\n", hotfixName, version);
    
    mergeIntoAndPush(hotfixName, "master", "hotfix");
    mergeIntoAndPush(hotfixName, DEV_BRANCH, "hotfix");
    if (releaseVersion) {
        char releaseName[1000];
        buildBranchName(releaseName, "release", releaseVersion);
        mergeIntoAndPush(hotfixName, releaseName, "hotfix");
    }
    tag(version);
    deleteBranch(hotfixName);
}
