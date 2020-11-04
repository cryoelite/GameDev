// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "The_Escape/The_EscapeGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeThe_EscapeGameModeBase() {}
// Cross Module References
	THE_ESCAPE_API UClass* Z_Construct_UClass_AThe_EscapeGameModeBase_NoRegister();
	THE_ESCAPE_API UClass* Z_Construct_UClass_AThe_EscapeGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_The_Escape();
// End Cross Module References
	void AThe_EscapeGameModeBase::StaticRegisterNativesAThe_EscapeGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AThe_EscapeGameModeBase_NoRegister()
	{
		return AThe_EscapeGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AThe_EscapeGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AThe_EscapeGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_The_Escape,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AThe_EscapeGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "The_EscapeGameModeBase.h" },
		{ "ModuleRelativePath", "The_EscapeGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AThe_EscapeGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AThe_EscapeGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AThe_EscapeGameModeBase_Statics::ClassParams = {
		&AThe_EscapeGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AThe_EscapeGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AThe_EscapeGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AThe_EscapeGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AThe_EscapeGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AThe_EscapeGameModeBase, 2350288563);
	template<> THE_ESCAPE_API UClass* StaticClass<AThe_EscapeGameModeBase>()
	{
		return AThe_EscapeGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AThe_EscapeGameModeBase(Z_Construct_UClass_AThe_EscapeGameModeBase, &AThe_EscapeGameModeBase::StaticClass, TEXT("/Script/The_Escape"), TEXT("AThe_EscapeGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AThe_EscapeGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
