#pragma once

#include<Windows.h>
#include<string>


class window final
{
public:
	window() = default;

	~window() = default;

	[[nodiscard]] HRESULT create(HINSTANCE instance,int width,int height, std::string_view name)
};

