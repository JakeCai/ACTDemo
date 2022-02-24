// Copyright Epic Games, Inc. All Rights Reserved.

#include "ACTGameSkill.h"

#define LOCTEXT_NAMESPACE "FACTGameSkillModule"

void FACTGameSkillModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FACTGameSkillModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FACTGameSkillModule, ACTGameSkill)
