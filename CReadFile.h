/*
===	Author:	junqingmark 
===	Date:	2015.11.10
===	File:	iReadFile.h
*/

#ifndef _CREADFILE_H_
#define _CREADFILE_H_
#include "IReadFile.h"

class CReadFile:public IReadFile
{
	public:
		CReadFile(const char* fileName);
		virtual ~CReadFile();
		
		//return how much was read
		virtual size_t read(void *buffer,size_t sizeToRead);
		
		//change position in file,return true if successful
		virtual bool seek(s32 finalPos,bool MoveFromStart=false);
		
		//return the size of file
		virtual size_t getSize();
		
		//return the file is open
		bool isOpen();
		
		//return where in the file we are
		virtual s32 getPos();
		
		//return the name of file
		virtual const char* getFileName();
		
	private:
		
		void openFile();
		
		const char* FileName;
		FILE* File;
		size_t FileSize;
};


#endif