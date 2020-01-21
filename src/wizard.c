#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "wizard.h"

struct wizard  *
wizard_new(char *name)
{
	struct wizard  *w;
	assert((w = malloc(sizeof(struct wizard))) != NULL);
	assert((w->name = strdup(name)) != NULL);
	return w;
}
