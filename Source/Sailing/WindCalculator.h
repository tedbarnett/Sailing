#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WindCalculator.generated.h"

UCLASS()
class SAILING_API UWindCalculator : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "Wind")
    static void CalculateSailAndStarboard(float W, float B, float& S, bool& Starboard);
};
