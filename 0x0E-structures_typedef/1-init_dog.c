#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - initialise variable of type struct dog
 * @d: the dog to be initaialised
 * @name: the name of the odg
 * @age: the age of the dig
 * @owner: owner of the dog
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
