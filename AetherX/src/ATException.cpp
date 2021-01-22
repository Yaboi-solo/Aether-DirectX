#include "ATException.h"
#include <sstream>

ATException::ATException(int line, const char* file) noexcept
	:
	line (line),
	file (file)
{}

const char* ATException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* ATException::GetType() const noexcept
{
	return "Aether Exception";
}

int ATException::GetLine() const noexcept
{
	return line;
}

const std::string& ATException::GetFile() const noexcept
{
	return file;
}

std::string ATException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}