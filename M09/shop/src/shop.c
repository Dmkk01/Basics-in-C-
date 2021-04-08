#include "shop.h"
#include <stdio.h>
#include <stdlib.h>

int write_binary(const char* filename, const Product* shop) {
	FILE* f = fopen(filename, "wb");
    if(!f)
        return 1;

    int i=0;
    for(; shop[i].name[0]; i++);

    int ret = fwrite(shop, sizeof(Product), i, f);

    if(ret != i) {
        fclose(f);
        return 1;
    }

    fclose(f);
    return 0;
}

Product* read_binary(const char* filename) {
	FILE* f = fopen(filename, "rb");
    if(!f)
        return NULL;

    Product* array = malloc(sizeof(Product));
    int i = 0;
    int ret = fread(&array[i], sizeof(Product), 1, f);
    while(ret == 1) {
        i++;
        array = realloc(array, (i+1)*sizeof(Product));
        ret = fread(&array[i], sizeof(Product), 1, f);
    }

    array[i].name[0] = 0;
    fclose(f);
    return array;
}

int write_plaintext(const char* filename, const Product* shop) {
	FILE* f = fopen(filename, "w");
    if(!f)
        return 1;

    for(int i=0; shop[i].name[0]; i++) {
        int ret = fprintf(f, "%s %f %d\n", shop[i].name, shop[i].price, shop[i].in_stock);
        if(ret < 0)
            return 1;
    }

    fclose(f);
    return 0;
}

Product* read_plaintext(const char* filename) {
	FILE* f = fopen(filename, "r");
    if(!f)
        return NULL;

    Product* array = malloc(sizeof(Product));
    int i = 0;
    int ret = fscanf(f, "%s %f %d\n", array[i].name, &array[i].price, &array[i].in_stock);
    while(ret > 0) {
        i++;
        array = realloc(array, (i+1)*sizeof(Product));
        ret = fscanf(f, "%s %f %d\n", array[i].name, &array[i].price, &array[i].in_stock);
    }

    array[i].name[0] = 0;
    fclose(f);
    return array;
}
