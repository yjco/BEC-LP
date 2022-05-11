#include <stdio.h>
#include <stdlib.h>

/*
 * Exercise 6-6 (P. 119)
 * Write a simplier version of the define processor
 */

#define	HASHSIZE	101

//struct nlist;
struct nlist {

	struct nlist *next;
	char *name;
	char *defn;

}

//unsigned hash(char *s);
//struct nlist *lookup(char *s);
//struct nlist *install(char *name, char *defn);

unsigned hash(char *s) {

	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++) hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;

}

struct nlist *lookup(char *s) {

	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next) if (strcmp(s, np->name) == 0) return np;
	return NULL;

}

struct nlist *install(char *name, char *defn) {

	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {

		np = (struct nlist *) malloc(sizeof(*np));

		if (np == NULL || (np->name = strdup(name)) == NULL) return NULL;

		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;

	} else free((void *) np->defn);

	if ((np->defn = strdup(defn)) == NULL) return NULL;
	return np;

}

int remove(char *name) {

	struct nlist *np;

	if ((np = lookup(name)) == NULL) {

		return -1;
			
	} else {

		np = NULL;

	}

}

int main() {

}

