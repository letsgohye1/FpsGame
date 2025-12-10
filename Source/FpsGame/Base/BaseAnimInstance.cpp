#include "BaseAnimInstance.h"
#include "BaseCharacter.h"
//#include "Math/UnrealMathUtility.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    ABaseCharacter* Character = Cast<ABaseCharacter>(TryGetPawnOwner());
    if (!Character) return;

    if (Character)
    {
        GroundSpeed = Character->GetVelocity().Size2D();
        Direction = CalculateDirection(Character->GetVelocity(), Character->GetActorRotation());
        bIsCrouched = Character->GetCharacterMovement()->IsCrouching();

        
        //Lean
        bLeftLean = Character->bLeftLean;
        bRightLean = Character->bRightLean;

        float TargetLeanAngle = 0.f;

        if (bLeftLean) 
        {
            TargetLeanAngle = -30.f;
        }

        else if(bRightLean)
        {
            TargetLeanAngle = 30.f;
        }

        else
        {
            TargetLeanAngle = 0.f;
        }

        CurrentLeanAngle = FMath::FInterpTo(CurrentLeanAngle, TargetLeanAngle, DeltaSeconds, 8.0f);
    }
}
