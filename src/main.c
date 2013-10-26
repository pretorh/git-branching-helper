#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "git.h"
#include "helper.h"

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
        createFeatureBranch(argv[2]);
        notYetImplemented();
    } else if (0 == strcmp("mf", argv[1])) {
        validateArgCount(argc, 2, "mf 'feature branch name'");
        mergeFeatureBranch(argv[2]);
        notYetImplemented();
    } else if (0 == strcmp("cr", argv[1])) {
        validateArgCount(argc, 3, "cr 'release version name' 'version bump script'");
        createReleaseBranch(argv[2], argv[3]);
        notYetImplemented();
    } else if (0 == strcmp("mr", argv[1])) {
        validateArgCount(argc, 2, "mr 'release version name'");
        mergeReleaseBranch(argv[2]);
        notYetImplemented();
    } else if (0 == strcmp("ch", argv[1])) {
        validateArgCount(argc, 3, "mr 'hotfix version name' 'version bump script'");
        createHotfixBranch(argv[2], argv[3]);
        notYetImplemented();
    } else if (0 == strcmp("mh", argv[1])) {
        validateArgCount(argc, 2, "mh 'hotfix version name' ['release version name']");
        mergeHotfixBranch(argv[2], argc == 4 ? argv[3] : NULL);
        notYetImplemented();
    } else {
        printf("unknown command '%s'\n", argv[1]);
        return 1;
    }
    
    printf("bye\n");
    return 0;
}
