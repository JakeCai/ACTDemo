// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ACTSkillComponent.generated.h"

class UACTSkillManager;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class ACTGAMESKILL_API UACTSkillComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UACTSkillComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnyWhere,BlueprintReadWrite)
	UACTSkillManager* SkillManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* SkillMontage;

	UFUNCTION(BlueprintCallable)
	virtual void OnInit(UACTSkillManager* InSkillManager) { SkillManager = InSkillManager; }

	UFUNCTION(BlueprintCallable)
	virtual void OnCast();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCastImp();

	UFUNCTION(BlueprintCallable)
	void PlayAnimation();
};
