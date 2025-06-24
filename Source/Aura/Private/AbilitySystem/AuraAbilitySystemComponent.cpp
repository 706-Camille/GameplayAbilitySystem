// seungmin


#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystemComponent.h"

void UAuraAbilitySystemComponent::InitAbilityActorInfoSet()
{
	// Delegate에 콜백함수를 등록. EffectAppiledToSelf -> 콜백함수 호출됨
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	for (const FGameplayTag& Tag : TagContainer)
	{
		// TODO : Broadcast the tag to ther Widget Controller
		const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);
	}
	
}
