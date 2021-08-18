// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoVRStereoLayers.h"

DEFINE_LOG_CATEGORY_STATIC(LogPicoLayer, Log, All);

FPicoVRStereoLayer::FPicoVRStereoLayer(uint32 InId, const IStereoLayers::FLayerDesc& InDesc) :
	Id(InId)
{
	SetDesc(InDesc);
}

FPicoVRStereoLayer::~FPicoVRStereoLayer()
{

}

TSharedPtr<FPicoVRStereoLayer, ESPMode::ThreadSafe> FPicoVRStereoLayer::Clone() const
{
	return MakeShareable(new FPicoVRStereoLayer(*this));
}

void FPicoVRStereoLayer::SetDesc(const IStereoLayers::FLayerDesc& InDesc)
{
	Desc = InDesc;
}

FMatrix FPicoVRStereoLayer::GetLayerMV(FQuat CamOri, FVector CamPos, bool& fixedOverLay)
{
	FVector mModelLocation = FVector::ZeroVector;
	FQuat mModelRotation = FQuat::Identity;
	FVector mModelScale = FVector::OneVector;
	FVector mTexSize = FVector::OneVector;

	FMatrix modelRefine = FMatrix(
		FPlane(1.0f, 0.0f, 0.0f, 0.0f),
		FPlane(0.0f, 1.0f, 0.0f, 0.0f),
		FPlane(0.0f, 0.0f, -1.0f, 0.0f),
		FPlane(0.0f, 0.0f, 0.0f, 1.0f));
	FMatrix mViewMatrix = FMatrix::Identity;
	FMatrix mModelMatrix = FMatrix::Identity;
	FMatrix mMVMatrix = FMatrix::Identity;

	mModelLocation = Desc.Transform.GetLocation();
	mModelScale = Desc.Transform.GetScale3D();
	mModelScale = FVector(mModelScale.Y, mModelScale.Z, mModelScale.X);
	mTexSize = FVector(Desc.QuadSize.X / 100, Desc.QuadSize.Y / 100, 1);

	switch (Desc.PositionType)
	{
	case IStereoLayers::TrackerLocked:
	case IStereoLayers::FaceLocked:
		fixedOverLay = true;

		mModelMatrix.M[0][3] = mModelLocation.Y / 100;
		mModelMatrix.M[1][3] = mModelLocation.Z / 100;
		mModelMatrix.M[2][3] = mModelLocation.X / 100;
		mModelMatrix = mModelMatrix * FScaleMatrix(mModelScale * mTexSize);
		mModelMatrix.M[1][1] = -mModelMatrix.M[1][1];

		mMVMatrix = mViewMatrix.Inverse() * modelRefine * mModelMatrix;
		
		break;

	case IStereoLayers::WorldLocked:
	default:
		fixedOverLay = false;
		CamOri = FQuat(-CamOri.Y, -CamOri.Z, CamOri.X, -CamOri.W);
		mViewMatrix = FRotationMatrix(CamOri.Rotator());
		mViewMatrix.M[0][3] = CamPos.Y / 100;
		mViewMatrix.M[1][3] = CamPos.Z / 100;
		mViewMatrix.M[2][3] = -CamPos.X / 100;
		/*UE_LOG(LogPicoLayer, Log, TEXT("Pvr_UE mViewMatrix M is %f,%f,%f,%f---%f,%f,%f,%f---%f,%f,%f,%f---%f,%f,%f,%f")
				, mViewMatrix.M[0][0]
				, mViewMatrix.M[0][1]
				, mViewMatrix.M[0][2]
				, mViewMatrix.M[0][3]
				, mViewMatrix.M[1][0]
				, mViewMatrix.M[1][1]
				, mViewMatrix.M[1][2]
				, mViewMatrix.M[1][3]
				, mViewMatrix.M[2][0]
				, mViewMatrix.M[2][1]
				, mViewMatrix.M[2][2]
				, mViewMatrix.M[2][3]
				, mViewMatrix.M[3][0]
				, mViewMatrix.M[3][1]
				, mViewMatrix.M[3][2]
				, mViewMatrix.M[3][3]);*/
		mModelRotation = Desc.Transform.GetRotation();
		mModelRotation = FQuat(-mModelRotation.Y, -mModelRotation.Z, mModelRotation.X, -mModelRotation.W);
		mModelMatrix = FRotationMatrix(mModelRotation.Rotator());
		mModelMatrix.M[0][3] = mModelLocation.Y / 100;
		mModelMatrix.M[1][3] = mModelLocation.Z / 100;
		mModelMatrix.M[2][3] = mModelLocation.X / 100;
		mModelMatrix = mModelMatrix * FScaleMatrix(mModelScale * mTexSize);
		mModelMatrix.M[1][1] = -mModelMatrix.M[1][1];
		/*UE_LOG(LogPicoLayer, Log, TEXT("Pvr_UE FScaleMatrix M is %f,%f,%f,%f---%f,%f,%f,%f---%f,%f,%f,%f---%f,%f,%f,%f")
				, AAA.M[0][0]
				, AAA.M[0][1]
				, AAA.M[0][2]
				, AAA.M[0][3]
				, AAA.M[1][0]
				, AAA.M[1][1]
				, AAA.M[1][2]
				, AAA.M[1][3]
				, AAA.M[2][0]
				, AAA.M[2][1]
				, AAA.M[2][2]
				, AAA.M[2][3]
				, AAA.M[3][0]
				, AAA.M[3][1]
				, AAA.M[3][2]
				, AAA.M[3][3]);*/
		mMVMatrix = mViewMatrix.Inverse() * modelRefine * mModelMatrix;
		/*UE_LOG(LogPicoLayer, Log, TEXT("Pvr_UE mMVMatrix M is %f,%f,%f,%f---%f,%f,%f,%f---%f,%f,%f,%f---%f,%f,%f,%f")
				, mMVMatrix.M[0][0]
				, mMVMatrix.M[0][1]
				, mMVMatrix.M[0][2]
				, mMVMatrix.M[0][3]
				, mMVMatrix.M[1][0]
				, mMVMatrix.M[1][1]
				, mMVMatrix.M[1][2]
				, mMVMatrix.M[1][3]
				, mMVMatrix.M[2][0]
				, mMVMatrix.M[2][1]
				, mMVMatrix.M[2][2]
				, mMVMatrix.M[2][3]
				, mMVMatrix.M[3][0]
				, mMVMatrix.M[3][1]
				, mMVMatrix.M[3][2]
				, mMVMatrix.M[3][3]);*/
		break;
	}
	return mMVMatrix;
}
