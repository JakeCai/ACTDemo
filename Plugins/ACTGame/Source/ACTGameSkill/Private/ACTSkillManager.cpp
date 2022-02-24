// Fill out your copyright notice in the Description page of Project Settings.


#include "ACTSkillManager.h"
#include "ACTSkillComponent.h"

// Sets default values for this component's properties
UACTSkillManager::UACTSkillManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UACTSkillManager::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetOwner() && GetOwner()->InputComponent)
	{
		GetOwner()->InputComponent->BindAction("LeftMouseClick", EInputEvent::IE_Pressed, this, &UACTSkillManager::CastSkill1);
		GetOwner()->InputComponent->BindAction("RightMouseClick", EInputEvent::IE_Pressed, this, &UACTSkillManager::CastSkill2);
		GetOwner()->InputComponent->BindAction("Q", EInputEvent::IE_Pressed, this, &UACTSkillManager::CastSkill3);
		GetOwner()->InputComponent->BindAction("E", EInputEvent::IE_Pressed, this, &UACTSkillManager::CastSkill4);
		GetOwner()->InputComponent->BindAction("R", EInputEvent::IE_Pressed, this, &UACTSkillManager::CastSkill5);
		GetOwner()->InputComponent->BindAction("F", EInputEvent::IE_Pressed, this, &UACTSkillManager::CastSkill6);
		
		//        GetOwner()->

	}
}


// Called every frame
void UACTSkillManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UACTSkillComponent* UACTSkillManager::AddSkill(TSubclassOf<UACTSkillComponent> SkillClass)
{
	UACTSkillComponent* NewSkill = NewObject<UACTSkillComponent>(GetOwner(), SkillClass);
	NewSkill->RegisterComponent();
	SkillArray.Add(NewSkill);
	NewSkill->OnInit(this);
	return NewSkill;
}

void UACTSkillManager::BindSkill(UACTSkillComponent* InBindSkill, UACTSkillComponent*& TargetSkill)
{
	if (!InBindSkill)
	{
		return;
	}
	TargetSkill = InBindSkill;
}


void UACTSkillManager::CastSkill(UACTSkillComponent* Skill)
{
	if (!Skill)
	{
		return;
	}
	Skill->OnCast();
}
