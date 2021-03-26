// Copyright 2021 Xsolla Inc. All Rights Reserved.

#include "XsollaUtilsSettings.h"
#include "UObject/ConstructorHelpers.h"

UXsollaUtilsSettings::UXsollaUtilsSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UXsollaUtilsTheme> ThemeFinder(TEXT("/XsollaInventory/Utils/BP_DefaultTheme.BP_DefaultTheme_C"));
	InterfaceTheme = ThemeFinder.Class;
}
