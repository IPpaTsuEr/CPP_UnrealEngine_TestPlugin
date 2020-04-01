// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "HashLibraryBPLibrary.h"
#include "HashLibrary.h"

UHashLibraryBPLibrary::UHashLibraryBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UHashLibraryBPLibrary::HashLibrarySampleFunction(float Param)
{
	return -1;
}

int32 UHashLibraryBPLibrary::GetHashCode(FString String) {
	int32 Hash = 0L;
	for (int i = 0; i < String.Len(); i++) {
		Hash += String[i];
		Hash *= 1313131;
	}
	Hash ^= (unsigned)Hash >> 16;
	Hash &= 0x7FFFFFFF;
	return Hash;
}