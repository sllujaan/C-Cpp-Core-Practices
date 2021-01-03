#include "File.h"

MY_FILES::FILE::FILE()
{

}

void MY_FILES::FILE::init()
{
	int ret = SetFileAttributesA(
		"C:\\Users\\SALMAN-ALTAF\\Desktop\\testDir\\New folder",
		FILE_ATTRIBUTE_HIDDEN
	);

	if (ret != 0) {
		LOG("Attribute Set.");
	}
}
