// Copyright 2021 Xsolla Inc. All Rights Reserved.

#pragma once

#include "XsollaInventoryDataModel.h"

#include "XsollaUtilsHttpRequestHelper.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "Subsystems/SubsystemCollection.h"

#include "XsollaInventorySubsystem.generated.h"

class FJsonObject;

DECLARE_DYNAMIC_DELEGATE(FOnInventoryUpdate);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnInventoryError, int32, StatusCode, int32, ErrorCode, const FString&, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnCouponRewardsUpdate, FInventoryCouponRewardData, RewardsData);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnCouponRedeemUpdate, FInventoryRedeemedCouponData, RewardData);

UCLASS()
class XSOLLAINVENTORY_API UXsollaInventorySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UXsollaInventorySubsystem();

	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// End USubsystem

	/**
	 * Initialize the controller with provided Project ID (use to override project settings)
	 *
	 * @param InProjectId New Project ID value from Publisher Account Project settings > Project ID.
	 */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory")
	void Initialize(const FString& InProjectId);

	/** Update List of Purchased Virtual Items
	 * Updates the list of purchased virtual items (cached locally).
	 *
	 * @param AuthToken User authorization token.
	 * @param SuccessCallback Callback function called after local cache of purchased virtual items was successfully updated.
	 * @param ErrorCallback Callback function called after the request resulted with an error.
	 * @param Limit Limit for the number of elements on the page.
	 * @param Offset Number of the element from which the list is generated (the count starts from 0).
	 */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory", meta = (AutoCreateRefTerm = "SuccessCallback, ErrorCallback"))
	void UpdateInventory(const FString& AuthToken,
		const FOnInventoryUpdate& SuccessCallback, const FOnInventoryError& ErrorCallback, const int Limit = 50, const int Offset = 0);

	/** Update Virtual Currency Balance
	 * Updates virtual currency balance (cached locally).
	 *
	 * @param AuthToken User authorization token.
	 * @param SuccessCallback Callback function called after local cache of virtual currency balance was successfully updated.
	 * @param ErrorCallback Callback function called after the request resulted with an error.
	 */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory|VirtualCurrency", meta = (AutoCreateRefTerm = "SuccessCallback, ErrorCallback"))
	void UpdateVirtualCurrencyBalance(const FString& AuthToken,
		const FOnInventoryUpdate& SuccessCallback, const FOnInventoryError& ErrorCallback);

	/** Update User Subscriptions
	 * Updates the list of user subscriptions (cached locally).
	 *
	 * @param AuthToken User authorization token.
	 * @param SuccessCallback Callback function called after list of user subscriptions was successfully updated.
	 * @param ErrorCallback Callback function called after the request resulted with an error.
	 */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory|Subscriptions", meta = (AutoCreateRefTerm = "SuccessCallback, ErrorCallback"))
	void UpdateSubscriptions(const FString& AuthToken,
		const FOnInventoryUpdate& SuccessCallback, const FOnInventoryError& ErrorCallback);

	/** Consume Inventory Item
	 * Consumes an inventory item.
	 *
	 * @param AuthToken User authorization token.
	 * @param ItemSKU Desired item SKU.
	 * @param Quantity Item quantity. If the item is uncountable, should be zero.
	 * @param InstanceID Instance item ID. If the item is countable, should be empty.
	 * @param SuccessCallback Callback function called after successful inventory item consumption.
	 * @param ErrorCallback Callback function called after the request resulted with an error.
	 */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory", meta = (AutoCreateRefTerm = "SuccessCallback, ErrorCallback"))
	void ConsumeInventoryItem(const FString& AuthToken, const FString& ItemSKU, const int32 Quantity, const FString& InstanceID,
		const FOnInventoryUpdate& SuccessCallback, const FOnInventoryError& ErrorCallback);

	/** Get Coupon Rewards
	 * Gets coupon rewards by its code. Can be used to let users choose one of many items as a bonus.
	 * The usual case is choosing a DRM if the coupon contains a game as a bonus.
	 *
	 * @param AuthToken User authorization token.
	 * @param CouponCode Unique case sensitive code. Contains letters and numbers.
	 * @param SuccessCallback Callback function called after receiving coupon rewards successfully.
	 * @param ErrorCallback Callback function called after the request resulted with an error.
	 */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory|Coupons", meta = (AutoCreateRefTerm = "SuccessCallback, ErrorCallback"))
	void GetCouponRewards(const FString& AuthToken, const FString& CouponCode,
		const FOnCouponRewardsUpdate& SuccessCallback, const FOnInventoryError& ErrorCallback);

	/** Redeem Coupon
	 * Redeems a coupon code. The user gets a bonus after a coupon is redeemed.
	 *
	 * @param AuthToken User authorization token.
	 * @param CouponCode Unique case sensitive code. Contains letters and numbers.
	 * @param SuccessCallback Callback function called after successful coupon redemption.
	 * @param ErrorCallback Callback function called after the request resulted with an error.
	 */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory|Coupons", meta = (AutoCreateRefTerm = "SuccessCallback, ErrorCallback"))
	void RedeemCoupon(const FString& AuthToken, const FString& CouponCode,
		const FOnCouponRedeemUpdate& SuccessCallback, const FOnInventoryError& ErrorCallback);

