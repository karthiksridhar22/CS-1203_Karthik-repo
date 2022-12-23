#include <stdio.h>
#include <stdlib.h>

typedef struct skip_list_node {
  int key;
  int value;
  struct skip_list_node *forward[2];
} skip_list_node;

typedef struct skip_list {
  skip_list_node *head;
} skip_list;

skip_list *skip_list_init() {
  skip_list *list = malloc(sizeof(skip_list));
  list->head = malloc(sizeof(skip_list_node));
  list->head->forward[0] = NULL;
  list->head->forward[1] = NULL;
  return list;
}

void skip_list_insert(skip_list *list, int key, int value) {
  skip_list_node *update[2];
  skip_list_node *x = list->head;
  for (int i = 1; i >= 0; i--) {
    while (x->forward[i] != NULL && x->forward[i]->key < key) {
      x = x->forward[i];
    }
    update[i] = x;
  }
  x = x->forward[0];
  if (x == NULL || x->key != key) {
    x = malloc(sizeof(skip_list_node));
    x->key = key;
    x->value = value;
    x->forward[0] = update[0]->forward[0];
    update[0]->forward[0] = x;
    x->forward[1] = update[1]->forward[1];
    update[1]->forward[1] = x;
  }
}

skip_list_node *skip_list_search(skip_list *list, int key) {
  skip_list_node *x = list->head;
  for (int i = 1; i >= 0; i--) {
    while (x->forward[i] != NULL && x->forward[i]->key < key) {
      x = x->forward[i];
    }
  }
  x = x->forward[0];
  if (x != NULL && x->key == key) {
    return x;
  } else {
    return NULL;
  }
}

void skip_list_delete(skip_list *list, int key) {
  skip_list_node *update[2];
  skip_list_node *x = list->head;
  for (int i = 1; i >= 0; i--) {
    while (x->forward[i] != NULL && x->forward[i]->key < key) {
      x = x->forward[i];
    }
    update[i] = x;
  }
  x = x->forward[0];
  if (x != NULL && x->key == key) {
    update[0]->forward[0] = x->forward[0];
    update[1]->forward[1] = x->forward[1];
    free(x);
  }
}

int main() {
  skip_list *list = skip_list_init();

  skip_list_insert(list, 1, 10);
  skip_list_insert(list, 2, 20);
  skip_list_insert(list, 3, 30);
  skip_list_insert(list, 4, 40);
  skip_list_insert(list, 5, 50);

  skip_list_node *node = skip_list_search(list, 3);
  if (node != NULL) {
    printf("Key: %d, Value: %d\n", node->key, node->value);
  }

  skip_list_delete(list, 3);
  node = skip_list_search(list, 3);
  if (node == NULL) {
    printf("Key 3 not found\n");
  }

  return 0;
}

 
