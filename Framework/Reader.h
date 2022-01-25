#pragma once
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
inline Buffer ReadFromFile(char* path);
