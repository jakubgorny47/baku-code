#ifndef VECTRIS_H
#define VECTRIS_H
#include <stdlib.h>

typedef struct{
	void* _data; //underscore to note that it's not safe to touch variable, do not modify!
	unsigned int _size, _typeSize, _extra, extra; //size is mem_size_bytes / _typeSize, it's not raw size
	//_extra is how much extra space is left and "extra" is just how much extra space we should add
} vectris;

vectris vectris_init(unsigned int typeSize, unsigned int initialCapacity);
void vectris_allocate(vectris* v, unsigned int additionalSize);
void vectris_deallocate(vectris* v, unsigned int additionalSize);
void vectris_clear(vectris* v);
void vectris_push(vectris* v, void* element);
void vectris_pushi(vectris* v, long int element);
void vectris_pushf(vectris* v, float element);
void vectris_pushd(vectris* v, double element);
void vectris_pop(vectris* v);
void* vectris_get(vectris* v, unsigned int index);
void vectris_insert(vectris* v, unsigned int index, void* element);
void vectris_inserti(vectris* v, unsigned int index, long int number); //for <=64bit integers
void vectris_insertf(vectris* v, unsigned int index, float number); //for floating point numbers
void vectris_insertd(vectris* v, unsigned int index, double number); //for double precission fp nums
void* vectris_remove(vectris* v, unsigned int index);

#endif