#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, const char **argv) {
    validateArgCount(argc, 1, "need at least the command name");
    
    if (0 == strcmp("cf", argv[1])) {
        validateArgCount(argc, 2, "cf 'feature branch name'");
        printf("Create feature branch '%s'\n", argv[2]);
        
        printf("git checkout -b %s %s\n", argv[2], DEV_BRANCH);
        printf("git push origin %s\n", argv[2]);
        notYetImplemented();
    } else if (0 == strcmp("mf", argv[1])) {
        validateArgCount(argc, 2, "mf 'feature branch name'");
        printf("Merge feature branch '%s'\n", argv[2]);
        
        printf("git checkout %s\n", DEV_BRANCH);
        printf("git merge --no-ff %s -m \"Merge %s branch '%s' into '%s'\"\n", argv[2], "feature", argv[2], DEV_BRANCH);
        printf("git push origin %s\n", DEV_BRANCH);
        
        printf("git branch -d %s\n", argv[2]);
        printf("git push origin --delete %s\n", argv[2]);
        
        notYetImplemented();
    } else if (0 == strcmp("cr", argv[1])) {
        validateArgCount(argc, 3, "cr 'release version name' 'version bump script'");
        printf("Create release branch for version '%s'\n", argv[2]);
        
        char releaseName[1000];
        strcpy(releaseName, "release-");
        strcpy(releaseName + 8, argv[2]);
        
        printf("git checkout -b %s %s\n", releaseName, DEV_BRANCH);
        printf("./%s \"%s\"\n", argv[3], argv[2]);
        printf("git commit -a -m \"version bump %s\"\n", argv[2]);
        printf("git push origin %s\n", releaseName);
        
        notYetImplemented();
    } else if (0 == strcmp("mr", argv[1])) {
        validateArgCount(argc, 2, "mr 'release version name'");
        printf("Merge release branch for version '%s'\n", argv[2]);
        
        char releaseName[1000];
        strcpy(releaseName, "release-");
        strcpy(releaseName + 8, argv[2]);
        
        printf("git checkout %s\n", "master");
        printf("git merge --no-ff %s -m \"Merge %s branch '%s' into '%s'\"\n", releaseName, "release", argv[2], "master");
        printf("git tag -a %s -m \"%s\"\n", argv[2], releaseName);
        printf("git push origin %s\n", "master");
        
        printf("git checkout %s\n", DEV_BRANCH);
        printf("git merge --no-ff %s -m \"Merge %s branch '%s' into '%s'\"\n", releaseName, "release", argv[2], DEV_BRANCH);
        printf("git push origin %s\n", DEV_BRANCH);
        
        printf("git branch -d %s\n", releaseName);
        printf("git push origin --delete %s\n", releaseName);
        
        notYetImplemented();
    } else if (0 == strcmp("ch", argv[1])) {
        validateArgCount(argc, 3, "mr 'hotfix version name' 'version bump script'");
        printf("Create hot fix for '%s'\n", argv[2]);
        
        char hotfixName[1000];
        strcpy(hotfixName, "hotfix-");
        strcpy(hotfixName + 7, argv[2]);
        
        printf("git checkout -b %s %s\n", hotfixName, "master");
        printf("./%s \"%s\"\n", argv[3], argv[2]);
        printf("git commit -a -m \"version bump %s\"\n", argv[2]);
        printf("git push origin %s\n", hotfixName);
        
        notYetImplemented();
    } else if (0 == strcmp("mh", argv[1])) {
        validateArgCount(argc, 2, "mh 'hotfix version name' ['release version name']");
        printf("Merge hotfix branch for version '%s'\n", argv[2]);
        
        char hotfixName[1000];
        strcpy(hotfixName, "hotfix-");
        strcpy(hotfixName + 7, argv[2]);
        
        printf("git checkout %s\n", "master");
        printf("git merge --no-ff %s -m \"Merge %s branch '%s' into '%s'\"\n", hotfixName, "hotfix", argv[2], "master");
        printf("git tag -a %s -m \"%s\"\n", argv[2], hotfixName);
        printf("git push origin %s\n", "master");
        
        if (argc == 4) {
            char releaseName[1000];
            strcpy(releaseName, "release-");
            strcpy(releaseName + 8, argv[3]);
            printf("git checkout %s\n", releaseName);
            printf("git merge --no-ff %s -m \"Merge %s branch '%s' into '%s'\"\n", hotfixName, "hotfix", argv[2], releaseName);
            printf("git push origin %s\n", releaseName);
        }
        
        printf("git checkout %s\n", DEV_BRANCH);
        printf("git merge --no-ff %s -m \"Merge %s branch '%s' into '%s'\"\n", hotfixName, "hotfix", argv[2], DEV_BRANCH);
        printf("git push origin %s\n", DEV_BRANCH);
        
        printf("git branch -d %s\n", hotfixName);
        printf("git push origin --delete %s\n", hotfixName);
        
        notYetImplemented();
    } else {
        printf("unknown command '%s'\n", argv[1]);
        return 1;
    }
    
    printf("bye\n");
    return 0;
}
