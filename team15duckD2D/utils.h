#pragma once

#define PI 3.141592f
#define PI2 2 * PI

namespace TEAM_15DUCK_UTILL
{
	const wstring MakeImageName(const WCHAR* imageName, const WCHAR* folderName = nullptr);

	const wstring AppendInt(const WCHAR* imageName, int value);

}