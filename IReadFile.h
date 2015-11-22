/*
===	Author:	junqingmark 
===	Date:	2015.11.10
===	File:	iReadFile.h
*/

#ifndef _IREADFILE_H_
#define _IREADFILE_H_
#include <stdio.h>

typedef signed int s32;

class IReadFile
{
	public:
		virtual ~IReadFile(){}
		
		//read specific amount of bytes from file
		//return the bytes read from the file	
		virtual size_t read(void *buffer,size_t sizeToRead)=0;
		
		//change position in the file,if change success return true,if MoveFromStart set to true,
		//means the position is changed from begin of the file
		//return true if seek is success,else return false
		virtual bool seek(s32 finalPos,bool MoveFromStart=false)=0;
		
		//return the size of the file
		virtual size_t getSize()=0;
		
		//return the current position in the file
		virtual s32 getPos()=0;
		
		//return name of the file
		virtual const char* getFileName()=0;
	
};

//Internal function
IReadFile* createReadFile(const char* fileName);
IReadFile* createLimitReadFile(const char* fileName,IReadFile* alreadyOpenedFile,size_t areaSize);
IReadFile* createMemoryReadFile(void* memory,s32 size,const char* fileName,bool deleteMemoryWhenDropped);
#endif