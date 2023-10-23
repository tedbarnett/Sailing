#include "WindCalculator.h"
#include "Math/UnrealMathUtility.h"

void UWindCalculator::CalculateSailAndStarboard(float W, float B, float& S, bool& Starboard)
{
    // Calculation for Apparent Wind Angle (A)
    float A;
    if (B <= 180.0f)
    {
        A = FMath::Lerp(0.0f, 180.0f, FMath::Clamp((W - 0.5f) * 2.0f, 0.0f, 1.0f));
    }
    else
    {
        A = FMath::Lerp(180.0f, 360.0f, FMath::Clamp((W - 0.5f) * 2.0f, 0.0f, 1.0f));
    }

    // Interpolation of SailPctOut (S) based on Apparent Wind Angle (A)
    TMap<float, float> SailPctOutData = {
        {0, 0.0f}, {15, 0.0f}, {30, 0.0f}, {45, 0.0f}, {60, 0.17f}, {75, 0.33f}, {90, 0.50f},
        {105, 0.58f}, {120, 0.67f}, {135, 0.75f}, {150, 0.83f}, {165, 0.92f}, {180, 1.00f},
        {195, 0.92f}, {210, 0.83f}, {225, 0.75f}, {240, 0.67f}, {255, 0.58f}, {270, 0.50f},
        {285, 0.33f}, {300, 0.17f}, {315, 0.0f}, {330, 0.0f}, {345, 0.0f}, {360, 0.0f}
    };
    float SailPctOut = 0.0f;
    for (auto& Pair : SailPctOutData)
    {
        if (A <= Pair.Key)
        {
            SailPctOut = Pair.Value;
            break;
        }
    }

    // Starboard determination
    Starboard = A <= 180;

    // Return the values
    S = SailPctOut;
}
