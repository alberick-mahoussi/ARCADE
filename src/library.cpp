/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-lise-emmanuelle.christian
** File description:
** library
*/

#include <dlfcn.h>
#include "core/core.hpp"

Library::Library()
{
}

Library::~Library()
{
}

void *Library::loadLibrary(std::string libraryPath)
{
	void *library = dlopen(libraryPath.c_str(), RTLD_LAZY);

	if (library == nullptr) {
		std::cerr << dlerror() << std::endl;
		exit(84);
	}
	return library;
}

void Library::closeLibrary(void *handle)
{
	dlclose(handle);
}

void *Library::getFunction(void *handle, std::string functionName)
{
	void *func = dlsym(handle, functionName.c_str());
    const char *error = dlerror();
    if (error != NULL) {
        std::cerr << error << std::endl;
        std::exit(84);
    }
    return func;
}