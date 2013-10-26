#include "helper.h"
#include "git.h"

const char *DEV_BRANCH = "dev";

void mergeIntoAndPush(const char *from, const char *into, const char *type) {
    checkoutBranch(into);
    mergeBranch(from, type, into);
    pushToOrigin(into);
}

void buildBranchName(char *into, const char *type, const char *name) {
    sprintf(into, "%s-%s", type, name);
}

void buildVersionBumpMessage(char *into, const char *version) {
    sprintf(into, "version bump %s", version);
}
