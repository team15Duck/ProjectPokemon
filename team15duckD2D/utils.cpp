#include "stdafx.h"
#include "utils.h"


namespace TEAM_15DUCK_UTILL
{
	const wstring MakeImageName(const WCHAR * imageName, const WCHAR * folderName)
	{
		wstring str = L"";

		if (nullptr != folderName)
		{
			str.append(folderName);
			str.append(L"/");
		}

		str.append(imageName);
		str.append(L".bmp");

		return str;
	}
	const wstring AppendInt(const WCHAR * imageName, int value)
	{
		wstring str = L"";

		str.append(imageName);
		str.append(to_wstring(value));

		return str;
	}
}