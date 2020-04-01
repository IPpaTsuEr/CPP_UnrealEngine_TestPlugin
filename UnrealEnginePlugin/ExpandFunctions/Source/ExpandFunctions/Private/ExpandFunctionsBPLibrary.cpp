// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ExpandFunctionsBPLibrary.h"
#include "ExpandFunctions.h"

UExpandFunctionsBPLibrary::UExpandFunctionsBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float ExpandFunctionsSampleFunction(float Param)
{
	return -1;
}

int32 UExpandFunctionsBPLibrary::HashCode(FString String)
{
	int32 Hash = 0L;
	for (int i = 0; i < String.Len(); i++) {
		Hash += String[i];
		Hash *= 1313131;
	}
	Hash ^= (unsigned)Hash >> 16;
	Hash &= 0x7FFFFFFF;
	return Hash;
}
//返回由TargetPath指定对象的指针，可指定Texture、Material、SoundWave、SoundCue、ParticlesSystem、AnimMontage、BlendSpace(1D，2D，3D)、AnimSequence、AnimBlueprint、SkeletalMesh等等
// 可不使用前缀，无需后缀
UObject * UExpandFunctionsBPLibrary::LoadResourceObject(FString Path,FString SourceName) {
	if (!Path.StartsWith("/Game/"))Path.InsertAt(0, "/Game/");
	if (!Path.EndsWith("/"))Path.Append("/");
	return LoadObject<UObject>(NULL, (Path+ SourceName+"."+ SourceName).GetCharArray().GetData());
}
//运行时报错，在文件路径后面加_C 或是 去掉路径前缀 
//例如 Texture2D'/Game/Textures/2DBackground.2DBackground' 路径前缀为 Texture2D
//Material'/Game/Materials/DynamicTextureMaterial.DynamicTextureMaterial'
//Blueprint'/Game/AI/AIACtor.AIActor_C' _C为后缀

UClass * UExpandFunctionsBPLibrary::LoadBlueprintClass(FString Path,FString SourceName) {
	if (!Path.StartsWith("/Game/"))Path.InsertAt(0, "/Game/");
	if (!Path.EndsWith("/"))Path.Append("/");
	return  LoadClass<UClass>(NULL, (Path + SourceName + "." + SourceName+"_C").GetCharArray().GetData());
}
//如果要获取某个蓝图BP的类型class，可以通过ConstructorHelpers::FClassFinder()来获取
//继承于UObject的类型可使用 cast<TargetClassType>(Source)来转型

