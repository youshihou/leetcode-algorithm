//
//  hash_table.c
//  algorithm
//
//  Created by Ankui on 5/4/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "hash_table.h"
#include "algorithm-common.h"

int hash_init(struct hash_table* table, int size) {
    if (size <= 0) { return -1; }
    struct hash_data** data = malloc(sizeof(struct hash_data*) * size);
    memset(data, 0, sizeof(struct hash_data*) * size);
    if (data == NULL) { return -1; }
    table->head = data;
    table->size = size;
    return 0;
}

void hash_free(struct hash_table table) {
    if (table.head != NULL) {
        for (int i = 0; i < table.size; i++) {
            struct hash_data* data = table.head[i];
            while (data != NULL) {
                struct hash_data* tmp = data;
                data = data->next;
                free(tmp);
            }
        }
        free(table.head);
        table.head = NULL;
    }
    table.size = 0;
}

int hash_insert(struct hash_table table, int key, int value) {
    struct hash_data* data = malloc(sizeof(struct hash_data));
    if (data == NULL) { return -1; }
    data->key = key;
    data->value = value;
    int idx = abs(key) % table.size;
    data->next = table.head[idx];
    table.head[idx] = data;
    return 0;
}

struct hash_data* hash_find(struct hash_table table, int key) {
    int idx = abs(key) % table.size;
    struct hash_data* data = table.head[idx];
    while (data != NULL) {
        if (data->key == key) {
            return data;
        }
        data = data->next;
    }
    return NULL;
}
