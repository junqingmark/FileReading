/*
===	Author:	junqingmark 
===	Date:	2015.11.10
===	File:	iReadFile.h
*/

#include "CReadFile.h"

using namespace std;

CReadFile::CReadFile(const char* fileName)
{
	FileName = fileName;
	FileSize = 0;
	openFile();
}

CReadFile::~CReadFile()
{
	if(File != NULL)
	{
		fclose(File);
	}
}

bool CReadFile::isOpen()
{
	return File != NULL;
}

size_t CReadFile::read(void *buffer,size_t sizeToRead)
{
	if(!isOpen())
	{
		return 0;
	}
	
	return fread(buffer,1,sizeToRead,File);
}

bool CReadFile::seek(s32 finalPos,bool MoveFromStart)
{
	if(!isOpen())
	{
		return false;
	}
	
	return 0 == fseek(File,finalPos,MoveFromStart? SEEK_SET : SEEK_CUR);
}

size_t CReadFile::getSize()
{
	return FileSize;
}

s32 CReadFile::getPos()
{
	return ftell(File);
}

void CReadFile::openFile()
{
	File = fopen(FileName,"rb");
	
	if(File)
	{
		//get file size
		fseek(File,0,SEEK_END);
		FileSize = ftell(File);
		fseek(File,0,SEEK_SET);
	}
}

const char* CReadFile::getFileName()
{
	return FileName;
}

IReadFile* createReadFile(const char* fileName)
{
	CReadFile *file = new CReadFile(fileName);
	if(file->isOpen())
	{
		return file;
	}
	
	delete file;
	return NULL;
}