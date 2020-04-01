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
//������TargetPathָ�������ָ�룬��ָ��Texture��Material��SoundWave��SoundCue��ParticlesSystem��AnimMontage��BlendSpace(1D��2D��3D)��AnimSequence��AnimBlueprint��SkeletalMesh�ȵ�
// �ɲ�ʹ��ǰ׺�������׺
UObject * UExpandFunctionsBPLibrary::LoadResourceObject(FString Path,FString SourceName) {
	if (!Path.StartsWith("/Game/"))Path.InsertAt(0, "/Game/");
	if (!Path.EndsWith("/"))Path.Append("/");
	return LoadObject<UObject>(NULL, (Path+ SourceName+"."+ SourceName).GetCharArray().GetData());
}
//����ʱ�������ļ�·�������_C ���� ȥ��·��ǰ׺ 
//���� Texture2D'/Game/Textures/2DBackground.2DBackground' ·��ǰ׺Ϊ Texture2D
//Material'/Game/Materials/DynamicTextureMaterial.DynamicTextureMaterial'
//Blueprint'/Game/AI/AIACtor.AIActor_C' _CΪ��׺

UClass * UExpandFunctionsBPLibrary::LoadBlueprintClass(FString Path,FString SourceName) {
	if (!Path.StartsWith("/Game/"))Path.InsertAt(0, "/Game/");
	if (!Path.EndsWith("/"))Path.Append("/");
	return  LoadClass<UClass>(NULL, (Path + SourceName + "." + SourceName+"_C").GetCharArray().GetData());
}
//���Ҫ��ȡĳ����ͼBP������class������ͨ��ConstructorHelpers::FClassFinder()����ȡ
//�̳���UObject�����Ϳ�ʹ�� cast<TargetClassType>(Source)��ת��

