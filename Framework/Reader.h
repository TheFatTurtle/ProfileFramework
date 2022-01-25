#pragma once
#include <stdio.h>
//Reminder: Load file -> Allocate entire file in memory, split into strings, add to group, add buffer to group, when group is destroyed the buffer also is destroyed.
//Why shouldn't the structure only hold the buffer?
//Not all groups are created from files 
struct Buffer {
	size_t size;
	char* data;
	~Buffer() {
		if(data)
		delete data;
	};
};
//This might very well break in Android, but it shouldn't
inline Buffer* ReadFromFile(char* path) {
	FILE* file = fopen(path, "r");
	Buffer *buffer;
	if (!file) return nullptr;
	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);
	fseek(file, 0, SEEK_SET);
	buffer->size = size;
	buffer->data = new char[size];
	fgets(buffer->data, size, file);
	return buffer;
};
	
