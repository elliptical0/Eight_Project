// Fill out your copyright notice in the Description page of Project Settings.


#include "NetCompression.h"


FVector_NetQuantize UNetCompression::NetQuantize(FVector input)
{
	return FVector_NetQuantize(input);
}

FVector_NetQuantizeNormal UNetCompression::NetQuantizeNormal(FVector input)
{
	return FVector_NetQuantizeNormal(input);
}
