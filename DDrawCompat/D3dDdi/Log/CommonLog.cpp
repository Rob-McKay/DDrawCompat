#include <cctype>

#include <Common/Log.h>
#include <D3dDdi/Log/CommonLog.h>

std::ostream& operator<<(std::ostream& os, const D3DDDI_RATIONAL& val)
{
	return Compat::LogStruct(os)
		<< val.Numerator
		<< val.Denominator;
}

std::ostream& operator<<(std::ostream& os, D3DDDIFORMAT val)
{
	bool isFourCc = true;
	for (UINT i = 0; i < 4; ++i)
	{
		if (!isalnum(reinterpret_cast<const char*>(&val)[i]))
		{
			isFourCc = false;
			break;
		}
	}

	if (isFourCc)
	{
		return os << "FOURCC(" << std::string(reinterpret_cast<const char*>(&val), sizeof(val)) << ')';
	}

	switch (val)
	{
		LOG_CONST_CASE(D3DDDIFMT_UNKNOWN);
		LOG_CONST_CASE(D3DDDIFMT_R8G8B8);
		LOG_CONST_CASE(D3DDDIFMT_A8R8G8B8);
		LOG_CONST_CASE(D3DDDIFMT_X8R8G8B8);
		LOG_CONST_CASE(D3DDDIFMT_R5G6B5);
		LOG_CONST_CASE(D3DDDIFMT_X1R5G5B5);
		LOG_CONST_CASE(D3DDDIFMT_A1R5G5B5);
		LOG_CONST_CASE(D3DDDIFMT_A4R4G4B4);
		LOG_CONST_CASE(D3DDDIFMT_R3G3B2);
		LOG_CONST_CASE(D3DDDIFMT_A8);
		LOG_CONST_CASE(D3DDDIFMT_A8R3G3B2);
		LOG_CONST_CASE(D3DDDIFMT_X4R4G4B4);
		LOG_CONST_CASE(D3DDDIFMT_A2B10G10R10);
		LOG_CONST_CASE(D3DDDIFMT_A8B8G8R8);
		LOG_CONST_CASE(D3DDDIFMT_X8B8G8R8);
		LOG_CONST_CASE(D3DDDIFMT_G16R16);
		LOG_CONST_CASE(D3DDDIFMT_A2R10G10B10);
		LOG_CONST_CASE(D3DDDIFMT_A16B16G16R16);
		LOG_CONST_CASE(D3DDDIFMT_A8P8);
		LOG_CONST_CASE(D3DDDIFMT_P8);
		LOG_CONST_CASE(D3DDDIFMT_L8);
		LOG_CONST_CASE(D3DDDIFMT_A8L8);
		LOG_CONST_CASE(D3DDDIFMT_A4L4);
		LOG_CONST_CASE(D3DDDIFMT_V8U8);
		LOG_CONST_CASE(D3DDDIFMT_L6V5U5);
		LOG_CONST_CASE(D3DDDIFMT_X8L8V8U8);
		LOG_CONST_CASE(D3DDDIFMT_Q8W8V8U8);
		LOG_CONST_CASE(D3DDDIFMT_V16U16);
		LOG_CONST_CASE(D3DDDIFMT_W11V11U10);
		LOG_CONST_CASE(D3DDDIFMT_A2W10V10U10);
		LOG_CONST_CASE(D3DDDIFMT_D16_LOCKABLE);
		LOG_CONST_CASE(D3DDDIFMT_D32);
		LOG_CONST_CASE(D3DDDIFMT_D15S1);
		LOG_CONST_CASE(D3DDDIFMT_D24S8);
		LOG_CONST_CASE(D3DDDIFMT_D24X8);
		LOG_CONST_CASE(D3DDDIFMT_D24X4S4);
		LOG_CONST_CASE(D3DDDIFMT_D16);
		LOG_CONST_CASE(D3DDDIFMT_D32F_LOCKABLE);
		LOG_CONST_CASE(D3DDDIFMT_D24FS8);
		LOG_CONST_CASE(D3DDDIFMT_D32_LOCKABLE);
		LOG_CONST_CASE(D3DDDIFMT_S8_LOCKABLE);
		LOG_CONST_CASE(D3DDDIFMT_S1D15);
		LOG_CONST_CASE(D3DDDIFMT_S8D24);
		LOG_CONST_CASE(D3DDDIFMT_X8D24);
		LOG_CONST_CASE(D3DDDIFMT_X4S4D24);
		LOG_CONST_CASE(D3DDDIFMT_L16);
		LOG_CONST_CASE(D3DDDIFMT_G8R8);
		LOG_CONST_CASE(D3DDDIFMT_R8);
		LOG_CONST_CASE(D3DDDIFMT_VERTEXDATA);
		LOG_CONST_CASE(D3DDDIFMT_INDEX16);
		LOG_CONST_CASE(D3DDDIFMT_INDEX32);
		LOG_CONST_CASE(D3DDDIFMT_Q16W16V16U16);
		LOG_CONST_CASE(D3DDDIFMT_R16F);
		LOG_CONST_CASE(D3DDDIFMT_G16R16F);
		LOG_CONST_CASE(D3DDDIFMT_A16B16G16R16F);
		LOG_CONST_CASE(D3DDDIFMT_R32F);
		LOG_CONST_CASE(D3DDDIFMT_G32R32F);
		LOG_CONST_CASE(D3DDDIFMT_A32B32G32R32F);
		LOG_CONST_CASE(D3DDDIFMT_CxV8U8);
		LOG_CONST_CASE(D3DDDIFMT_A1);
		LOG_CONST_CASE(D3DDDIFMT_A2B10G10R10_XR_BIAS);
		LOG_CONST_CASE(D3DDDIFMT_PICTUREPARAMSDATA);
		LOG_CONST_CASE(D3DDDIFMT_MACROBLOCKDATA);
		LOG_CONST_CASE(D3DDDIFMT_RESIDUALDIFFERENCEDATA);
		LOG_CONST_CASE(D3DDDIFMT_DEBLOCKINGDATA);
		LOG_CONST_CASE(D3DDDIFMT_INVERSEQUANTIZATIONDATA);
		LOG_CONST_CASE(D3DDDIFMT_SLICECONTROLDATA);
		LOG_CONST_CASE(D3DDDIFMT_BITSTREAMDATA);
		LOG_CONST_CASE(D3DDDIFMT_MOTIONVECTORBUFFER);
		LOG_CONST_CASE(D3DDDIFMT_FILMGRAINBUFFER);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED9);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED10);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED11);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED12);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED13);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED14);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED15);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED16);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED17);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED18);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED19);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED20);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED21);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED22);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED23);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED24);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED25);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED26);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED27);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED28);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED29);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED30);
		LOG_CONST_CASE(D3DDDIFMT_DXVA_RESERVED31);
		LOG_CONST_CASE(D3DDDIFMT_BINARYBUFFER);
	}

	return os << "D3DDDIFMT_" << static_cast<DWORD>(val);
}
