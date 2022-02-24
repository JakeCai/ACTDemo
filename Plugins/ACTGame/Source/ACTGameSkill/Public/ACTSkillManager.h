// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define ACT_SKILL_DEFINE(SKILLNAME)\
UPROPERTY(VisibleAnywhere, BlueprintReadWrite) \
UACTSkillComponent* Skill##SKILLNAME; \
\
UFUNCTION(BlueprintCallable) \
virtual void BindSkill##SKILLNAME(UACTSkillComponent* Skill) { BindSkill(Skill, Skill##SKILLNAME); } \
\
UFUNCTION(BlueprintCallable) \
virtual void CastSkill##SKILLNAME() { CastSkill(Skill##SKILLNAME); } 

#include "CoreMinimal.h"
#include "ACTSkillComponent.h"
#include "Components/ActorComponent.h"
#include "ACTSkillManager.generated.h"

class UACTSkillComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class ACTGAMESKILL_API UACTSkillManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UACTSkillManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<UACTSkillComponent*> SkillArray;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UACTSkillComponent* NowAnimSkill;

	UFUNCTION(BlueprintCallable)
	UACTSkillComponent* AddSkill(TSubclassOf<UACTSkillComponent> SkillClass);

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill(UACTSkillComponent* InBindSkill, UACTSkillComponent* &TargetSkill);

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill(UACTSkillComponent* Skill);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UACTSkillComponent* Skill1;
	
	UFUNCTION(BlueprintCallable)
	virtual void BindSkill1(UACTSkillComponent* Skill) { BindSkill(Skill, Skill1); }
	
	UFUNCTION(BlueprintCallable)
	virtual void CastSkill1() { CastSkill(Skill1); }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UACTSkillComponent* Skill2;
	
	UFUNCTION(BlueprintCallable)
	virtual void BindSkill2(UACTSkillComponent* Skill) { BindSkill(Skill, Skill2); }
	
	UFUNCTION(BlueprintCallable)
	virtual void CastSkill2() { CastSkill(Skill2); }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UACTSkillComponent* Skill3;
	
	UFUNCTION(BlueprintCallable)
	virtual void BindSkill3(UACTSkillComponent* Skill) { BindSkill(Skill, Skill3); }
	
	UFUNCTION(BlueprintCallable)
	virtual void CastSkill3() { CastSkill(Skill3); }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UACTSkillComponent* Skill4;
	
	UFUNCTION(BlueprintCallable)
	virtual void BindSkill4(UACTSkillComponent* Skill) { BindSkill(Skill, Skill4); }
	
	UFUNCTION(BlueprintCallable)
	virtual void CastSkill4() { CastSkill(Skill4); }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UACTSkillComponent* Skill5;
	
	UFUNCTION(BlueprintCallable)
	virtual void BindSkill5(UACTSkillComponent* Skill) { BindSkill(Skill, Skill5); }
	
	UFUNCTION(BlueprintCallable)
	virtual void CastSkill5() { CastSkill(Skill5); }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UACTSkillComponent* Skill6;
	
	UFUNCTION(BlueprintCallable)
	virtual void BindSkill6(UACTSkillComponent* Skill) { BindSkill(Skill, Skill6); }
	
	UFUNCTION(BlueprintCallable)
	virtual void CastSkill6() { CastSkill(Skill6); }
};
