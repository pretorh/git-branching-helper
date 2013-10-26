#include "helper.h"

const char *DEV_BRANCH = "dev";

void buildBranchName(char *into, const char *type, const char *name) {
    sprintf(into, "%s-%s", type, name);
}

void buildVersionBumpMessage(char *into, const char *version) {
    sprintf(into, "version bump %s", version);
}
