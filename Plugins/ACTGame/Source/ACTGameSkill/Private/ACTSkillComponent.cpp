// Fill out your copyright notice in the Description page of Project Settings.


#include "ACTSkillComponent.h"
#include "GameFramework/Character.h"
#include "ACTSkillManager.h"

// Sets default values for this component's properties
UACTSkillComponent::UACTSkillComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UACTSkillComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UACTSkillComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UACTSkillComponent::OnCast()
{
	PlayAnimation();
	OnCastImp();
}


void UACTSkillComponent::PlayAnimation()
{
	if (!SkillMontage || !SkillManager)
	{
		return;
	}
	
	ACharacter* tCharacter = Cast<ACharacter>(GetOwner());
	if (!tCharacter)
	{
		return;
	}
	tCharacter->PlayAnimMontage(SkillMontage);
	SkillManager->NowAnimSkill = this;
}