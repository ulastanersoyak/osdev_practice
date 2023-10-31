#include "string.h"

#include <stddef.h>
#include <stdint.h>

void *memchr(const void *str, uint32_t c, size_t n) {
  unsigned char *p = (unsigned char *)str;
  unsigned char *chr = NULL;
  while ((str != NULL) && (n--)) {
    if (*p != (unsigned char)c) {
      p++;
    } else {
      chr = p;
      break;
    }
  }
  return chr;
}

int32_t memcmp(const void *str1, const void *str2, size_t n) {
  // check if both point to the same memory location
  if (str1 == str2) {
    return 0;
  }
  const uint8_t *ptr1 = (const uint8_t *)str1;
  const uint8_t *ptr2 = (const uint8_t *)str2;
  for (size_t i = 0; i < n; i++, ptr1++, ptr2++) {
    if (*ptr1 != *ptr2) {
      return (*ptr1 > *ptr2) ? 1 : -1;
    }
  }
  return 0;
}

void *memcpy(void *dest, const void *src, size_t n) {
  uint8_t *destin = (uint8_t *)dest;
  uint8_t *source = (uint8_t *)src;
  for (size_t i = 0; i < n; i++) {
    destin[i] = source[i];
  }
  return dest;
}

void *memset(void *ptr, int c, size_t n) {
  char *c_ptr = (char *)ptr;
  for (size_t i = 0; i < n; i++) {
    c_ptr[i] = (char)c;
  }
  return ptr;
}

char *strcat(char *dest,const char *src){
  size_t size = strlen(dest);
  size_t i;
  for(i = 0; src[i] != '\0'; i++){
    dest[size + i] = src[i];
  }
  dest[size + i] = '\0';
  return dest;
}

char *strncat(char *dest, const char *src, uint32_t n){
  size_t size = strlen(dest);
  size_t i;
  for(i = 0; i < n; i++){
    dest[size + i] = src[i];
  }
  dest[size + i] = '\0';
  return dest;
}

char *strchr(const char *str, uint32_t n){
  for(size_t i = 0; str[i] != '\0'; i++){
    if(str[i] == n){
      return (char*)str + i;
    }   
  }
  return 0;
}

size_t strlen(const char *str) {
  size_t size = 0;
  while (str[size]) {
    size++;
  }
  return size;
}
