// Vince Petrelli All Rights Reserved


#include "Characters/WarriorHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "WarriorDebugHelper.h"

AWarriorHeroCharacter::AWarriorHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	// 아래 코드로 마우스를 돌린다고 해서 캐릭터의 몸까지 같이 돌아가지 않게 함.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// 스프링암 생성 및 루트에 부착
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f; // 캐릭터와의 거리
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true; // 컨트롤러 회전에 따라 스프링암이 회전

	// 카메라 생성 및 스프링암에 부착
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false; // 스프링암이 회전하므로 카메라는 직접 회전할 필요 X

	// CharacterMovementComponent 설정
	GetCharacterMovement()->bOrientRotationToMovement = true; // 캐릭터가 입력한 방향으로 몸을 돌리도록 한다.
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f); // 캐릭터가 몸을 돌리는 회전 속도
	GetCharacterMovement()->MaxWalkSpeed = 400.f; // 캐릭터의 최대 걷기 속도
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f; // 이동 입력을 뗐을 때 얼마나 빨리 멈추는지 결정하는 제동 감속도
}

void AWarriorHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("Working"));
}
