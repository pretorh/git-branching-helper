#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "git.h"

const char *DEV_BRANCH = "dev";

void validateArgCount(int actual, int wanted, const char *detail) {
    if (actual <= wanted) {
        printf("missing arguments: %s\n", detail);
        exit(1);
    }
}

void notYetImplemented() {
    printf("\nNot yet implemented\n");
    exit(2);
}

void buildBranchName(char *into, const char *type, const char *name) {
    sprintf(into, "%s-%s", type, name);
}

void buildVersionBumpMessage(char *into, const char *version) {
    sprintf(into, "version bump %s", version);
}

int main(int argc, const char **argv) {
    validateArgCount(argc, 1, "need at least the command name");
    
    if (0 == strcmp("cf", argv[1])) {
        validateArgCount(argc, 2, "cf 'feature branch name'");
        printf("Create feature branch '%s'\n", argv[2]);
        
        char featName[1000];
        buildBranchName(featName, "feat", argv[2]);
        
        createBranchAndSwitch(featName, DEV_BRANCH);
        pushToOrigin(featName);
        
        notYetImplemented();
    } else if (0 == strcmp("mf", argv[1])) {
        validateArgCount(argc, 2, "mf 'feature branch name'");
        printf("Merge feature branch '%s'\n", argv[2]);
        
        char featName[1000];
        buildBranchName(featName, "feat", argv[2]);
        
        checkoutBranch(DEV_BRANCH);
        mergeBranch(featName, "feature", DEV_BRANCH);
        pushToOrigin(DEV_BRANCH);
        deleteBranch(featName);
        
        notYetImplemented();
    } else if (0 == strcmp("cr", argv[1])) {
        validateArgCount(argc, 3, "cr 'release version name' 'version bump script'");
        printf("Create release branch for version '%s'\n", argv[2]);
        
        char releaseName[1000];
        buildBranchName(releaseName, "release", argv[2]);
        
        char message[100];
        buildVersionBumpMessage(message, argv[2]);
        
        createBranchAndSwitch(releaseName, DEV_BRANCH);
        printf("./%s \"%s\"\n", argv[3], argv[2]);
        commit(message);
        pushToOrigin(releaseName);
        
        notYetImplemented();
    } else if (0 == strcmp("mr", argv[1])) {
        validateArgCount(argc, 2, "mr 'release version name'");
        printf("Merge release branch for version '%s'\n", argv[2]);
        
        char releaseName[1000];
        buildBranchName(releaseName, "release", argv[2]);
        
        checkoutBranch("master");
        mergeBranch(releaseName, "release", "master");
        tag(argv[2]);
        pushToOrigin("master");
        checkoutBranch(DEV_BRANCH);
        mergeBranch(releaseName, "release", DEV_BRANCH);
        pushToOrigin(DEV_BRANCH);
        deleteBranch(releaseName);
        
        notYetImplemented();
    } else if (0 == strcmp("ch", argv[1])) {
        validateArgCount(argc, 3, "mr 'hotfix version name' 'version bump script'");
        printf("Create hot fix for '%s'\n", argv[2]);
        
        char hotfixName[1000];
        buildBranchName(hotfixName, "hotfix", argv[2]);
        char message[100];
        buildVersionBumpMessage(message, argv[2]);
        
        createBranchAndSwitch(hotfixName, "master");
        printf("./%s \"%s\"\n", argv[3], argv[2]);
        commit(message);
        pushToOrigin(hotfixName);
        
        notYetImplemented();
    } else if (0 == strcmp("mh", argv[1])) {
        validateArgCount(argc, 2, "mh 'hotfix version name' ['release version name']");
        printf("Merge hotfix branch for version '%s'\n", argv[2]);
        
        char hotfixName[1000];
        buildBranchName(hotfixName, "hotfix", argv[2]);
        
        checkoutBranch("master");
        mergeBranch(hotfixName, "hotfix", "master");
        tag(argv[2]);
        pushToOrigin("master");
        
        if (argc == 4) {
            char releaseName[1000];
            buildBranchName(releaseName, "release", argv[3]);
            
            checkoutBranch(releaseName);
            mergeBranch(hotfixName, "hotfix", releaseName);
            pushToOrigin(releaseName);
        }
        
        checkoutBranch(DEV_BRANCH);
        mergeBranch(hotfixName, "hotfix", DEV_BRANCH);
        pushToOrigin(DEV_BRANCH);
        deleteBranch(hotfixName);
        
        notYetImplemented();
    } else {
        printf("unknown command '%s'\n", argv[1]);
        return 1;
    }
    
    printf("bye\n");
    return 0;
}
