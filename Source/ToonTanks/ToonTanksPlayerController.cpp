// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksPlayerController.h"
#include "GameFramework/Pawn.h"

void AToonTanksPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
    APawn* ControlledPawn = GetPawn();
    if (!ControlledPawn) return;

    if (bPlayerEnabled)
    {
        ControlledPawn->EnableInput(this);

        FInputModeGameOnly InputMode;
        SetInputMode(InputMode);

        bShowMouseCursor = false;
    }
    else
    {
        ControlledPawn->DisableInput(this);

        FInputModeUIOnly InputMode;
        SetInputMode(InputMode);

        bShowMouseCursor = true;
    }
}