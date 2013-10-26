#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        validateArgCount(argc, 2, "cf 'branch name'");
        printf("Create feature branch '%s'\n", argv[2]);
        
        printf("git checkout -b %s dev\n", argv[2]);
        printf("git push origin %s\n", argv[2]);
        notYetImplemented();
    } else if (0 == strcmp("mf", argv[1])) {
        validateArgCount(argc, 2, "mf 'feature branch name'");
        printf("Merge feature branch '%s'\n", argv[2]);
        
        printf("git checkout dev\n");
        printf("git merge --no-ff %s -m \"Merge feature branch '%s' into 'dev'\"\n", argv[2], argv[2]);
        printf("git branch -d %s\n", argv[2]);
        printf("git push origin --delete %s\n", argv[2]);
        printf("git push origin dev\n");
        
        notYetImplemented();
    } else if (0 == strcmp("cr", argv[1])) {
        validateArgCount(argc, 3, "cr 'release version name' 'version bump script'");
        printf("Create release branch for version '%s'\n", argv[2]);
        
        printf("git checkout -b release-%s dev\n", argv[2]);
        printf("git push origin release-%s\n", argv[2]);
        printf("./%s \"%s\"\n", argv[3], argv[2]);
        printf("git commit -a -m \"version bump %s\"\n", argv[2]);
        
        notYetImplemented();
    } else if (0 == strcmp("mr", argv[1])) {
        validateArgCount(argc, 2, "mr 'release version name'");
        printf("Merge release branch for version '%s'\n", argv[2]);
        
        printf("git checkout master\n");
        printf("git merge --no-ff release-%s -m \"Merge release branch '%s' into 'master'\"\n", argv[2], argv[2]);
        printf("git tag -a %s -m \"release-%s\"\n", argv[2], argv[2]);
        printf("git push origin master\n");
        printf("\n");
        
        printf("git checkout dev\n");
        printf("git merge --no-ff release-%s -m \"Merge release branch '%s' into 'dev'\"\n", argv[2], argv[2]);
        printf("git branch -d release-%s\n", argv[2]);
        printf("git push origin --delete release-%s\n", argv[2]);
        
        notYetImplemented();
    } else if (0 == strcmp("ch", argv[2])) {
        validateArgCount(argc, 3, "mr 'hotfix version name' 'version bump script'");
        printf("Create hot fix for '%s'\n", argv[2]);
        
        printf("git checkout -b hotfix-%s dev\n", argv[2]);
        printf("./%s \"%s\"\n", argv[3], argv[2]);
        printf("git commit -a -m \"version bump %s\"\n", argv[2]);
        printf("git push origin hotfix-%s\n", argv[2]);
        
        notYetImplemented();
    } else if (0 == strcmp("mh", argv[2])) {
        validateArgCount(argc, 2, "mh 'hotfix version name'");
        printf("Merge hotfix branch for version '%s'\n", argv[2]);
        
        printf("git checkout master\n");
        printf("git merge --no-ff hotfix-%s -m \"Merge hotfix branch '%s' into 'master'\"\n", argv[2], argv[2]);
        printf("git tag -a %s -m \"hotfix-%s\"\n", argv[2], argv[2]);
        printf("git push origin master\n");
        printf("\n");
        
        printf("git checkout dev\n");
        printf("git merge --no-ff hotfix-%s -m \"Merge hotfix branch '%s' into 'dev'\"\n", argv[2], argv[2]);
        printf("git push origin dev\n");
        
        printf("git branch -d hotfix-%s\n", argv[2]);
        printf("git push origin --delete hotfix-%s\n", argv[2]);
        
        notYetImplemented();
    } else {
        printf("unknown command '%s'\n", argv[1]);
        return 1;
    }
    
    printf("bye\n");
    return 0;
}
