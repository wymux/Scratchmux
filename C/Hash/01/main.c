#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct entry {
	char *key;
	void *val;
	struct entry *next;
} entry;

typedef struct htbl {
	entry **buckets;
	int n_buckets;
} htbl;

uint32_t
hash(char *s) {
	uint32_t h = 5381;
	char c;
	while ((c = *s++)) {
		h = (33 * h + c);
	}

	return h;
}

uint32_t get_bucket(htbl *h, char *key) {
	return hash(key) % h->n_buckets;
}

htbl *hash_new() {
	int n_buckets = 4;
	htbl *h = malloc(sizeof(htbl));
	h->n_buckets = n_buckets;
	h->buckets = calloc(n_buckets, sizeof(entry *));
	return h;
}

void
hash_set(htbl *h, char *key, void *val)
{
	uint32_t bucket = get_bucket(h, key);
	entry *v = h->buckets[bucket];

	while (v != NULL) {
		if (strcmp(v->key, key) == 0) {
			v->val = val;
			return;
		}
		v = v->next;
	}

	entry *new_val = malloc(sizeof(entry));
	new_val->key = strdup(key);
	new_val->val = val;
	new_val->next = h->buckets[bucket];
	h->buckets[bucket] = new_val;
}

void
*hash_get(htbl *h, char *key)
{
	uint32_t bucket = get_bucket(h, key);
	entry *v = h->buckets[bucket];

	while (v != NULL) {
		if (strcmp(v->key, key) == 0) return v->val;
		v = v->next;
	}

	return NULL;
}

void
hash_delete(htbl *h, char *key)
{
	uint32_t bucket = get_bucket(h, key);
	entry *p = NULL;
	entry *v = h->buckets[bucket];

	while (v != NULL) {
		if (strcmp(v->key, key) == 0) {
			if (p == NULL) {
				h->buckets[bucket] = v->next;
			} else {
				p->next = v->next;
			}
			free(v->key);
			free(v);
			return;
		}
		p = v;
		v = v->next;
	}
}

void
hash_free(htbl *h)
{
	for (int b = 0; b < h->n_buckets; b++) {
		entry *v = h->buckets[b];
		while (v != NULL) {
			entry *next = v->next;
			free(v->key);
			free(v);
			v = next;
		}
	}

	free(h->buckets);
	free(h);
}

int
main()
{
	htbl *h = hash_new();
	int a = 5;
	hash_set(h, "item a", &a);
	hash_delete(h, "item a");
}
