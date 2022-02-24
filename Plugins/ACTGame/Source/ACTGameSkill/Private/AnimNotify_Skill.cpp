// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_Skill.h"
#include "ACTSkillManager.h"
#include "ACTSkillComponent.h"

void UAnimNotify_Skill::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	if (!MeshComp)
	{
		return;
	}
	
	TInlineComponentArray<UACTSkillManager*> Components(MeshComp->GetOwner());
	for (auto Manager : Components)
	{
		UACTSkillComponent *NowSkill = Manager->NowAnimSkill;
		if (!NowSkill)
		{
			return;
		}
		UFunction* tFunc = NowSkill->FindFunction(FunctionName);
		if (tFunc)
		{
			NowSkill->ProcessEvent(tFunc, nullptr);
		}
	}
}
