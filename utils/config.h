#ifndef CONFIG_H
#define CONFIG_H

#include <iostream> // for cout
#include <vector>
#include <fstream>
#include <algorithm> // for remove_if
#include <string>

struct Config
{
public:
	static Config& get(const std::string& configPath = "");
private:
	Config(const char* configPath);

	void setValue(std::string& name, std::string& value);
public:
	bool created = false;
	float fov = 45.0f;
	float width = 800.0f;
	float height = 800.0f;
	const char* windowName = "glfwFramework";
	std::string shadersPath;
	std::string resPath;
};

#endif
