// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	if (!size) {
		return NULL;
	}

	void *address_start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (address_start == MAP_FAILED) {
		return NULL;
	}

	if (mem_list_add(address_start, size) == -1) {
		munmap(address_start, size);
		return NULL;
	}

	return address_start;
}

void *calloc(size_t nmemb, size_t size)
{
	if (!size) {
		return NULL;
	}

	void *ret = malloc(nmemb * size);
	if (!ret) {
		return NULL;
	}

	ret = memset(ret, 0, nmemb * size);

	return ret;
}

void free(void *ptr)
{
	if (!ptr) {
		return;
	}

	struct mem_list *item = mem_list_find(ptr);
	if (!item) {
		return;
	}

	munmap(item->start, item->len);
	mem_list_del(item->start);
}

void *realloc(void *ptr, size_t size)
{
	if (!ptr) {
		return malloc(size);
	}

	if (!size) {
		free(ptr);
		return NULL;
	}

	void *new_address = malloc(size);
	if (!new_address) {
		return NULL;
	}

	struct mem_list *item = mem_list_find(ptr);
	size_t old_size = item->len;

	size_t copy_size;
	if (size < old_size) {
		copy_size = size;
	} else {
		copy_size = old_size;
	}

	new_address = memcpy(new_address, ptr, copy_size);

	free(ptr);

	return new_address;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return realloc(ptr, nmemb * size);
}
