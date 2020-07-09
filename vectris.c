#include "vectris.h"

vectris vectris_init(unsigned int typeSize, unsigned int initialCapacity) {
	int reserve = (initialCapacity ? 10 : 0);

	vectris v = {NULL, initialCapacity, typeSize, reserve, 10};
	vectris_allocate(&v, initialCapacity + reserve);
	v._size = initialCapacity;

	return v;
}

void vectris_allocate(vectris* v, unsigned int additionalSize) {
	void* newData = realloc(v->_data, v->_typeSize * (v->_size + additionalSize));
	
	if (newData == NULL)
		free(v->_data);
	else
		v->_extra = additionalSize;
	v->_data = newData;
}

void vectris_deallocate(vectris* v, unsigned int substractSize) {
	if (v->_size - substractSize < 1) {
		free(v->_data);
		v->_size = 0;
		v->_extra = 0;
		v->_data = NULL;

		return;
	}

	void* newData = realloc(v->_data, v->_typeSize * (v->_size - substractSize + v->extra));
	
	if(newData == NULL)
		free(v->_data);

	v->_data = newData;
	v->_size -= substractSize;
}

void vectris_clear(vectris* v) {
	vectris_deallocate(v, v->_size);
}

void vectris_push(vectris* v, void* element) {
	if (v->_extra < 1)
		vectris_allocate(v, v->extra);

	memcpy(v->_size * v->_typeSize + (unsigned int)v->_data, element, v->_typeSize);
	v->_size++;
	v->_extra--;
}

void vectris_pushi(vectris* v, long int number) {
	vectris_push(v, &number);
}

void vectris_pushf(vectris* v, float number) {
	vectris_push(v, &number);
}

void vectris_pushd(vectris* v, double number) {
	vectris_push(v, &number);
}

void vectris_pop(vectris* v) {
	if (v->_size < 1)
		return;
	vectris_deallocate(v, 1);
	v->_extra++;
}

void* vectris_get(vectris* v, unsigned int index) {
	if (v->_size < 1 || v->_size <= index)
		return NULL;
	return (void*)((unsigned int)v->_data + index * v->_typeSize);
}

void vectris_insert(vectris* v, unsigned int index, void* element) {
	if (v->_extra < 1)
		vectris_allocate(v, v->extra);

	memmove((unsigned int)v->_data + index * v->_typeSize + v->_typeSize, (unsigned int)v->_data + index * v->_typeSize, (v->_size - index) * v->_typeSize);
	memcpy((unsigned int)v->_data + index * v->_typeSize, element, v->_typeSize);
}

void vectris_inserti(vectris* v, unsigned int index, long int number) {
	vectris_insert(v, index, &number);
}

void vectris_insertf(vectris* v, unsigned int index, float number) {
	vectris_insert(v, index, &number);
}

void vectris_insertd(vectris* v, unsigned int index, double number) {
	vectris_insert(v, index, &number);
}

vectris vectris_remove(vectris* v, unsigned int index) {
    void* temp;
    vectris  v1 = vectris _init(sizeof(vectris_get(v,0)),v->_size-1);
    unsigned int ind = 0;
    for(int i = 0; i < v->_size; i++){
        if(i != index){
            temp = vectris _get(v,i);
            vectris _insert(&v1, ind, temp);
            ind++;
        }
    }
    return v1;
}
