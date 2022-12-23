#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 10

typedef struct hash_map {
    char *key;
    int value;
    struct hash_map *next;
} hash_map;

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

hash_map *create_hash_map(char *key, int value) {
    hash_map *map = (hash_map*) malloc(sizeof(hash_map));
    map->key = strdup(key);
    map->value = value;
    map->next = NULL;
    return map;
}

void insert(hash_map **table, char *key, int value) {
    unsigned long index = hash(key) % HASH_TABLE_SIZE;
    hash_map *entry = create_hash_map(key, value);
    entry->next = table[index];
    table[index] = entry;
}

int search(hash_map **table, char *key) {
    unsigned long index = hash(key) % HASH_TABLE_SIZE;
    hash_map *entry = table[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}

int main() {
    hash_map *table[HASH_TABLE_SIZE];
    memset(table, 0, sizeof(table));

    insert(table, "key1", 1);
    insert(table, "key2", 2);
    insert(table, "key3", 3);

    printf("%d\n", search(table, "key1"));
    printf("%d\n", search(table, "key2"));
    printf("%d\n", search(table, "key3"));
    printf("%d\n", search(table, "key4"));

    return 0;
}
