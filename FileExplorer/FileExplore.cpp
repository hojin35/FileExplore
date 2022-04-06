#include<filesystem>
#include<iostream>
#include<string>
namespace fs = std::filesystem;

int cnt = 0;
void Tree(fs::path _path,int depth)
{
	fs::path path;
	fs::directory_iterator itr(_path);
	while (itr != fs::end(itr))
	{
		const fs::directory_entry& entry = *itr;
		//std::cout << entry.path() << std::endl;
		path = entry.path();

		auto myname = path.filename();
		for (int i = 0; i < depth; i++)
			std::cout << "弛   ";
			std::cout << "戍式式 " << myname << std::endl;

		if (fs::is_directory(path))
		{	
			Tree(path,depth+1);
		}
		itr++;
	}
}

int main()
{
	fs::path startPath;
	startPath = "c:/Download/";
	fs::path path;
	int depth = 0;
	fs::directory_iterator itr(startPath);
	std::cout << "$ tree" << std::endl;
	std::cout << startPath << std::endl;

	while (itr != fs::end(itr))
	{
		const fs::directory_entry& entry = *itr;
		//std::cout << entry.path() << std::endl;
		path = entry.path();

		auto myname = path.filename();
		for (int i = 0; i < depth; i++)
			std::cout << "弛   ";
			std::cout << "戍式式 " << myname << std::endl;


		if (fs::is_directory(path))
		{
			Tree(path,depth+1);
		}
		itr++;
	}
}