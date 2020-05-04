//
//  hash_table.h
//  algorithm
//
//  Created by Ankui on 5/4/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef hash_table_h
#define hash_table_h

#include <stdio.h>

struct hash_data {
    int key;
    int value;
    struct hash_data* next;
};

struct hash_table {
    int size;
    struct hash_data** head;
};



int hash_init(struct hash_table* table, int size);
void hash_free(struct hash_table table);
int hash_insert(struct hash_table table, int key, int value);
struct hash_data* hash_find(struct hash_table table, int key);


#endif /* hash_table_h */
