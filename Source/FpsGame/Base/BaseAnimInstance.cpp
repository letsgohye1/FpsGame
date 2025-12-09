#include "BaseAnimInstance.h"
#include "BaseCharacter.h"
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

    }
}
