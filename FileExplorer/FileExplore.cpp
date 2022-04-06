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
		for (int i = 0; i < depth; i++)
			std::cout << " ";
		std::cout << "¤¤" << path << std::endl;

		if (fs::is_directory(path))
		{	
			Tree(path,depth+1);
		}
		itr++;
	}
}

int main()
{
	fs::path path;
	int depth = 1;
	fs::directory_iterator itr("c:/Download/");
	std::cout << "$ tree" << std::endl;

	while (itr != fs::end(itr))
	{
		const fs::directory_entry& entry = *itr;
		//std::cout << entry.path() << std::endl;
		path = entry.path();

		for (int i = 0; i < depth; i++)
			std::cout << " ";
		std::cout << depth << path << std::endl;


		if (fs::is_directory(path))
		{
			Tree(path,depth+1);
		}
		itr++;
	}
}