protected:
	void UpdateInventory_HttpRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse,
		const bool bSucceeded, FOnInventoryUpdate SuccessCallback, FOnInventoryError ErrorCallback);
	void UpdateVirtualCurrencyBalance_HttpRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse,
		const bool bSucceeded, FOnInventoryUpdate SuccessCallback, FOnInventoryError ErrorCallback);
	void UpdateSubscriptions_HttpRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse,
		const bool bSucceeded, FOnInventoryUpdate SuccessCallback, FOnInventoryError ErrorCallback);

	void ConsumeInventoryItem_HttpRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse,
		const bool bSucceeded, FOnInventoryUpdate SuccessCallback, FOnInventoryError ErrorCallback);

	void UpdateCouponRewards_HttpRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse,
		const bool bSucceeded, FOnCouponRewardsUpdate SuccessCallback, FOnInventoryError ErrorCallback);
	void RedeemCoupon_HttpRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse,
		const bool bSucceeded, FOnCouponRedeemUpdate SuccessCallback, FOnInventoryError ErrorCallback);

	void HandleRequestError(const XsollaHttpRequestError& ErrorData, FOnInventoryError ErrorCallback);

private:
	/** Create http request and add Xsolla API meta */
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> CreateHttpRequest(const FString& Url, const EXsollaHttpRequestVerb Verb = EXsollaHttpRequestVerb::VERB_GET,
		const FString& AuthToken = FString(), const FString& Content = FString());

	/** Serialize json object into string */
	FString SerializeJson(const TSharedPtr<FJsonObject> DataJson) const;

	/** Get name of publishing platform */
	FString GetPublishingPlatformName() const;

public:
	/** Gets cached inventory data */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory")
	FInventoryItemsData GetInventory() const;

	/** Gets cached virtual currencies balance */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory|VirtualCurrency")
	TArray<FVirtualCurrencyBalance> GetVirtualCurrencyBalance() const;

	UFUNCTION(BlueprintPure, Category = "Xsolla|Inventory|VirtualCurrency")
	FVirtualCurrencyBalance GetVirtualCurrencyBalanceBySku(const FString& CurrencySku, bool& bWasFound) const;

	/** Gets cached user subscriptions */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory|Subscriptions")
	TArray<FSubscriptionItem> GetSubscriptions() const;

	/** Gets name of the cached item with given SKU */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory")
	FString GetItemName(const FString& ItemSKU) const;

	/** Checks if certain item is in the inventory */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Inventory")
	bool IsItemInInventory(const FString& ItemSKU) const;

protected:
	/** Cached Xsolla Store project id */
	FString ProjectID;

	/** User inventory */
	FInventoryItemsData Inventory;

	/** Cached virtual currency balance */
	FVirtualCurrencyBalanceData VirtualCurrencyBalance;

	/** Cached user subscriptions */
	FSubscriptionData Subscriptions;
};
