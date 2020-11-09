// Copyright 2020 Xsolla Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "XsollaUtilsDataModel.generated.h"

/** Target platform name */
UENUM(BlueprintType)
enum class EXsollaPublishingPlatform : uint8
{
	PlaystationNetwork,
	XboxLive,
	Xsolla,
	PcStandalone,
	NintendoShop,
	GooglePlay,
	AppStoreIos,
	AndroidStandalone,
	IosStandalone,
	AndroidOther,
	IosOther,
	PcOther
};

USTRUCT(BlueprintType)
struct XSOLLAUTILS_API FXsollaItemGroup
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Item Group")
	int32 id;

	UPROPERTY(BlueprintReadOnly, Category = "Item Group")
	FString external_id;

	UPROPERTY(BlueprintReadOnly, Category = "Item Group")
	FString name;

	UPROPERTY(BlueprintReadOnly, Category = "Item Group")
	FString description;

	UPROPERTY(BlueprintReadOnly, Category = "Item Group")
	FString image_url;

	UPROPERTY(BlueprintReadOnly, Category = "Item Group")
	int32 level;

	UPROPERTY(BlueprintReadOnly, Category = "Item Group")
	int32 order;

	UPROPERTY(BlueprintReadOnly, Category = "Item Group")
	FString parent_external_id;

	public:
	FXsollaItemGroup()
        : id(-1)
        , level(0)
        , order(1){};
};

USTRUCT(BlueprintType)
struct XSOLLAUTILS_API FXsollaItemAttribute
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Item Attribute")
	int32 stack_size;

	UPROPERTY(BlueprintReadOnly, Category = "Item Attribute")
	bool licensed;

public:
	FXsollaItemAttribute()
		: stack_size(0)
		, licensed(false){};
};

USTRUCT(BlueprintType)
struct XSOLLAUTILS_API FXsollaPrice
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Item Price")
	FString amount;

	UPROPERTY(BlueprintReadOnly, Category = "Item Price")
	FString amount_without_discount;

	UPROPERTY(BlueprintReadOnly, Category = "Item Price")
	FString currency;

public:
	FXsollaPrice(){};
};

USTRUCT(BlueprintType)
struct XSOLLAUTILS_API FXsollaExpirationPeriod
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Item Expiration Period")
	int32 value;

	UPROPERTY(BlueprintReadOnly, Category = "Item Expiration Period")
	FString type;

public:
	FXsollaExpirationPeriod()
		: value(0){};
};

USTRUCT(BlueprintType)
struct XSOLLAUTILS_API FXsollaItemOptions
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Item Options")
	FXsollaExpirationPeriod expiration_period;
};

USTRUCT(BlueprintType)
struct XSOLLAUTILS_API FXsollaVirtualCurrencyCalculatedPrice
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Virtual Currency Calculated Price")
	FString amount;

	UPROPERTY(BlueprintReadOnly, Category = "Virtual Currency Calculated Price")
	FString amount_without_discount;
};

USTRUCT(BlueprintType)
struct XSOLLAUTILS_API FXsollaVirtualCurrencyPrice
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Item Virtual Currency Price")
	FString sku;

	UPROPERTY(BlueprintReadOnly, Category = "Item Virtual Currency Price")
	bool is_default;

	UPROPERTY(BlueprintReadOnly, Category = "Item Virtual Currency Price")
	int amount;

	UPROPERTY(BlueprintReadOnly, Category = "Item Virtual Currency Price")
	int amount_without_discount;

	UPROPERTY(BlueprintReadOnly, Category = "Item Virtual Currency Price")
	FString image_url;

	UPROPERTY(BlueprintReadOnly, Category = "Item Virtual Currency Price")
	FString name;

	UPROPERTY(BlueprintReadOnly, Category = "Item Virtual Currency Price")
	FString description;

	UPROPERTY(BlueprintReadOnly, Category = "Item Virtual Currency Price")
	FString type;

	UPROPERTY(BlueprintReadOnly, Category = "Item Virtual Currency Price")
	FXsollaVirtualCurrencyCalculatedPrice calculated_price;

public:
	FXsollaVirtualCurrencyPrice()
		: is_default(false)
		, amount(0)
		, amount_without_discount(0){};
};

USTRUCT(BlueprintType)
struct XSOLLAUTILS_API FXsollaUnitItem
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Unit Item")
	FString sku;

	UPROPERTY(BlueprintReadOnly, Category = "Unit Item")
	FString name;

	UPROPERTY(BlueprintReadOnly, Category = "Unit Item")
	FString type;

	UPROPERTY(BlueprintReadOnly, Category = "Unit Item")
	FString drm_name;

	UPROPERTY(BlueprintReadOnly, Category = "Unit Item")
	FString drm_sku;
};

USTRUCT(BlueprintType)
struct XSOLLAUTILS_API FXsollaRewardItem
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Reward Item")
	FString sku;

	UPROPERTY(BlueprintReadOnly, Category = "Reward Item")
	FString name;

	UPROPERTY(BlueprintReadOnly, Category = "Reward Item")
	FString type;

	UPROPERTY(BlueprintReadOnly, Category = "Reward Item")
	FString virtual_item_type;

	UPROPERTY(BlueprintReadOnly, Category = "Reward Item")
	FString description;

	UPROPERTY(BlueprintReadOnly, Category = "Reward Item")
	FString image_url;

	UPROPERTY(BlueprintReadOnly, Category = "Reward Item")
	TArray<FXsollaUnitItem> unit_items;
};

USTRUCT(BlueprintType)
struct XSOLLAUTILS_API FXsollaBonusItem
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Bonus Item")
	FXsollaRewardItem item;

	UPROPERTY(BlueprintReadOnly, Category = "Bonus Item")
	int32 quantity;

public:
	FXsollaBonusItem()
		: quantity(0){};
};